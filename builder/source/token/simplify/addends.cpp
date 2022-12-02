
#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#include "source/token/simplify/interface.hpp"
#include "source/token/simplify/aux.hpp"


#include "common/util.hpp"
#include "source/token/simplify/extract.hpp"

#include "source/token/combine/interface.hpp"

#include <iostream> // DBG XXX
#include <memory>
#include <numeric>
#include <algorithm>


#include "source/token/simplify/steps.hpp"



namespace bld::src::pc {


static
long cumulate_addends(const long cum, const own_token_t<kind::num>& num) {
  long val = ((long)num->get_value()) * (num->get_sign() == sign::neg ? -1 : 1);
  return cum + val; 
}



template <>
template <>
own_piece_t
simplify<kind::addends>::run_step<reduce_step::addends_numbers>(ctoken_t<kind::addends> addsPc) {

  auto isNumber = [] (cpiece_t pc) { return pc->get_kind() == kind::num; };
  auto isOther = [] (cpiece_t pc) { return pc->get_kind() != kind::num; };

  auto addends = addsPc->get_tokens();

  auto numericAdds = extract_tokens_in< token<kind::num> >( addsPc, isNumber );
  auto otherAdds = extract_tokens_in< piece >( addsPc, isOther );
  
  auto cumResult = std::accumulate( std::begin(numericAdds), std::end(numericAdds), long(0), cumulate_addends );

  if (otherAdds.empty()) {

    return make_num( cumResult );

  } else if ((not otherAdds.empty()) and cumResult != 0) {

    otherAdds.push_back( make_num( cumResult ) );

    return make_token< kind::addends >( std::move(otherAdds) );

  } else { // if ((not otherAdds.empty()) and cumResult == 0)

    return make_token< kind::addends >( std::move(otherAdds) );
  }
}

static
std::pair<long, long> get_fraction_sum( std::vector<std::pair<long,long>>& pairNumbers ) {

  auto currentLCM = 1;
  for (auto [n, d] : pairNumbers) {
    currentLCM = std::lcm(currentLCM, d);
  }

  auto sum = 0;
  for (const auto& numDen : pairNumbers) {
    auto mul = currentLCM / numDen.second;

    auto newAdd = numDen.first * mul * (numDen.second < 0 ? (-1) : 1);
    sum += newAdd;
  }

  if (sum % currentLCM == 0) {
    return std::make_pair(sum / currentLCM, 1);
  } else {
    return std::make_pair(sum, currentLCM);
  }
}


template <>
template <>
own_piece_t
simplify<kind::addends>::run_step<reduce_step::addends_numbers_with_fractions>(ctoken_t<kind::addends> addsPc) {

  auto isNumeric = [] (cpiece_t pc) { return (pc->get_kind() == kind::fraction and static_cast<ctoken_t<kind::fraction>>(pc)->is_numeric()) or pc->get_kind() == kind::num; };
  auto isOther = [&] (cpiece_t pc) { return not isNumeric(pc); };

  auto allToks = addsPc->get_tokens();

  auto numericAdds = extract_tokens_in< piece >( addsPc, isNumeric );
  if (numericAdds.size() < 2) {
    return edit_piece( addsPc );
  }
  auto otherAdds = extract_tokens_in< piece >( addsPc, isOther );

  auto toFracLambda = [] (cpiece_t pc) -> std::pair<long, long> {
    bool isNeg = (pc->get_sign() == sign::neg);
    if (pc->get_kind() == kind::fraction) {
      auto fracElm = static_cast<ctoken_t<kind::fraction>>(pc);
      auto numElm = static_cast<ctoken_t<kind::num>>(fracElm->get_numerator());
      auto denElm = static_cast<ctoken_t<kind::num>>(fracElm->get_denominator());
      return std::make_pair(
        isNeg ? (-1)*numElm->get_value() : numElm->get_value(),
        denElm->get_value()
      );
    } else {
      auto numElm = static_cast<ctoken_t<kind::num>>(pc);
      return std::make_pair(isNeg ? (-1)*numElm->get_value() : numElm->get_value(), 1);
    }
  };


  auto fracNumbers = transform_vec_if( allToks, isNumeric, toFracLambda );

  auto [numVal, denVal] = get_fraction_sum(fracNumbers);

  auto simplFrac = simplify<kind::fraction>::on( make_token< kind::fraction >( make_num( numVal ), make_num( denVal ) ) );

  if (otherAdds.empty()) {
    return simplFrac;
  } else {
    otherAdds.push_back( std::move(simplFrac) );
    return make_token< kind::addends >( std::move(otherAdds) );
  }
}


template <>
template <>
own_piece_t
simplify<kind::addends>::run_step<reduce_step::addends_inner>(ctoken_t<kind::addends> addsPc) {

  auto isAddend = [] (cpiece_t pc) { return pc->get_kind() == kind::addends; };
  auto isOther = [] (cpiece_t pc) { return pc->get_kind() != kind::addends; };

  auto innerAdds = extract_tokens_in< token<kind::addends> >( addsPc, isAddend );

  auto otherToks = extract_tokens_in< piece >( addsPc, isOther );

  if (innerAdds.size() > 1 or (innerAdds.size() == 1 and (not otherToks.empty()))) {

    for (auto& innerAdd : innerAdds) {

      auto secElems = innerAdd->get_tokens();
  
      std::transform(std::begin(secElems), std::end(secElems), std::back_inserter(otherToks), [] (cpiece_t pc) { return edit_piece(pc); } );
    }
    if (otherToks.size() == 1) {
      return std::move( otherToks.front() );
    } else {
      return make_token< kind::addends >( std::move(otherToks) );
    }
  }

  return edit_piece( addsPc );
}

// template <>
// template <>
// own_piece_t
// simplify<kind::addends>::run_step<reduce_step::addends_vars>(ctoken_t<kind::addends> addsPc) {
// 
//   auto isVar = [] (cpiece_t pc) { return pc->get_kind() == kind::var; };
// 
//   auto isOther = [] (cpiece_t pc) { return pc->get_kind() != kind::var; };
// 
//   auto vars = extract_tokens_in< token<kind::var> >( addsPc, isVar );
// 
//   // std::cout << "Vars : " << vars.size() << '\n';
// 
//   std::vector<unsigned> posToErase;
// 
//   for (auto i = 0u; i < vars.size(); ++i) {
//     auto pcA = vars[i].get();
//     for (auto j = i+1; j < vars.size(); ++j) {
// 
//       if (std::find(std::begin(posToErase), std::end(posToErase), j) == std::end(posToErase)) {
// 
//         auto pcB = vars[j].get();
// 
//         // std::cout << " varA : " << maybe_erase_neg(pcA->get_pc_string()) << '\n';
//         // std::cout << " varB : " << maybe_erase_neg(pcB->get_pc_string()) << '\n';
//         if (pcA->get_sign() != pcB->get_sign() and maybe_erase_neg(pcA->get_pc_string()) == maybe_erase_neg(pcB->get_pc_string())) {
// 
//           posToErase.push_back(i);
//           posToErase.push_back(j);
//           break;
//         }
//       }
//     }
//   }
// 
// 
//   // Reverse order, so following erases do not invalidate unsafe iterators
//   std::sort(std::begin(posToErase), std::end(posToErase), [] (unsigned a, unsigned b) { return a > b; });
//   for (auto i : posToErase) {
//     vars.erase( std::begin(vars) + i );
//   }
// 
//   auto otherToks = extract_tokens_in< piece >( addsPc, isOther );
// 
//   std::move(std::begin(vars), std::end(vars), std::back_inserter(otherToks));
// 
//   if (otherToks.empty()) {
//     otherToks.push_back( make_num(0) );
//   }
// 
//   return make_token< kind::addends >( std::move(otherToks) );
// }


// template <>
// template <>
// own_piece_t
// simplify<kind::addends>::run_step<reduce_step::addends_factors>(ctoken_t<kind::addends> addsPc) {
// 
//   auto isFactor = [] (cpiece_t pc) { return pc->get_kind() == kind::factors; };
// 
//   auto isOther = [] (cpiece_t pc) { return pc->get_kind() != kind::factors; };
// 
//   auto facs = extract_tokens_in< token<kind::factors> >( addsPc, isFactor );
// 
// 
//   std::vector<unsigned> posToErase;
// 
//   for (auto i = 0u; i < facs.size(); ++i) {
// 
//     for (auto j = i+1; j < facs.size(); ++j) {
// 
//       if (std::find(std::begin(posToErase), std::end(posToErase), j) == std::end(posToErase)) {
// 
//         auto fracAoverB = simplify<kind::fraction>::on( make_token< kind::fraction >( facs[i], facs[j] ) );
// 
//         // std::cout << "Simplified " << fracAoverB->get_pc_string() << '\n';
//         if (are_equal( fracAoverB.get(), make_num(-1).get() )) {
// 
//           posToErase.push_back(i);
//           posToErase.push_back(j);
//           break;
//         }
//       }
//     }
//   }
// 
//   // Reverse order, so following erases do not invalidate unsafe iterators
//   std::sort(std::begin(posToErase), std::end(posToErase), [] (unsigned a, unsigned b) { return a > b; });
//   for (auto i : posToErase) {
//     facs.erase( std::begin(facs) + i );
//   }
// 
//   auto otherToks = extract_tokens_in< piece >( addsPc, isOther );
// 
//   std::move(std::begin(facs), std::end(facs), std::back_inserter(otherToks));
// 
//   if (otherToks.empty()) {
//     otherToks.push_back( make_num(0) );
//   }
// 
//   if (otherToks.size() == 1) {
//     return std::move(otherToks.front());
//   } else {
//     return make_token< kind::addends >( std::move(otherToks) );
//   }
// }


template <>
template <>
own_piece_t
simplify<kind::addends>::run_step<reduce_step::addends_num_factors>(ctoken_t<kind::addends> addsPc) {

  // std::cout << "SIMPLIFYING ADDENDS : " << addsPc->get_pc_string() << " : " << addsPc->get_kind() << '\n';

  // auto isFactor = [] (cpiece_t pc) { return pc->get_kind() == kind::factors; };
  // auto isOther = [] (cpiece_t pc) { return pc->get_kind() != kind::factors; };

  auto allAdds = addsPc->get_tokens(); // extract_tokens_in< token<kind::factors> >( addsPc, isFactor );

  // for (auto add : allAdds) {
  //   std::cout << "RECEIVING : " << add->get_pc_string() << " as " << add->get_kind() << '\n';
  // }

  auto isNumber = [] (cpiece_t pc) { return pc->get_kind() == kind::num; };
  auto isNotNumber = [] (cpiece_t pc) { return pc->get_kind() != kind::num; };

  vec_own_token_t<kind::num> nums;
  vec_own_piece_t numFacs;
  std::vector<sign> signs;

  for (auto& innerAdd : allAdds) {

    auto numPcs =  extract_tokens_in< token<kind::num> >( innerAdd, isNumber );

    if (numPcs.empty()) {

      nums.push_back( make_num(1) );
    } else if (numPcs.size() == 1) {
      nums.push_back( static_unique_pointer_cast< token<kind::num> >( std::move(numPcs.front()) ) );

    } else {
      auto redNum = simplify<kind::factors>::on( make_token< kind::factors >( transform_vec(numPcs, [](const own_token_t<kind::num>& pc) { return edit_piece(pc.get()); }) ) );
      if (redNum->get_kind() != kind::num) { throw std::logic_error("Expected kind::num in addends_num_factors"); }
      nums.push_back( static_unique_pointer_cast< token<kind::num> >( std::move(redNum) ) );
    }

    auto notNumPcs = extract_tokens_in< piece >( innerAdd, isNotNumber );

    if (notNumPcs.empty()) {
      numFacs.push_back( make_num(1) );
    } else if (notNumPcs.size() == 1) {
      numFacs.push_back( std::move(notNumPcs.front()) );
    } else {
      numFacs.push_back( simplify<kind::factors>::on( make_token<kind::factors>( std::move(notNumPcs) ) ) );
    }

    signs.push_back( innerAdd->get_sign() );

    // std::cout << "Decomp num : " << innerAdd->get_pc_string() << " : " << nums.back()->get_pc_string() << ", kind : " << nums.back()->get_kind() << '\n';
    // std::cout << "Decomp fac : " << innerAdd->get_pc_string() << " : " << numFacs.back()->get_pc_string() << ", kind : " << numFacs.back()->get_kind() << '\n';
  }

  vec_own_piece_t newToks;

  std::set<unsigned, std::greater<unsigned>> posToErase;

  for (auto idA = 0u; idA < allAdds.size(); idA++) {

    vec_own_token_t< kind::num > numsToReduce;
    for (auto idB = idA + 1; idB < allAdds.size(); idB++) {
      if (std::find(std::begin(posToErase), std::end(posToErase), idB) == std::end(posToErase) and
          are_equal(numFacs[idA].get(), numFacs[idB].get())) {

        numsToReduce.push_back( make_num( nums[idB]->get_value() ) );
        if (signs[idB] == sign::neg) { numsToReduce.back()->flip_sign(); }
        posToErase.insert( idA );
        posToErase.insert( idB );
      }
    }
    if (not numsToReduce.empty()) {
      numsToReduce.push_back( make_num( nums[idA]->get_value() ) );
      if (signs[idA] == sign::neg) { numsToReduce.back()->flip_sign(); }
      auto numsToReduceRaw = transform_vec( numsToReduce, [] (const auto& own) { return static_cast<cpiece_t>(own.get()); } );
      auto partialAdds = simplify_piece( fold_caddends( numsToReduceRaw ) ); // make_token< kind::addends >( transform_vec(numsToReduce, [](const own_token_t<kind::num>& pc) { return edit_piece(pc.get()); }) ) );
      // std::cout << "Partial adds : " << partialAdds->get_pc_string() << '\n';
      newToks.push_back( simplify_piece( make_token< kind::factors >( partialAdds, numFacs[idA] ) ) );
    }
  }

  for (auto i : posToErase) {
    allAdds.erase( std::begin(allAdds) + i );
  }
  for (auto& rem : allAdds) {
    newToks.push_back( edit_piece(rem) );
  }

  if (newToks.empty()) {
    return edit_piece( addsPc );
  } else if (newToks.size() == 1) {
    return simplify_piece( newToks.front() );
  } else {
    auto newAdds = make_token< kind::addends >( std::move(newToks) );
    if (newAdds->get_token_count() == 1) {
      // Need to simplify again, because addends obj may remain with 1 object (if any in newToks is 0)
      return simplify_piece( newAdds->get_tokens().front() );
    }
    return newAdds;
  }
}

} // namespace bld::src::pc
