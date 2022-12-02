
#include "source/sequences.hpp"

#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#include "source/token/simplify/interface.hpp"

#include "source/token/combine/interface.hpp"

#include <stdexcept>

#include <iostream>


namespace bld::src::pc {


static
res try_compare_strings( cpiece_t lhs, cpiece_t rhs, opkind opKind ) {

  auto lhsStr = lhs->get_pc_string();
  auto rhsStr = rhs->get_pc_string(); 

  if (lhsStr == rhsStr){
    if (opKind == opkind::eq or opKind == opkind::leq or opKind == opkind::geq) {
      return res::tru;
    } else if (opKind == opkind::neq or opKind == opkind::lt or opKind == opkind::gt) {
      return res::fal;
    } else {
      throw std::logic_error("Unreachable in evaluate");
    }
  }
  return res::unk;
}


static
res try_compare_numbers( cpiece_t lhs, cpiece_t rhs, opkind opKind ) {

  if (lhs->get_kind() == kind::num and rhs->get_kind() == kind::num) {

    auto lhsNum = static_cast<ctoken_t<kind::num>>(lhs)->get_value();
    auto rhsNum = static_cast<ctoken_t<kind::num>>(rhs)->get_value();

    if (opKind == opkind::eq) {
      return lhsNum == rhsNum ? res::tru : res::fal;
    } else if (opKind == opkind::neq) {
      return lhsNum != rhsNum ? res::tru : res::fal;
    } else if (opKind == opkind::lt) {
      return lhsNum < rhsNum ? res::tru : res::fal;
    } else if (opKind == opkind::leq) {
      return lhsNum <= rhsNum ? res::tru : res::fal;
    } else if (opKind == opkind::gt) {
      return lhsNum > rhsNum ? res::tru : res::fal;
    } else if (opKind == opkind::geq) {
      return lhsNum >= rhsNum ? res::tru : res::fal;
    }
  }
  return res::unk;
}


static
res try_compare_vars( cpiece_t lhs, cpiece_t rhs, opkind opKind ) {

  if (lhs->get_kind() == kind::var and rhs->get_kind() == kind::var) {

    std::string lhsStr = lhs->get_pc_string();
    std::string rhsStr = rhs->get_pc_string();

    if (lhsStr == rhsStr){
      if (opKind == opkind::eq or opKind == opkind::leq or opKind == opkind::geq) {
        return res::tru;
      } else if (opKind == opkind::neq or opKind == opkind::lt or opKind == opkind::gt) {
        return res::fal;
      } else {
        throw std::logic_error("Unreachable in evaluate");
      }
    }
  }
  return res::unk;
}

static
res try_compare_general( cpiece_t lhs, cpiece_t rhs, opkind opk ) {

  if (opk == opkind::eq or opk == opkind::leq or opk == opkind::geq) {
    return are_equal( lhs, rhs ) ? res::tru : res::unk;
  } else if (opk == opkind::neq) {
    return (not are_equal( lhs, rhs )) ? res::unk : res::tru;
  } else { // lt, gt
    return res::unk;
  }
}

