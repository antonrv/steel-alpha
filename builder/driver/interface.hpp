#ifndef STEEL_COMPILER_INTERFACE_HPP
#define STEEL_COMPILER_INTERFACE_HPP

#include "common/step_enum.hpp"

namespace bld {

class options;

template <step S>
void run( const options * );

template <step S>
void run_builder_tests( const options * );

} // namespace bld

#endif // STEEL_COMPILER_INTERFACE_HPP
