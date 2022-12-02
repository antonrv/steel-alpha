#ifndef STEEL_COMPILER_ELEMENT_UNDEFINED_TRAITS_HPP
#define STEEL_COMPILER_ELEMENT_UNDEFINED_TRAITS_HPP

#include "files/enum.hpp"
#include "files/paths/enum.hpp"


namespace bld {

class undefined_file;

// Traits of file kinds
template <file_kind FK>
struct ftraits;

template <>
struct ftraits<file_kind::undefined> {
  using base_type = undefined_file;
  static constexpr file_kind yield = file_kind::undefined;
};

} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_UNDEFINED_TRAITS_HPP
