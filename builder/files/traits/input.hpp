#ifndef STEEL_COMPILER_ELEMENT_UDER_TRAITS_HPP
#define STEEL_COMPILER_ELEMENT_UDER_TRAITS_HPP

#include "files/enum.hpp"
#include "files/paths/enum.hpp"

namespace bld {

class inspectable_file;

// Traits of file kinds
template <file_kind FK>
struct ftraits;


// According to file_kind
template <>
struct ftraits<file_kind::input> {
  using base_type = inspectable_file;
  static constexpr bool base_type_overridable = false;
  static constexpr file_kind yield = file_kind::sgraph; // via translation instr
  // static constexpr key_path keyPath = key_path::undefined;
  // // static constexpr ext prefix_extension = ext::any;
};

} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_UDER_TRAITS_HPP
