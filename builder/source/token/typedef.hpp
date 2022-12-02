#ifndef COMMON_IT_PARSER_DEFS_HPP
#define COMMON_IT_PARSER_DEFS_HPP

#include "source/sequences.hpp"

#include "common/typedef.hpp"

// #ifndef PARSER_TEST
// #include "source/object/typedef.hpp"
// #endif // PARSER_TEST

#include <string>
#include <vector>
#include <memory>
#include <functional>

namespace bld::src {

class sobject_base;

} // namespace bld::src::pc


namespace bld::src::pc {


class piece;

  template <kind>
  class token;

class terminal;
class multiple;

class access;
class guard;
class loop_var;

template <mem_ak MemAccessKind>
class mem_access;

template <mem_ak MemAccessKind>
class mem_guard;

using piece_context = std::add_pointer_t<std::add_const_t<sobject_base>>;

static const piece_context UniversalCtxt = nullptr;

// Piece type composition
using cst_piece = std::add_const_t<piece>;

using cpiece_t = std::add_pointer_t< cst_piece >; // All pieces are immutable
using own_cpiece_t = std::unique_ptr< cst_piece >;

using vec_cpiece_t = std::vector< cpiece_t >;
using vec_own_cpiece_t = std::vector< own_cpiece_t >;

using piece_t = std::add_pointer_t< piece >; // All pieces are immutable
using own_piece_t = std::unique_ptr< piece >;

using vec_piece_t = std::vector<piece_t>;
using vec_own_piece_t = std::vector<own_piece_t>;

// Token type composition

template <kind Kind>
using token_t = std::add_pointer_t< token<Kind> >; // All tokens are immutable

template <kind Kind>
using own_token_t = std::unique_ptr< token<Kind> >;

template <kind Kind>
using vec_own_token_t = std::vector< own_token_t<Kind> >;

template <kind Kind>
using vec_token_t = std::vector< token_t<Kind> >;


template <kind Kind>
using cst_token = std::add_const_t<token<Kind>>;
template <kind Kind>
using ctoken_t = std::add_pointer_t< cst_token<Kind> >; // All tokens are immutable

template <kind Kind>
using own_ctoken_t = std::unique_ptr< cst_token<Kind> >;

template <kind Kind>
using vec_own_ctoken_t = std::vector<own_ctoken_t<Kind>>;

template <kind Kind>
using vec_ctoken_t = std::vector< ctoken_t<Kind> >;


using pred_fun_t = std::function<bool(cpiece_t)>;

using edit_fun_t = std::function<own_piece_t(cpiece_t)>;

using vec_string_t = std::vector<std::string>;

using loopvar_t = std::add_pointer_t<loop_var>;
using cloopvar_t = std::add_pointer_t<const loop_var>;
using own_loopvar_t = std::unique_ptr<loop_var>;
using own_cloopvar_t = std::unique_ptr<const loop_var>;

using vec_cloopvar_t = std::vector<cloopvar_t>;

using access_t = std::add_pointer_t<access>;
using caccess_t = std::add_pointer_t<std::add_const_t<access>>;
using own_access_t = std::unique_ptr<access>;
using own_caccess_t = std::unique_ptr<const access>;

using guard_t = std::add_pointer_t<guard>;
using cguard_t = std::add_pointer_t<std::add_const_t<guard>>;
using own_guard_t = std::unique_ptr<guard>;
using own_cguard_t = std::unique_ptr<const guard>;

using terminal_t = std::add_pointer_t<terminal>;
using cterminal_t = std::add_pointer_t<std::add_const_t<terminal>>;
using vec_terminal_t = std::vector<terminal_t>;
using vec_cterminal_t = std::vector<cterminal_t>;

using multiple_t = std::add_pointer_t<multiple>;
using cmultiple_t = std::add_pointer_t<std::add_const_t<multiple>>;


template <typename T>
class dim_container;

using dim_bool_t = dim_container<bool>;
using dim_cpiece_t = dim_container<cpiece_t>;
using dim_own_piece_t = dim_container<own_piece_t>;
using dim_own_cpiece_t = dim_container<own_cpiece_t>;
using dim_own_cloopvar_t = dim_container<own_cloopvar_t>;
using dim_cloopvar_t = dim_container<cloopvar_t>;

template <kind Kind>
using dim_own_ctoken_t = dim_container< own_ctoken_t<Kind> >;

template <kind Kind>
using dim_ctoken_t = dim_container< ctoken_t<Kind> >;

// template <kind Kind>
// using dim_own_token_t = dim_container< own_token_t<Kind> >;


} // namespace bld::src::pc

#endif // COMMON_IT_PARSER_DEFS_HPP
