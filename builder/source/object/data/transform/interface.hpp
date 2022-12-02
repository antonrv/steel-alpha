#ifndef COMMON_IT_DATA_TRANSFORM_HPP
#define COMMON_IT_DATA_TRANSFORM_HPP

#include "source/object/typedef.hpp"

#include "source/sequences.hpp"
#include "source/sequences.hpp"

#include <memory>

namespace bld::src {

class sobject_base;

template <obj>
class sobject;


set_csob_t collect_local_contexts( pc::cpiece_t inputPc );


bool is_statically_defined( pc::cpiece_t inputPc ); // or is_transformable_in_context

pc::own_piece_t transform_to_local_context( pc::cpiece_t inputPc, csob_t srcCtxt );

pc::own_piece_t transform_from_callee_to_call(pc::cpiece_t opInCallee, cso_t<obj::fun_call> fCallInCaller);

pc::own_piece_t transform_from_call_to_callee(pc::cpiece_t inputPc, cso_t<obj::fun_call> fCallInCaller);


///// Uniform alignment
pc::vec_own_piece_t align_contexts_uniform( pc::vec_cpiece_t inVec );

std::pair<pc::own_piece_t, pc::own_piece_t> align_contexts_uniform( pc::cpiece_t pcA, pc::cpiece_t pcB );



///// Target alignment
pc::vec_own_piece_t align_contexts_to_target( pc::vec_cpiece_t inVec, pc::piece_context targetLocalCtxt );

std::pair<pc::own_piece_t, pc::own_piece_t> align_contexts_to_target( pc::cpiece_t pcA, pc::cpiece_t pcB, pc::piece_context targetLocalCtxt );

pc::own_piece_t align_contexts_to_target( pc::cpiece_t inPc, pc::piece_context targetLocalCtxt );

} // namespace bld::src

#endif // COMMON_IT_DATA_TRANSFORM_HPP
