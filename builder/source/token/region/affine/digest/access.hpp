#ifndef PARSER_REGION_AFFINE_DIGEST_ACCESS_HPP
#define PARSER_REGION_AFFINE_DIGEST_ACCESS_HPP

#include "source/token/typedef.hpp"

#include "source/token/transform/range.hpp"

#include "source/token/region/affine/dim/container.hpp"

#include <vector>
#include <memory>

namespace bld::src::pc {

template <mem_ak>
class mem_access;

using offsets_t = vec_own_cpiece_t;


bool are_proper_global( const dim_cpiece_t globalEmbeds );

class digest_access {
private:
  const mem_access<mem_ak::affine> * const m_inputAffAccess;
  // Elem-per-dim match
  dim_own_cpiece_t m_globalEmbeddings;
  dim_own_cpiece_t m_coordinates;
  dim_own_cpiece_t m_localEmbeddings;
  dim_own_ctoken_t<kind::range> m_memRanges;
  dim_own_ctoken_t<kind::range> m_callRanges;

  vec_own_cpiece_t m_localOffsets;
  // Not related to dims. Just encompass the aggregation of local offset + ds offset. Its size is at least 1, with '0' if no offset expressed in any context (local or ds)
  vec_own_cpiece_t m_downstreamOffsets;

private:
  void init_ranges( const mem_access<mem_ak::affine> * inputAff );

  void init_coord_no_offsets( dim_cpiece_t matchedAddends, const mem_access<mem_ak::affine> * inputAff );

  void init_coord_offsets( dim_cpiece_t matchedAddends, const mem_access<mem_ak::affine> * inputAff );

  void init_coord_from_input_local_embeds( dim_cpiece_t matchedAddends, dim_cpiece_t inputLocalEmbeds, const mem_access<mem_ak::affine> * inputAff );

  void init_downstream_offsets( const mem_access<mem_ak::affine> * inputAff );

public:

  // Constructor without globalEmbeds (some testing cases)
  digest_access( const mem_access<mem_ak::affine> * inputAff );

  // Constructor for primaries
  digest_access( const dim_cpiece_t globalEmbeds, const mem_access<mem_ak::affine> * inputAffPc );

  // Constructor for secondaries
  digest_access( const dim_cpiece_t globalEmbeds, const dim_cpiece_t localEmbeds, const mem_access<mem_ak::affine> * inputAffPc );

  dim_cpiece_t get_global_embeddings() const;
  dim_cpiece_t get_local_embeddings() const;
  dim_cpiece_t get_coordinates() const;
  dim_ctoken_t<kind::range> get_mem_ranges() const;
  dim_ctoken_t<kind::range> get_call_ranges() const;


  vec_cpiece_t get_local_offsets() const;

  vec_cpiece_t get_aggregated_offsets() const;

  bool has_downstream_offsets() const;

  std::string get_local_embeddings_string( piece_context srcCtxt ) const;
  // std::string get_descriptor_string( csob_t srcCtxt ) const;

  std::string get_info() const;

  bool is_built_from( const mem_access<mem_ak::affine> * inAff ) const;

#ifndef PARSER_TEST
private:
  unsigned get_dimensions() const;

  bool are_blocks_disjoint_detail(dim_cpiece_t locEmbeds) const;

public:


  bool are_blocks_internally_disjoint() const;
  bool are_blocks_disjoint_under(dim_cpiece_t externLocEmbeds) const;

  bool is_on_loop_mesh() const;

  own_ctoken_t<kind::range> get_induced_call_range(unsigned d, cpiece_t locEmbed) const;
#endif // PARSER_TEST
};

} // namespace bld::src::pc

#endif // PARSER_REGION_AFFINE_DIGEST_ACCESS_HPP
