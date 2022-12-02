
module RunTestCases;

import SteelRT.Util.Sequence;
import SteelRT.Util.Types;
import SteelRT.Util.App;

import SteelRT.Task.Descriptor;
import SteelRT.Task.DescriptorPoisonPill;

import App.Graph;

import SteelRT.Work.Descriptor.Local;
import SteelRT.Task.MakeAsync;
import SteelRT.Dep.Guard.Backend;

import SteelRT.Test;

import <stdexcept>;


////////////////////////// COMMON STUFF

const depth_t depth = 0;
thread_id_t mainThreadId = 0;

namespace ctxt {

template <class QueueContainerT>
using active = test::mock_ctxt::with_queue<QueueContainerT>;

} // namespace ctxt


static
auto make_poison_pill() {
  using pp_desc_t = task::poison_pill::descriptor;
  return std::unique_ptr< pp_desc_t, std::function<void(task::poly_descriptor*)> >( new pp_desc_t(), [](task::poly_descriptor* ptr){delete ptr;} );
}

template <app::call AppCall, std::size_t Id>
static
auto init_tuple_arg() {
  return util::tuple::element_t<Id, typename app::traits<AppCall>::arg_tuple_type>();
}

template <class LocalContainerT, app::call AppCall, std::size_t... Ids>
static
void test_push_pop(LocalContainerT& contRef, std::index_sequence<Ids...>) {

  static constexpr app::impl AppImpl = app::traits<AppCall>::belonging_impl;
  static constexpr app::id AppId = app::traits< AppImpl >::belonging_id;

  if constexpr (AppId != app::id::poison_pill) {

  using GroupImplT = app::group_impl_of_t<AppImpl>;

  using AppGroupImplTuple = typename LocalContainerT::unique_group_impls;

  if (contRef.template has_enqueued_work< AppGroupImplTuple >()) { throw std::runtime_error("Container not expected to have work -- before push"); }


  contRef.template push_descriptor< GroupImplT >( mainThreadId, task::make_async<AppCall>( depth, init_tuple_arg<AppCall, Ids>() ... ) );

  if (not contRef.template has_enqueued_work< AppGroupImplTuple >()) { throw std::runtime_error("Container expected to have work"); }

  auto retUPtr = contRef.try_front_and_pop( mainThreadId );

  if (retUPtr->appId != static_cast<enum_uint_t>(AppId)) { throw std::runtime_error("popped appId not expected"); }

  if (contRef.template has_enqueued_work< AppGroupImplTuple >()) { throw std::runtime_error("Container not expected to have work -- after pop"); }
  }
}

template <typename QueueContainerT, app::call... AppCalls>
static
void test_push_pop_all(QueueContainerT& queueContainer, util::sequence::enum_t<app::call, AppCalls...>) {

  ( test_push_pop<QueueContainerT, AppCalls>(
      queueContainer, std::make_index_sequence<app::traits<AppCalls>::arg_tuple_type::size()>{}
    ), ...
  );
}


template <class LocalContainerT, app::call AppCall, std::size_t... Ids>
static
void test_push_pop_order_poison_pill(LocalContainerT& contRef, std::index_sequence<Ids...>) {

  static constexpr app::impl AppImpl = app::traits<AppCall>::belonging_impl;
  static constexpr app::id AppId = app::traits< AppImpl >::belonging_id;

  if constexpr (AppId != app::id::poison_pill) {

  using GroupImplT = app::group_impl_of_t<AppImpl>;

  using AppGroupImplTuple = util::tuple_t< GroupImplT >;

  // Push AppId first, pp second
  {
    // Push AppId
    contRef.template push_descriptor< GroupImplT >( mainThreadId, task::make_async<AppCall>( depth, init_tuple_arg<AppCall, Ids>() ... ) );

    // Push poison pill
    contRef.template push_descriptor<task::poison_pill::group_impl_t>( mainThreadId, make_poison_pill() );

    // AppId is popped first always
    auto retUPtr = contRef.try_front_and_pop( mainThreadId );
    if (retUPtr->appId != static_cast<enum_uint_t>(AppId)) { throw std::runtime_error("popped appId not expected"); }

    // pp popped second always
    auto ppUPtr = contRef.try_front_and_pop( mainThreadId );
    if (ppUPtr->appId != global::PoisonPillAppIndex) { throw std::logic_error("Expected poison pill task"); }
  }

  // Push pp first, AppId second
  {
    // Push poison pill
    contRef.template push_descriptor<task::poison_pill::group_impl_t>( mainThreadId, make_poison_pill() );

    // Push AppId
    contRef.template push_descriptor< GroupImplT >( mainThreadId, task::make_async<AppCall>( depth, init_tuple_arg<AppCall, Ids>() ... ) );

    // AppId is popped first
    auto retUPtr = contRef.try_front_and_pop( mainThreadId );
    if (retUPtr->appId != static_cast<enum_uint_t>(AppId)) { throw std::runtime_error("popped appId not expected"); }

    // pp popped second always
    auto ppUPtr = contRef.try_front_and_pop( mainThreadId );
    if (ppUPtr->appId != global::PoisonPillAppIndex) { throw std::logic_error("Expected poison pill task"); }
  }
  }
}

