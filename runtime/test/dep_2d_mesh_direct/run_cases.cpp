
module RunTestCases;

import App.Proxy;

import SteelRT.Dep.Wrap.Region;
import SteelRT.Dep;

import SteelRT.Test;


////////////////////////////////////// COMMON STUFF (unify with other tests TODO)

const depth_t d = 0;

namespace ctxt {

  template <typename ImplSelectorT, app::impl... Impls>
  using active = test::mock_ctxt::with_selector<ImplSelectorT, Impls...>;

} // namespace ctxt


enum class depkind { tru, anti, write };

template <unsigned Order, depkind DK>
struct case_runner {
  template <typename WrapT, typename CtxtT>
  static
  void create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride);
};



//////////////////////////////////////////////// TRUE DEPS

template <>
template <typename WrapT, typename CtxtT>
void case_runner<0, depkind::tru>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto woTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  auto rwTask0 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask1 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask2 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask3 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  auto roTask0 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask1 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask2 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask3 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  ctxtRef.operate( std::move(woTask0) );
  ctxtRef.operate( std::move(woTask1) );
  ctxtRef.operate( std::move(woTask2) );
  ctxtRef.operate( std::move(woTask3) );

  ctxtRef.operate( std::move(rwTask0) );
  ctxtRef.operate( std::move(rwTask1) );
  ctxtRef.operate( std::move(rwTask2) );
  ctxtRef.operate( std::move(rwTask3) );

  ctxtRef.operate( std::move(roTask0) );
  ctxtRef.operate( std::move(roTask1) );
  ctxtRef.operate( std::move(roTask2) );
  ctxtRef.operate( std::move(roTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<1, depkind::tru>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto woTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  ctxtRef.operate( std::move(woTask0) );
  ctxtRef.operate( std::move(woTask1) );
  ctxtRef.operate( std::move(woTask2) );
  ctxtRef.operate( std::move(woTask3) );

  auto rwTask0 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask1 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask2 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask3 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  ctxtRef.operate( std::move(rwTask0) );
  ctxtRef.operate( std::move(rwTask1) );
  ctxtRef.operate( std::move(rwTask2) );
  ctxtRef.operate( std::move(rwTask3) );

  auto roTask0 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask1 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask2 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask3 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  ctxtRef.operate( std::move(roTask0) );
  ctxtRef.operate( std::move(roTask1) );
  ctxtRef.operate( std::move(roTask2) );
  ctxtRef.operate( std::move(roTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<2, depkind::tru>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto woTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask0) );
  auto woTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask1) );
  auto woTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask2) );
  auto woTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask3) );

  auto rwTask0 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask0) );
  auto rwTask1 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask1) );
  auto rwTask2 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask2) );
  auto rwTask3 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask3) );

  auto roTask0 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask0) );
  auto roTask1 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask1) );
  auto roTask2 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask2) );
  auto roTask3 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<3, depkind::tru>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto woTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask0) );
  auto rwTask0 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask0) );
  auto roTask0 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask0) );

  auto woTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask1) );
  auto rwTask1 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask1) );
  auto roTask1 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask1) );

  auto woTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask2) );
  auto rwTask2 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask2) );
  auto roTask2 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask2) );

  auto woTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask3) );
  auto rwTask3 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask3) );
  auto roTask3 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<4, depkind::tru>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto woTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask3) );
  auto rwTask3 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask3) );
  auto roTask3 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask3) );

  auto woTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask2) );
  auto rwTask2 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask2) );
  auto roTask2 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask2) );

  auto woTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask0) );
  auto rwTask0 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask0) );
  auto roTask0 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask0) );

  auto woTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask1) );
  auto rwTask1 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask1) );
  auto roTask1 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask1) );
}



//////////////////////////////////////////////// ANTI DEPS

