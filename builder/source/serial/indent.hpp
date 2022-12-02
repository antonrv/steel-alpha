
#include <string>

namespace bld::src {

class indent_raii {
private:
  static unsigned IndentLevel;
public:
  indent_raii();
  ~indent_raii();

  // unsigned get_indent() const;
  static std::string get_ind_str();
  static std::string get_nl_ind_str();
  static std::string get_nl_str();
};


} // namespace bld::src 
