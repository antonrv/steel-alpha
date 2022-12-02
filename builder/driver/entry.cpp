

#include "driver/interface.hpp"

#include "options/interface.hpp"

#include <stdexcept>
#include <iostream>
#include <memory>

using namespace bld;



template <step... Steps>
void process_n_run_all( const options * opts, std::integer_sequence<step, Steps...> ) {

  ( run<Steps>( opts ), ... );
}

template <step... Steps>
void process_n_run_all_tests( const options * opts, std::integer_sequence<step, Steps...> ) {
  ( run_builder_tests<Steps>( opts ), ... );
}

// Requires -DINPUT_STEPS=inspect,translate ... etc to compile
ENABLE_SEQUENCE(bld, step, INPUT_STEPS)

int main(int argc, const char** argv) {

  std::unique_ptr<options> opts;

  try {
 
    opts = std::make_unique<options>( argc, argv );

    if (state::options::is_set<opt_kind::builder_test>()) {

      process_n_run_all_tests( opts.get(), enabled::Sequence_step{} );

    } else if (state::options::is_set<opt_kind::app>() or
        state::options::is_set<opt_kind::runtime_test>()) {

      process_n_run_all( opts.get(), enabled::Sequence_step{} );
    } else {
      std::cerr << "Not run.\n";
    }


  } catch (const std::runtime_error& rte) {
    std::cerr << ":::Driver. Runtime error caught : " << rte.what() << " V\n" << (opts ? opts->get_parsed_info() : "")<< '\n';
  } catch (const std::logic_error& le) {
    std::cerr << ":::Driver. Logic error caught : " << le.what() << " V\n" << (opts ? opts->get_parsed_info() : "") << '\n';
  } catch (const std::exception& e) {
    std::cerr << ":::Driver. Generic error caught : " << e.what() << " V\n" << (opts ? opts->get_parsed_info() : "") << '\n';
  } catch (...) {
    std::cerr << ":::Driver. Unknown error caught.\n" << (opts ? opts->get_parsed_info() : "") << '\n';
  }
  
  return 0;
}
