#ifndef MULTIPLE_DECL_HPP_HPP
#define MULTIPLE_DECL_HPP_HPP

#include "source/token/piece.hpp"


#include <vector>
#include <memory>



namespace bld::src::pc {

class terminal;

template <unsigned NumTokens>
class token_tuple;



class multiple : public piece {
public:

  static constexpr bool is_derived = false;

private:

  vec_own_piece_t m_tokens;

private:
  
  static std::string get_expr_from(const vec_cpiece_t& inputPcVec, char combOp, sign s);

  void set_as_parent() const;

protected:

  std::string get_pc_string_from(char combOp, sign s = sign::pos) const;

protected:


public:



  multiple();
  multiple(vec_own_piece_t&& f);

  multiple(const multiple& other);

  multiple(const vec_piece_t& f);

  vec_piece_t edit_tokens() final override;
  vec_cpiece_t get_tokens() const final override;

  vec_own_piece_t& edit_own_tokens();

  unsigned get_token_count() const;

  bool is_multiple() const final override;
  bool is_terminal() const final override;
  virtual bool is_arith() const override;
  virtual bool is_rt() const override;
  virtual sign get_sign() const override;
  virtual void flip_sign() override;

protected:
  // Used by kind::factors and kind::fraction
  sign extract_sign();
public:

  vec_cpiece_t gather_pieces_satisfying( pred_fun_t && satisfyLambda ) const final override;

  cpiece_t find_piece_satisfying( pred_fun_t satisfyLambda ) const final override;

#ifndef PARSER_TEST
  bool find_data_use(cso_t<obj::data_use> dUse) const final override;
#endif // PARSER_TEST

  std::vector<terminal_t> edit_flatten_terminals() final override;

  std::vector<cterminal_t> get_flatten_terminals() const final override;

  // Implementations depending on PARSER_TEST
  piece_context get_global_context() const final override;
  piece_context get_local_context() const final override;

};



} // namespace bld::src::pc


#include "source/token/token_tuple.hpp"


#endif // MULTIPLE_DECL_HPP_HPP
