#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#include "source/token/simplify/interface.hpp"

#include "common/util.hpp"
#include "source/token/simplify/extract.hpp"

#include "source/token/combine/interface.hpp"

#include <iostream> // DBG XXX
#include <memory>
#include <numeric>
#include <algorithm>


#include "source/token/simplify/steps.hpp"

namespace bld::src::pc {

template <range_limit RL>
static
long reduce_numbers(const long cum, const own_token_t<kind::num>& num) {

  static_assert(RL == range_limit::min or RL == range_limit::max);

  long val = ((long)num->get_value()) * (num->get_sign() == sign::neg ? -1 : 1);

  if constexpr (RL == range_limit::min) {
    return std::min(cum, val);
  } else { // (RL == range_limit::max)
    return std::max(cum, val);
  }
}


template <range_limit RL>
static
own_piece_t simplify_numbers( cpiece_t inputPc ) {

  if ( inputPc->get_kind() != kind::cs_list) {
    return edit_piece(inputPc);
  }

  auto cslPc = static_cast<ctoken_t<kind::cs_list>>( inputPc );

  static_assert(RL == range_limit::min or RL == range_limit::max);

  auto isNumber = [] (cpiece_t pc) { return pc->get_kind() == kind::num; };
  auto isOther = [] (cpiece_t pc) { return pc->get_kind() != kind::num; };

  auto numericElms = extract_tokens_in< token<kind::num> >( cslPc, isNumber );

  if (numericElms.size() < 2) {
    return edit_piece(inputPc);
  }

  auto otherElms = extract_tokens_in< piece >( cslPc, isOther );

  long init = 0;

  if constexpr (RL == range_limit::min) {
    init = std::numeric_limits<long>::max();
  } else { // (RL == range_limit::max)
    init = std::numeric_limits<long>::min();
  }
  
  auto redResult = std::accumulate( std::begin(numericElms), std::end(numericElms), init, reduce_numbers<RL> );

  if (otherElms.empty()) {

    return make_num( redResult );

  } else {

    otherElms.push_back( make_num( redResult ) );

    return make_token< kind::cs_list >( std::move(otherElms) );
  }
}


template <>
template <>
own_piece_t
simplify<kind::range>::run_step<reduce_step::range_numeric_args>(ctoken_t<kind::range> rngPc) {

  auto minPc = rngPc->get_limit<range_limit::min>();
  auto maxPc = rngPc->get_limit<range_limit::max>();

  return make_token< kind::range >( simplify_numbers<range_limit::min>(minPc), simplify_numbers<range_limit::max>(maxPc) );
}



static
own_piece_t simplify_equal( cpiece_t inputPc ) {

  if ( inputPc->get_kind() != kind::cs_list) {
    return edit_piece(inputPc);
  }

  auto cslPc = static_cast<ctoken_t<kind::cs_list>>( inputPc );

  auto isAny = [] (cpiece_t pc) { return true; };

  auto elms = extract_tokens_in< piece >( cslPc, isAny );

  std::vector<unsigned> posToErase;

  for (auto i = 0u; i < elms.size(); ++i) {


    if (std::find(std::begin(posToErase), std::end(posToErase), i) == std::end(posToErase) and elms[i]->get_kind() != kind::num) {

      for (auto j = i+1; j < elms.size(); ++j) {

        if (std::find(std::begin(posToErase), std::end(posToErase), j) == std::end(posToErase) and elms[j]->get_kind() != kind::num) {


          auto fracAoverB = simplify_piece( make_token< kind::fraction >( elms[i], elms[j] ) );


          // i elem equal to j elem, mark j to remove
          if ( are_equal( fracAoverB.get(), make_num(1).get() ) ) {

            posToErase.push_back(j);
          }
        }
      }
    }
  }

  // Reverse order, so following erases do not invalidate unsafe iterators
  std::sort(std::begin(posToErase), std::end(posToErase), [] (unsigned a, unsigned b) { return a > b; });
  for (auto i : posToErase) {
    elms.erase( std::begin(elms) + i );
  }

  if (elms.empty()) {
    throw std::logic_error("Empty vector while simplifying list elements in range");
  }

  if (elms.size() == 1) {
    return std::move(elms.front());
  } else {
    return make_token< kind::cs_list >( std::move(elms) );
  }
}

template <>
template <>
own_piece_t
simplify<kind::range>::run_step<reduce_step::range_equal_args>(ctoken_t<kind::range> rngPc) {

  auto minPc = rngPc->get_limit<range_limit::min>();
  auto maxPc = rngPc->get_limit<range_limit::max>();

  return make_token< kind::range >( simplify_equal(minPc), simplify_equal(maxPc) );
}



template <range_limit RL>
static
own_piece_t simplify_zero( cpiece_t inputPc ) {


  if ( inputPc->get_kind() != kind::cs_list) {
    return edit_piece(inputPc);
  }


  auto cslPc = static_cast<ctoken_t<kind::cs_list>>( inputPc );

  static_assert(RL == range_limit::min or RL == range_limit::max);

  auto isZero = [] (cpiece_t pc) { return pc->get_kind() == kind::num and static_cast<ctoken_t<kind::num>>(pc)->get_value() == 0; };
  auto isOther = [isZero] (cpiece_t pc) { return not isZero(pc); };

  auto zeroElms = extract_tokens_in< token<kind::num> >( cslPc, isZero );
  auto otherElms = extract_tokens_in< piece >( cslPc, isOther );


  if (zeroElms.empty()) {
    return edit_piece(inputPc);
  }


  if constexpr (RL == range_limit::min) {

    return make_num(0);

  } else if constexpr (RL == range_limit::max) {

    if (otherElms.empty()) {
      return make_num(0);
    } else if (otherElms.size() == 1) {
      return edit_piece( otherElms.front() );
    } else {
      return make_token< kind::cs_list >( std::move(otherElms) );
    }
  }
}


template <>
template <>
own_piece_t
simplify<kind::range>::run_step<reduce_step::range_zero_args>(ctoken_t<kind::range> rngPc) {

  auto minPc = rngPc->get_limit<range_limit::min>();
  auto maxPc = rngPc->get_limit<range_limit::max>();

  return make_token< kind::range >( simplify_zero<range_limit::min>(minPc), simplify_zero<range_limit::max>(maxPc) );
}


} // namespace bld::src::pc
