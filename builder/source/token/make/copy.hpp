#ifndef PARSER_PIECE_CLONE_HPP
#define PARSER_PIECE_CLONE_HPP

// To transitively include the basic pieces
#include "source/token/terminal/num.hpp"
#include "source/token/terminal/var.hpp"
#include "source/token/terminal/undef.hpp"
#include "source/token/terminal/loopvar.hpp"
#include "source/token/multiple/addends.hpp"
#include "source/token/multiple/factors.hpp"
#include "source/token/multiple/cs_list.hpp"
#include "source/token/multiple/fraction.hpp"
#include "source/token/multiple/address.hpp"
#include "source/token/multiple/offset.hpp"
#include "source/token/multiple/range.hpp"
#include "source/token/multiple/call.hpp"
#include "source/token/multiple/binop.hpp"

#include "common/util.hpp"

namespace bld::src::pc {



// Core functions, defined in clone.cpp
own_piece_t edit_piece_core( cpiece_t inputPc );
own_cpiece_t const_piece_core( cpiece_t inputPc );


///////////////
//
// COPY-PIECE INTERFACE  : return type is always own_piece_t. EDIT_PIECE
//
///////////////
template <
  typename T,
  req_t<
    std::conjunction<
      std::is_lvalue_reference<T>,
      std::negation<is_unique_ptr<std::remove_const_t<std::remove_reference_t<T>>>>
    >
  >...
>
own_piece_t edit_piece(T&& f) {
  // std::cout << "Copy from CONST RAW PTR REF " << __PRETTY_FUNCTION__ << "\n";
  return edit_piece_core( f );
}

template <
  typename T,
  req_t<
    std::conjunction<
      std::is_pointer<T>,
      std::negation<is_unique_ptr<std::remove_reference_t<T>>>
    >
  >...
>
own_piece_t edit_piece(T&& f) {
  // std::cout << "Copy from CONST RAW PTR COPY " << __PRETTY_FUNCTION__ << "\n";
  return edit_piece_core( f );
}

template <
  typename T,
  req_t<
    std::conjunction<
      std::is_lvalue_reference<T>,
      is_unique_ptr<std::remove_reference_t<T>>
    >
  >...
>
own_piece_t edit_piece(T&& f) {
  // std::cout << "Copy from CONST OWN PTR " << __PRETTY_FUNCTION__ << "\n";
  return edit_piece_core( f.get() );
}

template <
  typename T,
  req_t<
    std::conjunction<
      std::negation<std::is_lvalue_reference<T>>,
      is_unique_ptr<std::remove_reference_t<T>>
    >
  >...
>
own_piece_t edit_piece(T&& f) {
  // std::cout << "Copy from RVALUE OWN PTR " << __PRETTY_FUNCTION__ << "\n";
  return edit_piece_core( f.get() );
}


///////////////
//
// CLONE-PIECE INTERFACE : return type is always own_cpiece_t: CONST_PIECE
//
///////////////
template <
  typename T,
  req_t<
    std::conjunction<
      std::is_lvalue_reference<T>,
      std::negation<is_unique_ptr<std::remove_const_t<std::remove_reference_t<T>>>>
    >
  >...
>
own_cpiece_t const_piece(T&& f) {
  // std::cout << "Copy from CONST RAW PTR " << __PRETTY_FUNCTION__ << "\n";
  return const_piece_core( f );
}

template <
  typename T,
  req_t<
    std::conjunction<
      std::is_pointer<T>,
      std::negation<is_unique_ptr<std::remove_const_t<std::remove_reference_t<T>>>>
    >
  >...
>
own_cpiece_t const_piece(T&& f) {
  // std::cout << "Copy from CONST RAW PTR " << __PRETTY_FUNCTION__ << "\n";
  return const_piece_core( f );
}

template <
  typename T,
  req_t<
    std::conjunction<
      std::is_lvalue_reference<T>,
      is_unique_ptr<std::remove_const_t<std::remove_reference_t<T>>>
    >
  >...
>
own_cpiece_t const_piece(T&& f) {
  // std::cout << "Copy from CONST OWN PTR " << __PRETTY_FUNCTION__ << "\n";
  return const_piece_core( f.get() );
}

template <
  typename T,
  req_t<
    std::conjunction<
      std::negation<std::is_lvalue_reference<T>>,
      is_unique_ptr<std::remove_const_t<std::remove_reference_t<T>>>
    >
  >...
>
own_cpiece_t const_piece(T&& f) {
  // std::cout << "Copy from RVALUE OWN PTR " << __PRETTY_FUNCTION__ << "\n";
  return static_unique_pointer_cast< const piece >( std::forward<T>( f ) );
}



///////////////
//
// INTERFACE for copying a vector
//
///////////////
template <typename VecT>
vec_own_piece_t edit_piece_vector( const VecT& inVec ) {

  vec_own_piece_t retVec;

  for (auto& pc : inVec) {
    retVec.emplace_back( edit_piece(pc) );
  }

  // std::transform(std::begin(inVec), std::end(inVec), std::back_inserter(retVec),
  //   [] (const typename VecT::value_type& elm) { return edit_piece(elm); });

  return retVec;
  // return transform_vec( inVec, [] (auto&& pc) { return edit_piece(pc); } );
}

///////////////
//
// INTERFACE for cloning a vector
//
///////////////
template <typename VecT>
vec_own_cpiece_t const_piece_vector( const VecT& inVec ) {

  vec_own_cpiece_t retVec;

  for (auto& pc : inVec) {
    retVec.emplace_back( const_piece(pc) );
  }

  return retVec;
}



} // namespace bld::src::pc

#endif // PARSER_PIECE_CLONE_HPP
