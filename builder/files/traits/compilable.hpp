#ifndef STEEL_COMPILER_ELEMENT_COMPILABLE_TRAITS_HPP
#define STEEL_COMPILER_ELEMENT_COMPILABLE_TRAITS_HPP

#include "files/enum.hpp"
#include "files/paths/enum.hpp"

namespace bld {

class dependent_file;

// Traits of file kinds
template <file_kind FK>
struct ftraits;

template <>
struct ftraits<file_kind::compilable> {
  using base_type = dependent_file; 
  static constexpr bool base_type_overridable = false;
  static constexpr file_kind yield = file_kind::compiled; 
  // static constexpr key_path keyPath = key_path::inherited;
  // // static constexpr ext prefix_extension = ext::none; 
};

} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_COMPILABLE_TRAITS_HPP
