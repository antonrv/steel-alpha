#ifndef TOKEN_TUPLE_DECL_HPP_HPP
#define TOKEN_TUPLE_DECL_HPP_HPP

#include "source/token/multiple/multiple.hpp"


namespace bld::src::pc {

void tokens_to_vector_detail(vec_own_piece_t& vec);

template <typename OwnPcT, typename... OwnPcTs>
void tokens_to_vector_detail(vec_own_piece_t& vec, OwnPcT&& pc, OwnPcTs&&... args) {
  vec.emplace_back( std::move(pc) );
  tokens_to_vector_detail( vec, std::forward<OwnPcTs>(args) ... );
}


template <typename... OwnPcTs>
vec_own_piece_t tokens_to_vector(OwnPcTs&&... args) {
  vec_own_piece_t retVec;
  tokens_to_vector_detail( retVec, std::forward<OwnPcTs>(args) ... );
  return retVec;
}



template <unsigned NumTokens>
class token_tuple : public multiple {

public:

  token_tuple() :
  multiple()
  {}

  token_tuple(const token_tuple& other) :
  multiple(other)
  {}

  token_tuple(vec_own_piece_t&& f) : multiple(std::forward<vec_own_piece_t>(f)) {}

  // template <typename... OwnPieceTs>
  // token_tuple(OwnPieceTs&&... args) : multiple(tokens_to_vector( std::forward<OwnPieceTs>(args) ... )) {}


protected:

  template <unsigned Id>
  piece * edit_token() {
    if (multiple::get_token_count() <= Id) {
      throw std::logic_error("Cannot edit " + std::to_string(Id) + ". Num tokens : " + std::to_string(multiple::get_token_count()));
    }
    return multiple::edit_tokens()[Id];
  }

  template <unsigned Id>
  cpiece_t get_token() const {
    if (multiple::get_token_count() <= Id) {
      throw std::logic_error("Cannot get " + std::to_string(Id) + ". Num tokens : " + std::to_string(multiple::get_token_count()));
    }
    return multiple::get_tokens()[Id];
  }

  template <unsigned Id>
  bool has_token() const {
    return multiple::get_token_count() > Id;
  }

};


using unary = token_tuple<1>;
using binary = token_tuple<2>;
using triple = token_tuple<3>;
// using tetra = token_tuple<4>;

} // namespace bld::src::pc

#endif // TOKEN_TUPLE_DECL_HPP_HPP
