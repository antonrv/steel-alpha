
export module SteelRT.Task.Dispatcher.Promise.Base;

import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.Sequence;
import SteelRT.Util.Tuple;
// import SteelRT.Util.FwDeclarations.Work;
import SteelRT.Util.App;
import SteelRT.Util.Work;
import SteelRT.Util.Require;

import SteelRT.Task.DescriptorState;

import <experimental/coroutine>;


namespace task::coro {


export
using suspend = std::experimental::suspend_always;


export
enum class last_await : enum_uint_t { none, called, guard_destroy, guard_sync };


// template <typename AppGroupImplTupleT>
// using tuple_push_fn_t = util::tuple::lift_t< workload::wtraits< workload::kind::desc >::template push_fn_type, app_group_impl_tuple_t >;



export
template <app::impl AppImpl>
class dispatcher_promise_base {

public:

  using this_call_sequence = typename app::traits<AppImpl>::dispatch_sequence;
  using this_impl_sequence = util::sequence::unique_t< util::sequence::transform_t<this_call_sequence, app::impl, app::impl_of> >;


  using app_group_impl_tuple_t = util::tuple::lift_enums_t< this_impl_sequence, app::group_impl_of_t >;

  static constexpr std::size_t GroupImplCount = app_group_impl_tuple_t::size();

  using core_tuple_push_fn_t = util::tuple::unique_t< util::tuple::lift_enums_t< this_impl_sequence, workload::wtraits< workload::kind::desc >::template push_fn_type > >;

  using own_poly_desc_t = workload::wtraits< workload::kind::desc >::own_poly_type;


  using push_desc_fn_t = workload::wtraits< workload::kind::desc >::push_fn_type<AppImpl>;

  using push_poly_desc_fn_t = workload::wtraits< workload::kind::desc >::push_poly_fn_t;


protected:

  using handle_type = std::experimental::coroutine_handle< dispatcher_promise_base >;

// General parameters
  attr::descriptor& m_descriptorAttributesRef;

  greed_t m_pushGreed = 0u;
  greed_t m_pushedCount = 0u;

// Push-behavior parameters

  util::tuple::as_std_t< core_tuple_push_fn_t > m_currentTuplePushFn;

  push_desc_fn_t m_globalPush = nullptr;

// Extract-behavior parameters

  own_poly_desc_t m_ownDescExtract = nullptr;
 
  std::array<bool, GroupImplCount> m_enabledExtractions;

  last_await m_lastAwait = last_await::none;

public:

  last_await get_last_await() const noexcept {
    return m_lastAwait;
  }

  dispatcher_promise_base( attr::descriptor& originalAttrs ) : m_descriptorAttributesRef(originalAttrs) { }


private:

  template <
    typename ResumerTuplePushFnT,
    std::size_t Id,
    util::req_t<
      util::tuple::contains<
        util::tuple::element_t<Id, core_tuple_push_fn_t>,
        util::tuple::as_types_t< ResumerTuplePushFnT >
      >
    > ...
  >
  void set_push_function( const ResumerTuplePushFnT& resumerPushFns ) {
    // Set this function to push AppGroupImpl stored tasks in the local queue of the thread
    std::get<Id>( m_currentTuplePushFn ) = std::get< util::tuple::element_t<Id, core_tuple_push_fn_t> >( resumerPushFns );
  }

  template <
    typename ResumerTuplePushFnT,
    std::size_t Id,
    util::req_t<
      std::negation<
        util::tuple::contains<
          util::tuple::element_t<Id, core_tuple_push_fn_t>,
          util::tuple::as_types_t< ResumerTuplePushFnT >
        >
      >
    > ...
  >
  void set_push_function( const ResumerTuplePushFnT& resumerPushFns ) {
    // The thread cannot push into its local queue AppGroupImpl stored in Id of core_tuple_push_fn_t
    std::get<Id>(m_currentTuplePushFn) = nullptr;
  }

  template <typename ResumerTuplePushFnT, std::size_t... Ids>
  void set_all_push_functions( const ResumerTuplePushFnT& resumerPushFns, std::index_sequence<Ids...> ) {
    ( set_push_function<Ids>( resumerPushFns ), ... );
  }


public:


  template <typename ResumerTuplePushFnT>
  void set_push_config(greed_t pushGreed, const ResumerTuplePushFnT& resumerPushFns) noexcept {

    m_pushGreed = pushGreed;
    m_pushedCount = 0u;
    
    set_all_push_functions( resumerPushFns, std::make_index_sequence<GroupImplCount>{} );
  }

private:

////// Set config for enabled extractions
  template <
    typename ResumerAppGroupImplTupleT,
    std::size_t Id,
    util::req_t<
      util::tuple::contains<
        util::tuple::element_t<Id, app_group_impl_tuple_t>,
        ResumerAppGroupImplTupleT
      >
    > ...
  >
  void set_enabled_extraction( ) noexcept {
    // Resumer tuple DOES contain AppGroupImpl in position Id
    std::get<Id>( m_enabledExtractions ) = true;
  }

  template <
    typename ResumerAppGroupImplTupleT,
    std::size_t Id,
    util::req_t<
      std::negation<
        util::tuple::contains<
          util::tuple::element_t<Id, app_group_impl_tuple_t>,
          ResumerAppGroupImplTupleT
        >
      >
    > ...
  >
  void set_enabled_extraction( ) noexcept {
    // Resumer tuple does NOT contain AppGroupImpl in position Id
    std::get<Id>( m_enabledExtractions ) = false;
  }

  template <typename ResumerAppGroupImplTupleT, std::size_t... Ids>
  void set_all_enabled_extractions( std::index_sequence<Ids...> ) {
    ( set_enabled_extraction<ResumerAppGroupImplTupleT, Ids>(), ... );
  }


public:

  // Called from dispatcher object
  const attr::descriptor& get_attr_descriptor_ref() const noexcept {
    return m_descriptorAttributesRef;
  }

  void set_push_global( push_poly_desc_fn_t& pushGlobal ) noexcept {
    m_globalPush = pushGlobal;
  }

  const push_poly_desc_fn_t& get_push_global() const noexcept {
    return m_globalPush;
  }



  template <app::impl DescAppImpl>
  const auto& get_push_local() const noexcept {

    using this_push_fn_t = workload::wtraits<workload::kind::desc>::push_fn_type<DescAppImpl>;

    return std::get< this_push_fn_t >( m_currentTuplePushFn ); // may be nullptr
  }

  bool push_greed_unsatisfied() const noexcept {
    return global::greed_unsatisfied( m_pushedCount, m_pushGreed );
  }


  template <typename ResumerAppGroupImplTupleT>
  void set_extract_config( ) noexcept {

    m_pushGreed = 0; // Special value to create a extract_awaiter instead of a push_awaiter

    set_all_enabled_extractions<ResumerAppGroupImplTupleT>( std::make_index_sequence<GroupImplCount>{} );
  }

  template <typename AppGroupImplT>
  bool get_enabled_extract() const noexcept {
    return std::get< util::tuple::index_v<AppGroupImplT, app_group_impl_tuple_t> >( m_enabledExtractions );
  }

  void set_extract_descriptor( own_poly_desc_t&& ownPolyDesc ) noexcept {
    m_ownDescExtract = ownPolyDesc;
  }

  own_poly_desc_t extract_descriptor() noexcept {
    auto ret = std::move( m_ownDescExtract );
    m_ownDescExtract = nullptr;
    return ret;
  }

};

} // namespace task::coro
