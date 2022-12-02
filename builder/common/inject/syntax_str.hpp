#ifndef STEEL_COMPILER_COMMON_INJECT_SYNTAX_STR_HPP
#define STEEL_COMPILER_COMMON_INJECT_SYNTAX_STR_HPP

#include <string>
#include <ostream>

namespace bld::syn {

class str {
private:
  const std::string m_str;
public:
  explicit str();
  explicit str(const char* in);
  explicit str(std::string&& in);
  explicit str(const std::string& in);
  explicit str(str&&) = default;
  const std::string& inner() const;
  bool empty() const;
};


class endl { public: endl(); };
class comment { public: comment(); };
class return_as_param { public: return_as_param(); };
class aware_type { public: aware_type(); };
class aware_raii { public: aware_raii(); };

class task_attr_desc_ref { public: task_attr_desc_ref(); };
class task_attr_desc_obj { public: task_attr_desc_obj(); };

class depwrap {
  str m_first;
  str m_second;
public:
  explicit depwrap(str&& in2) : m_first(), m_second(std::move(in2)) {}
  explicit depwrap(str&& in1, str&& in2) : m_first(std::move(in1)), m_second(std::move(in2)) {}
  const str& first() const { return m_first; }
  const str& second() const { return m_second; }
};

class nms_app { public: nms_app(); };

} // namespace bld::syn

std::ostream& operator<<(std::ostream& os, const bld::syn::str& inNode );

std::ostream& operator<<(std::ostream& os, bld::syn::endl&& );

std::ostream& operator<<(std::ostream& os, bld::syn::comment&& );

std::ostream& operator<<(std::ostream& os, bld::syn::return_as_param&& );
std::ostream& operator<<(std::ostream& os, const bld::syn::return_as_param& );

std::ostream& operator<<(std::ostream& os, bld::syn::aware_type&& );
std::ostream& operator<<(std::ostream& os, const bld::syn::aware_type& );

std::ostream& operator<<(std::ostream& os, bld::syn::aware_raii&& );
std::ostream& operator<<(std::ostream& os, const bld::syn::aware_raii& );

std::ostream& operator<<(std::ostream& os, const bld::syn::task_attr_desc_ref& );
std::ostream& operator<<(std::ostream& os, const bld::syn::task_attr_desc_obj& );

std::ostream& operator<<(std::ostream& os, const bld::syn::depwrap& inNode );

std::ostream& operator<<(std::ostream& os, const bld::syn::nms_app& inNode );

#endif // STEEL_COMPILER_COMMON_INJECT_SYNTAX_STR_HPP