template <>
template <typename WrapT, typename CtxtT>
void case_runner<0, depkind::anti>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto roTask0 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask1 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask2 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask3 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  auto woTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  auto rwTask0 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask1 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask2 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask3 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  ctxtRef.operate( std::move(roTask0) );
  ctxtRef.operate( std::move(roTask1) );
  ctxtRef.operate( std::move(roTask2) );
  ctxtRef.operate( std::move(roTask3) );

  ctxtRef.operate( std::move(woTask0) );
  ctxtRef.operate( std::move(woTask1) );
  ctxtRef.operate( std::move(woTask2) );
  ctxtRef.operate( std::move(woTask3) );

  ctxtRef.operate( std::move(rwTask0) );
  ctxtRef.operate( std::move(rwTask1) );
  ctxtRef.operate( std::move(rwTask2) );
  ctxtRef.operate( std::move(rwTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<1, depkind::anti>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto roTask0 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask1 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask2 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto roTask3 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  ctxtRef.operate( std::move(roTask0) );
  ctxtRef.operate( std::move(roTask1) );
  ctxtRef.operate( std::move(roTask2) );
  ctxtRef.operate( std::move(roTask3) );

  auto woTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto woTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  ctxtRef.operate( std::move(woTask0) );
  ctxtRef.operate( std::move(woTask1) );
  ctxtRef.operate( std::move(woTask2) );
  ctxtRef.operate( std::move(woTask3) );

  auto rwTask0 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask1 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask2 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto rwTask3 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  ctxtRef.operate( std::move(rwTask0) );
  ctxtRef.operate( std::move(rwTask1) );
  ctxtRef.operate( std::move(rwTask2) );
  ctxtRef.operate( std::move(rwTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<2, depkind::anti>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto roTask0 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask0) );
  auto roTask1 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask1) );
  auto roTask2 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask2) );
  auto roTask3 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask3) );

  auto woTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask0) );
  auto woTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask1) );
  auto woTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask2) );
  auto woTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask3) );

  auto rwTask0 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask0) );
  auto rwTask1 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask1) );
  auto rwTask2 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask2) );
  auto rwTask3 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<3, depkind::anti>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto roTask0 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask0) );
  auto woTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask0) );
  auto rwTask0 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask0) );

  auto roTask1 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask1) );
  auto woTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask1) );
  auto rwTask1 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask1) );

  auto roTask2 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask2) );
  auto woTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask2) );
  auto rwTask2 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask2) );

  auto roTask3 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask3) );
  auto woTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask3) );
  auto rwTask3 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<4, depkind::anti>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto roTask3 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask3) );
  auto woTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask3) );
  auto rwTask3 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask3) );

  auto roTask2 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask2) );
  auto woTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask2) );
  auto rwTask2 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask2) );

  auto roTask0 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask0) );
  auto woTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask0) );
  auto rwTask0 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask0) );

  auto roTask1 = task::make_async<app::call::caller_ro_fooapp_ro_0>( d, wd.emit_bnd_reader({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(roTask1) );
  auto woTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(woTask1) );
  auto rwTask1 = task::make_async<app::call::caller_rw_fooapp_rw_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(rwTask1) );
}




//////////////////////////////////////////////// WRITE DEPS

