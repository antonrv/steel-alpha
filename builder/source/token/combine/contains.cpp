
#include "source/token/combine/interface.hpp"

#include "source/token/simplify/interface.hpp"
#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#ifndef PARSER_TEST
  #include "source/token/combine/test_on_local_contexts.hpp"
  #include "source/object/data/transform/interface.hpp"
#endif // PARSER_TEST

#include <algorithm>
#include <iostream>

namespace bld::src::pc {

static
bool exists_in(const vec_cpiece_t vec, cpiece_t inputPc) {

  return std::find_if(std::begin(vec), std::end(vec),
      [inputPc] (cpiece_t pc) {
        return are_equal( pc, inputPc );
      }
      ) != std::end(vec);
}

static
bool guess_simplified( cpiece_t inPc, cpiece_t inRhsPc ) {

  if (inPc->get_kind() != kind::fraction) {

    return true;

  } else {

    // Resulting fraction may be composed by other things, and may have vanished rhs pieces

    auto frac = static_cast< ctoken_t<kind::fraction> >(inPc); 

    auto toksDen = frac->get_denominator()->get_tokens();

    auto inputTermsRhs = inRhsPc->get_flatten_terminals();

    return std::none_of( std::begin(inputTermsRhs), std::end(inputTermsRhs), [toksDen] (cterminal_t trm) { return exists_in(toksDen, trm); } );
  }
}




///////////////
//
// INTERFACE
//
///////////////
bool contains_piece(cpiece_t inLhsPc, cpiece_t inRhsPc) {

  if (are_equal(inLhsPc, inRhsPc)) {
    return true;
  }

  if (are_equal( inRhsPc, make_num(1).get() )) {
    return true;
  }

#ifndef PARSER_TEST

  auto funTest = [] (cpiece_t lhs, cpiece_t rhs) {
      auto simplPc = simplify_piece( make_token< kind::fraction >( simplify_piece( lhs ), simplify_piece( rhs ) ) );
      return guess_simplified( simplPc.get(), rhs );
    };

  return test_on_multiple_local_contexts<bool>( inLhsPc, inRhsPc,
    false, // Return false if funTest did not satisfied following condition
    [] (bool retVal) { return retVal; }, // Exit on the first 'true'
    funTest );

#else

  auto simplPc = simplify_piece( make_token< kind::fraction >( simplify_piece( inLhsPc ), simplify_piece( inRhsPc ) ) );

  return guess_simplified( simplPc.get(), inRhsPc );

#endif // PARSER_TEST
}



} // namespace bld::src::pc
