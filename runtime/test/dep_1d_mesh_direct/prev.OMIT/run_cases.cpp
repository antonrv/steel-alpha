
module RunTestCases;

import App.Traits;
import App.ProxyKernelGenerated;
import App.UserTranslatedKernel;

import SteelRT.Dep;

import SteelRT.Test;

////////////////////////////////////// COMMON STUFF (unify with other tests TODO)

const depth_t d = 0;

namespace ctxt {

  template <typename ImplSelectorT, app::impl... Impls>
  using active = test::mock_ctxt::with_selector<ImplSelectorT, Impls...>;

} // namespace ctxt


//////////////////////////////////////////////// TRUE DEPS

template <typename WrapT, typename CtxtT>
static
void true_dep_correct_order0(WrapT& wd, CtxtT& ctxtRef) {

  auto rwTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  auto rwTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  auto rwTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  auto rwTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );

  auto roTask0 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(0) );
  auto roTask1 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(1) );
  auto roTask2 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(2) );
  auto roTask3 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(3) );

  ctxtRef.operate( std::move(rwTask0) );
  ctxtRef.operate( std::move(rwTask1) );
  ctxtRef.operate( std::move(rwTask2) );
  ctxtRef.operate( std::move(rwTask3) );

  ctxtRef.operate( std::move(roTask0) );
  ctxtRef.operate( std::move(roTask1) );
  ctxtRef.operate( std::move(roTask2) );
  ctxtRef.operate( std::move(roTask3) );
}

template <typename WrapT, typename CtxtT>
static
void true_dep_correct_order1(WrapT& wd, CtxtT& ctxtRef) {

  auto rwTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  auto rwTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  auto rwTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  auto rwTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );

  ctxtRef.operate( std::move(rwTask0) );
  ctxtRef.operate( std::move(rwTask1) );
  ctxtRef.operate( std::move(rwTask2) );
  ctxtRef.operate( std::move(rwTask3) );

  auto roTask0 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(0) );
  auto roTask1 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(1) );
  auto roTask2 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(2) );
  auto roTask3 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(3) );

  ctxtRef.operate( std::move(roTask0) );
  ctxtRef.operate( std::move(roTask1) );
  ctxtRef.operate( std::move(roTask2) );
  ctxtRef.operate( std::move(roTask3) );
}

template <typename WrapT, typename CtxtT>
static
void true_dep_correct_order2(WrapT& wd, CtxtT& ctxtRef) {

  auto rwTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rwTask0) );
  auto rwTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rwTask1) );
  auto rwTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rwTask2) );
  auto rwTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rwTask3) );

  auto roTask0 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(0) );
  ctxtRef.operate( std::move(roTask0) );
  auto roTask1 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(1) );
  ctxtRef.operate( std::move(roTask1) );
  auto roTask2 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(2) );
  ctxtRef.operate( std::move(roTask2) );
  auto roTask3 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(3) );
  ctxtRef.operate( std::move(roTask3) );
}

template <typename WrapT, typename CtxtT>
static
void true_dep_correct_order3(WrapT& wd, CtxtT& ctxtRef) {

  auto rwTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rwTask0) );
  auto roTask0 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(0) );
  ctxtRef.operate( std::move(roTask0) );
  auto rwTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rwTask1) );
  auto roTask1 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(1) );
  ctxtRef.operate( std::move(roTask1) );
  auto rwTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rwTask2) );
  auto roTask2 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(2) );
  ctxtRef.operate( std::move(roTask2) );
  auto rwTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rwTask3) );
  auto roTask3 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(3) );
  ctxtRef.operate( std::move(roTask3) );
}

template <typename WrapT, typename CtxtT>
static
void true_dep_correct_order4(WrapT& wd, CtxtT& ctxtRef) {

  auto rwTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rwTask3) );
  auto roTask3 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(3) );
  ctxtRef.operate( std::move(roTask3) );

  auto rwTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rwTask2) );
  auto roTask2 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(2) );
  ctxtRef.operate( std::move(roTask2) );

  auto rwTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rwTask0) );
  auto roTask0 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(0) );
  ctxtRef.operate( std::move(roTask0) );

  auto rwTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rwTask1) );
  auto roTask1 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(1) );
  ctxtRef.operate( std::move(roTask1) );
}


//////////////////////////////////////////////// ANTI DEPS

