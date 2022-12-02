
#include "source/token/factorize.hpp"

#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#include "source/token/simplify/interface.hpp"
#include "source/token/combine/interface.hpp"

#include "common/util.hpp"

#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <iostream> // DBG XXX

namespace bld::src::pc {


///////////////
//
// INTERFACE
//
///////////////
own_piece_t extract_factors(cpiece_t inputPc, pred_fun_t fnPivot) {

  // std::cout << "Extracting factors of " << inputPc->get_kind() << " : " << inputPc->get_pc_string() << '\n';

  // fnPivot returns true if the piece is satisfied

  auto pcHasPivot = [fnPivot] (cpiece_t pc) -> bool {
        auto lmbd = fnPivot;
        auto vec = pc->gather_pieces_satisfying( std::move(lmbd) );
        return (not vec.empty());
      };

  auto onePc = make_num(1);

  own_piece_t retPiece;

  if (inputPc->get_kind() == kind::num) {

    retPiece = edit_piece( inputPc );

  } else if (inputPc->get_kind() == kind::var) {

    if (fnPivot(inputPc)) {
      if (inputPc->get_sign() == sign::neg) {
        retPiece = make_num(-1);
      } else {
        retPiece = make_num(1);
      }
    }

  } else if (inputPc->get_kind() == kind::addends) {

    vec_cpiece_t addendsWithPivot;

    auto elms = static_cast<const multiple*>(inputPc)->get_tokens();

    if (elms.size() == 1) {
      retPiece = extract_factors( elms.front(), fnPivot );
    } else {

      std::copy_if(
          std::begin(elms), std::end(elms),
          std::back_inserter(addendsWithPivot),
          pcHasPivot
          );

      auto newAddends = transform_vec( addendsWithPivot, std::bind(extract_factors, std::placeholders::_1, fnPivot) );

      retPiece = simplify_piece( make_token< kind::addends >( std::move(newAddends) ) );

    }

  } else if (inputPc->get_kind() == kind::factors) {

    auto elms = static_cast<const multiple*>(inputPc)->get_tokens();

    if (elms.size() == 1) {
      // a kind::factors token with single element, due to '1' elimination, to be degraded to a terminal
      retPiece = extract_factors( elms.front(), fnPivot );
    } else {

      auto foundIt = std::find_if(std::begin(elms), std::end(elms), fnPivot);
      if (foundIt != std::end(elms)) {


        elms.erase( std::remove_if(std::begin(elms), std::end(elms), fnPivot ), elms.end() );

        auto remain = edit_piece_vector(elms);
        auto facs = make_token< kind::factors >( std::move(remain) );

        if (inputPc->get_sign() == sign::neg) { facs->flip_sign(); }

        retPiece = simplify_piece( facs );
        
      } else {

        vec_cpiece_t factorsWithPivot;

        auto elms = static_cast<const multiple*>(inputPc)->get_tokens();


        std::copy_if(
            std::begin(elms), std::end(elms),
            std::back_inserter(factorsWithPivot),
            pcHasPivot
            );

        vec_own_piece_t newFactors;

        if (not factorsWithPivot.empty()) {
          elms.erase( std::remove_if(std::begin(elms), std::end(elms), pcHasPivot ), elms.end() );
          newFactors = edit_piece_vector( elms );
        }

        std::transform(
            std::begin(factorsWithPivot), std::end(factorsWithPivot),
            std::back_inserter(newFactors), 
            std::bind(extract_factors, std::placeholders::_1, std::forward<pred_fun_t>(fnPivot))
          );

        auto newFacs = make_token< kind::factors >( std::move(newFactors) );

        if (inputPc->get_sign() == sign::neg) { newFacs->flip_sign(); }

        retPiece = simplify_piece( newFacs );
      }

    }

  } else if (inputPc->get_kind() == kind::fraction) {

    auto frac = static_cast<ctoken_t<kind::fraction>>(inputPc);

    auto num = frac->get_numerator();
    auto den = frac->get_denominator();

    if (fnPivot(den)) {
      throw std::runtime_error("Expression must be linear on LV : " + inputPc->get_pc_string() + " wrt LV : " + frac->get_denominator()->get_pc_string());
    }

    if (fnPivot(num)) {

      auto newFrac = make_token< kind::fraction >( make_num(1), den );

      if (inputPc->get_sign() == sign::neg) { newFrac->flip_sign(); }

      retPiece = simplify_piece( newFrac );

    } else if (pcHasPivot(num)) {

      retPiece = make_token< kind::fraction >( extract_factors( num, fnPivot ), den );
    }
  }
  
  if (retPiece.get() == nullptr) {
    retPiece = make_num(0);
  }

//  std::cout << "EXTRACT FACTORS RETURN : " << retPiece->get_pc_string() << ". FROM : " << inputPc->get_pc_string() << '\n';
  return retPiece;
}


own_piece_t extract_non_factors(cpiece_t inputPc, pred_fun_t fnPivot) {

  // std::cout << "Extracting non-factors of " << inputPc->get_kind() << " : " << inputPc->get_pc_string() << '\n';

  auto pcWithPivot = [fnPivot] (cpiece_t pc) -> bool {
        auto lmbd = fnPivot;
        auto vec = pc->gather_pieces_satisfying( std::move(lmbd) );
        return (not vec.empty());
      };

  auto pcWithoutPivot = [fnPivot] (cpiece_t pc) -> bool {
        auto lmbd = fnPivot;
        auto vec = pc->gather_pieces_satisfying( std::move(lmbd) );
        return (vec.empty());
      };

  own_piece_t retPiece;

  if (inputPc->get_kind() == kind::num) {

     retPiece = edit_piece( inputPc );

  } else if (inputPc->get_kind() == kind::var) {

    if (not fnPivot(inputPc)) {
    
      retPiece = edit_piece( inputPc );

    } else {
      retPiece = make_num(0);
    }

  } else if (inputPc->get_kind() == kind::addends) {

    if (pcWithoutPivot(inputPc)) {
      retPiece = edit_piece( inputPc );
    } else {

      auto elms = static_cast<const multiple*>(inputPc)->get_tokens();

      vec_cpiece_t addendsWithoutPivot;
      std::copy_if(
          std::begin(elms), std::end(elms),
          std::back_inserter(addendsWithoutPivot),
          pcWithoutPivot
          );

      vec_cpiece_t addendsWithPivot;
      std::copy_if(
          std::begin(elms), std::end(elms),
          std::back_inserter(addendsWithPivot),
          pcWithPivot
          );


      auto newAddends = transform_vec(addendsWithoutPivot, [] (cpiece_t pc) { return edit_piece(pc); });

      for (auto pcWithPivot : addendsWithPivot) {
        newAddends.push_back( extract_non_factors( pcWithPivot, fnPivot ) );     
      }
          
      retPiece = simplify_piece( make_token< kind::addends >( std::move(newAddends) ) );
    }

  } else if (inputPc->get_kind() == kind::factors) {

    if (pcWithoutPivot(inputPc)) {
      retPiece = edit_piece( inputPc );
    } else {

      auto elms = static_cast<const multiple*>(inputPc)->get_tokens();

      vec_cpiece_t factorsWithoutPivot;
      std::copy_if(
          std::begin(elms), std::end(elms),
          std::back_inserter(factorsWithoutPivot),
          pcWithoutPivot
          );

      vec_cpiece_t factorsWithPivot;
      std::copy_if(
          std::begin(elms), std::end(elms),
          std::back_inserter(factorsWithPivot),
          pcWithPivot
          );


      auto newFactors = transform_vec(factorsWithoutPivot, [] (cpiece_t pc) { return edit_piece(pc); });

      for (auto pcWithPivot : factorsWithPivot) {
        newFactors.push_back( extract_non_factors( pcWithPivot, fnPivot ) );     
      }

      retPiece = simplify_piece( make_token< kind::factors >( std::move(newFactors) ) );

    }

  } else if (inputPc->get_kind() == kind::fraction) {

    auto frac = static_cast<ctoken_t<kind::fraction>>(inputPc);

    auto num = frac->get_numerator();
    auto den = frac->get_denominator();

    if (fnPivot(den)) {
      throw std::runtime_error("Expression must be linear on LV : " + inputPc->get_pc_string() + " wrt LV : " + frac->get_denominator()->get_pc_string());
    }

    if (fnPivot(num) or pcWithPivot(num)) {

      retPiece = make_num(0);

    } else {
      retPiece = simplify_piece( inputPc );
    }

  } else {
    throw std::logic_error("Unhandled case in extract_non_factors : kind::" + std::string(util::enum_convert<kind>::to_string_rt(inputPc->get_kind())));
  }


  if (retPiece.get() == nullptr) {
    retPiece = make_num(0);
  }

  // std::cout << "EXTRACT NON - FACTORS RETURN : " << retPiece->get_pc_string() << ". FROM : " << inputPc->get_pc_string() << '\n';
  return retPiece;
}





vec_cpiece_t get_children_factors(cpiece_t inPc) {

  vec_cpiece_t factorPieces;
  if (inPc->is_multiple() and inPc->get_kind() == kind::factors) {

    factorPieces = static_cast<ctoken_t<kind::factors>>( inPc )->get_tokens();

  } else if (inPc->is_multiple() and inPc->get_kind() == kind::addends) {

    factorPieces.push_back( inPc );

  } else if (inPc->is_multiple() and inPc->get_kind() == kind::fraction) {

    factorPieces.push_back( inPc );

  } else if (inPc->is_terminal()) {

    factorPieces.push_back( inPc );

  } else {
    throw std::logic_error("Unreachable. Cannot get_children_factors from : " + inPc->get_pc_string() + ". kind : " + std::string(util::enum_convert<kind>::to_string_rt(inPc->get_kind())));
  }

  return factorPieces;
}


own_piece_t extract_common_factors(cpiece_t lhsPc, cpiece_t rhsPc) {

  auto zeroNum = make_num(0);

  if (are_equal( lhsPc, zeroNum.get() ) or are_equal( rhsPc, zeroNum.get() )) {
    return zeroNum;
  }

  auto inLhsPc = simplify_piece( lhsPc );
  auto inRhsPc = simplify_piece( rhsPc );

  auto lhsFactorPieces = get_children_factors(inLhsPc.get());
  auto rhsFactorPieces = get_children_factors(inRhsPc.get());

  vec_cpiece_t intersection;

  std::set_intersection(
      std::begin(lhsFactorPieces), std::end(lhsFactorPieces),
      std::begin(rhsFactorPieces), std::end(rhsFactorPieces),
      std::back_inserter(intersection),
      [] (cpiece_t lhsFactor, cpiece_t rhsFactor) {
        if (are_equal( lhsFactor, rhsFactor ) or (are_equal( rhsFactor, lhsFactor ))) {
          // Always return false if they are equal, so equivalent under set_intersection algorithm
          return false; 
        } else {
          // Will return true at least in one direction => not equivalent
          return lhsFactor->get_pc_string() < rhsFactor->get_pc_string();
        }
      });

  if (intersection.empty()) {
    return make_num(1);
  } else if (intersection.size() == 1) {
    return edit_piece( intersection.front() );
  } else {
    return make_token< kind::factors >( edit_piece_vector(intersection) );
  }
}




own_piece_t extract_addends( cpiece_t pc, std::function<bool(cpiece_t)> fnSatisfy ) {

  own_piece_t retPiece;

  if (pc->is_terminal() or pc->get_kind() == kind::factors or pc->get_kind() == kind::fraction) {


    if ( fnSatisfy(pc) ) {
      retPiece = edit_piece( pc );
    } else {
      retPiece = make_num(0);
    }

  } else {

    if (pc->get_kind() == kind::addends) {

      auto adds = static_cast<ctoken_t<kind::addends>>(pc)->get_tokens();

      // std::cout << "EXTRACT_ADDENDS RECEIVED ADDENDS OF SIZE : " << adds.size() << '\n';
      // for (auto add : adds) {
      //   std::cout << "add indiv : " << add->get_kind() << " : " << add->get_pc_string() << '\n';
      // }

      
      auto retAdds = transform_vec_if(adds,
          fnSatisfy,
          [] (cpiece_t pcAdd) {
            return edit_piece( pcAdd );
          });
      // Following would be robust against decayable addends.
      // auto retAdds = transform_vec_if( adds, fnSatisfy, std::bind(extract_addends, std::placeholders::_1, fnSatisfy) );

      // for (auto& add : retAdds) {
      //   std::cout << "add filter : " << add->get_kind() << " : " << add->get_pc_string() << '\n';
      // }

    retPiece = make_token< kind::addends >( std::move(retAdds) );

    } else {
      throw std::logic_error("Unreachable in decompose addends : " + std::string(util::enum_convert<kind>::to_string_rt(pc->get_kind())));
    }
  }

  if (retPiece.get() == nullptr) {
    throw std::logic_error("Could not extract_addends. No pieces satisfying function");
  }

  // if (retAdds.size() == 1) {

  //   retPiece = edit_piece( retAdds.front() );

  // } else {
  //   retPiece = make_token< kind::addends >( std::move(retAdds) );
  // }

  // std::cout << "EXTRACT_ADDENDS RETURN : " << retPiece->get_pc_string() << ". FROM " << pc->get_kind() << " : " << pc->get_pc_string() << '\n';

  return retPiece;
}



///////////////
//
// INTERFACE
//
///////////////
unsigned count_contiguous_factors(cpiece_t inputPc, pred_fun_t fnPivot) {

  if (not inputPc->is_arith()) {
    throw std::runtime_error("Could not count_contiguous_factors : Not an arithmetic piece : " + inputPc->get_pc_string());
  }

  // Returns the max number of pcs that satisfy fnPivot and are present in the same kind::factors
  // If fnPivot marks Loop variables and this:
  // · Returns 0 => inputPc is a point expression
  // · Returns 1 => inputPc is an affine expression
  // · Returns > 1 => inputPc is a non-affine/linear expression : loopvars are multiplying

  if (inputPc->is_terminal()) {

    return (fnPivot(inputPc) ? 1 : 0);

  } else if (inputPc->get_kind() == kind::addends) {

    auto adds = static_cast<ctoken_t<kind::addends>>(inputPc)->get_tokens();

    auto countAdds = transform_vec( adds, std::bind(count_contiguous_factors, std::placeholders::_1, fnPivot) );

    return *std::max_element(std::begin(countAdds), std::end(countAdds));
    
  } else if (inputPc->get_kind() == kind::factors) {

    auto facs = static_cast<ctoken_t<kind::factors>>(inputPc)->get_tokens();

    auto countFacs = transform_vec( facs, std::bind(count_contiguous_factors, std::placeholders::_1, fnPivot) );

    return std::accumulate(std::begin(countFacs), std::end(countFacs), unsigned(0));

  } else if (inputPc->get_kind() == kind::fraction) {

    auto frac = static_cast<ctoken_t<kind::fraction>>(inputPc);

    return count_contiguous_factors( frac->get_numerator(), fnPivot );

  } else {

    throw std::runtime_error("Could not count_contiguous_factors : Unreachable");
  }

}


} // namespace bld::src::pc
