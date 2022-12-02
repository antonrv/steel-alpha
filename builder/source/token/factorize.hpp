#ifndef COMMON_IT_SOURCE_PIECE_TEST_FACTORIZE_HPP
#define COMMON_IT_SOURCE_PIECE_TEST_FACTORIZE_HPP

#include "source/token/typedef.hpp"


namespace bld::src::pc {


own_piece_t extract_factors(cpiece_t inputPc, std::function<bool(cpiece_t)> fnPivot);

own_piece_t extract_non_factors(cpiece_t inputPc, std::function<bool(cpiece_t)> fnPivot);

bool contains_piece(cpiece_t inLhsPc, cpiece_t inRhsPc);


vec_cpiece_t get_children_factors(cpiece_t inPc);

own_piece_t extract_common_factors(cpiece_t lhsPc, cpiece_t rhsPc);


own_piece_t extract_addends( cpiece_t pc, std::function<bool(cpiece_t)> fnSatisfy );

unsigned count_contiguous_factors(cpiece_t inputPc, pred_fun_t fnPivot);

} // namespace bld::src::pc

#endif // COMMON_IT_SOURCE_PIECE_TEST_FACTORIZE_HPP
