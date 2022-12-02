

namespace bld::src::pc {

std::pair<
  dim_own_cpiece_t, // Addends assigned to each dimension
  vec_own_cpiece_t // Remaining addends not matched to anything (true offset)
>
make_dim_matching( const dim_cpiece_t globalEmbeds, const dim_cpiece_t localEmbeds, const mem_access<mem_ak::affine> * aff );

std::pair<
  dim_own_cpiece_t, // Addends assigned to each dimension
  vec_own_cpiece_t // Remaining addends not matched to anything (true offset)
>
make_dim_matching( const dim_cpiece_t globalEmbeds, const mem_access<mem_ak::affine> * aff );

unsigned score_dim_matching( const dim_cpiece_t globalEmbeds, const dim_cpiece_t localEmbeds, const mem_access<mem_ak::affine> * aff );

} // namespace bld::src::pc