template <typename QueueContainerT, app::call... AppCalls>
static
void test_push_pop_order_poison_pill_all(QueueContainerT& queueContainer, util::sequence::enum_t<app::call, AppCalls...>) {

  ( test_push_pop_order_poison_pill<QueueContainerT, AppCalls>(
      queueContainer, std::make_index_sequence<app::traits<AppCalls>::arg_tuple_type::size()>{}
    ), ...
  );
}


template <class LocalContainerT, app::call AppCall, std::size_t... Ids>
static
void test_push_pop_order_depth_youth(LocalContainerT& contRef, std::index_sequence<Ids...>) {

  static constexpr app::impl AppImpl = app::traits<AppCall>::belonging_impl;
  static constexpr app::id AppId = app::traits< AppImpl >::belonging_id;

  if constexpr (AppId != app::id::poison_pill) {

  using GroupImplT = app::group_impl_of_t<AppImpl>;

  depth_t d = 0;

  {
    contRef.template push_descriptor< GroupImplT >( mainThreadId, task::make_async<AppCall>( depth, init_tuple_arg<AppCall, Ids>() ... ) );

    contRef.template push_descriptor< GroupImplT >( mainThreadId, task::make_async<AppCall>( depth, init_tuple_arg<AppCall, Ids>() ... ) );

    auto retFirstUPtr = contRef.try_front_and_pop( mainThreadId );
    auto retSecondUPtr = contRef.try_front_and_pop( mainThreadId );
    if (retFirstUPtr->youth > retSecondUPtr->youth) { throw std::logic_error("Expected older popped first"); }
  }

  depth_t depthZero = 0;
  depth_t depthOne = 1;

  {
    contRef.template push_descriptor< GroupImplT >( mainThreadId, task::make_async<AppCall>( depthZero, init_tuple_arg<AppCall, Ids>() ... ) );

    contRef.template push_descriptor< GroupImplT >( mainThreadId, task::make_async<AppCall>( depthOne, init_tuple_arg<AppCall, Ids>() ... ) );

    auto retFirstUPtr = contRef.try_front_and_pop( mainThreadId );
    auto retSecondUPtr = contRef.try_front_and_pop( mainThreadId );

    if (retFirstUPtr->depth < retSecondUPtr->depth) { throw std::logic_error("Expected deeper popped first"); }
  }

  }
}

template <typename QueueContainerT, app::call... AppCalls>
static
void test_push_pop_order_depth_youth_all(QueueContainerT& queueContainer, util::sequence::enum_t<app::call, AppCalls...>) {

  ( test_push_pop_order_depth_youth<QueueContainerT, AppCalls>(
      queueContainer, std::make_index_sequence<app::traits<AppCalls>::arg_tuple_type::size()>{}
    ), ...
  );
}


////////////////////////// TEST CASES

namespace test {

template <>
void runner::run_case<case_id::push_pop>() {

  using queue_container_t = util::sequence::to_variadic_t< app::enabled_impls, workload::desc::local_container>;

  queue_container_t queueContainer;

  test_push_pop_all<queue_container_t>(queueContainer, app::enabled_calls{});

}

template <>
void runner::verify_case<case_id::push_pop>() {
  // Nothing to verify 
}


template <>
void runner::run_case<case_id::push_pop_poison_pill>() {

  using queue_container_t = util::sequence::to_variadic_t< app::enabled_impls, workload::desc::full_local_container>;

  queue_container_t queueContainer;


  queueContainer.template push_descriptor<task::poison_pill::group_impl_t>( mainThreadId, make_poison_pill() );

  auto retUPtr = queueContainer.try_front_and_pop( mainThreadId );

  if (not retUPtr) {
    throw std::runtime_error("Expected poped poison pill");
  }

  auto ppUPtr = static_cast<task::poison_pill::descriptor*>( retUPtr.get() );
  if (ppUPtr->appId != global::PoisonPillAppIndex) { throw std::logic_error("Expected poison pill task"); }

}

template <>
void runner::verify_case<case_id::push_pop_poison_pill>() {
  // Nothing to verify 
}


template <>
void runner::run_case<case_id::push_pop_order_poison_pill>() {

  using queue_container_t = util::sequence::to_variadic_t< app::enabled_impls, workload::desc::full_local_container>;

  queue_container_t queueContainer;

  test_push_pop_order_poison_pill_all<queue_container_t>(queueContainer, app::enabled_calls{});

}

template <>
void runner::verify_case<case_id::push_pop_order_poison_pill>() {
  // Nothing to verify 
}



template <>
void runner::run_case<case_id::push_pop_order_depth_youth>() {

  using queue_container_t = util::sequence::to_variadic_t< app::enabled_impls, workload::desc::local_container>;

  queue_container_t queueContainer;

  test_push_pop_order_depth_youth_all<queue_container_t>(queueContainer, app::enabled_calls{});
}

template <>
void runner::verify_case<case_id::push_pop_order_depth_youth>() {
  // Nothing to verify 
}

} // namespace test


