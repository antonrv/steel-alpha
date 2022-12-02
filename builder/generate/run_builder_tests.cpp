
#include "generate/generator.hpp"

#include "files/interface.hpp"

#include "source/object/state/def.hpp"
#include "source/object/function/definition.hpp"
#include "source/object/function/task.hpp"
#include "source/object/function/call.hpp"

#include "options/interface.hpp"

#include "driver/interface.hpp"

#include "common/test/run.hpp"

namespace bld {

static
set_cfileb_t run_on_source(state::filename src) {


  // Pick only functions belonging to this source
  auto fDefsAsTasks = src::state<src::obj::fun_def>::get_all_satisfying(
        [src] (const auto& fDef) {
          return fDef->is_task() and fDef->get_source_filename() == src;
        }
      );

  auto allTasks = transform_vec( fDefsAsTasks, [] (src::cso_t<src::obj::fun_def> fDef) { return fDef->get_task(); } );

  // Pick only calls belonging to this source
  auto callsToTask = src::state<src::obj::fun_call>::get_all_satisfying(
        [src] (const auto& fCall) {
          return fCall->get_callee()->is_task() and fCall->get_source_filename() == src;
        }
      );

  generator genInstance;

  genInstance.set_kernel_elements( allTasks, callsToTask);


  set_cfileb_t retSet;

  // Will generate App.Enum module interface
  retSet.insert( genInstance.template run<gen_kind::app_enum>(key_path::build_builder_test_suite_autogen, src) );

  // Will generate App.Graph module interface
  retSet.insert( genInstance.template run<gen_kind::app_graph>(key_path::build_builder_test_suite_autogen, src) );
 
  // Will generate App.Proxy module interface
  retSet.insert( genInstance.template run<gen_kind::app_proxy>(key_path::build_builder_test_suite_autogen, src) );

  return retSet;
}


template <>
void run_builder_tests<step::generate>( const options * opt ) {

  opt->reset_state();

  test::run_on_suites( run_on_source, step::generate );
}

} // namespace bld
