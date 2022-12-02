
module RunTestCases;

import App.Proxy;

import SteelRT.Dep.Wrap.Region;
import SteelRT.Dep;

import SteelRT.Task.Descriptor;
import SteelRT.Task.Dispatcher;

import SteelRT.Work.Descriptor.Global;
import SteelRT.Work.Descriptor.Local;

import SteelRT.Test;

#include <assert.h>

const depth_t d = 0;

namespace ctxt {

template <typename ImplSelectorT, template <app::impl...> class DescContainerT, app::impl... Impls>
using active = test::mock_ctxt::with_selector_queue<ImplSelectorT, DescContainerT, Impls...>;

} // namespace ctxt


namespace test {

template <>
void runner::run_case<case_id::dim1_basic>() {

  using selector_t = policy::selector::implementation<policy::pick_implement::single>;
  selector_t singleSel;
  ctxt::active<selector_t, workload::desc::global_container, app::impl::caller, app::impl::foo> ctxtRef(singleSel);

  unsigned nElem = 32;
  unsigned nElemPerBlock = 8;

  {
    std::unique_ptr<float[]> dataUPtr{ new float[nElem] };

    auto wd = dep::wrap_mesh<1>(dataUPtr.get(), {nElem}, {nElemPerBlock}, {0, nElem});

    auto rw1stTask1 = task::make_async<app::call::caller_fooapp_0>( d, wd.emit_bnd_writer(0), nElemPerBlock );
    ctxtRef.operate( std::move(rw1stTask1) );

    auto rw1stTask2 = task::make_async<app::call::caller_fooapp_0>( d, wd.emit_bnd_writer(1), nElemPerBlock );
    ctxtRef.operate( std::move(rw1stTask2) );

    auto rw1stTask3 = task::make_async<app::call::caller_fooapp_0>( d, wd.emit_bnd_writer(2), nElemPerBlock );
    ctxtRef.operate( std::move(rw1stTask3) );

    auto rw1stTask4 = task::make_async<app::call::caller_fooapp_0>( d, wd.emit_bnd_writer(3), nElemPerBlock );
    ctxtRef.operate( std::move(rw1stTask4) );

    // safe::check_throw(wd.is_destroyable(), "Guard not destroyable");

    std::vector<float> refVec(nElem, 13);
    std::vector<float> gotVec(nElem, 0);

    for (auto i = 0; i < nElem; i++) { gotVec[i] = dataUPtr[i]; }

    if (refVec != gotVec) {
      std::string errStr;
      for (auto i = 0; i < nElem; i++) { errStr += std::to_string(gotVec[i]) + ","; }
      safe::check_throw(refVec == gotVec, "Vectors not equal : Got " + errStr);
    }

  }

}

template <>
void runner::verify_case<case_id::dim1_basic>() {

}


} // namespace test
