
module RunTestCases;

import App.Proxy;

import SteelRT.Dep;

import SteelRT.Task.Descriptor;
import SteelRT.Task.Dispatcher;

import SteelRT.Work.Descriptor.Global;
import SteelRT.Work.Descriptor.Local;

import SteelRT.Test;

import <list>;

#include <assert.h>


const depth_t d = 0;

namespace ctxt {

template <typename ImplSelectorT, template <app::impl...> class DescContainerT, app::impl... Impls>
using active = test::mock_ctxt::with_selector_queue<ImplSelectorT, DescContainerT, Impls...>;

} // namespace ctxt


namespace test {


template <>
void runner::run_case<case_id::kernel2kernel_run>() {

  // Create solver
  using selector_t = policy::selector::implementation<policy::pick_implement::next_kernel>;
  selector_t nextKernelSel;

  ctxt::active< selector_t, workload::desc::global_container, app::impl::foo_k1, app::impl::foo_k2 > s(nextKernelSel);

  int b = 4;

  auto foo_k1_c1 = task::make_async<app::call::foo_d1_foo_0>( d, b );

  auto foo_k1_c2 = task::make_async<app::call::main_entry_foo_0>( d, b );

  // Expect run as impl::foo_k1
  s.operate( std::move(foo_k1_c1) );

  // Expect run as impl::foo_k2 despite second call related to foo_k1
  s.operate( std::move(foo_k1_c2) );
}

template <>
void runner::verify_case<case_id::kernel2kernel_run>() {
  using namespace test;
  using namespace instr;
  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, 2>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, 1>("impl::foo_k1"),
    expect<event::dep_execute::kernel_start, amount::equal, 1>("impl::foo_k2"),
    expect<event::dep_execute::kernel_end, amount::equal, 1>("impl::foo_k1"),
    expect<event::dep_execute::kernel_end, amount::equal, 1>("impl::foo_k2"),
    expect<event::dep_release::publish_start, amount::equal, 2>(),
    expect<event::dep_release::publish_end, amount::equal, 2>(),
    expect<event::dep_release::publish_error_start, amount::equal, 0>(),
    expect<event::dep_release::publish_error_end, amount::equal, 0>()
  );
}

//////////////////////////////////////////////////////

template <>
void runner::run_case<case_id::dispatcher2kernel_run>() {

  // Create solver
  using selector_t = policy::selector::implementation<policy::pick_implement::next_kernel>;
  selector_t nextKernelSel;

  ctxt::active< selector_t, workload::desc::global_container, app::impl::foo_k1, app::impl::foo_d1 > s(nextKernelSel);

  int b = 4;

  auto foo_d1_c = task::make_async<app::call::main_entry_foo_1>( d, b );

  // Expect run as kernel
  s.operate( std::move(foo_d1_c) );

}

template <>
void runner::verify_case<case_id::dispatcher2kernel_run>() {
  using namespace test;
  using namespace instr;
  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, 1>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, 1>("impl::foo_k1"),
    expect<event::dep_execute::kernel_end, amount::equal, 1>("impl::foo_k1"),
    expect<event::dep_dispatch::create_start, amount::equal, 0>(),
    expect<event::dep_dispatch::create_end, amount::equal, 0>(),
    expect<event::coro_dispatcher::constructor, amount::equal, 0>(),
    expect<event::coro_dispatcher::destroying_handle, amount::equal, 0>(),
    expect<event::dep_release::publish_start, amount::equal, 1>(),
    expect<event::dep_release::publish_end, amount::equal, 1>(),
    expect<event::dep_release::publish_error_start, amount::equal, 0>(),
    expect<event::dep_release::publish_error_end, amount::equal, 0>()
  );
}

//////////////////////////////////////////////////////


template <>
void runner::run_case<case_id::kernel2dispatcher_create>() {

  // Create solver
  using selector_t = policy::selector::implementation<policy::pick_implement::next_dispatcher>;
  selector_t nextDispatcherSel;

  ctxt::active< selector_t, workload::desc::global_container, app::impl::foo_k1, app::impl::foo_d1 > s(nextDispatcherSel);

  int b = 4;

  auto foo_k1_c1 = task::make_async<app::call::foo_d1_foo_0>( d, b );

  // Expect creation of dispatcher impl::foo_d1
  s.operate( std::move(foo_k1_c1) );

}

