#ifndef TERMINAL_DECL_HPP_HPP
#define TERMINAL_DECL_HPP_HPP


#include "source/token/piece.hpp"



namespace bld::src::pc {



template <kind Kind>
class token;


class terminal : public piece {
private:


  sign m_sign = sign::pos;

#ifndef PARSER_TEST
  cso_t<obj::data_use> m_dataUse = nullptr;
#endif // PARSER_TEST

public:

  terminal();

  terminal(sign s);


  terminal(const terminal& ) = default;
  // terminal(const terminal& ); // DBG XXX


  virtual kind get_kind() const override = 0;

  std::string get_pc_string() const override = 0;

  bool is_multiple() const final override;
  bool is_terminal() const final override;
  bool is_arith() const override;
  bool is_rt() const override;

  sign get_sign() const final override;
  void flip_sign() final override;



  bool has_data_use() const;

  // Implementations depending on PARSER_TEST
  piece_context get_global_context() const final override;
  piece_context get_local_context() const final override;

#ifndef PARSER_TEST

public:

  void set_data_use(cso_t<obj::data_use>);

  cso_t<obj::data_use> get_data_use() const;

  bool find_data_use(cso_t<obj::data_use> dUse) const final override;

#endif // PARSER_TEST



  vec_cpiece_t gather_pieces_satisfying( pred_fun_t&& satisfyLambda ) const final override;

  cpiece_t find_piece_satisfying( pred_fun_t satisfyLambda ) const final override;

  std::vector<terminal_t> edit_flatten_terminals() final override;
  std::vector<cterminal_t> get_flatten_terminals() const final override;

  vec_piece_t edit_tokens() final override;
  vec_cpiece_t get_tokens() const final override;


  bool is_direct_call_argument() const;
  bool is_direct_operator_argument() const;
};

} // namespace bld::src::pc

#endif // TERMINAL_DECL_HPP_HPP
