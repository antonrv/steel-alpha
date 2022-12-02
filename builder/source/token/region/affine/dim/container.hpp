#ifndef SOURCE_TOKEN_DIM_CONTAINER_HPP
#define SOURCE_TOKEN_DIM_CONTAINER_HPP

#include "source/token/typedef.hpp"

#include "common/util.hpp"
#include "common/typedef.hpp"

#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#include <vector>

namespace bld::src::pc {

// A wrapper over a vector with proper bounds checking and 'dim' semantics, to enhance readability of data objects that encapsulate dimensional information across 'd' dimensions.

template <typename T> struct ret_type { using type = T; };
template <typename T> struct ret_type <std::unique_ptr<T>>{ using type = std::add_pointer_t<T>; };

template <
  typename UptrT, typename AllocT,
  req_t< is_unique_ptr<UptrT> >...
  // req_t< std::conjunction<is_unique_ptr<UptrT>, std::is_const<typename UptrT::element_type>> >...
>
static
std::vector<UptrT, AllocT> copy_vec(const std::vector<UptrT, AllocT>& otherVec) {
  return transform_vec( otherVec,
      [] (const UptrT& own) {
        return static_unique_pointer_cast< typename UptrT::element_type >( const_piece(own.get()) );
      }
    );
}

// template <
//   typename UptrT, typename AllocT,
//   req_t< std::conjunction<is_unique_ptr<UptrT>, std::negation<std::is_const<typename UptrT::element_type>>> >...
// >
// static
// std::vector<UptrT, AllocT> copy_vec(const std::vector<UptrT, AllocT>& otherVec) {
//   return transform_vec( otherVec, [] (const UptrT& own) { return edit_piece(own.get()); } );
// }

// template <
//   typename T, typename AllocT,
//   req_t< std::negation<is_unique_ptr<T>> >...
// >
// static
// std::vector<T> copy_vec(std::vector<T, AllocT>&& otherVec) {
//   return otherVec;
// }
// 
// template <
//   typename T, typename AllocT,
//   req_t< std::negation<is_unique_ptr<T>> >...
// >
// static
// std::vector<T> copy_vec(const std::vector<T, AllocT>& otherVec) {
//   return otherVec;
// }



template <typename T>
class dim_container {

  std::vector<T> m_elements;

  static constexpr bool are_elements_owned = is_unique_ptr<T>::value;
  using return_type = typename ret_type<T>::type;

public:

  // using value_type = return_type; // T;

  dim_container() = default;
  // dim_container(dim_container&&) = default;

  // dim_container(const dim_container<T>& other) :
  //   m_elements( copy_vec(other.m_elements) )
  // {}


  dim_container(unsigned nDims) : m_elements(nDims) {}
  dim_container(std::vector<T>&& inVec) : m_elements(std::move(inVec)) {}
  
  // void add_elem(T&& t) {
  //   m_elements.push_back( std::forward<T>(t) );
  // }

  void check_bounds(unsigned d) const {
    if (d >= m_elements.size()) {
      throw std::logic_error("Could not get element " + std::to_string(d) + " of dim container of size : " + std::to_string(m_elements.size()));
    }
  }

  auto get_elem(unsigned d) const {
    this->check_bounds(d);
    if constexpr (are_elements_owned) {
      return static_cast<const return_type>( m_elements[d].get() );
    } else {
      return static_cast<const T&>( m_elements[d] );
    }
  }

  auto begin() const {
    return m_elements.begin();
  }

  auto end() const {
    return m_elements.end();
  }

  T& edit_elem(unsigned d) {
    this->check_bounds(d);
    return m_elements[d];
  }

  unsigned size() const {
    return m_elements.size();
  }

  bool empty() const {
    return m_elements.empty();
  }

  auto get_vec() const {
    if constexpr (are_elements_owned) {
      return transform_vec( m_elements, [] (const T& own) { return own.get(); } );
    } else {
      return m_elements;
    }
  }

  const std::vector<T>& ref_vec() const {
    return m_elements;
  }
};


} // namespace bld::src::pc

#endif // SOURCE_TOKEN_DIM_CONTAINER_HPP
