
module RunTestCases;

import App.Proxy;

import SteelRT.Dep;

import SteelRT.Test;

import <vector>;

////////////////////////////////////// COMMON STUFF (unify with consistency TODO)

const depth_t d = 0;

namespace ctxt {

template <typename ImplSelectorT, app::impl... Impls>
using active = test::mock_ctxt::with_selector<ImplSelectorT, Impls...>;

} // namespace ctxt


template <app::call AppCall, typename DescT>
static
void run_solver(DescT&& desc) {

  // Single selector assumes a singleton sequence of available implementations.
  using selector_t = policy::selector::implementation<policy::pick_implement::single>;
  selector_t singleSel;

  ctxt::active< selector_t, app::traits<AppCall>::belonging_impl > s(singleSel);

  s.operate( std::move(desc) );
}

static
void common_verify(const std::string& instrFn) {
  test::validate_log(instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 1>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 0>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::less_or_equal_than, 1>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 0>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 0>()
  );
}

static
void common_verify_error(const std::string& instrFn) {
  test::validate_log(instrFn,
    test::expect<instr::event::dep_solver::all_ready, test::amount::equal, 0>(),
    test::expect<instr::event::dep_solver::not_ready, test::amount::equal, 0>(),
    test::expect<instr::event::dep_execute::kernel_start, test::amount::equal, 0>(),
    test::expect<instr::event::dep_acquire::getting_wrapped, test::amount::equal, 0>(),
    test::expect<instr::event::dep_execute::kernel_end, test::amount::equal, 0>(),
    test::expect<instr::event::dep_release::publish_start, test::amount::equal, 0>(),
    test::expect<instr::event::dep_release::publish_end, test::amount::equal, 0>(),
    test::expect<instr::event::dep_release::publish_error_start, test::amount::equal, 1>(),
    test::expect<instr::event::dep_release::publish_error_end, test::amount::equal, 1>()
  );
}

////////////////////////////////////// Test cases


