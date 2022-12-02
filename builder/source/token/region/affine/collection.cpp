#include "source/token/region/affine/collection.hpp"

#include "source/token/combine/interface.hpp"

#include "source/token/region/affine/access.hpp"
#include "source/token/region/affine/dim/matching.hpp"

#include "source/token/combine/interface.hpp"

#include "source/token/multiple/range.hpp"

#include "common/util.hpp"

#ifdef REGION_LOG
#include <iostream>
#endif // REGION_LOG


namespace bld::src::pc {



#ifndef PARSER_TEST
bool is_primary( unsigned nDim, const affine_access * aff ) {
  return aff->get_this_dimensions() > 0 and aff->get_this_dimensions() == nDim and aff->is_on_call_within_loop() and not aff->has_offset();
}
#else
bool is_primary( unsigned nDim, const affine_access * aff ) {
  return aff->get_this_dimensions() > 0 and aff->get_this_dimensions() == nDim and not aff->has_offset();
}
#endif

bool is_not_primary( unsigned nDim, const affine_access * aff ) {
  return not is_primary(nDim, aff);
}


digest_collection::digest_collection( const dim_cpiece_t globalEmbeds, std::vector<const affine_access*> inputAffs) {

  if (are_proper_global( globalEmbeds )) {

    m_storedPrimaryAccesses = transform_vec_if(
        inputAffs,
        std::bind( is_primary, globalEmbeds.size(), std::placeholders::_1), // Transform if satisfy this
        [&globalEmbeds] (const affine_access * aff) {
          return std::make_unique<const digest_access>( globalEmbeds, aff );
        }
      );

    // Now we can calculate the unique local embeds of primaries
    auto allDistinctLocalEmbeds = this->get_unique_primary_local_embeddings();

    // To build the secondary accesses
    m_storedSecondaryAccesses = transform_vec_if( inputAffs, 
        std::bind( is_not_primary, globalEmbeds.size(), std::placeholders::_1 ), // Transform if satisfy this
        [&allDistinctLocalEmbeds, &globalEmbeds] (const affine_access * aff) {

          if (allDistinctLocalEmbeds.empty() and aff->get_dimensions() == 0) {
            return std::make_unique<const digest_access>( aff );
          }

          // We build the secondary with the local embeds that yield the best-fit dimensional matching
          // From global and local embeds the digest_access of the lower-dim affines can be built.

          if (allDistinctLocalEmbeds.empty() and aff->get_downstream_guard() != nullptr) {

            return std::make_unique<const digest_access>( globalEmbeds, aff ); // As primary. Maybe induced from ds global embeds. Trying TODO XXX
            
          } else if (allDistinctLocalEmbeds.empty() and aff->get_downstream_guard() == nullptr) {
          // // } else if (aff->get_downstream_guard() == nullptr) {

            return std::make_unique<const digest_access>( globalEmbeds, aff );
            // return std::make_unique<const digest_access>( aff );
          }

          auto scores = transform_vec( allDistinctLocalEmbeds, std::bind( score_dim_matching, globalEmbeds, std::placeholders::_1, aff ) );

          auto maxScoreIt = std::max_element( std::begin(scores), std::end(scores) );

          
          return std::make_unique<const digest_access>(
            globalEmbeds,
            allDistinctLocalEmbeds[ std::distance( std::begin(scores), maxScoreIt ) ],
            aff
          );
        }
      );

  } else {

    // Not proper, let the digestion depend solely on primordial accesses
    // std::cout << " Building BASIC (non proper globals)\n";

    m_storedSecondaryAccesses = transform_vec( inputAffs,
      [] (const affine_access * aff) { return std::make_unique<const digest_access>( aff ); } );

  }

  
#ifdef REGION_LOG
  std::cout << "@@@@@@@@@ Built Affine Collection from : "<< affs.size() << " affine_access " << this->get_info() << '\n';
#endif // REGION_LOG
}



std::string digest_collection::get_info() const {

  std::string retStr;

#ifndef PARSER_TEST
  retStr += "\tPrimary affine accesses V\n";
  auto affAccs = this->get_primary_digest_accesses();
  for (auto& a : affAccs) { retStr += a->get_info() + "\n"; }

  retStr += "\tSecondary affine accesses V\n";
  affAccs = this->get_secondary_digest_accesses();
  for (auto& a : affAccs) { retStr += a->get_info() + "\n"; }

#else // PARSER_TEST

  retStr += "\tAll affine accesses V\n";
  auto affAccs = this->get_all_digest_accesses();
  for (auto& a : affAccs) { retStr += a->get_info() + "\n"; }

#endif // PARSER_TEST
  return retStr;
}

// private
const digest_access * digest_collection::get_primary_digest_access( const affine_access * aff ) const {

  auto foundIt = std::find_if( std::begin(m_storedPrimaryAccesses), std::end(m_storedPrimaryAccesses),
    [aff] (const std::unique_ptr<const digest_access>& ownDigAcc) {
      return ownDigAcc->is_built_from( aff );
    });
  if (foundIt == std::end(m_storedPrimaryAccesses)) {
    return nullptr;
  }
  return foundIt->get();
}

// private
const digest_access * digest_collection::get_secondary_digest_access( const affine_access * aff ) const {

  auto foundIt = std::find_if( std::begin(m_storedSecondaryAccesses), std::end(m_storedSecondaryAccesses),
    [aff] (const std::unique_ptr<const digest_access>& ownDigAcc) {
      return ownDigAcc->is_built_from( aff );
    });
  if (foundIt == std::end(m_storedSecondaryAccesses)) {
    return nullptr;
  }
  return foundIt->get();
}


const digest_access * digest_collection::get_digest_access( const affine_access * aff ) const {

  auto foundPrimary = this->get_primary_digest_access(aff);
  auto foundSecondary = this->get_secondary_digest_access(aff);

  if (foundPrimary != nullptr and foundSecondary != nullptr) {
    throw std::logic_error("Cannot get local embeddings of affine. Duplicated affine access : " + aff->get_info());
  }

  if (foundPrimary != nullptr) {
    return foundPrimary;
  } else if (foundSecondary != nullptr) {
    return foundSecondary;
  } else {
    throw std::logic_error("Cannot get local embeddings of affine. Not found ptr of affine access : " + aff->get_info());
  }
}


std::vector<const digest_access*> digest_collection::get_primary_digest_accesses() const {
  return transform_vec( m_storedPrimaryAccesses, [] (const std::unique_ptr<const digest_access>& ownDigAcc) { return ownDigAcc.get(); } );
}

std::vector<const digest_access*> digest_collection::get_secondary_digest_accesses() const {
  return transform_vec( m_storedSecondaryAccesses, [] (const std::unique_ptr<const digest_access>& ownDigAcc) { return ownDigAcc.get(); } );
}

std::vector<const digest_access*> digest_collection::get_all_digest_accesses() const {

  std::vector<const digest_access*> retVec;

  retVec = this->get_primary_digest_accesses();
  auto secondary = this->get_secondary_digest_accesses();

  std::copy(std::begin(secondary), std::end(secondary), std::back_inserter(retVec));

  return retVec;
}


std::vector< dim_cpiece_t > digest_collection::get_unique_primary_local_embeddings() const {

  auto locEmbeds = transform_vec( m_storedPrimaryAccesses, [] (const auto& digAcc) { return digAcc->get_local_embeddings().get_vec(); } );

  std::sort( std::begin(locEmbeds), std::end(locEmbeds),
      [] (const vec_cpiece_t& vecA, const vec_cpiece_t& vecB) {
        return std::lexicographical_compare(
            std::begin(vecA), std::end(vecA),
            std::begin(vecB), std::end(vecB),
            less_than
          );
      }
    );

  auto areEqual = [] (const vec_cpiece_t& vecA, const vec_cpiece_t& vecB) {
        return std::lexicographical_compare(
            std::begin(vecA), std::end(vecA),
            std::begin(vecB), std::end(vecB),
            are_equal
          );
      };

  locEmbeds.erase( std::unique(std::begin(locEmbeds), std::end(locEmbeds), areEqual), std::end(locEmbeds) );

  return transform_vec( locEmbeds, [] (vec_cpiece_t vec) { return dim_cpiece_t( std::move(vec) ); } );
}


} // namespace bld::src::pc
