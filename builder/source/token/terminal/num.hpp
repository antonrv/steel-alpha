#ifndef NUM_DECL_HPP_HPP
#define NUM_DECL_HPP_HPP


#include "source/token/terminal/terminal.hpp"

#include <memory>

namespace bld::src::pc {


own_token_t<kind::num> make_num(long n);

template <>
class token<kind::num> : public terminal {
public:

  static constexpr bool is_derived = false;

private:

  unsigned m_value = 0;

  void inner_simplify();

public:

  token(unsigned n, sign = sign::pos);


  token(const token& other);
  token(token&& other) = default;

  kind get_kind() const final override;

  unsigned get_value() const;

  void set_value(unsigned v);

  std::string get_pc_string() const final override;

};

} // namespace bld::src::pc

#endif // NUM_DECL_HPP_HPP
