#include "source/token/make/token.hpp"

#include "source/token/simplify/interface.hpp"

namespace bld::src::pc {

own_token_t<kind::num> make_num(long n) {
  return make_token< kind::num >( n < 0 ? -n : n, n < 0 ? sign::neg : sign::pos );
}

static
bool is_zero(cpiece_t pc) {
  if (pc->get_kind() == kind::num) {
    return static_cast<ctoken_t<kind::num>>(pc)->get_value() == 0;
  }
  return false;
}

own_piece_t make_substract( cpiece_t aPc, cpiece_t bPc ) {
  if (is_zero(aPc) and is_zero(bPc)) {
    return make_num(0);
  } else if (is_zero(aPc)) {
    auto negPc = edit_piece(bPc);
    negPc->flip_sign();
    return negPc;
  } else if (is_zero(bPc)) {
    return edit_piece( aPc );
  } else {
    auto subs = make_token< kind::addends >( aPc, bPc );
    subs->edit_tokens()[1]->flip_sign();
    return subs;
  }
}


own_piece_t fold_addends( vec_cpiece_t vec ) {

  if (vec.empty()) {
    return make_num(0);
  } else if (vec.size() == 1) {
    return simplify_piece( edit_piece( vec.front() ) );
  } else {
    return simplify_piece( make_token< kind::addends >( edit_piece_vector( vec ) ) );
  }
}

own_cpiece_t fold_caddends( vec_cpiece_t vec ) {
  return static_unique_pointer_cast< const piece >( fold_addends(vec) );
}


vec_own_piece_t unfold_addends( cpiece_t inputPc ) {

  // Replace by get_tokens, as get_tokens belongs to piece TODO
  vec_own_piece_t retVec;

  if (inputPc->get_kind() == kind::addends) {

    auto adds = static_cast<ctoken_t<kind::addends>>( inputPc );

    if (adds->get_token_count() == 0 ) {

      throw std::logic_error("Could not unfold_addends. Input piece is addends without tokens");

    } else if ( adds->get_token_count() == 1 ) {

      retVec.emplace_back( simplify_piece( adds->get_tokens().front() ) );

    } else {

      retVec = transform_vec( adds->get_tokens(), [] (cpiece_t pc) { return simplify_piece(pc); } );
    }

  } else {

    retVec.emplace_back( simplify_piece(inputPc) );
  }

  return retVec;
}


vec_own_cpiece_t unfold_caddends( cpiece_t inputPc ) {

  auto nonConstVec = unfold_addends( inputPc );

  return transform_vec( nonConstVec, [] (const own_piece_t& ownPc) { return const_piece(ownPc); } );
}

own_piece_t fold_factors( vec_cpiece_t vec ) {

  if (vec.empty()) {
    return make_num(0);
  } else if (vec.size() == 1) {
    return simplify_piece( edit_piece( vec.front() ) );
  } else {
    return simplify_piece( make_token< kind::factors >( edit_piece_vector( vec ) ) );
  }
}

own_cpiece_t fold_cfactors( vec_cpiece_t vec ) {
  return static_unique_pointer_cast< const piece >( fold_factors(vec) );
}


own_ctoken_t<kind::range> make_range_plus_one( cpiece_t inputPc ) {

  return make_token< kind::range >(
      edit_piece( inputPc ),
      make_token< kind::addends >( edit_piece(inputPc), make_num(1) )
    );
}

} // namespace bld::src::pc 
