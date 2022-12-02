#ifndef COMMON_UTIL_HPP
#define COMMON_UTIL_HPP

#include <algorithm>
#include <numeric>

namespace bld {


template<class InputIt, class OutputIt, class UnaryPredicate, class Convert>
OutputIt transform_if(InputIt inFirst, InputIt inLast, 
                 OutputIt outFirst, UnaryPredicate pred, Convert conv)
{

  while (inFirst != inLast) {
    if (pred(*inFirst)) {
      *outFirst++ = conv(*inFirst);
    }
    inFirst++;
  }
  return outFirst;
}

template < typename ContainerT, typename FunT>
std::invoke_result_t<FunT, typename ContainerT::value_type> string_from_container( const ContainerT& containerInput, FunT&& fun ) {

  return std::accumulate(std::begin(containerInput), std::end(containerInput), std::string(),
      [fun] (const std::string& cum, const auto& elem) {
        return cum + fun(elem);
      }
    );
}

template <class ContainerAT, class ContainerBT, class OpT>
std::vector< typename OpT::result_type >
compose_vecs( const ContainerAT& containerInputA, const ContainerBT& containerInputB, OpT op ) {

  if (containerInputA.size() != containerInputB.size()) {
    throw std::logic_error("Could not compose_vecs. Sizes must be the same");
  }

  std::vector< typename OpT::result_type > retVec;

  auto itB = std::begin(containerInputB);

  for (auto itA = std::begin(containerInputA); itA != std::end(containerInputA); itA++, itB++) {
    retVec.emplace_back( op(*itA, *itB) );
  }

  return retVec;
}

template <class ContainerAT, class ContainerBT, class OpT>
std::vector< typename OpT::result_type >
compose_tri( const ContainerAT& containerInputA, const ContainerBT& containerInputB, const ContainerBT& containerInputC, OpT op ) {

  if (containerInputA.size() != containerInputB.size() or containerInputB.size() != containerInputC.size()) {
    throw std::logic_error("Could not compose_tri. Sizes must be the same : " + std::to_string(containerInputA.size()) + ", " + std::to_string(containerInputB.size()) + ", " + std::to_string(containerInputC.size()));
  }

  std::vector< typename OpT::result_type > retVec;

  auto itB = std::begin(containerInputB);
  auto itC = std::begin(containerInputC);

  for (auto itA = std::begin(containerInputA); itA != std::end(containerInputA); itA++, itB++, itC++) {
    retVec.emplace_back( op(*itA, *itB, *itC) );
  }

  return retVec;
}


// Syntatic sugar for std::transform
template < typename ContainerT, typename FunT>
std::vector< std::invoke_result_t<FunT, typename ContainerT::value_type> > transform_vec( const ContainerT& containerInput, FunT&& fun ) {

  std::vector< std::invoke_result_t<FunT, typename ContainerT::value_type> > retVec;

  std::transform(std::begin(containerInput), std::end(containerInput), std::back_inserter(retVec), fun );

  return retVec;
}


// Syntatic sugar for transform_if
template < typename ContainerT, typename PredT, typename FunT >
std::vector< std::invoke_result_t<FunT, typename ContainerT::value_type> > transform_vec_if( const ContainerT& vecInput, PredT&& pred, FunT&& fun ) {

  std::vector< std::invoke_result_t<FunT, typename ContainerT::value_type> > retVec;

  transform_if(std::begin(vecInput), std::end(vecInput), std::back_inserter(retVec), pred, fun );

  return retVec;
}


template < typename ToT, typename FromT >
std::unique_ptr<ToT> static_unique_pointer_cast( std::unique_ptr<FromT>&& old ){
  return std::unique_ptr<ToT>{ static_cast<ToT*>( old.release() ) };
}


} // namespace bld

#endif // COMMON_UTIL_HPP
