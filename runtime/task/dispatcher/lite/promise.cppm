
export module SteelRT.Task.Dispatcher.Promise;

// import SteelRT.Util.FwDeclarations.Work;
import SteelRT.Util.Require;
import SteelRT.Util.App;
import SteelRT.Util.Work;

import SteelRT.Dep.Guard.Frontend;

export import SteelRT.Task.Dispatcher.Promise.Base;



export import SteelRT.Task.Dispatcher.Awaiter;
export import SteelRT.Task.Dispatcher.Awaiter.Guard;

export import SteelRT.Task.Descriptor;

import <experimental/coroutine>;


namespace task::coro {

template <typename T>
struct is_awaitable_descriptor : std::false_type { };

template <app::call AppCall, typename ArgTupleT>
struct is_awaitable_descriptor< std::unique_ptr< task::descriptor<AppCall, ArgTupleT>, workload::wtraits<workload::kind::desc>::deleter_type> > : std::true_type { };


export
template <app::impl AppImpl>
class dispatcher_promise_lite : public dispatcher_promise_base_lite<AppImpl> {
private:

  using super_type = dispatcher_promise_base_lite<AppImpl>;

public:

  using handle_type = std::experimental::coroutine_handle< dispatcher_promise_lite >;

public:

  template <typename... Ts>
  dispatcher_promise_lite( attr::descriptor& originalAttrs, Ts... ) :
    super_type(originalAttrs)
  {
    // instr::trace<instr::event::coro_promise::constructor>();
  }

  template <
    typename OwnDescT,
    util::req_t< is_awaitable_descriptor<OwnDescT> >...
  >
  auto await_transform(OwnDescT&& ownDesc) noexcept { // This can be const TODO

    using desc_type = typename OwnDescT::element_type;
    using group_impl_type = typename desc_type::group_impl_type;

    super_type::m_lastAwait = last_await::called;

    return awaiter_lite< OwnDescT, AppImpl >( std::forward<OwnDescT>(ownDesc), *this );
  }

  template <
    typename GuardFndT,
    util::req_t< dep::guard::fnd::is<GuardFndT> >...
  >
  guard_awaiter<GuardFndT> await_transform(GuardFndT& guardFndRef) noexcept {
    super_type::m_lastAwait = last_await::guard_destroy;
    return guard_awaiter<GuardFndT>(guardFndRef);
  }

  // Always suspend on suspend_always
  suspend await_transform(suspend&& s) noexcept {
    super_type::m_lastAwait = last_await::guard_destroy;
    return s;
  }


  // Called at the begining of the coroutine instance (a dispatcher instance)
  auto get_return_object() {
    // From promise returns a coroutine handle
    // which implicitly builds a dispatcher
    // instr::trace<instr::event::coro_promise::building_resumable>();
    return handle_type::from_promise(*this);
  }

  auto initial_suspend() { return std::experimental::suspend_always(); } // We could also suspend_never
  auto final_suspend() { return std::experimental::suspend_always(); } // Need to suspend always so that the 'done' method of the handle works fine

  // Need to be defined, because our coroutine is finite (runs until its end), but does not return anything at the end via co_return
  void return_void() noexcept {}

  void unhandled_exception() {
    // instr::trace<instr::event::coro_promise::captured_error>();
    auto exceptionPtr = std::current_exception();
    if (exceptionPtr) {
      std::rethrow_exception(exceptionPtr);
    }
  }
};



} // namespace task::coro
