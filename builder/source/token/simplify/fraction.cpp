
#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#include "source/token/simplify/interface.hpp"
#include "source/token/simplify/aux.hpp"
#include "source/token/make/token.hpp"

#include "source/token/combine/interface.hpp"

#include "common/util.hpp"

#include <iostream> // DBG XXX
#include <memory>
#include <numeric>
#include <algorithm>

#include "source/token/simplify/steps.hpp"



namespace bld::src::pc {



template <>
template <>
own_piece_t
simplify<kind::fraction>::run_step<reduce_step::fraction_zero>(ctoken_t<kind::fraction> fracPc) {

  auto num = fracPc->get_numerator();
  auto den = fracPc->get_denominator();

  if (are_equal( den, make_num(0).get() )) {
    throw std::runtime_error("Zero in denominator not allowed : " + fracPc->get_pc_string());
  }

  if (are_equal( num, make_num(0).get() )) {
    return make_num(0);
  }

  return edit_piece( fracPc );
}


// template <>
// template <>
// own_piece_t
// simplify<kind::fraction>::run_step<reduce_step::fraction_signs>(ctoken_t<kind::fraction> fracPc) {
// 
//   bool isMod = fracPc->is_mod();
//   
//   auto num = fracPc->get_numerator();
//   auto den = fracPc->get_denominator();
// 
//   if (num->is_terminal() and den->is_terminal()) {
// 
//     auto numTerm = static_unique_pointer_cast<terminal>( edit_piece(num) );
//     auto denTerm = static_unique_pointer_cast<terminal>( edit_piece(den) );
// 
//     if (numTerm->get_sign() == sign::neg and denTerm->get_sign() == sign::neg) {
//       numTerm->flip_sign();
//       denTerm->flip_sign();
//       return make_token< kind::fraction >( std::move(numTerm), std::move(denTerm), isMod );
//     }
//   } 
// 
//   return edit_piece( fracPc );
// }

template <>
template <>
own_piece_t
simplify<kind::fraction>::run_step<reduce_step::fraction_unit_denominator>(ctoken_t<kind::fraction> fracPc) {

  bool isMod = fracPc->is_mod();

  auto den = fracPc->get_denominator();

  if (den->get_kind() == kind::num and not isMod) {

    auto numericDen = static_cast<ctoken_t<kind::num>>(den);
    auto val = numericDen->get_value();
    sign s = numericDen->get_sign();

    if (val == 1 and s == sign::neg) {
      auto newNum = edit_piece( fracPc->get_numerator() );
      newNum->flip_sign();
      return newNum;
    } else if (val == 1 and s == sign::pos) {
      return edit_piece( fracPc->get_numerator() );
    } else {
      // Value not one
    }

  } else if (den->get_kind() == kind::num and isMod) {
    // Fall through
  }
  return edit_piece( fracPc );
}


template <>
template <>
own_piece_t
simplify<kind::fraction>::run_step<reduce_step::fraction_numbers>(ctoken_t<kind::fraction> fracPc) {

  bool isMod = fracPc->is_mod();

  auto num = fracPc->get_numerator();
  auto den = fracPc->get_denominator();

  if (num->get_kind() == kind::num and den->get_kind() == kind::num and not isMod) {

    auto numNum = static_cast<ctoken_t<kind::num>>(fracPc->get_numerator());
    auto denNum = static_cast<ctoken_t<kind::num>>(fracPc->get_denominator());

    auto numValue = numNum->get_value();
    auto denValue = denNum->get_value();

    if (numValue == 0 and denValue != 0) {
      return make_num(0);
    } else if (denValue == 0) {
      throw std::runtime_error("Cannot simplify fraction with 0 in denominator");
    }

    auto gcd = std::gcd( numValue, denValue );

    if (gcd > 1) {

      auto newNum = make_num( numValue / gcd );
      auto newDen = make_num( denValue / gcd );

      if (denValue / gcd == 1) {

        // Fraction --> number
        if (fracPc->get_sign() == sign::neg) { newNum->flip_sign(); }
        return newNum;

      } else {

        // Simplified fraction
        auto newFrac = make_token< kind::fraction >( std::move(newNum), std::move(newDen) );
        if (fracPc->get_sign() == sign::neg) { newFrac->flip_sign(); }
        return newFrac;
        
      }
    } 
  } else if (num->get_kind() == kind::num and den->get_kind() == kind::num and isMod) {

    auto numNum = static_cast<ctoken_t<kind::num>>(fracPc->get_numerator());
    auto denNum = static_cast<ctoken_t<kind::num>>(fracPc->get_denominator());

    auto redMod = make_num( numNum->get_value() % denNum->get_value() );
    if (fracPc->get_sign() == sign::neg) { redMod->flip_sign(); }
    return redMod;
  }

  return edit_piece( fracPc );
}