template <>
template <typename WrapT, typename CtxtT>
void case_runner<0, depkind::write>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto wo1stTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo1stTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo1stTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo1stTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  auto wo2ndTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo2ndTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo2ndTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo2ndTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  ctxtRef.operate( std::move(wo1stTask0) );
  ctxtRef.operate( std::move(wo1stTask1) );
  ctxtRef.operate( std::move(wo1stTask2) );
  ctxtRef.operate( std::move(wo1stTask3) );

  ctxtRef.operate( std::move(wo2ndTask0) );
  ctxtRef.operate( std::move(wo2ndTask1) );
  ctxtRef.operate( std::move(wo2ndTask2) );
  ctxtRef.operate( std::move(wo2ndTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<1, depkind::write>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto wo1stTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo1stTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo1stTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo1stTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  ctxtRef.operate( std::move(wo1stTask0) );
  ctxtRef.operate( std::move(wo1stTask1) );
  ctxtRef.operate( std::move(wo1stTask2) );
  ctxtRef.operate( std::move(wo1stTask3) );

  auto wo2ndTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo2ndTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo2ndTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  auto wo2ndTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );

  ctxtRef.operate( std::move(wo2ndTask0) );
  ctxtRef.operate( std::move(wo2ndTask1) );
  ctxtRef.operate( std::move(wo2ndTask2) );
  ctxtRef.operate( std::move(wo2ndTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<2, depkind::write>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto wo1stTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask0) );
  auto wo1stTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask1) );
  auto wo1stTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask2) );
  auto wo1stTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask3) );

  auto wo2ndTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask0) );
  auto wo2ndTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask1) );
  auto wo2ndTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask2) );
  auto wo2ndTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<3, depkind::write>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto wo1stTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask0) );
  auto wo2ndTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask0) );

  auto wo1stTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask1) );
  auto wo2ndTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask1) );

  auto wo1stTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask2) );
  auto wo2ndTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask2) );

  auto wo1stTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask3) );
  auto wo2ndTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask3) );
}

template <>
template <typename WrapT, typename CtxtT>
void case_runner<4, depkind::write>::create_and_run_tasks(WrapT& wd, CtxtT& ctxtRef, unsigned nRowsPerBlock, unsigned nColsPerBlock, unsigned stride) {

  auto wo1stTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask3) );
  auto wo2ndTask3 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 1*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask3) );

  auto wo1stTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask2) );
  auto wo2ndTask2 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({1*nRowsPerBlock, 0*nColsPerBlock}, {range_t({1*nRowsPerBlock, 1*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask2) );

  auto wo1stTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask0) );
  auto wo2ndTask0 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 0*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({0*nColsPerBlock, 0*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask0) );

  auto wo1stTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo1stTask1) );
  auto wo2ndTask1 = task::make_async<app::call::caller_wo_fooapp_wo_0>( d, wd.emit_bnd_writer({0*nRowsPerBlock, 1*nColsPerBlock}, {range_t({0*nRowsPerBlock, 0*nRowsPerBlock + nRowsPerBlock}), range_t({1*nColsPerBlock, 1*nColsPerBlock + nColsPerBlock})}), nRowsPerBlock, nColsPerBlock, stride );
  ctxtRef.operate( std::move(wo2ndTask1) );
}


template <unsigned Order, depkind DK, typename CtxtT>
static
void run_generic( CtxtT& ctxtRef, unsigned nRows, unsigned nCols, unsigned nRowsPerBlock, unsigned nColsPerBlock, float init, float expected ) {

  auto nElem = nRows * nCols;

  std::unique_ptr<float[]> dataUPtr{ new float[nElem] };

  for (auto i = 0u; i < nElem; ++i) { dataUPtr[i] = init; }
  auto wd = dep::wrap_region<2,dep::mesh::direct>( dataUPtr.get(),
      {/*g-embeds*/nCols, 1},
      {/*l-embeds*/nRowsPerBlock, nColsPerBlock},
      {/*call-ranges*/
        range_t({0, nRows / nRowsPerBlock}),
        range_t({0, nCols / nColsPerBlock})
      }
    );

  case_runner<Order, DK>::create_and_run_tasks(wd, ctxtRef, nRowsPerBlock, nColsPerBlock, nCols);

  // Check and handle error // UNIFY WITH dep_Xd_mesh TODO
  std::vector<std::string> diffsExpected;
  for (auto i = 0u; i < nElem; ++i) {
    if (dataUPtr[i] != expected) {
      diffsExpected.push_back( std::to_string(dataUPtr[i]) + " != " + std::to_string(expected) + ". ");
    }
  }
  if (not diffsExpected.empty()) {
    auto diffStr = "Total diffs : " + std::to_string(diffsExpected.size()) + ". Unique diffs : ";
    std::sort(std::begin(diffsExpected), std::end(diffsExpected));
    diffsExpected.erase( std::unique(std::begin(diffsExpected), std::end(diffsExpected)), std::end(diffsExpected) );
    for (auto& diff : diffsExpected) {
      diffStr += diff + ", ";
    }
    std::string dkStr = std::string(DK == depkind::tru ? "true" : (DK == depkind::anti ? "anti" : "write")) + " dependency";
    throw std::runtime_error("Result not expected in case \'" + dkStr +"\', order "+ std::to_string(Order) + ". Differences : " + diffStr);
  }

  safe::check_throw(wd.is_destroyable(), "Guard not destroyable");
}




