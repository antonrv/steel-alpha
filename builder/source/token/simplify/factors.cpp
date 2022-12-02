
#include "source/token/make/piece.hpp"
#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#include "source/token/simplify/interface.hpp"

#include "common/util.hpp"
#include "source/token/simplify/extract.hpp"

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <iostream> // DBG XXX




#include "source/token/simplify/steps.hpp"



namespace bld::src::pc {


struct cum_t {
  unsigned reducedNums = 0;
  unsigned product = 1;
};


static
cum_t cumulate_factors (const cum_t& curCum, const own_token_t<kind::num>& num) {

  return cum_t({curCum.reducedNums + 1, curCum.product * num->get_value()});
}


template <>
template <>
own_piece_t
simplify<kind::factors>::run_step<reduce_step::factors_numbers>(ctoken_t<kind::factors> facPc) {

  auto isNumber = [] (cpiece_t pc) { return pc->get_kind() == kind::num; };
  auto isOther = [] (cpiece_t pc) { return pc->get_kind() != kind::num; };

  auto numericFacs = extract_tokens_in< token<kind::num> >( facPc, isNumber );

  auto otherFacs = extract_tokens_in< piece >( facPc, isOther );

  auto cumResult = std::accumulate( std::begin(numericFacs), std::end(numericFacs), cum_t({0,1}), cumulate_factors );

  if (numericFacs.empty()) {
    return edit_piece( facPc );
  }


  if (cumResult.reducedNums > 0) {

    if (cumResult.product == 0) {

      return make_num(0);

    } else {

      long reducedNum = static_cast<long>(cumResult.product);
      auto newNum = make_num( reducedNum );

      if (facPc->get_sign() == sign::neg) { newNum->flip_sign(); }

      if (otherFacs.empty()) {

        return newNum;

      } else {

        otherFacs.push_back( std::move(newNum) );
      }
    }
  }

  if (otherFacs.size() == 1) {
    return edit_piece( otherFacs.front().get() );
  } else {
    return make_token< kind::factors >( std::move(otherFacs) );
  }
}

template <>
template <>
own_piece_t
simplify<kind::factors>::run_step<reduce_step::factors_inner>(ctoken_t<kind::factors> facPc) {


  auto isFactor = [] (cpiece_t pc) { return pc->get_kind() == kind::factors; };
  auto isOther = [] (cpiece_t pc) { return pc->get_kind() != kind::factors; };

  auto innerFacs = extract_tokens_in< token<kind::factors> >( facPc, isFactor );

  auto otherToks = extract_tokens_in< piece >( facPc, isOther );

  if (innerFacs.empty()) {
    return edit_piece( facPc );
  }

  vec_own_piece_t liftedFactors;
  for (auto& innerFac : innerFacs) {

    auto inners = innerFac->get_tokens();

    std::transform(std::begin(inners), std::end(inners), std::back_inserter(liftedFactors), [] (cpiece_t pc) { return edit_piece(pc); } );
  }

  std::transform(std::begin(otherToks), std::end(otherToks), std::back_inserter(liftedFactors), [] (const own_piece_t& pc) { return edit_piece(pc.get()); } );
  
  auto retPc = fold_factors( transform_vec( liftedFactors, [] (const auto& own) { return static_cast<cpiece_t>(own.get()); } ) );

  if (facPc->get_sign() == sign::neg) { retPc->flip_sign(); }

  return retPc;
}


// template <>
// template <>
// own_piece_t
// simplify<kind::factors>::run_step<reduce_step::factors_inner>(ctoken_t<kind::factors> facPc) {
// 
//   std::cout << "FACTORS INNER GOT : " << facPc->get_pc_string() << '\n';
// 
//   auto isFactor = [] (cpiece_t pc) { return pc->get_kind() == kind::factors; };
//   auto isOther = [] (cpiece_t pc) { return pc->get_kind() != kind::factors; };
// 
//   auto innerFacs = extract_tokens_in< token<kind::factors> >( facPc, isFactor );
// 
//   auto otherToks = extract_tokens_in< piece >( facPc, isOther );
// 
//   if (innerFacs.size() > 1 or (innerFacs.size() == 1 and (not otherToks.empty()))) {
// 
//     for (auto& innerFac : innerFacs) {
// 
//       auto secElems = innerFac->get_tokens();
// 
//       std::transform(std::begin(secElems), std::end(secElems), std::back_inserter(otherToks), [] (cpiece_t pc) { return edit_piece(pc); } );
//     }
//     auto newFacs = simplify<kind::factors>::on( make_token< kind::factors >( std::move(otherToks) ) );
// 
//     if (facPc->get_sign() == sign::neg) { newFacs->flip_sign(); }
// 
//     return newFacs;
//   }
// 
//   return edit_piece( facPc );
// }

static
std::unique_ptr< token<kind::addends> >
contract_factors_addends( cpiece_t pc, ctoken_t<kind::addends> facPc ) {

  vec_own_piece_t newAdds;

  auto adds = facPc->get_tokens();
  for (auto add : adds) {
    newAdds.push_back( simplify<kind::factors>::on( make_token< kind::factors >( pc, add ) ) );
  }

  return make_token< kind::addends >( std::move(newAdds) );
}

// This function returns a single addends if there is at least one addends in the factors
template <>
template <>
own_piece_t
simplify<kind::factors>::run_step<reduce_step::factors_addends>(ctoken_t<kind::factors> facPc) {

  auto isAddend = [] (cpiece_t pc) { return pc->get_kind() == kind::addends; };
  auto isOther = [] (cpiece_t pc) { return pc->get_kind() != kind::addends; };

  auto innerAdds = extract_tokens_in< token<kind::addends> >( facPc, isAddend );

  auto otherToks = extract_tokens_in< piece >( facPc, isOther );
  
  if (innerAdds.empty() or (innerAdds.size() == 1 and otherToks.empty())) {

    return edit_piece( facPc );

  } else {

    // At least one addends and one 'other' or several addends and any 'other'

    vec_own_piece_t newFactors;

    if (otherToks.empty()) {

      // Several addends to collapse, no root. Collapse first 2 addends and recurse
      auto addsA = std::move(innerAdds.back()); innerAdds.pop_back();
      auto addsB = std::move(innerAdds.back()); innerAdds.pop_back();

      auto addsTksA = addsA->get_tokens();


      // addends * addends ---> addends. Addends reduced by 1
      vec_own_piece_t newAdds;

      for(auto& addA : addsTksA) {
        newAdds.push_back( simplify<kind::factors>::on( make_token< kind::factors >( addA, addsB ) ) );
      }

      newFactors.push_back( make_token< kind::addends >( std::move(newAdds) ) );


    } else {
      // other Toks not empty. Create a root from them

      auto rootPc = simplify<kind::factors>::on( make_token< kind::factors >( std::move(otherToks) ) );

      // Non-addend * addends ---> addends. Addends reduced by 1
      auto newAdds = contract_factors_addends( rootPc.get(), innerAdds.back().get() );
      innerAdds.pop_back();

      newFactors.push_back( std::move(newAdds) );
    }

    std::move(std::begin(innerAdds), std::end(innerAdds), std::back_inserter(newFactors));

    auto newFacs = simplify<kind::factors>::on( make_token< kind::factors >( std::move(newFactors) ) );
    if (facPc->get_sign() == sign::neg) { newFacs->flip_sign(); }
    return newFacs;
  }
}

template <>
template <>
own_piece_t
simplify<kind::factors>::run_step<reduce_step::factors_fractions>(ctoken_t<kind::factors> facPc) {

  // Only do it if it yields simplification

  auto isFraction = [] (cpiece_t pc) { return pc->get_kind() == kind::fraction; };
  auto isOther = [] (cpiece_t pc) { return pc->get_kind() != kind::fraction; };

  auto innerFracs = extract_tokens_in< token<kind::fraction> >( facPc, isFraction );
  auto otherToks = extract_tokens_in< piece >( facPc, isOther );

  if (innerFracs.empty() or innerFracs.size() + otherToks.size() < 2) {
    return edit_piece( facPc );
  }

  // Here we know there is at least one fraction and other thing (fraction or anything else)

  vec_cpiece_t newNumeratorFactors = transform_vec( otherToks, [] (const auto& own) { return static_cast<cpiece_t>(own.get()); } );
  vec_cpiece_t newDenominatorFactors;

  for (auto& frac : innerFracs) {

    newNumeratorFactors.push_back( frac->get_numerator() );
    newDenominatorFactors.push_back( frac->get_denominator() );
  }

  auto newFrac = simplify<kind::fraction>::on(
      make_token< kind::fraction >(
        fold_cfactors( newNumeratorFactors ),
        fold_cfactors( newDenominatorFactors )
      )
    );

  // if (facPc->get_flatten_terminals().size() > newFrac->get_flatten_terminals().size()) {
  //   // Then the new fraction resulted into a simplification
    if (facPc->get_sign() == sign::neg) { newFrac->flip_sign(); }
    return newFrac;
  // } else {
  //   return edit_piece( facPc );
  // }

}


} // namespace bld::src::pc
