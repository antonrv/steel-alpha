#ifndef MULTIPLE_LIST_DECL_HPP_HPP
#define MULTIPLE_LIST_DECL_HPP_HPP

#include "source/token/multiple/multiple.hpp"

namespace bld::src::pc {

template <>
class token<kind::cs_list> : public multiple {

public:

  token(vec_own_piece_t&& f);

  token(const token& other);

  template <typename... OwnPieceTs>
  token(OwnPieceTs&&... args) : multiple(tokens_to_vector( edit_piece(std::forward<OwnPieceTs>(args)) ... )) {}

  token(cpiece_t pcA, cpiece_t pcB);

  kind get_kind() const final override;

  bool is_arith() const final override;

  std::string get_pc_string() const final override;

  bool is_direct_call_argument() const;

  cpiece_t get_element(unsigned i) const;
  piece_t edit_element(unsigned i);
};


} // namespace bld::src::pc

#endif // MULTIPLE_LIST_DECL_HPP_HPP
