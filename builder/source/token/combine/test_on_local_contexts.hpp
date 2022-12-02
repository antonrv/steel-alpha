
#ifndef PARSER_TEST

#include "source/token/combine/interface.hpp"

#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#include "source/object/data/transform/interface.hpp"

#include <iostream> // DBG XXX

namespace bld::src::pc {

template <typename ResT>
ResT test_on_multiple_local_contexts(cpiece_t inLhsPc, cpiece_t inRhsPc,
  ResT negatValue,
  std::function<bool(ResT)> earlyExitPred,
  std::function<ResT(cpiece_t, cpiece_t)> funTest)
{

  // std::cout << "Testing on multiple local ctxts : \n";
  // std::cout << "LHS : " << inLhsPc->get_pc_string() << '\n';
  // std::cout << "RHS : " << inRhsPc->get_pc_string() << '\n';
  // std::cout << "negat value : " << negatValue << '\n';


  if (not on_same_global_context(inLhsPc, inRhsPc)) {
    throw std::logic_error("test_on_multiple_local_contexts : only callable when both pieces have different global contexts");
  }

  // std::cout << "TESTING ON MULTIPLE LOCAL CONTEXTS " << negatValue << '\n';

  auto allLocalCtxtLhs = collect_local_contexts( inLhsPc );
  auto allLocalCtxtRhs = collect_local_contexts( inRhsPc );

  set_csob_t allUniqueLocalCtxts;
  std::copy( std::begin(allLocalCtxtLhs), std::end(allLocalCtxtLhs), std::inserter(allUniqueLocalCtxts, std::end(allUniqueLocalCtxts)) );
  std::copy( std::begin(allLocalCtxtRhs), std::end(allLocalCtxtRhs), std::inserter(allUniqueLocalCtxts, std::end(allUniqueLocalCtxts)) );

  if (allUniqueLocalCtxts.empty()) {
    throw std::logic_error("testing function between pair of pieces : zero collected local contexts");
  }

  for (auto locCtxtA : allUniqueLocalCtxts) {

    auto transLhsPc = extend_piece( inLhsPc, locCtxtA );

    for (auto locCtxtB : allUniqueLocalCtxts) {

      auto transRhsPc = extend_piece( inRhsPc, locCtxtB );

      // std::cout << "Before calling eval fun : LHS : " << transLhsPc->get_pc_string() << ". RHS : " << transRhsPc->get_pc_string() << '\n';

      auto funEval = funTest(transLhsPc.get(), transRhsPc.get());
      if ( earlyExitPred(funEval) ) {
        // std::cout << "MUL CONTEXTS EXITED EARLY\n";
        return funEval;
      }
    }
  }

  // std::cout << "MUL CONTEXTS NOT FOUND SATISFACTION\n";
  return negatValue;
}

} // namespace bld::src::pc
#endif // PARSER_TEST