template <typename WrapT, typename CtxtT>
static
void anti_dep_correct_order0(WrapT& wd, CtxtT& ctxtRef) {

  auto roTask0 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(0) );
  auto roTask1 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(1) );
  auto roTask2 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(2) );
  auto roTask3 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(3) );

  auto rwTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  auto rwTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  auto rwTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  auto rwTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );

  ctxtRef.operate( std::move(roTask0) );
  ctxtRef.operate( std::move(roTask1) );
  ctxtRef.operate( std::move(roTask2) );
  ctxtRef.operate( std::move(roTask3) );

  ctxtRef.operate( std::move(rwTask0) );
  ctxtRef.operate( std::move(rwTask1) );
  ctxtRef.operate( std::move(rwTask2) );
  ctxtRef.operate( std::move(rwTask3) );
}


template <typename WrapT, typename CtxtT>
static
void anti_dep_correct_order1(WrapT& wd, CtxtT& ctxtRef) {

  auto roTask0 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(0) );
  auto roTask1 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(1) );
  auto roTask2 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(2) );
  auto roTask3 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(3) );

  ctxtRef.operate( std::move(roTask0) );
  ctxtRef.operate( std::move(roTask1) );
  ctxtRef.operate( std::move(roTask2) );
  ctxtRef.operate( std::move(roTask3) );

  auto rwTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  auto rwTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  auto rwTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  auto rwTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );

  ctxtRef.operate( std::move(rwTask0) );
  ctxtRef.operate( std::move(rwTask1) );
  ctxtRef.operate( std::move(rwTask2) );
  ctxtRef.operate( std::move(rwTask3) );
}

template <typename WrapT, typename CtxtT>
static
void anti_dep_correct_order2(WrapT& wd, CtxtT& ctxtRef) {

  // ro
  auto roTask0 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(0) );
  ctxtRef.operate( std::move(roTask0) );

  auto roTask1 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(1) );
  ctxtRef.operate( std::move(roTask1) );

  auto roTask2 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(2) );
  ctxtRef.operate( std::move(roTask2) );

  auto roTask3 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(3) );
  ctxtRef.operate( std::move(roTask3) );

  // rw
  auto rwTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rwTask0) );

  auto rwTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rwTask1) );

  auto rwTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rwTask2) );

  auto rwTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rwTask3) );
}

template <typename WrapT, typename CtxtT>
static
void anti_dep_correct_order3(WrapT& wd, CtxtT& ctxtRef) {

  auto roTask0 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(0) );
  ctxtRef.operate( std::move(roTask0) );
  auto rwTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rwTask0) );

  auto roTask1 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(1) );
  ctxtRef.operate( std::move(roTask1) );
  auto rwTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rwTask1) );

  auto roTask2 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(2) );
  ctxtRef.operate( std::move(roTask2) );
  auto rwTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rwTask2) );

  auto roTask3 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(3) );
  ctxtRef.operate( std::move(roTask3) );
  auto rwTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rwTask3) );
}

template <typename WrapT, typename CtxtT>
static
void anti_dep_correct_order4(WrapT& wd, CtxtT& ctxtRef) {

  auto roTask3 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(3) );
  ctxtRef.operate( std::move(roTask3) );
  auto rwTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rwTask3) );

  auto roTask2 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(2) );
  ctxtRef.operate( std::move(roTask2) );
  auto rwTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rwTask2) );

  auto roTask0 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(0) );
  ctxtRef.operate( std::move(roTask0) );
  auto rwTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rwTask0) );

  auto roTask1 = task::make_async<app::call::ro_region>( d, wd.emit_bnd_reader(1) );
  ctxtRef.operate( std::move(roTask1) );
  auto rwTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rwTask1) );
}

//////////////////////////////////////////////// WRITE DEPS

template <typename WrapT, typename CtxtT>
static
void write_dep_correct_order0(WrapT& wd, CtxtT& ctxtRef) {

  auto rw1stTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  auto rw1stTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  auto rw1stTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  auto rw1stTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );

  auto rw2ndTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  auto rw2ndTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  auto rw2ndTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  auto rw2ndTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );

  ctxtRef.operate( std::move(rw1stTask0) );
  ctxtRef.operate( std::move(rw1stTask1) );
  ctxtRef.operate( std::move(rw1stTask2) );
  ctxtRef.operate( std::move(rw1stTask3) );

  ctxtRef.operate( std::move(rw2ndTask0) );
  ctxtRef.operate( std::move(rw2ndTask1) );
  ctxtRef.operate( std::move(rw2ndTask2) );
  ctxtRef.operate( std::move(rw2ndTask3) );
}


template <typename WrapT, typename CtxtT>
static
void write_dep_correct_order1(WrapT& wd, CtxtT& ctxtRef) {

  auto rw1stTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  auto rw1stTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  auto rw1stTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  auto rw1stTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );

  ctxtRef.operate( std::move(rw1stTask0) );
  ctxtRef.operate( std::move(rw1stTask1) );
  ctxtRef.operate( std::move(rw1stTask2) );
  ctxtRef.operate( std::move(rw1stTask3) );

  auto rw2ndTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  auto rw2ndTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  auto rw2ndTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  auto rw2ndTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );

  ctxtRef.operate( std::move(rw2ndTask0) );
  ctxtRef.operate( std::move(rw2ndTask1) );
  ctxtRef.operate( std::move(rw2ndTask2) );
  ctxtRef.operate( std::move(rw2ndTask3) );
}

