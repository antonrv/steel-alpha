#ifndef MULTIPLE_ADDRESS_DECL_HPP_HPP
#define MULTIPLE_ADDRESS_DECL_HPP_HPP

#include "source/token/token_tuple.hpp"

namespace bld::src::pc {

template <>
class token<kind::address> : public unary {

  using super_type = unary;

public:

  token(own_piece_t&& operand);

  token(const token& other);

  kind get_kind() const final override;

  bool is_arith() const final override;

  std::string get_pc_string() const final override;

  cpiece_t get_operand() const;

  bool is_direct_call_argument() const;
};

} // namespace bld::src::pc

#endif // MULTIPLE_ADDRESS_DECL_HPP_HPP
