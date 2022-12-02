
#include "source/token/test/interface.hpp"

#include "options/interface.hpp"

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <iostream>

static
bool is_enabled(const std::vector<std::string>& opts, const char * optName) {
  auto foundLambda = [optName] (const std::string& str) { return str == optName or str == "all"; };
  return (std::find_if(std::begin(opts), std::end(opts), foundLambda) != std::end(opts));
}


static const char * testSuiteName = "token test";

namespace bld::src::pc {

template <token_test TT>
void run_case( const std::vector<std::string>& arguments ) {

  auto testCase = util::enum_convert<token_test>::to_string<TT>();

  try {

    if (is_enabled(arguments, testCase)) {
      run_tests<TT>();
      std::cerr << testSuiteName << " OK " << testCase << "\n";
    } else {
      std::cerr << testSuiteName << " SKIP " << testCase << "\n";
    }

  } catch (const std::runtime_error& rte) {

    std::cerr << testSuiteName << " FAIL " << testCase << "\n";
    std::cerr << "\tRuntime error : " << rte.what() << '\n';

  } catch (const std::logic_error& le) {

    std::cerr << testSuiteName << " FAIL " << testCase << "\n";
    std::cerr << "\tLogic error : " << le.what() << '\n';

  } catch (...) {

    std::cerr << testSuiteName << " FAIL " << testCase << "\n";
    std::cerr << "\tUnknown error caught\n";

    throw;
  }
}



template <token_test... TTs>
void run_all( const std::vector<std::string>& arguments, std::integer_sequence<token_test, TTs...> ) {

  ( run_case<TTs>( arguments ), ... );
}


template <token_test... TTs>
bool none_enabled(const std::vector<std::string>& initialArgs, std::integer_sequence<token_test, TTs...>) {

  return not (is_enabled( initialArgs, util::enum_convert<token_test>::to_string<TTs>() ) || ... );
}

} // namespace bld::src::pc


int main(int argc, const char ** argv) {

  try {

    std::vector<std::string> arguments(argv + 1, argv + argc);
    if (none_enabled(arguments, enabled::Sequence_token_test{})) { arguments.push_back("all"); }

    arguments.push_back("-parser-test");

    auto opts = std::make_unique<bld::options>( arguments );

    bld::src::pc::run_all( arguments, enabled::Sequence_token_test{} );

  } catch (const std::runtime_error& rte) {

    std::cerr << "\tRuntime error : " << rte.what() << '\n';

  } catch (const std::logic_error& le) {

    std::cerr << "\tLogic error : " << le.what() << '\n';

  } catch (...) {

    std::cerr << "\tUnknown error caught\n";
  }
}