  template <typename TokT, unsigned ElemID>
  static
  std::vector<std::unique_ptr<TokT>> extract_tokens_in( ctoken_t<kind::fraction> fracPc, std::function<bool(cpiece_t)> satFn ) {
     
    std::vector<std::unique_ptr<TokT>> retVec;
  
    if ( fracPc->get_fraction_piece<ElemID>()->get_kind() == kind::factors) {
  
      auto innerFactorElems = static_cast<ctoken_t<kind::factors>>(fracPc->get_fraction_piece<ElemID>())->get_tokens();
  
      retVec = transform_vec_if(innerFactorElems, 
          satFn,
          [] (cpiece_t pc) {
            return static_unique_pointer_cast<TokT>( edit_piece(pc) );
          });
    } else if ( satFn(fracPc->get_fraction_piece<ElemID>()) ) {

      retVec.push_back( static_unique_pointer_cast<TokT>( edit_piece( fracPc->get_fraction_piece<ElemID>() ) ) );

    }
  
    return retVec;
  }



template <>
template <>
own_piece_t
simplify<kind::fraction>::run_step<reduce_step::fraction_inner>(ctoken_t<kind::fraction> fracPc) {


  bool isMod = fracPc->is_mod();
  if (isMod) {
    return edit_piece(fracPc);
  }

  auto isFrac = [] (cpiece_t pc) { return pc->get_kind() == kind::fraction; };
  auto fracsInNumerator = extract_tokens_in<token<kind::fraction>, 0>( fracPc, isFrac );
  auto fracsInDenominator = extract_tokens_in<token<kind::fraction>, 1>( fracPc, isFrac );


  if (fracsInNumerator.empty() and fracsInDenominator.empty()) {
    return edit_piece( fracPc );
  }

  auto isNotFrac = [] (cpiece_t pc) { return pc->get_kind() != kind::fraction; };
  auto newNumFactors = extract_tokens_in<piece, 0>( fracPc, isNotFrac );
  auto newDenFactors = extract_tokens_in<piece, 1>( fracPc, isNotFrac );


  for (auto& innerNumFrac : fracsInNumerator) {
    newNumFactors.emplace_back( edit_piece(innerNumFrac->get_numerator()) );
    newDenFactors.emplace_back( edit_piece(innerNumFrac->get_denominator()) );
  }

  for (auto& innerDenFrac : fracsInDenominator) {
    newNumFactors.emplace_back( edit_piece(innerDenFrac->get_denominator()) );
    newDenFactors.emplace_back( edit_piece(innerDenFrac->get_numerator()) );
  }

  auto newNumeratorMaybeFactors = fold_factors(   transform_vec( newNumFactors, [] ( const auto& own) { return static_cast<cpiece_t>(own.get()); } ) );
  auto newDenominatorMaybeFactors = fold_factors( transform_vec( newDenFactors, [] ( const auto& own) { return static_cast<cpiece_t>(own.get()); } ) );


  auto retPc = simplify<kind::fraction>::on( make_token< kind::fraction >( newNumeratorMaybeFactors, newDenominatorMaybeFactors) );


  if (fracPc->get_sign() == sign::neg) { retPc->flip_sign(); }

  return retPc;
}


template <>
template <>
own_piece_t
simplify<kind::fraction>::run_step<reduce_step::fraction_numbers_in_factors>(ctoken_t<kind::fraction> fracPc) {

  bool isMod = fracPc->is_mod();
  if (isMod) {
    return edit_piece(fracPc);
  }

  auto isNum = [] (cpiece_t pc) { return pc->get_kind() == kind::num; };
  auto numsInNumerator = extract_tokens_in<piece, 0>( fracPc, isNum );
  auto numsInDenominator = extract_tokens_in<piece, 1>( fracPc, isNum );



  auto isNotNum = [] (cpiece_t pc) { return pc->get_kind() != kind::num and pc->get_kind() != kind::factors; };
  auto newNumFactors = extract_tokens_in<piece, 0>( fracPc, isNotNum );
  auto newDenFactors = extract_tokens_in<piece, 1>( fracPc, isNotNum );

  if (newNumFactors.empty() and newDenFactors.empty()) {
    // This is a numeric fraction, already reduced if possible, so skip
    return edit_piece( fracPc );
  }
  if (numsInNumerator.empty() or numsInDenominator.empty()) {
    // No numbers in this fraction, so skip
    return edit_piece( fracPc );
  }


  newNumFactors.emplace_back( simplify<kind::fraction>::on( make_token< kind::fraction >(
      make_token< kind::factors >( std::move(numsInNumerator) ),
      make_token< kind::factors >( std::move(numsInDenominator) )
    )) );

  if (newDenFactors.empty() and (not newNumFactors.empty())) {

    return make_token< kind::factors >( std::move(newNumFactors) );

  } else if ((not newDenFactors.empty()) and newNumFactors.empty()) {
    return make_token< kind::fraction >(
        make_num(1),
        make_token< kind::factors >( std::move(newDenFactors) )
      );

  } else {
    // Both non-empty
    return make_token< kind::fraction >(
        make_token< kind::factors >( std::move(newNumFactors) ),
        make_token< kind::factors >( std::move(newDenFactors) )
      );
  }
}

template <>
template <>
own_piece_t
simplify<kind::fraction>::run_step<reduce_step::fraction_vars_in_factors>(ctoken_t<kind::fraction> fracPc) {

  bool isMod = fracPc->is_mod();
  if (isMod) {
    return edit_piece(fracPc);
  }


  auto isVar = [] (cpiece_t pc) { return pc->get_kind() == kind::var; };
  auto varsInNumerator = extract_tokens_in< token<kind::var>, 0 >( fracPc, isVar );
  auto varsInDenominator = extract_tokens_in< token<kind::var>, 1 >( fracPc, isVar );

  auto isNotVar = [] (cpiece_t pc) { return pc->get_kind() != kind::var and pc->get_kind() != kind::factors; };
  auto newNumFactors = extract_tokens_in<piece, 0>( fracPc, isNotVar );
  auto newDenFactors = extract_tokens_in<piece, 1>( fracPc, isNotVar );


  if (varsInNumerator.empty() or varsInDenominator.empty()) {
    // No vars in this fraction, so skip
    return edit_piece( fracPc );
  }

  std::vector<unsigned> varsNumerToRemove;
  std::vector<unsigned> varsDenomToRemove;

  auto numId = 0u;
  auto denId = 0u;
  for (auto& numer : varsInNumerator) {
    auto numerVar = numer.get();
    denId = 0u;
    for (auto& denom : varsInDenominator) {
      auto denomVar = denom.get();
      if (std::find(std::begin(varsNumerToRemove), std::end(varsNumerToRemove), numId) == std::end(varsNumerToRemove) and
          std::find(std::begin(varsDenomToRemove), std::end(varsDenomToRemove), denId) == std::end(varsDenomToRemove)) {
        if (are_equal(numerVar, denomVar)) {
          varsNumerToRemove.push_back( numId );
          varsDenomToRemove.push_back( denId );
        } else {
          // Not equal
        }
      } else {
        // Already cancelled
      }
      denId++;
    }
    numId++;
  }

  // Reverse order, so following erases do not invalidate unsafe iterators
  auto fnReverse = [] (unsigned a, unsigned b) { return a > b; };
  std::sort(std::begin(varsNumerToRemove), std::end(varsNumerToRemove), fnReverse);
  for (auto i : varsNumerToRemove) {
    varsInNumerator.erase( std::begin(varsInNumerator) + i );
  }

  std::sort(std::begin(varsDenomToRemove), std::end(varsDenomToRemove), fnReverse);
  for (auto i : varsDenomToRemove) {
    varsInDenominator.erase( std::begin(varsInDenominator) + i );
  }

  std::move(std::begin(varsInNumerator), std::end(varsInNumerator), std::back_inserter(newNumFactors));
  std::move(std::begin(varsInDenominator), std::end(varsInDenominator), std::back_inserter(newDenFactors));

  if (newNumFactors.empty()) {
    newNumFactors.push_back( make_num(1) );
  }

  if (newDenFactors.empty()) {

    if (newNumFactors.size() == 1) {
      
      auto retPc = std::move( newNumFactors.front() );

      if (fracPc->get_sign() == sign::neg) { retPc->flip_sign(); }

      return retPc;
      
    } else {

      auto newFactors = make_token< kind::factors >( std::move(newNumFactors) );


      if (fracPc->get_sign() == sign::neg) { newFactors->flip_sign(); }

      return simplify<kind::factors>::on( newFactors.get() );

    }

  } else {

    auto newFrac = make_token< kind::fraction >(
        simplify<kind::factors>::on( make_token< kind::factors >( std::move(newNumFactors) ) ),
        simplify<kind::factors>::on( make_token< kind::factors >( std::move(newDenFactors) ) )
      );


    if (fracPc->get_sign() == sign::neg) { newFrac->flip_sign(); }
    
    return simplify<kind::fraction>::run_step<reduce_step::fraction_unit_denominator>( newFrac.get() );
  }

}

template <>
template <>
own_piece_t
simplify<kind::fraction>::run_step<reduce_step::fraction_addends_single_den>(ctoken_t<kind::fraction> fracPc) {

  bool isMod = fracPc->is_mod();
  if (isMod) {
    return edit_piece(fracPc);
  }

  auto num = fracPc->get_numerator();
  auto den = fracPc->get_denominator();

  if (num->get_kind() == kind::addends and den->get_kind() != kind::addends) {

    auto addsInNumerator = static_cast<const multiple*>(num)->get_tokens();

    vec_own_piece_t newAdds;

    for (auto add : addsInNumerator) {
      newAdds.push_back( make_token< kind::fraction >( add, den ) );
    }

    return simplify<kind::addends>::on( make_token< kind::addends >( std::move(newAdds) ) );

  } else {
    return edit_piece( fracPc );
  }

}

template <>
template <>
own_piece_t
simplify<kind::fraction>::run_step<reduce_step::fraction_raw_strings>(ctoken_t<kind::fraction> fracPc) {

  bool isMod = fracPc->is_mod();
  if (isMod) {
    return edit_piece(fracPc);
  }

  auto num = fracPc->get_numerator();
  auto den = fracPc->get_denominator();

  if (num->get_pc_string() == den->get_pc_string()) {
    return make_num(1);
  } else {
    return edit_piece(fracPc);
  }
}


} // namespace bld::src::pc