template <typename WrapT, typename CtxtT>
static
void write_dep_correct_order2(WrapT& wd, CtxtT& ctxtRef) {

  // ro
  auto rw1stTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rw1stTask0) );

  auto rw1stTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rw1stTask1) );

  auto rw1stTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rw1stTask2) );

  auto rw1stTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rw1stTask3) );

  // rw
  auto rw2ndTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rw2ndTask0) );

  auto rw2ndTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rw2ndTask1) );

  auto rw2ndTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rw2ndTask2) );

  auto rw2ndTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rw2ndTask3) );
}

template <typename WrapT, typename CtxtT>
static
void write_dep_correct_order3(WrapT& wd, CtxtT& ctxtRef) {

  auto rw1stTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rw1stTask0) );
  auto rw2ndTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rw2ndTask0) );

  auto rw1stTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rw1stTask1) );
  auto rw2ndTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rw2ndTask1) );

  auto rw1stTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rw1stTask2) );
  auto rw2ndTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rw2ndTask2) );

  auto rw1stTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rw1stTask3) );
  auto rw2ndTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rw2ndTask3) );
}

template <typename WrapT, typename CtxtT>
static
void write_dep_correct_order4(WrapT& wd, CtxtT& ctxtRef) {

  auto rw1stTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rw1stTask3) );
  auto rw2ndTask3 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(3) );
  ctxtRef.operate( std::move(rw2ndTask3) );

  auto rw1stTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rw1stTask2) );
  auto rw2ndTask2 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(2) );
  ctxtRef.operate( std::move(rw2ndTask2) );

  auto rw1stTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rw1stTask0) );
  auto rw2ndTask0 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(0) );
  ctxtRef.operate( std::move(rw2ndTask0) );

  auto rw1stTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rw1stTask1) );
  auto rw2ndTask1 = task::make_async<app::call::rw_region>( d, wd.emit_bnd_writer(1) );
  ctxtRef.operate( std::move(rw2ndTask1) );
}