template <>
void runner::verify_case<case_id::kernel2dispatcher_create>() {
  using namespace test;
  using namespace instr;
  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, 1>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, 0>(),
    expect<event::dep_execute::kernel_end, amount::equal, 0>(),
    expect<event::dep_dispatch::create_start, amount::equal, 1>("impl::foo_d1"),
    expect<event::dep_dispatch::create_end, amount::equal, 1>("impl::foo_d1"),
    expect<event::coro_dispatcher::constructor, amount::equal, 1>(),
    expect<event::coro_dispatcher::destroying_handle, amount::equal, 1>(),
    expect<event::dep_release::publish_start, amount::equal, 0>(),
    expect<event::dep_release::publish_end, amount::equal, 0>(),
    expect<event::dep_release::publish_error_start, amount::equal, 1>(),
    expect<event::dep_release::publish_error_end, amount::equal, 1>()
  );
}

//////////////////////////////////////////////////////

template <>
void runner::run_case<case_id::dispatcher2dispatcher_create>() {

  // Create solver
  using selector_t = policy::selector::implementation<policy::pick_implement::next_dispatcher>;
  selector_t nextDispatcherSel;

  ctxt::active< selector_t, workload::desc::global_container, app::impl::foo_k1, app::impl::foo_k2, app::impl::foo_d1, app::impl::foo_d2 > s(nextDispatcherSel);

  int b = 4;

  // Create call to dispatcher1
  auto first_foo_d1_c = task::make_async<app::call::main_entry_foo_1>( d, b );

  // Create another call to dispatcher1
  auto second_foo_d1_c = task::make_async<app::call::main_entry_foo_1>( d, b );

  // Expect creation of dispatcher impl::foo_d1
  s.operate( std::move(first_foo_d1_c) );

  // Expect creation of dispatcher impl::foo_d2, despite d1 task was created
  s.operate( std::move(second_foo_d1_c) );

}

template <>
void runner::verify_case<case_id::dispatcher2dispatcher_create>() {
  using namespace test;
  using namespace instr;
  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, 2>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, 0>(),
    expect<event::dep_execute::kernel_end, amount::equal, 0>(),
    expect<event::dep_dispatch::create_start, amount::equal, 1>("impl::foo_d1"),
    expect<event::dep_dispatch::create_end, amount::equal, 1>("impl::foo_d1"),
    expect<event::dep_dispatch::create_start, amount::equal, 1>("impl::foo_d2"),
    expect<event::dep_dispatch::create_end, amount::equal, 1>("impl::foo_d2"),
    expect<event::coro_dispatcher::constructor, amount::equal, 2>(),
    expect<event::coro_dispatcher::destroying_handle, amount::equal, 2>(),
    expect<event::dep_release::publish_start, amount::equal, 0>(),
    expect<event::dep_release::publish_end, amount::equal, 0>(),
    expect<event::dep_release::publish_error_start, amount::equal, 2>(),
    expect<event::dep_release::publish_error_end, amount::equal, 2>()
  );
}

//////////////////////////////////////////////////////

template <>
void runner::run_case<case_id::kernel2dispatcher_create_deplete>() {

  // Create solver
  using selector_t = policy::selector::implementation<policy::pick_implement::next_dispatcher>;
  selector_t nextDispatcherSel;

  ctxt::active< selector_t, workload::desc::global_container, app::impl::foo_k1, app::impl::foo_d1 > s(nextDispatcherSel);

  int b = 4;

  auto foo_k1_c1 = task::make_async<app::call::foo_d1_foo_0>( d, b );

  // Expect creation of dispatcher impl::foo_d
  s.operate( std::move(foo_k1_c1) );

  auto dispShPtr = s.template try_pop_dispatcher<app::impl::foo_d1>();

  // Resume and push task to local queue
  auto firstResumeTrial = dispShPtr->template try_resume< util::tuple_t< app::group_impl_of_t<app::impl::foo_k1> > >(global::MainThreadId);
  if (firstResumeTrial != task::state::dispatcher_status_trial::acquired_task) { throw std::runtime_error("Expected acquired alive (1st)"); }

  // Resume and terminate handle
  auto secondResumeTrial = dispShPtr->template try_resume< util::tuple_t< app::group_impl_of_t<app::impl::foo_k1> > >(global::MainThreadId);
  if (secondResumeTrial != task::state::dispatcher_status_trial::acquired_finished) { throw std::runtime_error("Expected acquired alive (2nd)"); }

  // try to resume and fail
  auto thirdResumeTrial = dispShPtr->template try_resume< util::tuple_t< app::group_impl_of_t<app::impl::foo_k1> > >(global::MainThreadId);
  if (thirdResumeTrial != task::state::dispatcher_status_trial::skipped_depleted) { throw std::runtime_error("Expected skipped_depleted (3rd)"); }

  // The kernel within the dispatcher will not run, but it operates on a read-only copy, so its execution will not make the dispatcher fail to publish
}

