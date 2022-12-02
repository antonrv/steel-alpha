#ifndef SOURCE_PIECE_TOKEN_REGION_AFFINE_DIGEST_FUNCTORS_HPP
#define SOURCE_PIECE_TOKEN_REGION_AFFINE_DIGEST_FUNCTORS_HPP

#include "source/token/typedef.hpp"

namespace bld::src::pc {

////////////////// STUFF TO BUILD MAIN digest/access.cpp members

struct make_local_coord {
  using result_type = own_cpiece_t;
  result_type operator() ( cpiece_t matchedAddend, cpiece_t globalEmbed ) const;
};

struct make_local_coord_offset {
  using result_type = own_cpiece_t;
  result_type operator() ( cpiece_t matchedAddend, cpiece_t globalEmbed, cpiece_t lvFactor ) const;
};

// struct make_naked_coord {
//   using result_type = own_cpiece_t;
//   result_type operator() ( cpiece_t matchedAddend, cpiece_t globalEmbed, cpiece_t localEmbed ) const;
// };

struct make_local_coord_deduced {
  using result_type = own_cpiece_t;
  result_type operator() ( cpiece_t matchedAddend, cpiece_t globalEmbed, cpiece_t localEmbed ) const;
};

struct make_local_embedding {
  using result_type = own_cpiece_t;
  result_type operator() ( cpiece_t localCoord, cpiece_t nakedCoord ) const;
};

struct make_mem_range {
  const mem_access<mem_ak::affine> * inputAff = nullptr;
  using result_type = own_ctoken_t<kind::range>;
  make_mem_range(const mem_access<mem_ak::affine> * aff);
  result_type operator() (cpiece_t localCoord, cpiece_t callGlobalEmbed ) const;
};

struct make_call_range {
  const mem_access<mem_ak::affine> * inputAff = nullptr;
  using result_type = own_ctoken_t<kind::range>;
  make_call_range(const mem_access<mem_ak::affine> * aff);
  result_type operator() ( cpiece_t localCoord, cpiece_t localEmbed ) const;
};


#ifndef PARSER_TEST

////////////////// STUFF TO EVALUATE NON-OVERLAPPING CONDITION

struct make_call_start {
  using result_type = own_cpiece_t;
  result_type operator()( ctoken_t<kind::range> memRange, cpiece_t coord ) const;
};

struct make_coord_start {
  using result_type = own_cpiece_t;
  result_type operator()( cpiece_t localEmbed, cpiece_t callStart ) const;
};

struct make_eval_binop {
  using result_type = own_ctoken_t<kind::binop>;
  result_type operator()( ctoken_t<kind::range> memRange, cpiece_t coordStart ) const;
};

#endif // PARSER_TEST

} // namespace bld::src::pc

#endif // SOURCE_PIECE_TOKEN_REGION_AFFINE_DIGEST_FUNCTORS_HPP