///////////////////////// COMMON STUFF 



template <class ProviderCtxtT, class StealerCtxtT, app::call AppCall, std::size_t... Ids>
static
void test_push_steal_pop(ProviderCtxtT& provRef, StealerCtxtT& stealerRef, std::index_sequence<Ids...>) {

  static constexpr app::impl AppImpl = app::traits<AppCall>::belonging_impl;
  static constexpr app::id AppId = app::traits< AppImpl >::belonging_id;

  if constexpr (AppId != app::id::poison_pill) {

  using GroupImplT = app::group_impl_of_t<AppImpl>;
  using AppGroupImplTuple = util::tuple_t< GroupImplT >;
  using NotThisAppGroupImplTuple = util::tuple::lift_enums_t< util::sequence::remove_t< app::enabled_impls, AppImpl>, app::group_impl_of_t >;

  if (stealerRef.template has_enqueued_work< NotThisAppGroupImplTuple >()) { throw std::runtime_error("Container not expected to have work -- before push"); }
  if (provRef.template has_enqueued_work< NotThisAppGroupImplTuple >()) { throw std::runtime_error("Container not expected to have work -- before push"); }

  if (provRef.template has_enqueued_work< AppGroupImplTuple >()) { throw std::runtime_error("Container not expected to have work -- before push"); }
  if (stealerRef.template has_enqueued_work< AppGroupImplTuple >()) { throw std::runtime_error("Container not expected to have work -- before push"); }

  depth_t d = 0;

  provRef.template push_descriptor<GroupImplT>( provRef.get_thread_id(), task::make_async<AppCall>( depth, init_tuple_arg<AppCall, Ids>() ... ) );

  bool notStealSuccess = provRef.template try_steal<NotThisAppGroupImplTuple>( stealerRef.get_thread_id() );
  if (notStealSuccess) { throw std::logic_error("Steal must not succeed"); }

  bool stealSuccess = provRef.template try_steal<AppGroupImplTuple>( stealerRef.get_thread_id() );

  if (not stealSuccess) { throw std::logic_error("Steal did not succeed"); }

  if (provRef.template has_enqueued_work< AppGroupImplTuple >()) { throw std::runtime_error("Container not expected to have work -- after steal"); }
  if (not stealerRef.template has_enqueued_work< AppGroupImplTuple >()) { throw std::runtime_error("Container expected to have work -- after steal"); }

  auto retUPtr = stealerRef.try_front_and_pop( mainThreadId );

  if (not retUPtr) { throw std::logic_error("Front and pop did not succeed"); }
  if (retUPtr->appId != static_cast<enum_uint_t>(AppId)) { throw std::runtime_error("stolen appId not expected"); }

  if (stealerRef.template has_enqueued_work< AppGroupImplTuple >()) { throw std::runtime_error("Container not expected to have work -- after steal"); }

  }
}

template <class ProviderCtxtT, class StealerCtxtT, app::call... AppCalls>
static
void test_push_steal_pop_all(ProviderCtxtT& provRef, StealerCtxtT& stealerRef, util::sequence::enum_t<app::call, AppCalls...>) {

  ( test_push_steal_pop<ProviderCtxtT, StealerCtxtT, AppCalls>(
      provRef, stealerRef, std::make_index_sequence<app::traits<AppCalls>::arg_tuple_type::size()>{}
    ), ...
  );
}


