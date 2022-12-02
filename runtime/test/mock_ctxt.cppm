export module SteelRT.Test.MockCtxt;

import SteelRT.Dep;

import SteelRT.Util.Values;

export import SteelRT.Work.Descriptor.Local;
export import SteelRT.Work.Descriptor.Global;

import SteelRT.Task.Descriptor;
import SteelRT.Task.Dispatcher;

import SteelRT.Util.App;

export import <list>;
import <csignal>;


export
namespace test::mock_ctxt { 
////////////// FOR CONSISTENCY AND WRAP_AND_RUN

template <typename ImplSelectorT, app::impl... Impls>
class with_selector : public dep::solver<with_selector<ImplSelectorT, Impls...>, ImplSelectorT, util::sequence::enum_t< app::impl, Impls...>> {
public:
  using allowed_impls = util::sequence::enum_t< app::impl, Impls...>;

  with_selector(ImplSelectorT& isr) : dep::solver<with_selector<ImplSelectorT, Impls...>, ImplSelectorT, util::sequence::enum_t< app::impl, Impls...>>(isr) {
    std::signal(global::ErrorSignal, global::signal_handler);
  }

  thread_id_t get_thread_id() const noexcept {
    return global::MainThreadId;
  }

  template <typename AppGroupImplT, typename DescT>
  void push_descriptor(thread_id_t t, DescT&& d) noexcept {
    // do nothing. d is deleted
  }

  template <policy::thread_status Status>
  void set() noexcept {
    // do nothing
  }

  with_selector& get_descriptor_container_ref() {
    return *this;
  }

};

///////////// QUEUE OPS TEST
template <class QueueContainerT>
class with_queue : public QueueContainerT {
private:
  thread_id_t m_threadId;
public:

  using allow_group_impls = typename QueueContainerT::unique_queue_params;

public:
  with_queue(thread_id_t thId) : QueueContainerT(), m_threadId(thId) {
    std::signal(global::ErrorSignal, global::signal_handler);
  }

  thread_id_t get_thread_id() const noexcept { return m_threadId; }

  template <typename AppGroupImplT>
  workload::desc::global_queue<AppGroupImplT>& get_stealer_queue_ref() {
    return QueueContainerT::template get_queue_ref<AppGroupImplT>();
  }

  template <policy::thread_status Status>
  void set() noexcept {
    // do nothing
  }

  QueueContainerT& get_descriptor_container_ref() {
    return static_cast<QueueContainerT&>(*this);
  }

};


///////////// REIMPLEMENT MOCK_CTXT
template <typename ImplSelectorT, template <app::impl...> class DescContainerT, app::impl... Impls>
class with_selector_queue :
  public dep::solver<with_selector_queue<ImplSelectorT, DescContainerT, Impls...>, ImplSelectorT, util::sequence::enum_t< app::impl, Impls...>>,
  public util::sequence::to_variadic_t< util::sequence::enum_t<app::impl, Impls...>, DescContainerT >
{
private:

  using solver_super_type = dep::solver<with_selector_queue<ImplSelectorT, DescContainerT, Impls...>, ImplSelectorT, util::sequence::enum_t< app::impl, Impls...>>;
  using descriptor_container_super_type = util::sequence::to_variadic_t< util::sequence::enum_t<app::impl, Impls...>, DescContainerT >;

  template <app::impl AppImpl>
  using vec_t = std::list< std::shared_ptr<task::coro::dispatcher<AppImpl>> >;

  using stored_dispatchers_t = std::tuple< vec_t<Impls> ... >;

  stored_dispatchers_t m_dispatchersTuple;

  bool m_gotError = false;

public:
  using allowed_impls = util::sequence::enum_t< app::impl, Impls...>;
  using allow_group_impls = util::tuple_t<app::group_impl_of_t<Impls>...>;
  using allowed_ids = util::sequence::unique_t< util::sequence::transform_t< allowed_impls, app::id, app::id_of_impl > >;

  template <typename... Ts>
  with_selector_queue(ImplSelectorT& isr, Ts... arg) :
    solver_super_type(isr),
    descriptor_container_super_type(arg...)
  {
    std::signal(global::ErrorSignal, global::signal_handler);
  }

  descriptor_container_super_type& get_descriptor_container_ref() {
    return static_cast<descriptor_container_super_type&>( *this );
  }

  with_selector_queue& get_dispatcher_container_ref() {
    return *this; 
  }

  thread_id_t get_thread_id() const noexcept {
    return global::MainThreadId;
  }


  template <typename AppGroupImplT, typename DescT>
  void push_descriptor(thread_id_t t, DescT&& d) noexcept {
    this->get_descriptor_container_ref().template push<AppGroupImplT>( t, std::forward<DescT>(d) );
    // do nothing. d is deleted
  }

  template <policy::thread_status Status>
  void set() noexcept {
    if constexpr (Status == policy::thread_status::error) {
      m_gotError = true;
    }
    // do nothing
  }
  bool got_error() const noexcept {
    return m_gotError;
  }


  template <app::impl AppImpl, typename DispShPtrT>
  void push_dispatcher(DispShPtrT&& dispShPtr) noexcept {
    std::get< vec_t<AppImpl> >(m_dispatchersTuple).emplace_back( std::forward<DispShPtrT>(dispShPtr) );
  }

  template <app::impl AppImpl>
  std::shared_ptr<task::coro::dispatcher<AppImpl>>
  try_pop_dispatcher() {
   
    if (not std::get< vec_t<AppImpl> >(m_dispatchersTuple).empty()) {

      auto retShPtr = std::get< vec_t<AppImpl> >(m_dispatchersTuple).back();
  
      std::get< vec_t<AppImpl> >(m_dispatchersTuple).pop_back();
      return retShPtr;
    }

    return nullptr;
  }

  template <typename AppGroupImplT>
  workload::desc::global_queue<AppGroupImplT>&
  get_stealer_queue_ref() noexcept {
    return this->get_descriptor_container_ref().template get_queue_ref<AppGroupImplT>();
  }

};

} // namespace test::mock_ctxt
