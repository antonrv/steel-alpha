

#include "source/object/data/transform/align/aux.hpp"

#include "source/object/function/definition.hpp"
#include "source/object/function/context.hpp"
#include "source/object/function/call.hpp" // DBG XXX

#include "source/token/make/copy.hpp"

#include "common/util.hpp"

#include <algorithm>

#include <iostream> // DBG XXX

namespace bld::src {

static
bool less_than_local( const pc::piece_context lhsLocal, const pc::piece_context rhsLocal ) {

  if (lhsLocal == pc::UniversalCtxt and rhsLocal != pc::UniversalCtxt) {
    // rhs dominates, goes first
    return false;
  } else if (lhsLocal != pc::UniversalCtxt and rhsLocal == pc::UniversalCtxt) {
    // lhs dominates, goes first
    return true;
  } else if (lhsLocal == pc::UniversalCtxt and rhsLocal == pc::UniversalCtxt) {
    // Will return false for lhs,rhs and rhs,lhs, so they are equivalent
    return false;
  }

  return lhsLocal->is_before( rhsLocal );
  // Assert both on same global context
}


static
bool less_than_global( const sobject<obj::fun_def>* fDefLhs, const sobject<obj::fun_def>* fDefRhs ) {

  if (fDefLhs == pc::UniversalCtxt and fDefRhs != pc::UniversalCtxt) {
    // rhs dominates, goes first
    return false;
  } else if (fDefLhs != pc::UniversalCtxt and fDefRhs == pc::UniversalCtxt) {
    // lhs dominates, goes first
    return true;
  } else if (fDefLhs == pc::UniversalCtxt and fDefRhs == pc::UniversalCtxt) {
    // Will return false for lhs,rhs and rhs,lhs, so they are equivalent
    return false;
  }

  if (fDefLhs->get_identifier() == fDefRhs->get_identifier()) {
    // Will return false for lhs,rhs and rhs,lhs, so is fine
    return false;
  }


  bool lhsCallsRhs = fDefLhs->does_call( fDefRhs );
  bool rhsCallsLhs = fDefRhs->does_call( fDefLhs );

  if (lhsCallsRhs and rhsCallsLhs) {
    throw std::logic_error("PM constraint : Function call cycles not allowed.");
  }

  if (lhsCallsRhs) {
    // Then lhs is less than rhs
    return true;

  } else if (rhsCallsLhs) {

    // Then rhs is less than lhs
    return false;

  } else {

    // Find call chain TODO
    throw std::logic_error("Could not find less_than relation between global contexts. Implement call chain discovery : \n\tLhs : " + fDefLhs->get_identifier() + "\n\tRhs : " + fDefRhs->get_identifier());
  }
}


static
bool less_than(const alignable& lhs, const alignable& rhs) {

  if (less_than_global(lhs.get_global(), rhs.get_global())) {

    // lhs dominates, so goes first
    return true;

  } else if (less_than_global(rhs.get_global(), lhs.get_global())) {

    // rhs dominates, so goes first
    return false;

  } else {
    // Equivalent under global comparison, so compare as local
    
    return less_than_local(lhs.get_local(), rhs.get_local());
  }
}




///////////////
//
// INTERFACE
//
///////////////
pc::vec_own_piece_t align_contexts_uniform( pc::vec_cpiece_t inVec ) {

  auto ctxtPairs = transform_vec( inVec, [] (pc::cpiece_t pc) { return alignable(pc); } );
  
  std::sort( std::begin(ctxtPairs), std::end(ctxtPairs), less_than );

  auto targetAlignable = ctxtPairs.front();

#ifdef TRANSFORM_LOG
  std::cout << "---Align : top ctxt : " << targetAlignable.get_piece()->get_pc_string() << ", global : " << targetAlignable.get_global()->get_identifier() << ", local : " << targetAlignable.get_local()->get_identifier() << "\n";
#endif // TRANSFORM_LOG

  if (targetAlignable.get_global() == pc::UniversalCtxt and targetAlignable.get_local() == pc::UniversalCtxt) {
    // Plain copy
    return edit_piece_vector( inVec );
  } else if (targetAlignable.get_global() != pc::UniversalCtxt and targetAlignable.get_local() == pc::UniversalCtxt) {
    throw std::runtime_error("align_contexts : Reached uncertain code, top global context is " + targetAlignable.get_global()->get_identifier() + " while top local is pc::UniversalCtxt. Is this allowed ?");
  } else if (targetAlignable.get_global() == pc::UniversalCtxt and targetAlignable.get_local() != pc::UniversalCtxt) {
    throw std::runtime_error("align_contexts : Reached uncertain code, top local context is " + targetAlignable.get_local()->get_identifier() + " while top global is pc::UniversalCtxt. Is this allowed ?");
  }

  return transform_vec( ctxtPairs, std::bind( align_to_target, std::placeholders::_1, targetAlignable ) );
}


///////////////
//
// INTERFACE
//
///////////////
std::pair<pc::own_piece_t, pc::own_piece_t> align_contexts_uniform( pc::cpiece_t pcA, pc::cpiece_t pcB ) {

  auto vec = align_contexts_uniform( {pcA, pcB} );

  return std::make_pair( edit_piece(vec.front()), edit_piece(vec.back()) );
}


} // namespace bld::src