namespace test {


///// No arguments treated as kernel dependencies. Nothing to resolve or synchronize
template <>
void runner::run_case<case_id::ro_no_wrap>() {

  // Async call without any kernel dep
  int b = 4;
  auto descUPtr = task::make_async<app::call::main_entry_foo_7>( d, b );

  run_solver<app::call::main_entry_foo_7>( std::move(descUPtr) );
}

template <>
void runner::verify_case<case_id::ro_no_wrap>() {
  common_verify(m_instrFn);
}

template <>
void runner::run_case<case_id::ro_ready_copy>() {
  // Synchronous setting of a kernel dependency (in scenarios where it may be writen, otherwise a int b = 4; would be enough
  const int b = 4;
  auto wb = dep::wrap(b);

  // At compile time we know that this is a call following a sync set not in a nested block. This info is encapsulated in traits<call::foo_ro>
  // Pass copy as is, expect no futurization and do not increase any observer counters.
  auto descUPtr = task::make_async<app::call::main_entry_foo_7>( d, wb.use_copy() );


  // ... some other reading b reference... Thats why we needed to wrap it before,

  // auto descBarUPtr = task::make_async<app::call::bar_rw_res>( d, wb.use() ); // This will trigger a compile error, as bar_rw reads AND writes

  // auto descZeeUPtr = task::make_async<app::call::zee_ro_r_res>( d, wb.use() ); // RO ref

  // Destroyable before kernel execution, as we took a copy
  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");

  run_solver<app::call::main_entry_foo_7>( std::move(descUPtr) );
}

template <>
void runner::verify_case<case_id::ro_ready_copy>() {
  common_verify(m_instrFn);
}


template <>
void runner::run_case<case_id::ro>() {
  // Synchronous setting of a kernel dependency (in scenarios where it may be writen)
  int b = 4;
  int expected = b;
  auto wb = dep::wrap(b);
// 
//   // ... some kernel altering b value... 
// 
//   // At compile time we cannot ensure that b is resolved at this point, so we pass the wrapper as is. This info is encapsulated in traits<call::foo_ro>
//   // Pass copy as is, expect an increase in the observer number in the associated promise_state
// 
  {
    auto descUPtr = task::make_async<app::call::main_entry_foo_1>( d, wb.emit_bnd_reader() );

    run_solver<app::call::main_entry_foo_1>( std::move(descUPtr) );
  }

  if (expected != b) {
    throw std::runtime_error("Result not expected");
  }

  // Destroyable only after kernel execution and descriptor is deleted
  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::ro>() {
  common_verify(m_instrFn);
}




// MOVE RAW/WAR/WAW to other test
template <>
void runner::run_case<case_id::rw>() {

  // Synchronous setting of a kernel dependency (in scenarios where it may be writen)
  int b = 4;
  int expected = b + 1;

  auto wb = dep::wrap(b);

  // ... some kernel may be altering b value... 

  {
    
    auto descBarUPtr = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() ); // WAR OK

    run_solver<app::call::main_entry_bar_0>( std::move(descBarUPtr) );
  }

  if (expected != b) {
    throw std::runtime_error("Result not expected");
  }

  // We cannot leave immediately destroying wb, The promise state has been preserved to the task descriptor, but that promise state is referencing a variable whose lifetime must be preserved.
  safe::check_throw(wb.is_destroyable(), "Guard not destroyable");

}

template <>
void runner::verify_case<case_id::rw>() {
  common_verify(m_instrFn);
}

// Illegal case. This must be illegal because if we are wrapping a variable, it means that at some point is going to be writen. If that variable is read-only by a kernel that requires a reference (not a copy), we cannot pass the value as a reference.
// void ro_ref_async_resolved() {
// 
//  {
//   const int b = 4;
//   auto wb = dep::wrap(b);
// 
//   {
//     auto descUPtr = task::make_async<app::call::main_entry_zee_2>( d, wb.use_copy() ); // This is illegal, because the kernel requires a reference.
// 
//     run_solver<app::call::zee_ro_res>( std::move(descUPtr) );
//   }
//  
//   safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
//  }
// 
// }


template <>
void runner::run_case<case_id::ro_cref>() {
 
   const int b = 4;
   auto wb = dep::wrap(b);
 
   {
     auto descUPtr = task::make_async<app::call::main_entry_zee_6>( d, wb.emit_bnd_reader() );
     // auto descUPtr = task::make_async<app::call::main_entry_zee_6>( d, wb.use_copy() );
 
     run_solver<app::call::main_entry_zee_6>( std::move(descUPtr) );
   }
  
   safe::check_throw(wb.is_destroyable(), "Guard not destroyable");

}

template <>
void runner::verify_case<case_id::ro_cref>() {
  common_verify(m_instrFn);
}

template <>
void runner::run_case<case_id::ro_ref>() {
 
   int b = 4;
   auto wb = dep::wrap(b);
 
   {
     auto descUPtr = task::make_async<app::call::main_entry_zee_5>( d, wb.emit_bnd_reader() );
 
     run_solver<app::call::main_entry_zee_5>( std::move(descUPtr) );
   }
  
   safe::check_throw(wb.is_destroyable(), "Guard not destroyable");

}

template <>
void runner::verify_case<case_id::ro_ref>() {
  common_verify(m_instrFn);
}



template <>
void runner::run_case<case_id::wo>() {

  // In the current implementation, we rely on wraping an uninit var.
  // For the moment indistinguishable from RW case, since we are not allocating.
  // In the future we may consider on allocating a new object T, passing no var and specifying a type to the dep::wrap function.

  int b;
  auto wb = dep::wrap<int>(b);

  {
     auto descUPtr = task::make_async<app::call::main_entry_kuu_2>( d, wb.emit_bnd_writer() );
 
     run_solver<app::call::main_entry_kuu_2>( std::move(descUPtr) );
  }

  if (wb.use_copy() != 13) {
    throw std::runtime_error("Result not expected");
  }
 
   safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::wo>() {
  common_verify(m_instrFn);
}

template <>
void runner::run_case<case_id::rw_vector>() {

  std::vector<int> vec; vec.push_back(4); vec.push_back(2); vec.push_back(61);
  std::vector<int> expectedVec(vec);

  auto wb = dep::wrap(vec);


  {
     auto descUPtr = task::make_async<app::call::main_entry_vii_3>( d, wb.emit_bnd_writer() );
 
     run_solver<app::call::main_entry_vii_3>( std::move(descUPtr) );
  }

  expectedVec.push_back(13);
  expectedVec.push_back(42);

  if (expectedVec != vec) {
    throw std::runtime_error("Result not expected");
  }
 
   safe::check_throw(wb.is_destroyable(), "Guard not destroyable");

}

template <>
void runner::verify_case<case_id::rw_vector>() {
  common_verify(m_instrFn);
}


template <>
void runner::run_case<case_id::ro_cast_error>() {

    int b = 4;
    auto wb = dep::wrap(b);

    {
      auto descUPtr = task::make_async<app::call::main_entry_zee_5>( d, wb.emit_bnd_reader() );

      // Not executed (assuming error happened somewhere during execution or dependency acquisition)
    }

    safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::ro_cast_error>() {
  common_verify_error(m_instrFn);
}

template <>
void runner::run_case<case_id::ro_error>() {
    const int b = 4;
    auto wb = dep::wrap(b);

    {
      auto descUPtr = task::make_async<app::call::main_entry_zee_6>( d, wb.emit_bnd_reader() );
      // auto descUPtr = task::make_async<app::call::main_entry_zee_6>( d, wb.use_copy() );

      // Not executed (assuming error happened somewhere during execution or dependency acquisition)
    }

    safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::ro_error>() {
  common_verify_error(m_instrFn);
}


template <>
void runner::run_case<case_id::rw_error>() {

    int b = 4;
    auto wb = dep::wrap(b);

    {
      auto descUPtr = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

      // Not executed (assuming error happened somewhere during execution or dependency acquisition)
    }

    safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::rw_error>() {
  common_verify_error(m_instrFn);
}

template <>
void runner::run_case<case_id::wo_error>() {

    // For the moment indistinguishable from rw case
    int b;
    auto wb = dep::wrap(b);

    {
      auto descUPtr = task::make_async<app::call::main_entry_bar_0>( d, wb.emit_bnd_writer() );

      // Not executed (assuming error happened somewhere during execution or dependency acquisition)
    }

    safe::check_throw(wb.is_destroyable(), "Guard not destroyable");
}

template <>
void runner::verify_case<case_id::wo_error>() {
  common_verify_error(m_instrFn);
}

} // namespace test
