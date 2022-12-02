#include "generate/gen_kind_enum.hpp"
#include "generate/generator.hpp"

#include "source/object/function/definition.hpp"
#include "source/object/state/def.hpp"

#include "options/state/decl.hpp"
#include "options/state/log.hpp"

#include "driver/interface.hpp"

namespace bld {

// XXX PUT SOME ORDER HERE
// XXX PUT SOME ORDER HERE
// XXX PUT SOME ORDER HERE
// XXX PUT SOME ORDER HERE
// XXX PUT SOME ORDER HERE
// XXX PUT SOME ORDER HERE
// XXX PUT SOME ORDER HERE

template <>
void run<step::generate>( const options * opt ) {


  generator genInstance;

  src::vec_ctask_t allTasks;

  auto fDefsAsTasks = src::state<src::obj::fun_def>::get_all_satisfying(
        [] (const auto& fDef) {
          return fDef->is_task();
        }
      );

  allTasks = transform_vec( fDefsAsTasks, [] (src::cso_t<src::obj::fun_def> fDef) { return fDef->get_task(); } );

  auto callsToTask = src::state<src::obj::fun_call>::get_all_satisfying(
        [] (const auto& fCall) {
          return fCall->get_callee()->is_task();
        }
      );

  genInstance.set_kernel_elements( allTasks, callsToTask );

  state::log<opt_kind::log_steps>("Running", step::generate, "on", allTasks.size(),"tasks and",callsToTask.size(),"calls");


  // App-dependent generations
  if (state::options::is_set<opt_kind::app>()) {


    // We create a virtual file with the name of the app, just to provide following functions a name for the generation files.
    state::filename entryAppFn( key_path::undefined, state::options::get_value<opt_kind::app>(), path_require::none );


    // Will generate App.Enum module interface
    genInstance.template run<gen_kind::app_enum>(key_path::build_app_autogen, entryAppFn);

    // Will generate App.Graph module interface
    genInstance.template run<gen_kind::app_graph>(key_path::build_app_autogen, entryAppFn);
 
    // Will generate App.Proxy module interface
    genInstance.template run<gen_kind::app_proxy>(key_path::build_app_autogen, entryAppFn);

  }

  if (state::options::is_set<opt_kind::runtime_test>()) {
    // throw std::runtime_error("Implement generation for runtime_test");

    auto casesFn = state::filename(key_path::steel_runtime_test_case, "cases.dat", path_require::exist);

    // Will generate RunTestCases module interface
    genInstance.template run<gen_kind::runtime_test>(key_path::build_runtime_test_case_autogen, casesFn);

    auto srcFn = state::filename(key_path::steel_runtime_test_case, "source.cpp", path_require::exist);

    // Will generate App.Enum module interface
    genInstance.template run<gen_kind::app_enum>(key_path::build_runtime_test_case_autogen, srcFn);

    // Will generate App.Graph module interface
    genInstance.template run<gen_kind::app_graph>(key_path::build_runtime_test_case_autogen, srcFn);
 
    // Will generate App.Proxy module interface
    genInstance.template run<gen_kind::app_proxy>(key_path::build_runtime_test_case_autogen, srcFn);

  //   // pass in scan stage TODO state::filename(key_path::steel_runtime_test_case, "run_cases.cpp", path_require::exist));
  //   // pass in scan stage TODO state::filename(key_path::steel_runtime_test_case, "source.cpp", path_require::exist));

  }


  if (state::options::is_set<opt_kind::app>() or state::options::is_set<opt_kind::runtime_test>()) {

    auto rtInstrumentEventsFn = state::filename(key_path::steel_runtime_instrument, "events.dat", path_require::exist);

    // Will generate SteelRT.Instrument.AllEvents module interface
    genInstance.template run<gen_kind::runtime_instrument>(key_path::build_runtime_gen, rtInstrumentEventsFn);
  }


  if (state::options::is_set<opt_kind::plat>()) { // -plat=hp_envy

    state::filename entryPlatFn( key_path::undefined, state::options::get_value<opt_kind::plat>(), path_require::none );

    genInstance.template run<gen_kind::plat_enum>(key_path::build_plat_autogen, entryPlatFn);

    // genInstance.template run<gen_kind::plat_graph>(key_path::build_plat_autogen, entryPlatFn); TODO
    
  }

  
  // if (state::options::is_set<opt_kind::runtime_test>()) {

  //   auto casesFn = state::filename(key_path::steel_runtime_test_case, "cases.dat", path_require::exist);
  //   // genInstance.set_rt_test_cases( casesFn );

  //   genInstance.set_kernel_elements( allTasks, src::state<src::obj::fun_call>::get_all());

  //   // pass in scan stage TODO state::filename(key_path::steel_runtime_test_case, "run_cases.cpp", path_require::exist));
  //   // pass in scan stage TODO state::filename(key_path::steel_runtime_test_case, "source.cpp", path_require::exist));
  //   auto srcFn = state::filename(key_path::steel_runtime_test_case, "source.cpp", path_require::exist);

  //   // Will generate TestCases module interface
  //   // Will generate RunTestCases module interface
  //   genInstance.template run<gen_kind::runtime_test>(key_path::build_runtime_test_case_autogen, casesFn);

  //   // Will generate App.Enum module interface
  //   genInstance.template run<gen_kind::app_enum>(key_path::build_runtime_test_case_autogen, srcFn);

  //   // Will generate App.Graph module interface
  //   genInstance.template run<gen_kind::app_graph>(key_path::build_runtime_test_case_autogen, srcFn);
 
  //   // Will generate App.Proxy module interface
  //   genInstance.template run<gen_kind::app_proxy>(key_path::build_runtime_test_case_autogen, srcFn);
  // }

  // if (state::options::is_set<opt_kind::app>() or state::options::is_set<opt_kind::runtime_test>()) {

  //   auto rtInstrumentEventsFn = state::filename(key_path::steel_runtime_instrument, "events.dat", path_require::exist);

  //   // genInstance.set_rt_instrument_filename(rtInstrumentEventsFn);

  //   // Will generate SteelRT.Instrument.AllEvents module interface
  //   genInstance.template run<gen_kind::runtime_instrument>(key_path::build_runtime_gen, rtInstrumentEventsFn);
  // }

}


} // namespace bld
