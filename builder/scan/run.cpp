#include "scan/lexer_def.hpp"

#include "driver/interface.hpp"

#include "files/interface.hpp"

#include "options/interface.hpp"
#include "options/state/log.hpp"



namespace bld {

template <key_path KP, path_scan PS, file_kind FK>
static
void record_scanable_sources() {

  auto fnVec = state::paths<KP>::template get_filenames<PS>();

  for (auto& fn : fnVec) {
    state::files<FK>::record_filename(fn);
  }
}


template <key_path... KPs>
void record_runtime_sources( std::integer_sequence< key_path, KPs...> ) {

  ( record_scanable_sources<KPs, path_scan::recurse, file_kind::runtime>(), ... );
}

using rt_modules_seq_t = std::integer_sequence<key_path, key_path::steel_runtime_modules_ctxt, key_path::steel_runtime_modules_dep, key_path::steel_runtime_modules_instrument, key_path::steel_runtime_modules_policy, key_path::steel_runtime_modules_safe, key_path::steel_runtime_modules_task, key_path::steel_runtime_modules_util, key_path::steel_runtime_modules_work, key_path::steel_runtime_instrument, key_path::steel_runtime_include>;


template <>
void run<step::scan>( const options * opt ) {

  state::log<opt_kind::log_steps>("Running", step::scan);

  scan_lexer lexerInstance;

  state::log<opt_kind::log_scan>("Scanning autogen sources...");
  lexerInstance.run_all<file_kind::autogen, code::interface>();
  lexerInstance.run_all<file_kind::autogen, code::implementation>();
  lexerInstance.run_all<file_kind::autogen, code::entry>();

  // Record sources of runtime modules
  record_runtime_sources( rt_modules_seq_t{} );

  if (state::options::is_set<opt_kind::runtime_test>()) { 
    // Register run_cases.cpp. Don't scan steel_runtime_test_case bc we don't want to scan source.cpp
    state::files<file_kind::runtime>::record_filename( state::filename(key_path::steel_runtime_test_case, "run_cases.cpp", path_require::exist) );

    // Record backbone runtime testing files
    record_scanable_sources<key_path::steel_runtime_test, path_scan::flat, file_kind::runtime>();
  }

  if (state::options::is_set<opt_kind::plat>()) {
    record_scanable_sources<key_path::build_plat_autogen, path_scan::flat, file_kind::autogen>();
  }

  state::log<opt_kind::log_scan>("Scanning runtime sources...");
  lexerInstance.run_all<file_kind::runtime, code::interface>();
  lexerInstance.run_all<file_kind::runtime, code::implementation>();
  lexerInstance.run_all<file_kind::runtime, code::entry>();

  state::log<opt_kind::log_scan>("Scanning translation sources...");
  lexerInstance.run_all<file_kind::translation, code::interface>();
  lexerInstance.run_all<file_kind::translation, code::implementation>();
  lexerInstance.run_all<file_kind::translation, code::entry>();
}

} // namespace bld
