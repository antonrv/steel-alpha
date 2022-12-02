

#include "source/token/multiple/cs_list.hpp"

#include "source/token/make/copy.hpp"

#include <iostream> // DBG XXX

namespace bld::src::pc {

static
vec_own_piece_t pieces_to_cslist(cpiece_t pcA, cpiece_t pcB) {
 
  vec_own_piece_t retVec;


  if (pcA->get_kind() == kind::cs_list and pcB->get_kind() == kind::cs_list) {
    auto pcAList = static_cast<ctoken_t<kind::cs_list>>( pcA )->get_tokens();
    auto pcBList = static_cast<ctoken_t<kind::cs_list>>( pcB )->get_tokens();

    for (auto aPc : pcAList) { retVec.emplace_back( edit_piece(aPc) ); } 
    for (auto bPc : pcBList) { retVec.emplace_back( edit_piece(bPc) ); } 

  } else if (pcA->get_kind() != kind::cs_list and pcB->get_kind() == kind::cs_list) {

    retVec.emplace_back( edit_piece( pcA ) );
    auto pcBList = static_cast<ctoken_t<kind::cs_list>>( pcB )->get_tokens();

    for (auto bPc : pcBList) { retVec.emplace_back( edit_piece(bPc) ); } 

  } else if (pcA->get_kind() == kind::cs_list and pcB->get_kind() != kind::cs_list) {

    auto pcAList = static_cast<ctoken_t<kind::cs_list>>( pcA )->get_tokens();

    for (auto aPc : pcAList) { retVec.emplace_back( edit_piece(aPc) ); } 
    retVec.emplace_back( edit_piece( pcB ) );

  } else {

    retVec.emplace_back( edit_piece( pcA ) );
    retVec.emplace_back( edit_piece( pcB ) );
  }

  return retVec;
}


token<kind::cs_list>::token(vec_own_piece_t&& a) :
multiple(std::move(a))
{}

token<kind::cs_list>::token(const token<kind::cs_list>& other) :
multiple(other)
{}

token<kind::cs_list>::token(cpiece_t pcA, cpiece_t pcB) :
multiple(pieces_to_cslist(pcA, pcB))
{}


kind token<kind::cs_list>::get_kind() const { return kind::cs_list; }

bool token<kind::cs_list>::is_arith() const {
  return false;
}


std::string token<kind::cs_list>::get_pc_string() const {
  return multiple::get_pc_string_from(',');
}



bool token<kind::cs_list>::is_direct_call_argument() const {
  // Parent is kind::call --> true
  if (this->get_parent()->get_kind() == kind::call) {
    return true;
  }
  return false;
}

cpiece_t token<kind::cs_list>::get_element(unsigned i) const {
  if (i >= multiple::get_token_count()) {
    throw std::logic_error("Could not get_element in cs_list : " + std::to_string(i) + " with total " + std::to_string(multiple::get_token_count()));
  }
  return multiple::get_tokens()[i];
}

piece_t token<kind::cs_list>::edit_element(unsigned i) {
  if (i >= multiple::get_token_count()) {
    throw std::logic_error("Could not get_element in cs_list : " + std::to_string(i) + " with total " + std::to_string(multiple::get_token_count()));
  }
  return multiple::edit_tokens()[i];
}

} // namespace bld::src::pc

