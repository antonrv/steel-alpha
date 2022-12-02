
module RunTestCases;

// import App.Traits;
// import App.ProxyKernelGenerated;
// import App.UserTranslatedKernel;
import App.Proxy;

import SteelRT.Dep;

import SteelRT.Test;

#include <cassert>

////////////////////////////////////// COMMON STUFF (unify with wrap_and_run TODO)

const depth_t d = 0;

namespace ctxt {

template <typename ImplSelectorT, app::impl... Impls>
using active = test::mock_ctxt::with_selector<ImplSelectorT, Impls...>;

} // namespace ctxt


static
void common_verify_multiple(const std::string& instrFn) {
  test::validate_log(instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 5>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 0>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 5>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 5>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 5>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 5>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 5>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 0>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 0>()
  );
}



namespace test {


// ======================================================================

template <>
void runner::run_case<case_id::true_dep_single0>() {

  int b = 4;
  int expected = b + 1;
  auto wb = dep::wrap(b);

  {
    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    // Register reader
    auto readerTask = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Run writer
    s.operate( std::move(writerTask) );

    // Run reader
    s.operate( std::move(readerTask) );
  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::true_dep_single0>() {

  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 2>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 0>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 2>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 2>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 2>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 2>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 2>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 0>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 0>()
  );

}

// ======================================================================

template <>
void runner::run_case<case_id::true_dep_single1>() {

  int b = 4;
  int expected = b + 1;
  auto wb = dep::wrap(b);

  {
    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    // Register reader
    auto readerTask = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Try run reader, expect fail
    s.operate( std::move(readerTask) );

    // Run writer
    s.operate( std::move(writerTask) );
  }


  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::true_dep_single1>() {

  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 1>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 1>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 1>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 1>()
  );

}

// ======================================================================

template <>
void runner::run_case<case_id::true_dep_multiple0>() {

  int b = 4;
  int expected = b + 1;
  auto wb = dep::wrap(b);

  {
    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    // Register readers
    auto readerTask1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );
    auto readerTask2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );
    auto readerTask3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );
    auto readerTask4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);


    // Run writer
    s.operate( std::move(writerTask) );

    // Run readers
    s.operate( std::move(readerTask1) );
    s.operate( std::move(readerTask2) );
    s.operate( std::move(readerTask3) );
    s.operate( std::move(readerTask4) );
  }


  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");

}


template <>
void runner::verify_case<case_id::true_dep_multiple0>() {
  common_verify_multiple(m_instrFn);
}

// ======================================================================

template <>
void runner::run_case<case_id::true_dep_multiple1>() {

  int b = 4;
  int expected = b + 1;
  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    // Run writer
    s.operate( std::move(writerTask) );

    // Register readers
    auto readerTask1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );
    auto readerTask2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );
    auto readerTask3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );
    auto readerTask4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Run readers
    s.operate( std::move(readerTask1) );
    s.operate( std::move(readerTask2) );
    s.operate( std::move(readerTask3) );
    s.operate( std::move(readerTask4) );
  }


  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::true_dep_multiple1>() {
  common_verify_multiple(m_instrFn);
}


// ======================================================================

template <>
void runner::run_case<case_id::true_dep_multiple2>() {

  int b = 4;
  int expected = b + 1;
  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    // Run writer
    s.operate( std::move(writerTask) );

    // Register readers
    auto readerTask1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );
    s.operate( std::move(readerTask1) );

    auto readerTask2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );
    auto readerTask3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );
    auto readerTask4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Run readers
    s.operate( std::move(readerTask2) );
    s.operate( std::move(readerTask3) );
    s.operate( std::move(readerTask4) );
  }


  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::true_dep_multiple2>() {
  common_verify_multiple(m_instrFn);
}

// ======================================================================


template <>
void runner::run_case<case_id::true_dep_multiple3>() {

  int b = 4;
  int expected = b + 1;
  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    // Register readers
    auto readerTask1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Run writer
    s.operate( std::move(writerTask) );

    s.operate( std::move(readerTask1) );

    auto readerTask2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    auto readerTask3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );
    s.operate( std::move(readerTask3) );

    auto readerTask4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    s.operate( std::move(readerTask2) );
    s.operate( std::move(readerTask4) );
  }


  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::true_dep_multiple3>() {
  common_verify_multiple(m_instrFn);
}


// ======================================================================

template <>
void runner::run_case<case_id::true_dep_multiple4>() {

  int b = 4;
  int expected = b + 1;
  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    // Register readers
    auto readerTask1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Run writer
    s.operate( std::move(writerTask) );


    auto readerTask2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    auto readerTask3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );
    s.operate( std::move(readerTask3) );

    auto readerTask4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // s.operate( std::move(readerTask2) ); One reader not run

    s.operate( std::move(readerTask4) );

    s.operate( std::move(readerTask1) );
  }


  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::true_dep_multiple4>() {
  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 4>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 0>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 4>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 4>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 4>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 4>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 4>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 1>()
  );
}


// ======================================================================

