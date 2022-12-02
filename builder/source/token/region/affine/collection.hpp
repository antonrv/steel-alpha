#ifndef PARSER_REGION_AFFINE_COLLECTION_HPP
#define PARSER_REGION_AFFINE_COLLECTION_HPP

#include "source/token/region/affine/digest/access.hpp"

#include <map>
#include <vector>
#include <memory>

namespace bld::src::pc {

template <mem_ak>
class mem_access;

bool is_primary( unsigned nDim, const mem_access<mem_ak::affine> * aff );
bool is_not_primary( unsigned nDim, const mem_access<mem_ak::affine> * aff );

class digest_collection {
public:

  using stored_digest_accesses_t = std::vector<std::unique_ptr<const digest_access>>;

private:

  stored_digest_accesses_t m_storedPrimaryAccesses;
  stored_digest_accesses_t m_storedSecondaryAccesses;

public:
  digest_collection( const dim_cpiece_t globalEmbeds, const std::vector<const mem_access<mem_ak::affine>*> affs);

  // digest_collection(digest_collection&&) = default;


private:
  const digest_access * get_primary_digest_access( const mem_access<mem_ak::affine> * aff ) const;
  const digest_access * get_secondary_digest_access( const mem_access<mem_ak::affine> * aff ) const;

public:
  const digest_access * get_digest_access( const mem_access<mem_ak::affine> * aff ) const;

  std::vector<const digest_access*> get_primary_digest_accesses() const;
  std::vector<const digest_access*> get_secondary_digest_accesses() const;

  std::vector<const digest_access*> get_all_digest_accesses() const;


  std::vector< dim_cpiece_t > get_unique_primary_local_embeddings() const;

  std::string get_info() const;
};

} // namespace bld::src::pc

#endif // PARSER_REGION_AFFINE_COLLECTION_HPP
