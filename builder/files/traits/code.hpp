#ifndef STEEL_COMPILER_ENUM_TRAITS_HPP
#define STEEL_COMPILER_ENUM_TRAITS_HPP

#include "files/enum.hpp"
#include "files/paths/enum.hpp"

#include "files/paths/dir.hpp"

namespace bld {

class scanable_file;
class dependent_file;
class bitcode_file;
class target_file;

class undefined_file;

// =========== Properties of CODE kinds ('code elements' or 'ctraitss')
template <code CodK>
struct ctraits;

// Readable kinds
template <>
struct ctraits<code::interface> {
  using base_type = undefined_file;
  static constexpr bool base_type_overrides = false;
  static constexpr file_kind yield = file_kind::undefined; // interfaces remain the same
  // static constexpr key_path keyPath = key_path::build_pcm;
  static constexpr ext source_extension = ext::module_interface;
  static constexpr ext compile_extension = ext::module_precompiled;
};

template <>
struct ctraits<code::implementation> {
  using base_type = undefined_file;
  static constexpr bool base_type_overrides = false;
  static constexpr file_kind yield = file_kind::undefined; // implementations remain the same
  // static constexpr key_path keyPath = key_path::build_obj;
  static constexpr ext source_extension = ext::implementation;
  static constexpr ext compile_extension = ext::object;
};

template <>
struct ctraits<code::entry> {
  // felement< FK, entry > derives from target_file if file_kind<>::base_type_overridable
  using base_type = target_file; 
  static constexpr bool base_type_overrides = true;
  // entries map to executables if file_kind<>::yield is undefined
  static constexpr file_kind yield = file_kind::executable; 
  // static constexpr key_path keyPath = key_path::build_obj;
  static constexpr ext source_extension = ext::entry;
  static constexpr ext compile_extension = ext::object;
};

// public interface
code source_extension_to_code(const std::string& fnExt);

} // namespace bld

#endif // STEEL_COMPILER_ENUM_TRAITS_HPP
