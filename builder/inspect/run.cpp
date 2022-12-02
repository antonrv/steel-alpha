#include "inspect/inspector.hpp"


// #include "source/object/data/use.hpp"
// #include "source/object/data/decl.hpp"

#include "files/paths/decl.hpp"

#include "options/interface.hpp"
#include "options/state/log.hpp"

#include "driver/interface.hpp"

#include "common/util.hpp"


namespace bld {


static
std::vector<state::filename> capture_filenames( const options * opt ) {

  if (state::options::is_set<opt_kind::app>()) {

    return opt->get_input_filenames();

  } else if (state::options::is_set<opt_kind::runtime_test>()) {

    // Cannot do this, otherwise it will try to inspect c++20 code, which is temporarily not allowed
    // return state::paths<key_path::steel_runtime_test_case>::get_filenames<path_scan::recurse>();

    return {state::filename(key_path::steel_runtime_test_case, "source.cpp", path_require::exist)};

  } else {
    return std::vector<state::filename>();
  }
}


template <>
void run<step::inspect>( const options * opt ) {

  opt->reset_state();

  auto sources = capture_filenames( opt );

  if (sources.empty()) {
    throw std::runtime_error("No files to inpsect");
  }

  state::log<opt_kind::log_steps>("Running", step::inspect, "on", sources.size(), "sources");

  inspector inspectorInstance(sources);
  inspectorInstance.run();

}


} // namespace bld