  static
  ctoken_t<kind::fraction> maybe_to_frac_mod(cpiece_t pc) {
    if (pc->get_kind() == kind::fraction) {
      if (static_cast<ctoken_t<kind::fraction>>(pc)->is_mod()) {
        return static_cast<ctoken_t<kind::fraction>>(pc);
      }
    }
    return nullptr;
  }
  static
  opkind flip(opkind opk) {
    if (opk == opkind::eq or opk == opkind::neq) {
      return opk;
    } else if (opk == opkind::leq) {
      return opkind::geq;
    } else if (opk == opkind::geq) {
      return opkind::leq;
    } else if (opk == opkind::lt) {
      return opkind::gt;
    } else if (opk == opkind::gt) {
      return opkind::lt;
    } else {
      throw std::logic_error("Unreachable in flip opkind");
    }
  }

static
res try_compare_mod( cpiece_t lhs, cpiece_t rhs, opkind opk) {

  auto maybeFracModLHS = maybe_to_frac_mod( lhs );
  auto maybeFracModRHS = maybe_to_frac_mod( rhs );

  ctoken_t<kind::fraction> fracMod = nullptr;
  cpiece_t otherPc = nullptr;

  if (maybeFracModLHS != nullptr and maybeFracModRHS == nullptr) {
    fracMod = maybeFracModLHS;
    otherPc = rhs;
  } else if (maybeFracModLHS == nullptr and maybeFracModRHS != nullptr) {
    fracMod = maybeFracModRHS;
    otherPc = lhs;
    opk = flip(opk);
  } else {
    return res::unk;
  }

  if (not are_equal(fracMod->get_denominator(), otherPc)) {
    return res::unk;
  }

  // then we have a 'X % other <OPKIND> other' situation, so we can statically calculate it

  if (opk == opkind::eq) {
    return res::fal;
  } else if (opk == opkind::neq) {
    return res::tru;
  } else if (opk == opkind::leq) {
    return res::tru;
  } else if (opk == opkind::geq) {
    return res::fal;
  } else if (opk == opkind::lt) {
    return res::tru;
  } else if (opk == opkind::gt) {
    return res::fal;
  } else {
    throw std::logic_error("Unreachable in try_compare_mod");
  }
}

static
res try_substract( cpiece_t lhs, cpiece_t rhs, opkind opKind ) {

  auto newRhs = edit_piece( rhs );

  newRhs->flip_sign();

  // std::cout << "new lhs 1 : " << lhs->get_pc_string() << '\n';
  // std::cout << "new lhs 2 : " << rhs->get_pc_string() << '\n';

  auto newLhs = make_token< kind::addends >( lhs, newRhs );

  auto simplLhs = simplify_piece( newLhs );

  // std::cout << "Substr : " << newLhs->get_pc_string() << '\n';

  return try_compare_numbers( simplLhs.get(), make_num(0).get(), opKind );
}


///////////////
//
// INTERFACE
//
///////////////
res try_pipeline( cpiece_t lhs, cpiece_t rhs, opkind opKind ) {

  // std::cout << "---------trying pipeline : LHS -> " << lhs->get_pc_string() << ". RHS -> " << rhs->get_pc_string() << '\n';

  auto lhsPcSimp = simplify_piece( lhs );
  auto rhsPcSimp = simplify_piece( rhs );

  // std::cout << "-------BEFORE TRY PIPELINE :\n";
  // std::cout << "LHS : " << lhsPcSimp->get_kind() << " : " << lhsPcSimp->get_pc_string() << '\n';
  // std::cout << "RHS : " << rhsPcSimp->get_kind() << " : " << rhsPcSimp->get_pc_string() << '\n';

  res retResult = res::unk;
  
  if (retResult == res::unk) {
    retResult = try_compare_strings(lhsPcSimp.get(), rhsPcSimp.get(), opKind);
  }
  
  if (retResult == res::unk) {
    retResult = try_compare_numbers(lhsPcSimp.get(), rhsPcSimp.get(), opKind);
  }

  if (retResult == res::unk) {
    retResult = try_compare_vars(lhsPcSimp.get(), rhsPcSimp.get(), opKind);
  }

  if (retResult == res::unk) {
    retResult = try_compare_mod(lhsPcSimp.get(), rhsPcSimp.get(), opKind);
  }

  if (retResult == res::unk) {
    retResult = try_compare_general(lhsPcSimp.get(), rhsPcSimp.get(), opKind);
  }

  if (retResult == res::unk) {
    retResult = try_substract(lhsPcSimp.get(), rhsPcSimp.get(), opKind);
  }

  // std::cout << "-----------tried pipeline. Result : " << retResult << '\n';

  return retResult;
}


} // namespace bld::src::pc