template <>
void runner::verify_case<case_id::kernel2dispatcher_create_deplete>() {
  using namespace test;
  using namespace instr;
  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, 1>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, 0>(),
    expect<event::dep_execute::kernel_end, amount::equal, 0>(),
    expect<event::dep_dispatch::create_start, amount::equal, 1>("impl::foo_d1"),
    expect<event::dep_dispatch::create_end, amount::equal, 1>("impl::foo_d1"),
    expect<event::coro_dispatcher::constructor, amount::equal, 1>(),
    expect<event::coro_dispatcher::destroying_handle, amount::equal, 1>(),
    expect<event::dep_release::publish_start, amount::equal, 1>(), // Dispatcher ended right (its kernel is read-only copy)
    expect<event::dep_release::publish_end, amount::equal, 1>(), // Dispatcher ended right (its kernel is read-only copy)
    expect<event::dep_release::publish_error_start, amount::equal, 1>(), // Kernel didnt run
    expect<event::dep_release::publish_error_end, amount::equal, 1>() // Kernel didnt run
  );
}

//////////////////////////////////////////////////////

template <>
void runner::run_case<case_id::kernel2dispatcher_create_deplete_run>() {

  // Create solver
  using selector_t = policy::selector::implementation<policy::pick_implement::next_dispatcher>;
  selector_t nextDispatcherSel;

  ctxt::active< selector_t, workload::desc::local_container, app::impl::foo_k1, app::impl::foo_d1 > thisCtxt(nextDispatcherSel);

  int b = 4;

  auto foo_k1_c1 = task::make_async<app::call::foo_d1_foo_0>( d, b );

  // Expect creation of dispatcher impl::foo_d
  thisCtxt.operate( std::move(foo_k1_c1) );

  auto dispShPtr = thisCtxt.try_pop_dispatcher<app::impl::foo_d1>();

  // Resume and push task to local queue
  auto firstResumeTrial = dispShPtr.get()->template try_resume< util::tuple_t< app::group_impl_of_t<app::impl::foo_k1> > >(global::MainThreadId);
  if (firstResumeTrial != task::state::dispatcher_status_trial::acquired_task) { throw std::runtime_error("Expected acquired task (1st)"); }

  // Resume and terminate handle
  auto secondResumeTrial = dispShPtr.get()->template try_resume< util::tuple_t< app::group_impl_of_t<app::impl::foo_k1> > >(global::MainThreadId);
  if (secondResumeTrial != task::state::dispatcher_status_trial::acquired_finished) { throw std::runtime_error("Expected acquired finished (2nd)"); }

  // try to resume and fail
  auto thirdResumeTrial = dispShPtr.get()->template try_resume< util::tuple_t< app::group_impl_of_t<app::impl::foo_k1> > >(global::MainThreadId);
  if (thirdResumeTrial != task::state::dispatcher_status_trial::skipped_depleted) { throw std::runtime_error("Expected skipped_depleted (3rd)"); }

  {
    auto popedTask = thisCtxt.try_front_and_pop( global::MainThreadId );

    static_assert( std::is_same_v< decltype(popedTask), workload::desc::own_poly_t> );

    using tuple_t = util::tuple::as_std_t< typename app::traits<app::call::foo_d1_foo_0>::arg_tuple_type >;
    using group_t = app::group_impl_of_t<app::impl::foo_k1>;

    if (not popedTask) { throw std::runtime_error("Expected to have poped task"); }

    // if (not dynamic_cast< task::group_descriptor< group_t >* >( popedTask.get() ) ) {
    //   throw std::runtime_error("Unexpected task::group_descriptor");
    // }
    auto groupDescPtr = static_cast< task::descriptor< app::call::foo_d1_foo_0, tuple_t >* >( popedTask.get() );

    // We create another context to run this task as a kernel (to not run it again as a dispatcher)
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;

    ctxt::active< selector_t, workload::desc::local_container, app::impl::foo_k1> kernelCtxt(singleSel);

    // Run task created in the dispatcher
    // kernelCtxt.operate<app::call::foo_d1_foo_0, tuple_t>( std::move(popedTask) );
    kernelCtxt.operate( std::move(popedTask) );
  }
}

