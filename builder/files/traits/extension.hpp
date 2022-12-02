#ifndef STEEL_COMPILER_FILE_EXTENSION_TRAITS_HPP
#define STEEL_COMPILER_FILE_EXTENSION_TRAITS_HPP

#include "files/enum.hpp"

namespace bld {

template <ext E>
struct etraits;

// Source extensions
template <> struct etraits<ext::implementation> {
  static constexpr bool is_suffix = true;
  static constexpr const char * value = ".cpp";
};
template <> struct etraits<ext::entry> {
  static constexpr bool is_suffix = true;
  static constexpr const char * value = ".cxx"; 
};
template <> struct etraits<ext::header> { 
  static constexpr bool is_suffix = true;
  static constexpr const char * value = ".hpp"; 
};
template <> struct etraits<ext::module_interface> { 
  static constexpr bool is_suffix = true;
  static constexpr const char * value = ".cppm"; 
};
// Object 
template <> struct etraits<ext::module_precompiled> { 
  static constexpr bool is_suffix = true;
  static constexpr const char * value = ".pcm"; 
};
template <> struct etraits<ext::object> { 
  static constexpr bool is_suffix = true;
  static constexpr const char * value = ".o"; 
};
template <> struct etraits<ext::executable> { 
  static constexpr bool is_suffix = true;
  static constexpr const char * value = ".rn"; 
};
// Steel-dependent infixes
template <> struct etraits<ext::sgraph> { 
  static constexpr bool is_suffix = false;
  static constexpr const char * value = ".sg"; 
};
template <> struct etraits<ext::translation> { 
  static constexpr bool is_suffix = false;
  static constexpr const char * value = ".tr"; 
};
template <> struct etraits<ext::autogen> { 
  static constexpr bool is_suffix = false;
  static constexpr const char * value = ".ag"; 
};
template <> struct etraits<ext::undefined> { 
  static constexpr bool is_suffix = false;
  static constexpr const char * value = ".undef"; 
};
template <> struct etraits<ext::any> { 
  static constexpr bool is_suffix = false;
  static constexpr const char * value = ""; 
};
template <> struct etraits<ext::none> { 
  static constexpr bool is_suffix = false;
  static constexpr const char * value = ""; 
};


} // namespace bld

#endif // STEEL_COMPILER_FILE_EXTENSION_TRAITS_HPP
