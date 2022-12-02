#ifndef OPERATION_COMPARE_HPP
#define OPERATION_COMPARE_HPP

#include "source/sequences.hpp"

namespace bld::src::pc {

class piece;

res try_pipeline( cpiece_t lhs, cpiece_t rhs, opkind opKind );

} // namespace bld::src::pc

#endif // OPERATION_COMPARE_HPP