template <>
void runner::verify_case<case_id::kernel2dispatcher_create_deplete_run>() {
  using namespace test;
  using namespace instr;
  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, 2>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, 1>("impl::foo_k1"),
    expect<event::dep_execute::kernel_end, amount::equal, 1>("impl::foo_k1"),
    expect<event::dep_dispatch::create_start, amount::equal, 1>("impl::foo_d1"),
    expect<event::dep_dispatch::create_end, amount::equal, 1>("impl::foo_d1"),
    expect<event::coro_dispatcher::constructor, amount::equal, 1>(),
    expect<event::coro_dispatcher::destroying_handle, amount::equal, 1>(),
    expect<event::dep_release::publish_start, amount::equal, 2>(), 
    expect<event::dep_release::publish_end, amount::equal, 2>(),
    expect<event::dep_release::publish_error_start, amount::equal, 0>(),
    expect<event::dep_release::publish_error_end, amount::equal, 0>()
  );
}

//////////////////////////////////////////////////////

template <>
void runner::run_case<case_id::recursive_dispatcher_bound_app>() {
  // An app is bounded if it does not have dispatchers or have dispatchers that do not dispatch dispatchable-only tasks (in this case, bar)

  const int b = 4;
  const int expected = b;

  auto wb = dep::wrap(b);
  {

  auto coreTask = task::make_async<app::call::bar_d_bar_0>( d, wb.emit_bnd_reader() );

  // We create a context that picks always the next_dispatcher (creates dispatchers until DepthLimit is reached)
  using selector_t = policy::selector::implementation<policy::pick_implement::next_dispatcher>;
  selector_t nextDispSel;

  ctxt::active< selector_t, workload::desc::local_container, app::impl::bar_k, app::impl::bar_d> thisCtxt(nextDispSel);

  // Expect creation of bar dispatcher with depth 0
  thisCtxt.operate( std::move(coreTask) );

  std::list< workload::disp::shown_t< app::impl::bar_d > > dispList;

  auto newDispShPtr = thisCtxt.template try_pop_dispatcher<app::impl::bar_d>();

  const unsigned safeBreak = global::DepthLimit + 1;
  unsigned safeCount = 0u;

  // // This loop is automatically bounded if app is bounded, because when max depth is reached, a kernel will be run, instead of the creation of a dispatcher
  while (newDispShPtr and safeCount < safeBreak) {

    dispList.push_back( std::move(newDispShPtr) );

    // Resume, expect push task to local queue acquired_task
    auto firstResumeTrial = dispList.back().get()->template try_resume< util::tuple_t< app::group_impl_of_t<app::impl::bar_k> > >(global::MainThreadId);
    if (firstResumeTrial != task::state::dispatcher_status_trial::acquired_task) { throw std::runtime_error("Expected acquired task"); }

    // Expect creation of bar dispatcher task with depth 1
    auto childTask = thisCtxt.try_front_and_pop( global::MainThreadId );

    if (not childTask.get()) { throw std::runtime_error("Expected poped task"); }

    // When max depth is reached, it will run as kernel
    thisCtxt.operate( std::move(childTask) );

    // If the kernel was run in previous operate, this newDispShPtr will be nullptr and we will break out of the loop
    newDispShPtr = thisCtxt.template try_pop_dispatcher<app::impl::bar_d>();

    safeCount++;
  }

  if (safeCount >= safeBreak) { throw std::runtime_error("Exceeded dispatcher depth limit"); }

  // Traversed in direct order (shallow-first, deep-last), omitting the last, dispatchers are not finished
  auto lastDispShPtr = dispList.back();
  dispList.pop_back();
  auto dispListWithoutLast = std::move(dispList);


  for (auto& dispShPtr : dispList) {
    auto retTrial = dispShPtr.get()->template try_resume< util::tuple_t< app::group_impl_of_t<app::impl::bar_k> > >(global::MainThreadId);
    if (retTrial != task::state::dispatcher_status_trial::acquired_guard_destroy) { throw std::runtime_error("Expected acquired guard destroy"); }
  }

  // Traversed in reverse order (deep-first, shallow-last), dispatchers can be finished

  dispList = std::move(dispListWithoutLast);
  dispList.push_back( std::move(lastDispShPtr) );
  dispList.reverse();

  for (auto& dispShPtr : dispList) {

    // Try to resume again. Expect acquired_finished
    auto retTrial = dispShPtr.get()->template try_resume< util::tuple_t< app::group_impl_of_t<app::impl::bar_k> > >(global::MainThreadId);
    if (retTrial != task::state::dispatcher_status_trial::acquired_finished) { throw std::runtime_error("Expected acquired finished"); }

    // Try to resume again. Expect depleted. skipped_depleted
    retTrial = dispShPtr.get()->template try_resume< util::tuple_t< app::group_impl_of_t<app::impl::bar_k> > >(global::MainThreadId);
    if (retTrial != task::state::dispatcher_status_trial::skipped_depleted) { throw std::runtime_error("Expected skipped depleted"); }

    dispShPtr.reset();

  }

  dispList.clear();

  }

  if (not wb.is_destroyable()) {
    throw std::runtime_error("Guard not destroyable");
  }

  if (expected != b) {
    throw std::runtime_error("Result not expected");
  }

}

