#include "source/token/typedef.hpp"


namespace bld::src::pc {


template <range_limit RL>
own_piece_t transform_range_limit(cpiece_t inputPc);

own_token_t<kind::range> transform_to_range( cpiece_t inputPc );

} // namespace bld::src::pc