namespace test {


template <>
void runner::run_case<case_id::dim2_mesh_true_dep>() {

  using selector_t = policy::selector::implementation<policy::pick_implement::single>;
  selector_t singleSel;
  ctxt::active<selector_t, app::impl::foo_wo, app::impl::foo_rw, app::impl::foo_ro> ctxtRef(singleSel);

  float init = 0.f;
  float expected = 20.f;

  unsigned nCols = 32;
  unsigned nRows = 16;
  unsigned nColsPerBlock = 16;
  unsigned nRowsPerBlock = 8;

  run_generic<0, depkind::tru>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<1, depkind::tru>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<2, depkind::tru>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<3, depkind::tru>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<4, depkind::tru>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );

}



template <>
void runner::verify_case<case_id::dim2_mesh_true_dep>() {

  constexpr const unsigned expectedRunsImplRO = 4 * 5 * 1 * 1; // (tasks per case) * (# orders) * (fit) * (truedep)
  constexpr const unsigned expectedRunsImplRW = 4 * 5 * 1 * 1; // (tasks per case) * (# orders) * (fit) * (truedep)
  constexpr const unsigned expectedRunsImplWO = 4 * 5 * 1 * 1; // (tasks per case) * (# orders) * (fit) * (truedep)

  constexpr const unsigned expectedRuns = expectedRunsImplRO + expectedRunsImplRW + expectedRunsImplWO;

  using namespace test;
  using namespace instr;

  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, expectedRuns>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, expectedRunsImplRO>("impl::foo_ro"),
    expect<event::dep_execute::kernel_end, amount::equal, expectedRunsImplRO>("impl::foo_ro"),
    expect<event::dep_execute::kernel_start, amount::equal, expectedRunsImplRW>("impl::foo_rw"),
    expect<event::dep_execute::kernel_end, amount::equal, expectedRunsImplRW>("impl::foo_rw"),
    expect<event::dep_execute::kernel_start, amount::equal, expectedRunsImplWO>("impl::foo_wo"),
    expect<event::dep_execute::kernel_end, amount::equal, expectedRunsImplWO>("impl::foo_wo"),
    expect<event::dep_release::publish_start, amount::equal, expectedRuns>(),
    expect<event::dep_release::publish_end, amount::equal, expectedRuns>(),
    expect<event::dep_release::publish_error_start, amount::equal, 0>(),
    expect<event::dep_release::publish_error_end, amount::equal, 0>()
  );
}


template <>
void runner::run_case<case_id::dim2_mesh_anti_dep>() {

  using selector_t = policy::selector::implementation<policy::pick_implement::single>;
  selector_t singleSel;
  ctxt::active<selector_t, app::impl::foo_wo, app::impl::foo_rw, app::impl::foo_ro> ctxtRef(singleSel);

  float init = 0.f;
  float expected = 20.f;

  unsigned nCols = 32;
  unsigned nRows = 16;
  unsigned nColsPerBlock = 16;
  unsigned nRowsPerBlock = 8;

  run_generic<0, depkind::anti>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<1, depkind::anti>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<2, depkind::anti>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<3, depkind::anti>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<4, depkind::anti>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );

}