template <>
void runner::verify_case<case_id::recursive_dispatcher_bound_app>() {
  using namespace test;
  using namespace instr;
  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, global::DepthLimit>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, 1>("impl::bar_k"),
    expect<event::dep_execute::kernel_end, amount::equal, 1>("impl::bar_k"),
    expect<event::dep_dispatch::create_start, amount::equal, global::DepthLimit - 1>("impl::bar_d"),
    expect<event::dep_dispatch::create_end, amount::equal, global::DepthLimit - 1>("impl::bar_d"),
    expect<event::coro_dispatcher::constructor, amount::equal, global::DepthLimit - 1>(),
    expect<event::coro_dispatcher::destroying_handle, amount::equal, global::DepthLimit - 1>(),
    expect<event::dep_release::publish_start, amount::equal, global::DepthLimit>(), 
    expect<event::dep_release::publish_end, amount::equal, global::DepthLimit>(),
    expect<event::dep_release::publish_error_start, amount::equal, 0>(),
    expect<event::dep_release::publish_error_end, amount::equal, 0>()
  );
}

//////////////////////////////////////////////////////

template <>
void runner::run_case<case_id::recursive_dispatcher_unbound_app>() {

  const int b = 4;

  auto wb = dep::wrap(b);
  {

  auto coreTask = task::make_async<app::call::unb_d_unb_0>( d, wb.emit_bnd_reader() );

  // We create a context that picks always the next_dispatcher (creates dispatchers until DepthLimit is reached)
  using selector_t = policy::selector::implementation<policy::pick_implement::next_dispatcher>;
  selector_t nextDispSel;

  ctxt::active< selector_t, workload::desc::local_container, app::impl::unb_d> thisCtxt(nextDispSel);

  // Expect creation of unb dispatcher with depth 0
  thisCtxt.operate( std::move(coreTask) );

  std::list< workload::disp::shown_t< app::impl::unb_d > > dispList;

  auto newDispShPtr = thisCtxt.template try_pop_dispatcher<app::impl::unb_d>();

  const unsigned safeBreak = global::DepthLimit + 1;
  unsigned safeCount = 0u;

  while (newDispShPtr and safeCount < safeBreak and not thisCtxt.got_error()) {

    dispList.push_back( std::move(newDispShPtr) );

    // Resume, expect push task to local queue acquired_task
    auto firstResumeTrial = dispList.back().get()->template try_resume< util::tuple_t< app::group_impl_of_t<app::impl::unb_d> > >(global::MainThreadId);
    if (firstResumeTrial != task::state::dispatcher_status_trial::acquired_task) { throw std::runtime_error("Expected acquired task"); }

    // Expect creation of unb dispatcher task with depth 1
    auto childTask = thisCtxt.try_front_and_pop( global::MainThreadId );

    if (not childTask.get()) { throw std::runtime_error("Expected poped task"); }

    // as this application is unbound, when max depth is reached, operate will safely detect an error, altering the state of ctxt 
    thisCtxt.operate( std::move(childTask) );


    // If the kernel was run in previous operate, this newDispShPtr will be nullptr and we will break out of the loop
    newDispShPtr = thisCtxt.template try_pop_dispatcher<app::impl::unb_d>();

    safeCount++;
  }

  if (not thisCtxt.got_error()) {
    throw std::runtime_error("Expected error not caught");
  }

  }

}

