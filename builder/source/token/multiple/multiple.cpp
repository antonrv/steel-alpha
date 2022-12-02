
#include "source/token/multiple/multiple.hpp"

#include "source/token/terminal/terminal.hpp"

#include "source/token/make/copy.hpp"

#include "source/token/combine/interface.hpp"

#ifndef PARSER_TEST
#include "source/object/data/use.hpp"
#endif // PARSER_TEST

// #include <algorithm>
#include <stdexcept>


namespace bld::src::pc {


void tokens_to_vector_detail(vec_own_piece_t& vec) {}



///////////////// MULTIPLE

void multiple::set_as_parent() const {
  for (auto& ownPc : m_tokens) {
    ownPc->set_parent(this);
  }
}

multiple::multiple() :
piece()
{}

multiple::multiple(vec_own_piece_t&& pieces) :
piece(),
m_tokens(std::move(pieces))
{
  this->set_as_parent();
}


multiple::multiple(const multiple& other) :
m_tokens( transform_vec( other.m_tokens, [] (const auto& pc) { return edit_piece(pc.get()); } ) )
{
  this->set_as_parent();
}

sign multiple::get_sign() const {
  throw std::logic_error("Cannot get_sign in multiple. Implement if needed : " + this->get_kind_str() + ". " + this->get_pc_string());
}

void multiple::flip_sign() {
  throw std::logic_error("Cannot flip_sign in multiple. Implement if needed : " + this->get_kind_str() + ". " + this->get_pc_string());
}

bool multiple::is_arith() const {
  auto toks = this->get_tokens();
  return std::all_of(std::begin(toks), std::end(toks), [] (cpiece_t pc) { return pc->is_arith(); });
}

bool multiple::is_rt() const {
  auto toks = this->get_tokens();
  return std::any_of(std::begin(toks), std::end(toks), [] (cpiece_t pc) { return pc->is_rt(); });
}


std::string multiple::get_expr_from(const vec_cpiece_t& inputPcVec, char combOp, sign s) {

  std::string retStr;
  for (auto pc : inputPcVec) {

    std::string combStr;
    if (not retStr.empty()) { combStr.push_back(combOp); }

    retStr += combStr + pc->get_pc_string();
  }

  if (inputPcVec.size() > 1) {
    return std::string(s == sign::neg ? "(-1)*" : "") + "(" + retStr + ")";
  } else {
    return (s == sign::neg ? "(-" + retStr + ")" : retStr);
  }
}


std::string multiple::get_pc_string_from(char combOp, sign s) const {

  if (this->get_kind() != kind::fraction) {

    auto copyElms = canonicalize(this->get_tokens());

    return multiple::get_expr_from( copyElms, combOp, s );

  } else {

    return multiple::get_expr_from( this->get_tokens(), combOp, s );

  }
}

vec_own_piece_t& multiple::edit_own_tokens() {
  return m_tokens;
}

vec_cpiece_t multiple::gather_pieces_satisfying( pred_fun_t && satisfyLambda ) const {

  vec_cpiece_t retVec;

  if (satisfyLambda(this)) {
    retVec.push_back(this);
  }

  for (auto& innerPc : m_tokens) {
    auto innerVec = innerPc->gather_pieces_satisfying( std::forward<pred_fun_t>(satisfyLambda) );
    retVec.insert( std::end(retVec), std::begin(innerVec), std::end(innerVec) );
  }

  return retVec;
}

cpiece_t multiple::find_piece_satisfying( pred_fun_t satisfyLambda ) const {

  auto satVec = this->gather_pieces_satisfying( std::move(satisfyLambda) );
  if (not satVec.empty()) {
    return satVec.front();
  } 
  return nullptr;
}


unsigned multiple::get_token_count() const {
  return m_tokens.size();
}


bool multiple::is_multiple() const { return true; }
bool multiple::is_terminal() const { return false; }


vec_piece_t multiple::edit_tokens() {

  return transform_vec( m_tokens, [] (const own_piece_t& pc) { return static_cast<piece_t>(pc.get()); });
}

vec_cpiece_t multiple::get_tokens() const {
  
  return transform_vec( m_tokens, [] (const own_piece_t& pc) { return static_cast<cpiece_t>(pc.get()); } );
}


// Used by kind::factors and kind::fraction
sign multiple::extract_sign() {

  auto editPieces = this->edit_tokens();

  auto nNegSigns = std::count_if(std::begin(editPieces), std::end(editPieces),
    [] (cpiece_t pc) {
      return pc->get_sign() == sign::neg;
    });

  std::for_each(std::begin(editPieces), std::end(editPieces),
    [] (piece_t pc) {
      if (pc->get_sign() == sign::neg) {
        pc->flip_sign();
      }
    });

  // std::cout << "extract_sign for " << this->get_kind() << " got # negs : " << nNegSigns << '\n';

  return (nNegSigns % 2) == 1 ? sign::neg : sign::pos;
}


#ifndef PARSER_TEST
bool multiple::find_data_use(cso_t<obj::data_use> dUse) const {
  return std::find_if(std::begin(m_tokens), std::end(m_tokens), [dUse] (const own_piece_t& pc) { return pc->find_data_use(dUse); }) != std::end(m_tokens);
}
#endif // PARSER_TEST


std::vector<terminal_t> multiple::edit_flatten_terminals() {

  std::vector<terminal_t> retVec;

  auto thisToks = this->edit_tokens();

  auto vecTerms = transform_vec( thisToks, [] (piece_t pc) { return pc->edit_flatten_terminals(); } );

  for (auto& vec : vecTerms) {
    std::copy(std::begin(vec), std::end(vec), std::back_inserter(retVec));
  }
  return retVec;
}

std::vector<cterminal_t> multiple::get_flatten_terminals() const {

  std::vector<cterminal_t> retVec;

  auto thisToks = this->get_tokens();

  auto vecTerms = transform_vec( thisToks, [] (cpiece_t pc) { return pc->get_flatten_terminals(); } );

  for (auto& vec : vecTerms) {
    std::copy(std::begin(vec), std::end(vec), std::back_inserter(retVec));
  }

  return retVec;
  // std::vector<cterminal_t> retVec;
  // for (auto pc : get_tokens()) {
  //   if (not pc->is_multiple()) {
  //     retVec.push_back( static_cast<cterminal_t>(pc) ); 
  //   } else {
  //     auto innerVec = static_cast<const multiple*>(pc)->get_flatten_terminals();
  //     retVec.insert( std::end(retVec), std::begin(innerVec), std::end(innerVec) );
  //   }
  // }
  // return retVec;
}


#ifndef PARSER_TEST

piece_context multiple::get_global_context() const {

  // Ensure all have same context

  auto vecCtxt = transform_vec_if( this->get_tokens(),
    [] (cpiece_t pc) {
      return pc->get_global_context() != UniversalCtxt;
    },
    [] (cpiece_t pc) {
      return pc->get_global_context();
    });

  if (vecCtxt.empty()) {
    return UniversalCtxt;
  }

  if ( std::adjacent_find( std::begin(vecCtxt), std::end(vecCtxt), std::not_equal_to<>() ) == std::end(vecCtxt) ) {

    // All elements have the same function context
    return vecCtxt.front();

  } else {
    throw std::logic_error("Could not get_global_context from multiple : its tokens do not have a common function context");
  }
}

piece_context multiple::get_local_context() const {

  auto locCtxtVec = transform_vec_if( this->get_tokens(),
      [] (cpiece_t pc) { return pc->get_local_context() != UniversalCtxt; },
      [] (cpiece_t pc) { return pc->get_local_context(); });

  if (locCtxtVec.empty()) {
    return UniversalCtxt;
  }

  auto earliestLocCtxtIt = std::min_element(std::begin(locCtxtVec), std::end(locCtxtVec),
    [] (piece_context locCtxtA, piece_context locCtxtB) {
      return locCtxtA->is_before( locCtxtB );
    } );

  return *earliestLocCtxtIt;
}

#else // PARSER_TEST enabled

piece_context multiple::get_global_context() const {
  return UniversalCtxt;
}

piece_context multiple::get_local_context() const {
  return UniversalCtxt;
}

#endif // PARSER_TEST


} // namespace bld::src::pc