template <class ProviderCtxtT, class StealerCtxtT, app::call AppCall, std::size_t... Ids>
static
void test_push_steal_pop_order_poison_pill(ProviderCtxtT& provRef, StealerCtxtT& stealerRef, std::index_sequence<Ids...>) {

  static constexpr app::impl AppImpl = app::traits<AppCall>::belonging_impl;
  static constexpr app::id AppId = app::traits< AppImpl >::belonging_id;

  if constexpr (AppId != app::id::poison_pill) {

  using GroupImplT = app::group_impl_of_t<AppImpl>;

  using AppGroupImplTuple = typename StealerCtxtT::allow_group_impls;
  depth_t d = 0;

  // Push AppId first, pp second
  {
    provRef.template push_descriptor<GroupImplT>( provRef.get_thread_id(), task::make_async<AppCall>( depth, init_tuple_arg<AppCall, Ids>() ... ) );

    provRef.template push_descriptor<task::poison_pill::group_impl_t>( mainThreadId, make_poison_pill() );

    // First steal
    provRef.template try_steal<AppGroupImplTuple>( stealerRef.get_thread_id() );

      // AppId is popped first always
    auto retUPtr = stealerRef.try_front_and_pop( mainThreadId );
    if (retUPtr->appId != static_cast<enum_uint_t>(AppId)) { throw std::runtime_error("popped appId not expected"); }

    // Second steal
    provRef.template try_steal<AppGroupImplTuple>( stealerRef.get_thread_id() );

    // pp popped second always
    auto ppUPtr = stealerRef.try_front_and_pop( mainThreadId );
    if (ppUPtr->appId != global::PoisonPillAppIndex) { throw std::logic_error("Expected poison pill task"); }
  }

  // Push pp first, AppId second
  {
    provRef.template push_descriptor<task::poison_pill::group_impl_t>( mainThreadId, make_poison_pill() );

    provRef.template push_descriptor<GroupImplT>( provRef.get_thread_id(), task::make_async<AppCall>( depth, init_tuple_arg<AppCall, Ids>() ... ) );

    // First steal
    provRef.template try_steal<AppGroupImplTuple>( stealerRef.get_thread_id() );

      // AppId is popped first always
    auto retUPtr = stealerRef.try_front_and_pop( mainThreadId );
    if (retUPtr->appId != static_cast<enum_uint_t>(AppId)) { throw std::runtime_error("popped appId not expected"); }

    // Second steal
    provRef.template try_steal<AppGroupImplTuple>( stealerRef.get_thread_id() );

    // pp popped second always
    auto ppUPtr = stealerRef.try_front_and_pop( mainThreadId );
    if (ppUPtr->appId != global::PoisonPillAppIndex) { throw std::logic_error("Expected poison pill task"); }
  }

  }
}

template <class ProviderCtxtT, class StealerCtxtT, app::call... AppCalls>
static
void test_push_steal_pop_order_poison_pill_all(ProviderCtxtT& provRef, StealerCtxtT& stealerRef, util::sequence::enum_t<app::call, AppCalls...>) {

  ( test_push_steal_pop_order_poison_pill<ProviderCtxtT, StealerCtxtT, AppCalls>(
      provRef, stealerRef, std::make_index_sequence<app::traits<AppCalls>::arg_tuple_type::size()>{}
    ), ...
  );
}





namespace test {

template <>
void runner::run_case<case_id::push_steal_pop>() {

  using queue_container_t = util::sequence::to_variadic_t< app::enabled_impls, workload::desc::local_container>;

  using ctxt_t = ctxt::active<queue_container_t>;

  thread_id_t threadProvider = 1;
  thread_id_t threadStealer = 2;

  ctxt_t ctxtProvider(threadProvider);
  ctxt_t ctxtStealer(threadStealer);

  ctxtProvider.register_this_thread_as_stealer( ctxtStealer );

  test_push_steal_pop_all<ctxt_t, ctxt_t>( ctxtProvider, ctxtStealer, app::enabled_calls{} );

}

template <>
void runner::verify_case<case_id::push_steal_pop>() {
  // Nothing to verify 
}

template <>
void runner::run_case<case_id::push_steal_pop_order_poison_pill>() {

  using queue_container_t = util::sequence::to_variadic_t< app::enabled_impls, workload::desc::full_local_container>;

  using ctxt_t = ctxt::active<queue_container_t>;

  thread_id_t threadProvider = 1;
  thread_id_t threadStealer = 2;

  ctxt_t ctxtProvider(threadProvider);
  ctxt_t ctxtStealer(threadStealer);

  ctxtProvider.register_this_thread_as_stealer( ctxtStealer );

  test_push_steal_pop_order_poison_pill_all<ctxt_t, ctxt_t>( ctxtProvider, ctxtStealer, app::enabled_calls{} );

}

template <>
void runner::verify_case<case_id::push_steal_pop_order_poison_pill>() {
  // Nothing to verify 
}


} // namespace test