template <>
void runner::verify_case<case_id::recursive_dispatcher_unbound_app>() {
  using namespace test;
  using namespace instr;
  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, global::DepthLimit>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, 0>(),
    expect<event::dep_execute::kernel_end, amount::equal, 0>(),
    expect<event::dep_dispatch::create_start, amount::equal, global::DepthLimit - 1>("impl::unb_d"),
    expect<event::dep_dispatch::create_end, amount::equal, global::DepthLimit - 1>("impl::unb_d"),
    expect<event::coro_dispatcher::constructor, amount::equal, global::DepthLimit - 1>(),
    expect<event::coro_dispatcher::destroying_handle, amount::equal, global::DepthLimit - 1>(),
    expect<event::dep_solver::error_while_executing, amount::equal, 1>("DepthLimit reached"),
    expect<event::dep_release::publish_start, amount::equal, 0>(), 
    expect<event::dep_release::publish_end, amount::equal, 0>(),
    expect<event::dep_release::publish_error_start, amount::equal, global::DepthLimit>(),
    expect<event::dep_release::publish_error_end, amount::equal, global::DepthLimit>()
  );
}

//////////////////////////////////////////////////////

template <app::impl KernelAppImpl, app::call KernelAppCall, app::impl DispatcherAppImpl, app::call DispatcherAppCall, typename T>
static void do_before_finish(T&& coreTask) {
  

  // We create a context that picks always the next_dispatcher (creates dispatchers until DepthLimit is reached)
  using selector_t = policy::selector::implementation<policy::pick_implement::next_dispatcher>;
  selector_t defaultSel;

  ctxt::active< selector_t, workload::desc::local_container, KernelAppImpl, DispatcherAppImpl> thisCtxt(defaultSel);

  // Expect creation of bar dispatcher
  thisCtxt.operate( std::move(coreTask) );

  // Get the dispatcher object
  auto dispShPtr = thisCtxt.template try_pop_dispatcher<DispatcherAppImpl>();

  // Resume, expect push task to local queue acquired_task
  auto firstResumeTrial = dispShPtr.get()->template try_resume< util::tuple_t< app::group_impl_of_t<KernelAppImpl> > >(global::MainThreadId);
  if (firstResumeTrial != task::state::dispatcher_status_trial::acquired_task) { throw std::runtime_error("Expected acquired task"); }

  // Try to resume multiple times, expecting acquired_guard_destroy
  for (auto t = 0u; t < 10; ++t) {
    auto retTrial = dispShPtr.get()->template try_resume< util::tuple_t< app::group_impl_of_t<KernelAppImpl> > >(global::MainThreadId);
    if (retTrial != task::state::dispatcher_status_trial::acquired_guard_destroy) {
      std::cout << "Trial " << t << '\n';
      throw std::runtime_error("Expected acquired guard destroy. Got " + std::to_string(t));
    }
  }

  // Get kernel and execute it (with another context)
  {
    auto popedTask = thisCtxt.try_front_and_pop( global::MainThreadId );

    using tuple_t = util::tuple::as_std_t< typename app::traits<DispatcherAppCall>::arg_tuple_type >;
    using group_t = app::group_impl_of_t<KernelAppImpl>;

    if (not popedTask) { throw std::runtime_error("Expected to have poped task"); }

    auto groupDescPtr = static_cast< task::descriptor< KernelAppCall, tuple_t >* >( popedTask.get() );

    // We create another context to run this task as a kernel (to not run it again as a dispatcher)
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;

    ctxt::active< selector_t, workload::desc::local_container, KernelAppImpl> kernelCtxt(singleSel);

    kernelCtxt.operate( std::move(popedTask) );
  }
  // Kernel is now finished.
  // Try to resume the dispatcher once. Guard is destroyable, so the coroutine is fininished. acquired_finished is expected

  auto retTrial = dispShPtr.get()->template try_resume< util::tuple_t< app::group_impl_of_t<KernelAppImpl> > >(global::MainThreadId);
  if (retTrial != task::state::dispatcher_status_trial::acquired_finished) { throw std::runtime_error("Expected acquired finished"); }

  // Try to resume again. Expect depleted. skipped_depleted
  auto finalTrial = dispShPtr.get()->template try_resume< util::tuple_t< app::group_impl_of_t<KernelAppImpl> > >(global::MainThreadId);
  if (finalTrial != task::state::dispatcher_status_trial::skipped_depleted) { throw std::runtime_error("Expected skipped depleted"); }


}

