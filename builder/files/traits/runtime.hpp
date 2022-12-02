#ifndef STEEL_COMPILER_ELEMENT_RUNTIME_TRAITS_HPP
#define STEEL_COMPILER_ELEMENT_RUNTIME_TRAITS_HPP


#include "files/enum.hpp"
#include "files/paths/enum.hpp"

namespace bld {

class scanable_file;

// Traits of file kinds
template <file_kind FK>
struct ftraits;

// A runtime source is compilable (but not modifiable)
template <>
struct ftraits<file_kind::runtime> {
  using base_type = scanable_file;
  static constexpr bool base_type_overridable = false;
  static constexpr file_kind yield = file_kind::compilable; // via scan deps instr
  // static constexpr key_path keyPath = key_path::steel_runtime; 
  // // static constexpr ext prefix_extension = ext::any;
};
} // namespace bld
#endif // STEEL_COMPILER_ELEMENT_RUNTIME_TRAITS_HPP
