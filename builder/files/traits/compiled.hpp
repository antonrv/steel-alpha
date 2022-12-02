#ifndef STEEL_COMPILER_ELEMENT_COMPILED_TRAITS_HPP
#define STEEL_COMPILER_ELEMENT_COMPILED_TRAITS_HPP

#include "files/enum.hpp"
#include "files/paths/enum.hpp"


namespace bld {

class bitcode_file;

// Traits of file kinds
template <file_kind FK>
struct ftraits;

template <>
struct ftraits<file_kind::compiled> {
  using base_type = bitcode_file; 
  static constexpr bool base_type_overridable = true;
  static constexpr file_kind yield = file_kind::undefined;
  // static constexpr key_path keyPath = key_path::undefined;
  // // static constexpr ext prefix_extension = ext::none;
};

} // namespace bld
#endif // STEEL_COMPILER_ELEMENT_COMPILED_TRAITS_HPP
