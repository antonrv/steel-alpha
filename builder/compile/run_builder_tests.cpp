
#include "options/interface.hpp"

#include "driver/interface.hpp"

namespace bld {

template <>
void run_builder_tests<step::compile>( const options * opt ) {
  // No tests
}

} // namespace bld
