
#include "source/token/typedef.hpp"

namespace bld::src::pc {


bool on_same_global_context(cpiece_t inLhs, cpiece_t inRhs);

vec_cpiece_t canonicalize( vec_cpiece_t vec );

bool less_than(cpiece_t inLhs, cpiece_t inRhs);

bool are_equal(cpiece_t inLhs, cpiece_t inRhs);

bool contains_piece(cpiece_t inLhsPc, cpiece_t inRhsPc);


own_token_t<kind::range> extend_ranges_to_context( vec_ctoken_t<kind::range> inputVecRanges, piece_context targetCtxt );

own_ctoken_t<kind::range> extend_range_from_coord( cpiece_t localCoord, ctoken_t<kind::range> dsRange, piece_context targetCtxt );

// Needed ? TODO
own_token_t<kind::range> extend_ranges_uniform( vec_ctoken_t<kind::range> vecRanges);

template <kind Kind>
own_piece_t extend_arith( vec_cpiece_t inVec, piece_context targetCtxt );

template <kind Kind>
own_piece_t extend_arith( cpiece_t inLhs, cpiece_t inRhs, piece_context targetCtxt );


own_piece_t extend_piece( cpiece_t inPc, piece_context targetCtxt );

// To test whether the two pieces satisfy a given function, trying multiple local contexts
#ifndef PARSER_TEST
#endif // PARSER_TEST

} // namespace bld::src::pc