template <>
void runner::run_case<case_id::anti_dep_single0>() {

  int b = 4;
  int expected = b + 1;
  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Register reader
    auto readerTask = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    // Run reader
    s.operate( std::move(readerTask) );

    // Run writer
    s.operate( std::move(writerTask) );

  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::anti_dep_single0>() {
  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 2>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 0>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 2>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 2>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 2>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 2>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 2>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 0>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 0>()
  );
}

// ======================================================================

template <>
void runner::run_case<case_id::anti_dep_single1>() {

  int b = 4;
  int expected = b;
  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Register reader
    auto readerTask = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );


    // Try run writer, expect fail
    s.operate( std::move(writerTask) );

    // Run reader
    s.operate( std::move(readerTask) );
  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::anti_dep_single1>() {
  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 1>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 1>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 1>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 1>()
  );
}


// ======================================================================

template <>
void runner::run_case<case_id::anti_dep_multiple0>() {

  int b = 4;
  int expected = b + 1;
  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Register reader
    auto readerTask1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register reader
    auto readerTask2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register reader
    auto readerTask3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register reader
    auto readerTask4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    // Run reader
    s.operate( std::move(readerTask1) );

    // Run reader
    s.operate( std::move(readerTask2) );

    // Run reader
    s.operate( std::move(readerTask3) );

    // Run reader
    s.operate( std::move(readerTask4) );

    // Run writer
    s.operate( std::move(writerTask) );

  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::anti_dep_multiple0>() {
  common_verify_multiple(m_instrFn);
}

// ======================================================================

template <>
void runner::run_case<case_id::anti_dep_multiple1>() {

  int b = 4;
  int expected = b + 1;
  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Register reader
    auto readerTask1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register reader
    auto readerTask2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Run reader
    s.operate( std::move(readerTask1) );

    // Run reader
    s.operate( std::move(readerTask2) );

    // Register reader
    auto readerTask3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register reader
    auto readerTask4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );


    // Run reader
    s.operate( std::move(readerTask3) );

    // Run reader
    s.operate( std::move(readerTask4) );

    // Run writer
    s.operate( std::move(writerTask) );

  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::anti_dep_multiple1>() {
  common_verify_multiple(m_instrFn);
}


// ======================================================================

template <>
void runner::run_case<case_id::anti_dep_multiple2>() {

  int b = 4;
  int expected = b + 1;
  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Register reader
    auto readerTask1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register reader
    auto readerTask2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Run reader
    s.operate( std::move(readerTask2) );

    // Run reader
    s.operate( std::move(readerTask1) );


    // Register reader
    auto readerTask3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register reader
    auto readerTask4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Run reader
    s.operate( std::move(readerTask3) );

    // Run reader
    s.operate( std::move(readerTask4) );

    // Register writer
    auto writerTask = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    // Run writer
    s.operate( std::move(writerTask) );

  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::anti_dep_multiple2>() {
  common_verify_multiple(m_instrFn);
}

// ======================================================================

template <>
void runner::run_case<case_id::anti_dep_multiple3>() {

  int b = 4;
  int expected = b;
  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    // Register reader
    auto readerTask1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register reader
    auto readerTask2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Run reader
    s.operate( std::move(readerTask2) );

    // Run reader
    s.operate( std::move(readerTask1) );


    // Register reader
    auto readerTask3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register reader
    auto readerTask4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Run reader
    s.operate( std::move(readerTask4) );

    // Register writer
    auto writerTaskFail = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    // Try run writer. must fail and publish error
    s.operate( std::move(writerTaskFail) );

    // Run last reader. must succeed
    s.operate( std::move(readerTask3) );
  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::anti_dep_multiple3>() {
  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 4>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 1>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 4>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 4>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 4>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 4>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 4>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 1>()
  );
}

// ======================================================================


template <>
void runner::run_case<case_id::write_dep_single0>() {

  int b;
  int expected = 13;
  auto wb = dep::wrap<int>(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_kuu_wo> s(singleSel);

    {
      // Register writers
       auto writerTask1 = task::make_async<app::call::main_entry_kuu_2>( d, wb.emit_bnd_writer() );

       auto writerTask2 = task::make_async<app::call::main_entry_kuu_2>( d, wb.emit_bnd_writer() );

      // Run writers
      s.operate( std::move(writerTask1) );

      s.operate( std::move(writerTask2) );
    }

    {
      auto writerTask1 = task::make_async<app::call::main_entry_kuu_2>( d, wb.emit_bnd_writer() );

      s.operate( std::move(writerTask1) );

      auto writerTask2 = task::make_async<app::call::main_entry_kuu_2>( d, wb.emit_bnd_writer() );

      s.operate( std::move(writerTask2) );
    }
  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::write_dep_single0>() {
  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 4>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 0>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 4>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 4>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 4>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 4>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 4>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 0>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 0>()
  );
}

// ======================================================================


template <>
void runner::run_case<case_id::write_dep_single1>() {

  int b;
  int expected = 13;
  auto wb = dep::wrap<int>(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_kuu_wo> s(singleSel);

    // Register writers
    auto writerTask1 = task::make_async<app::call::main_entry_kuu_2>( d, wb.emit_bnd_writer() );

    auto writerTask2 = task::make_async<app::call::main_entry_kuu_2>( d, wb.emit_bnd_writer() );

  
    // Try run second writer. must fail
    s.operate( std::move(writerTask2) );

    // Run writer. must succeed
    s.operate( std::move(writerTask1) );
  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::write_dep_single1>() {
  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 1>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 1>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 1>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 1>()
  );
}

// ======================================================================

template <>
void runner::run_case<case_id::mixed_dep_multiple1>() {

  int b = 4;
  int expected = b + 2;

  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    auto fooReader1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    auto barReaderWriter1 = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    auto barReaderWriter2 = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    auto fooReader2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    auto fooReader3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    auto fooReader4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    s.operate( std::move(fooReader1) );

    s.operate( std::move(barReaderWriter1) );

    s.operate( std::move(barReaderWriter2) );

    s.operate( std::move(fooReader2) );

    s.operate( std::move(fooReader3) );

    s.operate( std::move(fooReader4) );
  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::mixed_dep_multiple1>() {
  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 6>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 0>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 6>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 6>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 6>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 6>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 6>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 0>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 0>()
  );
}


// ======================================================================

template <>
void runner::run_case<case_id::mixed_dep_multiple2>() {

  int b = 4;
  int expected = b + 2;

  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    auto fooReader1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    auto barReaderWriter1 = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    s.operate( std::move(fooReader1) );

    s.operate( std::move(barReaderWriter1) );

    auto barReaderWriter2 = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    auto fooReader2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    auto fooReader3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    auto fooReader4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    s.operate( std::move(barReaderWriter2) );

    s.operate( std::move(fooReader4) );

    s.operate( std::move(fooReader2) );

    s.operate( std::move(fooReader3) );

  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::mixed_dep_multiple2>() {
  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 6>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 0>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 6>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 6>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 6>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 6>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 6>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 0>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 0>()
  );
}



// ======================================================================

template <>
void runner::run_case<case_id::mixed_dep_multiple3>() {

  int b = 4;
  int expected = b + 1;

  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw> s(singleSel);

    auto fooReader1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    auto barReaderWriter1 = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    auto fooReader2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Run reader
    s.operate( std::move(fooReader1) );

    // Run first writer
    s.operate( std::move(barReaderWriter1) );


    // Register second writer
    auto barReaderWriter2 = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    auto fooReader3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    auto fooReader4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Try run second writer before fooReader2 finished. must fail
    s.operate( std::move(barReaderWriter2) );

    // Must succeed (previous to barReaderWriter2)
    s.operate( std::move(fooReader2) );

    // Try run reader after its writer have failed. must fail while executing
    s.operate( std::move(fooReader4) );

    // Try run reader after its writer have failed. must fail while executing
    s.operate( std::move(fooReader3) );

  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::mixed_dep_multiple3>() {
  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 5>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 1>(),
    test::expect<instr::event::dep_solver::error_while_executing, test::amount::equal, 2>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 5>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 5>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 3>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 3>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 3>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 3>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 3>()
  );
}


// ======================================================================

template <>
void runner::run_case<case_id::mixed_dep_multiple4>() {

  int b = 4;
  int expected = 14; // Overwritten to 13 by kuu, then added 1 by bar

  auto wb = dep::wrap(b);

  {
    // Create solver
    using selector_t = policy::selector::implementation<policy::pick_implement::single>;
    selector_t singleSel;
    ctxt::active<selector_t, app::impl::kernel_foo_ro, app::impl::kernel_bar_rw, app::impl::kernel_kuu_wo> s(singleSel);

    auto fooReader1 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    auto barReaderWriter1 = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    auto fooReader2 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Run reader
    s.operate( std::move(fooReader1) );

    // Run first writer
    s.operate( std::move(barReaderWriter1) );


    // Register second writer. overwrites
    auto kuuWriter = task::make_async<app::call::main_entry_kuu_2>( d, wb.emit_bnd_writer() );

    auto fooReader3 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    // Register second reader-writer
    auto barReaderWriter2 = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

    s.operate( std::move(fooReader2) );

    s.operate( std::move(kuuWriter) );

    auto fooReader4 = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );


    auto kuuWriterFail = task::make_async<app::call::main_entry_kuu_2>( d, wb.emit_bnd_writer() );


    // Try run before reader3 and barReaderWriter2 have executed. must fail
    s.operate( std::move(kuuWriterFail) );

    s.operate( std::move(fooReader3) );

    s.operate( std::move(barReaderWriter2) );

    s.operate( std::move(fooReader4) );

  }

  safe::check_throw(expected == b, "Result not expected");

  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::mixed_dep_multiple4>() {
  test::validate_log(m_instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 7>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 1>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 7>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 7>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 7>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 7>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 7>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 1>()
  );
}

} // namespace test
