#ifndef MULTIPLE_CALL_DECL_HPP_HPP
#define MULTIPLE_CALL_DECL_HPP_HPP

#include "source/sequences.hpp"


#include "source/token/multiple/multiple.hpp"

#include "source/token/token_tuple.hpp"

#ifndef PARSER_TEST
#include "source/object/typedef.hpp"
#endif // PARSER_TEST


namespace bld::src::pc {

template <>
class token<kind::call> : public binary {


public:

  template <typename... OwnPieceTs>
  token(OwnPieceTs&&... args) : binary(tokens_to_vector( std::forward<OwnPieceTs>(args) ... )) {}

  token(vec_own_piece_t&& f);

  token(const token& other);

  token(cpiece_t namePiece, cpiece_t argsPiece);

  kind get_kind() const final override;

  sign get_sign() const final override;
  void flip_sign() final override;

  bool is_arith() const final override;
  bool is_rt() const final override;


  std::string get_pc_string() const final override;

  bool has_arguments() const;

  ctoken_t<kind::var> get_name() const;
  cpiece_t get_arguments() const;

  token_t<kind::var> edit_name();
  piece_t edit_arguments();


  cpiece_t get_argument(unsigned i) const;
  piece_t edit_argument(unsigned i);

  bool has_args() const;

};

} // namespace bld::src::pc

#endif // MULTIPLE_CALL_DECL_HPP_HPP