namespace test {

template <>
void runner::run_case<case_id::dim1_disjoint_correct_order>() {

  using selector_t = policy::selector::implementation<policy::pick_implement::single>;
  selector_t singleSel;
  ctxt::active<selector_t, app::impl::ro_region, app::impl::rw_region> ctxtRef(singleSel);



  ///////////// True dep correct order
  
  auto correctOrder = [&ctxtRef](int order, float init, float expected, uint_t nElem, uint_t nElemPerBlock, std::string kind) {

    std::unique_ptr<float[]> dataUPtr{ new float[nElem] };

    for (auto i = 0u; i < nElem; ++i) { dataUPtr[i] = init; }

    auto wd = dep::wrap_region<dep::guard::fnd::region::mode::disjoint>(dataUPtr.get(), nElem, nElemPerBlock);

    if (kind == "true dep") {
      switch (order) {
        case 0: true_dep_correct_order0(wd, ctxtRef); break;
        case 1: true_dep_correct_order1(wd, ctxtRef); break;
        case 2: true_dep_correct_order2(wd, ctxtRef); break;
        case 3: true_dep_correct_order3(wd, ctxtRef); break;
        case 4: true_dep_correct_order4(wd, ctxtRef); break;
      };
    } else if (kind == "anti dep") {
      switch (order) {
        case 0: anti_dep_correct_order0(wd, ctxtRef); break;
        case 1: anti_dep_correct_order1(wd, ctxtRef); break;
        case 2: anti_dep_correct_order2(wd, ctxtRef); break;
        case 3: anti_dep_correct_order3(wd, ctxtRef); break;
        case 4: anti_dep_correct_order4(wd, ctxtRef); break;
      };

    } else if (kind == "write dep") {
      switch (order) {
        case 0: write_dep_correct_order0(wd, ctxtRef); break;
        case 1: write_dep_correct_order1(wd, ctxtRef); break;
        case 2: write_dep_correct_order2(wd, ctxtRef); break;
        case 3: write_dep_correct_order3(wd, ctxtRef); break;
        case 4: write_dep_correct_order4(wd, ctxtRef); break;
      };
    } else { throw std::runtime_error("Wrong option : " + kind); }

    std::string diffExpected;
    for (auto i = 0u; i < nElem; ++i) { if (dataUPtr[i] != expected) { diffExpected += std::to_string(dataUPtr[i]) + " != " + std::to_string(expected) + ". "; } }
    if (not diffExpected.empty()) {
      throw std::runtime_error("Result not expected (" + kind + ") order "+ std::to_string(order) + ": " + diffExpected);
    }

    safe::check_throw(wd.is_destroyable(), "Guard not destroyable");
  };

  // Fitting blocks. 4 blocks, 8 elem each
  correctOrder(0, 1.f, 2.f, 32, 8, "true dep");
  correctOrder(1, 1.f, 2.f, 32, 8, "true dep");
  correctOrder(2, 1.f, 2.f, 32, 8, "true dep");
  correctOrder(3, 1.f, 2.f, 32, 8, "true dep");
  correctOrder(4, 1.f, 2.f, 32, 8, "true dep");
  // Non fitting blocks. 4 blocks, 9 elem each but last 5 elem
  correctOrder(0, 1.f, 2.f, 32, 9, "true dep");
  correctOrder(1, 1.f, 2.f, 32, 9, "true dep");
  correctOrder(2, 1.f, 2.f, 32, 9, "true dep");
  correctOrder(3, 1.f, 2.f, 32, 9, "true dep");
  correctOrder(4, 1.f, 2.f, 32, 9, "true dep");

  // Fitting blocks. 4 blocks, 8 elem each
  correctOrder(0, 1.f, 2.f, 32, 8, "anti dep");
  correctOrder(1, 1.f, 2.f, 32, 8, "anti dep");
  correctOrder(2, 1.f, 2.f, 32, 8, "anti dep");
  correctOrder(3, 1.f, 2.f, 32, 8, "anti dep");
  correctOrder(4, 1.f, 2.f, 32, 8, "anti dep");
  // Non fitting blocks. 4 blocks, 9 elem each but last 5 elem
  correctOrder(0, 1.f, 2.f, 32, 9, "anti dep");
  correctOrder(1, 1.f, 2.f, 32, 9, "anti dep");
  correctOrder(2, 1.f, 2.f, 32, 9, "anti dep");
  correctOrder(3, 1.f, 2.f, 32, 9, "anti dep");
  correctOrder(4, 1.f, 2.f, 32, 9, "anti dep");

  // Fitting blocks. 4 blocks, 8 elem each
  correctOrder(0, 1.f, 3.f, 32, 8, "write dep");
  correctOrder(1, 1.f, 3.f, 32, 8, "write dep");
  correctOrder(2, 1.f, 3.f, 32, 8, "write dep");
  correctOrder(3, 1.f, 3.f, 32, 8, "write dep");
  correctOrder(4, 1.f, 3.f, 32, 8, "write dep");
  // Non fitting blocks. 4 blocks, 9 elem each but last 5 elem
  correctOrder(0, 1.f, 3.f, 32, 9, "write dep");
  correctOrder(1, 1.f, 3.f, 32, 9, "write dep");
  correctOrder(2, 1.f, 3.f, 32, 9, "write dep");
  correctOrder(3, 1.f, 3.f, 32, 9, "write dep");
  correctOrder(4, 1.f, 3.f, 32, 9, "write dep");

}

template <>
void runner::verify_case<case_id::dim1_disjoint_correct_order>() {
  constexpr const unsigned expectedRuns = 8 * 5 * 2 * 3; // (tasks per case) * (# orders) * (fit,remain) * (truedep, antidep, writedep)
  constexpr const unsigned expectedRunsImplRO = 4 * 5 * 2 * 2; // (tasks per case) * (# orders) * (fit,remain) * (truedep, antidep)
  constexpr const unsigned expectedRunsImplRW = 4 * 5 * 2 * 2 + 8 * 5 * 2 ;

  using namespace test;
  using namespace instr;
  validate_log(m_instrFn,
    expect<event::dep_solver::all_ready, amount::equal, expectedRuns>(),
    expect<event::dep_solver::not_ready, amount::equal, 0>(),
    expect<event::dep_execute::kernel_start, amount::equal, expectedRunsImplRO>("impl::ro_region"),
    expect<event::dep_execute::kernel_end, amount::equal, expectedRunsImplRO>("impl::ro_region"),
    expect<event::dep_execute::kernel_start, amount::equal, expectedRunsImplRW>("impl::rw_region"),
    expect<event::dep_execute::kernel_end, amount::equal, expectedRunsImplRW>("impl::rw_region"),
    expect<event::dep_release::publish_start, amount::equal, expectedRuns>(),
    expect<event::dep_release::publish_end, amount::equal, expectedRuns>(),
    expect<event::dep_release::publish_error_start, amount::equal, 0>(),
    expect<event::dep_release::publish_error_end, amount::equal, 0>()
  );
}


////////////////////////////////////////////////




} // namespace test