static void verify_do_before_finish(std::string instrFn, char const * kernelStr, char const * dispatcherStr) {
  using namespace test;
  using namespace instr;
  validate_log(instrFn,
    expect<event::dep_solver::all_ready, amount::equal, 2>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, 1>(kernelStr),
    expect<event::dep_execute::kernel_end, amount::equal, 1>(kernelStr),
    expect<event::dep_dispatch::create_start, amount::equal, 1>(dispatcherStr),
    expect<event::dep_dispatch::create_end, amount::equal, 1>(dispatcherStr),
    expect<event::coro_dispatcher::constructor, amount::equal, 1>(),
    expect<event::coro_dispatcher::trying_resume, amount::equal, 13>(),
    expect<event::coro_dispatcher::destroying_handle, amount::equal, 1>(),
    expect<event::dep_release::publish_start, amount::equal, 2>(), 
    expect<event::dep_release::publish_end, amount::equal, 2>(),
    expect<event::dep_release::publish_error_start, amount::equal, 0>(),
    expect<event::dep_release::publish_error_end, amount::equal, 0>()
  );

}

template <>
void runner::run_case<case_id::dispatcher_read_before_finish>() {

  const int b = 4;
  const int expected = b;

  auto wb = dep::wrap(b);

  do_before_finish<app::impl::bar_k, app::call::bar_d_bar_0,
                   app::impl::bar_d, app::call::main_entry_bar_3>(task::make_async<app::call::bar_d_bar_0>( d, wb.emit_bnd_reader() ));

  if (not wb.is_destroyable()) {
    throw std::runtime_error("Guard not destroyable");
  }

  if (expected != b) {
    throw std::runtime_error("Result not expected");
  }
}

template <>
void runner::verify_case<case_id::dispatcher_read_before_finish>() {
  verify_do_before_finish(m_instrFn, "impl::bar_k", "impl::bar_d");
}

//////////////////////////////////////////////////////

template <>
void runner::run_case<case_id::dispatcher_write_before_finish>() {

  int b = 4;
  int expected = b + 1;

  auto wb = dep::wrap(b);

  do_before_finish<app::impl::zee_k, app::call::zee_d_zee_0,
                   app::impl::zee_d, app::call::main_entry_zee_4>(task::make_async<app::call::zee_d_zee_0>( d, wb.emit_bnd_writer() ));

  if (not wb.is_destroyable()) {
    throw std::runtime_error("Guard not destroyable");
  }

  if (expected != b) {
    throw std::runtime_error("Result not expected");
  }
}

template <>
void runner::verify_case<case_id::dispatcher_write_before_finish>() {
  verify_do_before_finish(m_instrFn, "impl::zee_k", "impl::zee_d");
}


} // namespace test
