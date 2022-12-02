#ifndef STEEL_COMPILER_ELEMENT_AUTOGEN_TRAITS_HPP
#define STEEL_COMPILER_ELEMENT_AUTOGEN_TRAITS_HPP

#include "files/enum.hpp"
#include "files/paths/enum.hpp"

namespace bld {

class modifiable_file;

// Traits of file kinds
template <file_kind FK>
struct ftraits;


template <>
struct ftraits<file_kind::autogen> {
  using base_type = modifiable_file;
  static constexpr bool base_type_overridable = false;
  static constexpr file_kind yield = file_kind::compilable; // via scan deps instr
  // static constexpr key_path keyPath = key_path::build_autogen; 
  // // static constexpr ext prefix_extension = ext::autogen;
};

} // namespace bld
#endif // STEEL_COMPILER_ELEMENT_AUTOGEN_TRAITS_HPP
