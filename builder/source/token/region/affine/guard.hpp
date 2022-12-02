#ifndef PARSER_REGION_AFFINE_GUARD_HPP
#define PARSER_REGION_AFFINE_GUARD_HPP

#include "source/token/region/guard.hpp" // Base

#include "source/token/region/affine/collection.hpp"

#include "source/token/region/affine/access.hpp"

#include "source/token/region/affine/digest/access.hpp"



namespace bld::src::pc {


template <>
class mem_guard <mem_ak::affine> : public guard {

using super_type = guard;

private:

  const dim_own_cpiece_t m_embeddings;
  const digest_collection m_affinesCollection;

  const dim_own_ctoken_t<kind::range> m_memRanges;
  const dim_own_ctoken_t<kind::range> m_callRanges;

  const offsets_t m_offsets;

  // Helper functions for construction
  dim_own_cpiece_t make_global_embeddings( unsigned maxDims, const std::vector<const affine_access*>& affs ) const;

  dim_own_ctoken_t<kind::range> make_global_mem_ranges( unsigned nDim, const digest_collection& digCollection) const;

  dim_own_ctoken_t<kind::range> make_call_ranges( unsigned nDim, const digest_collection& digCollection) const;

  vec_own_cpiece_t make_all_offsets( const digest_collection& digCollection) const;

public:

  mem_guard( const std::vector<const affine_access*>& affs, cso_t<obj::data_decl> dDecl = nullptr );

  ~mem_guard();

  virtual mem_ak get_mem_guard_kind() const final override;

public:

  std::string get_info() const;

  unsigned get_dimensions() const;

 
  dim_cpiece_t get_global_embeddings() const;

  dim_ctoken_t<kind::range> get_global_mem_ranges() const;

  dim_ctoken_t<kind::range> get_global_call_ranges() const;

  vec_cpiece_t get_all_offsets() const;


  dim_cpiece_t get_local_embeddings( const affine_access * aff ) const; 

  dim_cpiece_t get_local_coordinates( const affine_access * aff ) const;

  dim_ctoken_t<kind::range> get_local_mem_ranges( const affine_access * aff ) const;

  own_cpiece_t get_local_offset( const affine_access * aff ) const;


private:

  unsigned try_get_id_matching_global_embed( cpiece_t upstreamGlobalEmbed ) const;

  unsigned get_id_matching_global_embed( cpiece_t upstreamGlobalEmbed ) const;



public: // For dim_info

  bool has_range_matching_global_embed( cpiece_t upstreamGlobalEmbed ) const;

  ctoken_t<kind::range> get_range_matching_global_embed( cpiece_t globalEmbed ) const;

  vec_string_t get_vec_string_unique_local_embeds( std::vector<const digest_access *> digAccs ) const;

  vec_string_t get_vec_string_unique_local_embeds() const;

  dim_cpiece_t get_unique_local_embeds( std::vector<const digest_access *> digAccs ) const;
  dim_cpiece_t get_unique_local_embeds( ) const;


#ifndef PARSER_TEST

private:

  std::string get_mesh_type_str() const;

public:

  // Called from wrap_create
  std::string get_wrap_command() const final override;

  // Called from emit_bnd
  std::string get_emit_arguments( const access * acc ) const final override;

  std::string serial() const final override;

  friend class dim_info;
  friend class mem_access<mem_ak::affine>;
#endif // PARSER_TEST

};

} // namespace bld::src::pc

#endif // PARSER_REGION_AFFINE_GUARD_HPP
