#ifndef UNDEF_DECL_HPP_HPP
#define UNDEF_DECL_HPP_HPP


#include "source/token/terminal/terminal.hpp"

namespace bld::src::pc {

class loop_var;

template <>
class token<kind::undefined> : public terminal {
private:

  std::string m_name;

public:

  token();

  token(const std::string& is);

  token(const token& other) = default;

  kind get_kind() const final override;

  bool is_arith() const final override;
  bool is_rt() const final override;

  virtual std::string get_pc_string() const override;
};


} // namespace bld::src::pc

#endif // UNDEF_DECL_HPP_HPP