template <>
void runner::verify_case<case_id::dim2_mesh_anti_dep>() {

  constexpr const unsigned expectedRunsImplRO = 4 * 5 * 1 * 1; // (tasks per case) * (# orders) * (fit) * (antidep)
  constexpr const unsigned expectedRunsImplRW = 4 * 5 * 1 * 1; // (tasks per case) * (# orders) * (fit) * (antidep)
  constexpr const unsigned expectedRunsImplWO = 4 * 5 * 1 * 1; // (tasks per case) * (# orders) * (fit) * (antidep)

  constexpr const unsigned expectedRuns = expectedRunsImplRO + expectedRunsImplRW + expectedRunsImplWO;

  using namespace test;
  using namespace instr;

  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, expectedRuns>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, expectedRunsImplRO>("impl::foo_ro"),
    expect<event::dep_execute::kernel_end, amount::equal, expectedRunsImplRO>("impl::foo_ro"),
    expect<event::dep_execute::kernel_start, amount::equal, expectedRunsImplRW>("impl::foo_rw"),
    expect<event::dep_execute::kernel_end, amount::equal, expectedRunsImplRW>("impl::foo_rw"),
    expect<event::dep_execute::kernel_start, amount::equal, expectedRunsImplWO>("impl::foo_wo"),
    expect<event::dep_execute::kernel_end, amount::equal, expectedRunsImplWO>("impl::foo_wo"),
    expect<event::dep_release::publish_start, amount::equal, expectedRuns>(),
    expect<event::dep_release::publish_end, amount::equal, expectedRuns>(),
    expect<event::dep_release::publish_error_start, amount::equal, 0>(),
    expect<event::dep_release::publish_error_end, amount::equal, 0>()
  );
}



template <>
void runner::run_case<case_id::dim2_mesh_write_dep>() {

  using selector_t = policy::selector::implementation<policy::pick_implement::single>;
  selector_t singleSel;
  ctxt::active<selector_t, app::impl::foo_wo, app::impl::foo_rw, app::impl::foo_ro> ctxtRef(singleSel);

  float init = 0.f;
  float expected = 13.f;

  unsigned nCols = 32;
  unsigned nRows = 16;
  unsigned nColsPerBlock = 16;
  unsigned nRowsPerBlock = 8;

  run_generic<0, depkind::write>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<1, depkind::write>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<2, depkind::write>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<3, depkind::write>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );
  run_generic<4, depkind::write>( ctxtRef, nRows, nCols, nRowsPerBlock, nColsPerBlock, init, expected );

}



template <>
void runner::verify_case<case_id::dim2_mesh_write_dep>() {

  constexpr const unsigned expectedRunsImplRO = 0; // (tasks per case) * (# orders) * (fit) * (writedep)
  constexpr const unsigned expectedRunsImplRW = 0; // (tasks per case) * (# orders) * (fit) * (writedep)
  constexpr const unsigned expectedRunsImplWO = 8 * 5 * 1 * 1; // (tasks per case) * (# orders) * (fit) * (writedep)

  constexpr const unsigned expectedRuns = expectedRunsImplRO + expectedRunsImplRW + expectedRunsImplWO;

  using namespace test;
  using namespace instr;

  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, expectedRuns>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, expectedRunsImplRO>("impl::foo_ro"),
    expect<event::dep_execute::kernel_end, amount::equal, expectedRunsImplRO>("impl::foo_ro"),
    expect<event::dep_execute::kernel_start, amount::equal, expectedRunsImplRW>("impl::foo_rw"),
    expect<event::dep_execute::kernel_end, amount::equal, expectedRunsImplRW>("impl::foo_rw"),
    expect<event::dep_execute::kernel_start, amount::equal, expectedRunsImplWO>("impl::foo_wo"),
    expect<event::dep_execute::kernel_end, amount::equal, expectedRunsImplWO>("impl::foo_wo"),
    expect<event::dep_release::publish_start, amount::equal, expectedRuns>(),
    expect<event::dep_release::publish_end, amount::equal, expectedRuns>(),
    expect<event::dep_release::publish_error_start, amount::equal, 0>(),
    expect<event::dep_release::publish_error_end, amount::equal, 0>()
  );
}




} // namespace test
