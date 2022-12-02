#ifndef STEEL_COMPILER_REGISTER_YIELD_DECL_HPP
#define STEEL_COMPILER_REGISTER_YIELD_DECL_HPP

#include "files/enum.hpp"

namespace bld::state {

template <file_kind FK, code CodK>
typename felement<FK, CodK>::yield_ptr_type 
register_yield(filename fn);

template <file_kind FK>
fileb_t register_yield_coarse(filename fn);

} // namespace bld::state

#endif // STEEL_COMPILER_REGISTER_YIELD_DECL_HPP
