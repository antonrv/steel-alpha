#ifndef COMMON_IT_SOURCE_PIECE_TEST_SIMPLIFY_HPP
#define COMMON_IT_SOURCE_PIECE_TEST_SIMPLIFY_HPP

#include "common/typedef.hpp"
#include "source/token/typedef.hpp"


namespace bld::src::pc {

static unsigned IndentLevel = 0;


own_piece_t simplify_piece_core(cpiece_t inputPc);

template <
  typename T,
  req_t<
    std::conjunction<
      std::is_lvalue_reference<T>,
      std::negation<is_unique_ptr<std::remove_const_t<std::remove_reference_t<T>>>>
    >
  >...
>
own_piece_t simplify_piece(T&& f) {
  // std::cout << "Copy from CONST RAW PTR REF" << __PRETTY_FUNCTION__ << "\n";
  return simplify_piece_core( f );
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
own_piece_t simplify_piece(T&& f) {
  // std::cout << "Copy from CONST RAW PTR COPY" << __PRETTY_FUNCTION__ << "\n";
  return simplify_piece_core( f );
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
own_piece_t simplify_piece(T&& f) {
  // std::cout << "Copy from CONST OWN PTR " << __PRETTY_FUNCTION__ << "\n";
  return simplify_piece_core( f.get() );
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
own_piece_t simplify_piece(T&& f) {
  // std::cout << "Copy from RVALUE OWN PTR " << __PRETTY_FUNCTION__ << "\n";
  return simplify_piece_core( f.get() );
}


} // namespace bld::src::pc

#endif // COMMON_IT_SOURCE_PIECE_TEST_SIMPLIFY_HPP
