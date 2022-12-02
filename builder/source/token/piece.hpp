#ifndef PIECE_DECL_HPP_HPP
#define PIECE_DECL_HPP_HPP


#include "source/object/typedef.hpp"


namespace bld::src::pc {


class terminal;

class piece {
private:

  cpiece_t m_parent = nullptr;

public:

  piece();

  piece(const piece& pc);

  void set_parent(cpiece_t pc);

  cpiece_t get_parent() const;

  virtual ~piece() = 0;

  virtual std::string get_pc_string() const = 0;

  std::string get_kind_str() const;

  virtual kind get_kind() const = 0;

  virtual bool is_multiple() const = 0;
  virtual bool is_terminal() const = 0;
  virtual bool is_arith() const = 0;
  virtual bool is_rt() const = 0;
  virtual sign get_sign() const = 0;
  virtual void flip_sign() = 0;

  virtual vec_cpiece_t gather_pieces_satisfying( pred_fun_t&& satisfyLambda ) const = 0;

  virtual cpiece_t find_piece_satisfying( pred_fun_t satisfyLambda ) const = 0;

  virtual vec_terminal_t edit_flatten_terminals() = 0;
  virtual vec_cterminal_t get_flatten_terminals() const = 0;

  virtual vec_piece_t edit_tokens() = 0;
  virtual vec_cpiece_t get_tokens() const = 0;

  virtual piece_context get_global_context() const = 0;
  virtual piece_context get_local_context() const = 0; 

#ifndef PARSER_TEST
  virtual bool find_data_use(cso_t<obj::data_use> dUse) const = 0;
#endif // PARSER_TEST

#ifndef PARSER_TEST
  std::string serial() const;
#endif // PARSER_TEST
};


template <unsigned NumTokens>
class token_tuple;



} // namespace bld::src::pc

#endif // PIECE_DECL_HPP_HPP
