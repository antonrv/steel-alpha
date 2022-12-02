#include "common/inject/syntax_str.hpp"

namespace bld::syn {

str::str() : m_str() {}
str::str(const char* in) : m_str(in) {}
str::str(std::string&& in) : m_str(in) {}
str::str(const std::string& in) : m_str(in) {}
const std::string& str::inner() const { return m_str; }
bool str::empty() const { return m_str.empty(); }

endl::endl() {}
comment::comment() {}
return_as_param::return_as_param() {}
aware_type::aware_type() {}
aware_raii::aware_raii() {}

task_attr_desc_ref::task_attr_desc_ref() {}
task_attr_desc_obj::task_attr_desc_obj() {}

nms_app::nms_app() {}

} // namespace bld::syn

std::ostream& operator<<(std::ostream& os, const bld::syn::str& inNode ) {
  os << inNode.inner();
  return os;
}

std::ostream& operator<<(std::ostream& os, bld::syn::endl&& ) {
  os << "\n";
  return os;
}

std::ostream& operator<<(std::ostream& os, bld::syn::comment&& ) {
  os << "// ";
  return os;
}

std::ostream& operator<<(std::ostream& os, bld::syn::return_as_param&&  ) {
  os << "SI_retParam";
  return os;
}

std::ostream& operator<<(std::ostream& os, const bld::syn::return_as_param&  ) {
  os << "SI_retParam";
  return os;
}

std::ostream& operator<<(std::ostream& os, bld::syn::aware_type&&  ) {
  os << "aware";
  return os;
}

std::ostream& operator<<(std::ostream& os, const bld::syn::aware_type&  ) {
  os << "aware";
  return os;
}

std::ostream& operator<<(std::ostream& os, bld::syn::aware_raii&&  ) {
  os << "raiiInstr";
  return os;
}

std::ostream& operator<<(std::ostream& os, const bld::syn::aware_raii&  ) {
  os << "raiiInstr";
  return os;
}

std::ostream& operator<<(std::ostream& os, const bld::syn::task_attr_desc_ref&  ) {
  os << "task::attr::descriptor& ";
  return os;
}

std::ostream& operator<<(std::ostream& os, const bld::syn::task_attr_desc_obj&  ) {
  os << "attrDesc";
  return os;
}

std::ostream& operator<<(std::ostream& os, const bld::syn::depwrap& inNode ) {
  if (inNode.first().empty()) {
    os << "dep::wrap(" << inNode.second() << ")";
  } else {
    os << "dep::wrap<" << inNode.first() << ">(" << inNode.second() << ")";
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const bld::syn::nms_app& inNode ) {
  os << "export\nnamespace app";
  return os;
}

