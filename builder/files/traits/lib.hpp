#ifndef STEEL_COMPILER_ELEMENT_LIB_TRAITS_HPP
#define STEEL_COMPILER_ELEMENT_LIB_TRAITS_HPP

#include "files/enum.hpp"
#include "files/paths/enum.hpp"

namespace bld {

class final_file;

// Traits of file kinds
template <file_kind FK>
struct ftraits;

template <>
struct ftraits<file_kind::dyn_lib> {
  using base_type = final_file; 
  static constexpr bool base_type_overridable = false;
  static constexpr file_kind yield = file_kind::undefined; // yield nothing
  // static constexpr key_path keyPath = key_path::build_lib;
  // // static constexpr ext prefix_extension = ext::dyn_lib;
};

} // namespace bld
#endif // STEEL_COMPILER_ELEMENT_LIB_TRAITS_HPP
