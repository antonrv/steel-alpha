#ifndef STEEL_COMPILER_ELEMENT_MODULE_HPP
#define STEEL_COMPILER_ELEMENT_MODULE_HPP

#include "files/typedef.hpp"
#include "files/felement/compare_def.hpp"

#include "files/traits/interface.hpp"
#include "files/semantic/interface.hpp"

#include "files/felement/decl.hpp"

namespace bld {

template <file_kind FK, code CodK>
class felement;


class module { 
public:
  static constexpr bool is_derived = false;
private:


  // We could incorporate here pointers to parent/child modules
  // We could incorporate here info to build or not a library for this module  TODO LINKLIB

  const std::string m_identifier;

  // file_t<file_kind::compilable, code::interface> m_ifmodulePtr = nullptr;
  cfile_t<file_kind::compilable, code::interface> m_ifmodulePtr = nullptr;

  // set_file_t<file_kind::compilable, code::implementation> m_implementations;
  set_cfile_t<file_kind::compilable, code::implementation> m_implementations;
public:

  module(const std::string& id);
  ~module();

  const std::string& get_identifier() const;

  void set_interface(cfile_t<file_kind::compilable, code::interface> ifPtr);
  void add_new_implementation(cfile_t<file_kind::compilable, code::implementation> imPtr);

  cfile_t<file_kind::compilable, code::interface> get_interface() const;
  // file_t<file_kind::compilable, code::interface> edit_interface() const;

  set_cfile_t<file_kind::compilable, code::implementation> get_implementations() const;

  // set_file_t<file_kind::compilable, code::implementation> edit_implementations() const;

  bool is_cpp_std () const;

};

} // namespace bld


#endif // STEEL_COMPILER_ELEMENT_MODULE_HPP
