

#include "files/module/decl.hpp"


namespace bld {

module::module(const std::string& id) : m_identifier(id) {}

module::~module() {}

const std::string& module::get_identifier() const {
  return m_identifier;
}

void module::set_interface(cfile_t<file_kind::compilable, code::interface> ifPtr) {
  m_ifmodulePtr = ifPtr;
}

void module::add_new_implementation(cfile_t<file_kind::compilable, code::implementation> imPtr) {
  m_implementations.insert( imPtr );
}

cfile_t<file_kind::compilable, code::interface>
module::get_interface() const {
  return m_ifmodulePtr;
}

// file_t<file_kind::compilable, code::interface>
// module::edit_interface() const {
//   return m_ifmodulePtr;
// }

set_cfile_t<file_kind::compilable, code::implementation>
module::get_implementations() const {
  set_cfile_t<file_kind::compilable, code::implementation> retSet;
  for (auto impl : m_implementations) {
    retSet.insert( impl );
  }
  return retSet;
}

// set_file_t<file_kind::compilable, code::implementation>
// module::edit_implementations() const {
//   return m_implementations;
// }

bool module::is_cpp_std () const {
  return get_identifier().front() == '<' && get_identifier().back() == '>'; 
}

bool compare_modules::operator()(cmodule_t ma, cmodule_t mb) const {
  return ma->get_identifier() < mb->get_identifier();
}

bool compare_own_modules::operator()(const own_module_t& ma, const own_module_t& mb) const {
  return ma->get_identifier() < mb->get_identifier();
}

} // namespace bld
