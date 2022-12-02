

#include "common/test/run.hpp"
#include "common/test/compare.hpp"

#include "common/aux.hpp"

#include "files/interface.hpp"
#include "files/paths/decl.hpp"
#include "options/state/decl.hpp"
#include "options/state/log.hpp"

#include <vector>
#include <iostream>

namespace bld::test {

static
std::pair<
  std::vector< state::filename >,
  key_path
>
enable_paths_and_get_sources( const std::string& testSuiteStr, step stepVal ) {

  state::options::set_value<opt_kind::builder_test>( testSuiteStr );

  auto sourceFiles = state::paths<key_path::steel_builder_test_suite>::get_filenames<path_scan::flat>();

  if (sourceFiles.empty()) {
    throw std::runtime_error("Could not run_suite " + testSuiteStr + ". Not source files in " + state::paths<key_path::steel_builder_test_suite>::get_path());
  }

  if (stepVal == step::inspect) {

    return std::make_pair( sourceFiles, key_path::steel_builder_test_suite_ref_inspect );

  } else if (stepVal == step::translate) {

    return std::make_pair( sourceFiles, key_path::steel_builder_test_suite_ref_translate );

  } else if (stepVal == step::generate) {

    return std::make_pair( sourceFiles, key_path::steel_builder_test_suite_ref_autogen );

  } else {
    throw std::logic_error("Could not run_suite for step " + std::string(util::enum_convert<step>::to_string_rt(stepVal)));
  }
}


template <suite Suite>
void run_suite( std::vector<std::string>& enabledSuites, run_src_t testFun, step stepVal ) {

  std::string testSuiteStr = util::enum_convert<suite>::to_string<Suite>();

  auto foundIt = std::find( std::begin(enabledSuites), std::end(enabledSuites), testSuiteStr );

  if (foundIt == std::end(enabledSuites) and enabledSuites.front() != "all") {
    // Skip. This test suite not enabled
    return;
  }

  auto [sourceFiles, refPath] = enable_paths_and_get_sources( testSuiteStr, stepVal );

  for (auto origFn : sourceFiles) {

    set_cfileb_t yieldFiles;

    try {

      yieldFiles = testFun( origFn );

    } catch ( ... ) {
      std::cerr << "Got error while running test " << stepVal << " on case " << Suite << " on : " << origFn.get_full_name() << '\n';
      throw;
    }

    for (auto yieldFile : yieldFiles) {

      auto testResult = compare_files(
          yieldFile->get_filename(),
          state::filename( refPath, yieldFile->get_filename().get_tail(), path_require::exist ),
          Suite,
          stepVal
        );

      state::log_if<opt_kind::builder_test>(testSuiteStr, testResult );
    }


  }


  if (foundIt != std::end(enabledSuites)) {
    // Pointing to non-all
    enabledSuites.erase( foundIt );
  }
}


template <suite... Suites>
void run_all_suites( std::vector<std::string>& enabledSuites, run_src_t testFun, step stepVal, std::integer_sequence<suite, Suites...> ) {

  ( run_suite<Suites>( enabledSuites, testFun, stepVal ), ... );
}


///////////////
//
// INTERFACE
//
///////////////
void run_on_suites( run_src_t testFun, step stepVal ) {

  auto buildTestOpt = state::options::get_value<opt_kind::builder_test>();

  std::vector<std::string> enabledSuites = split_string( buildTestOpt, ',' );

  if (buildTestOpt.empty()) {
    throw std::runtime_error("Cannot run_on_suites. 'Set builder_test'");
  }

  if (std::find(std::begin(enabledSuites), std::end(enabledSuites), "all") != std::end(enabledSuites) and enabledSuites.size() > 1) {
    throw std::runtime_error("Cannot run_on_suites. 'all' must appear alone");
  }


  run_all_suites( enabledSuites, testFun, stepVal, enabled::Sequence_suite{} );


  if (not enabledSuites.empty()) {

    std::string errStr;
    for (auto suiteNotRun : enabledSuites) {
      if (suiteNotRun != "all") {
        errStr += "Builder test suite not run : " + suiteNotRun + '\n';
      }
    }
    if (not errStr.empty()) {
      throw std::runtime_error("Could not run all build test suites :\n" + errStr);
    }

  } else {
    // OK. All run
  }
}


} // namespace bld::test
