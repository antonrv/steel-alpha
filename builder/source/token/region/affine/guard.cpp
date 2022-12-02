
#include "source/token/region/affine/guard.hpp"


#include "source/token/region/affine/access.hpp"
#include "source/token/region/affine/to_string.hpp"

#include "source/token/terminal/loopvar.hpp"
#include "source/token/make/copy.hpp"

#include "source/token/token_tuple.hpp"

#include "common/util.hpp"

#include "source/token/factorize.hpp"

#include "source/token/combine/interface.hpp"



#include "source/token/make/copy.hpp"
#include "source/token/simplify/interface.hpp"

#include "common/util.hpp"

#ifndef PARSER_TEST
  #include "source/object/data/transform/interface.hpp" // transform_to_local_context
  #include "source/object/data/decl.hpp" // transform_to_local_context
#endif // PARSER_TEST

#include "source/serial/make_serial.hpp"


#include <vector>
#include <algorithm>
#include <memory>
#include <iostream> // DBG XXX

namespace bld::src::pc {




static
unsigned get_max_dimensions(const std::vector<const affine_access*>& affs) {

  if (affs.empty()) {
    throw std::logic_error("Cannot make_guard. Empty vector of affine pcs");
  }

  // std::cout << "Getting max dimensions from affines : \n"; for (auto aa : affs) { std::cout << aa->get_info() << '\n'; }

  auto maxDims = (*std::max_element(std::begin(affs), std::end(affs),
      [] (const affine_access * affA, const affine_access * affB) {
        return affA->get_dimensions() < affB->get_dimensions();
      }))->get_dimensions();

  // std::cout << "Got max dims : " << maxDims << '\n';
  return maxDims;
}


static
own_cpiece_t extract_common_factor( const vec_own_cpiece_t& factorsOnSameLV ) {

  if (factorsOnSameLV.empty()) {
    throw std::logic_error("Could not extract common factor : empty vector");
  }

  // std::cout << "Extracting common factor from : ";
  // for (auto f : factorsOnSameLV) { std::cout << f->get_pc_string() << " ; "; }
  // std::cout << "\n";

  auto nElems = factorsOnSameLV.size();

  vec_own_cpiece_t reducedFactors;

  if (nElems == 1) {

    // std::cout << "Extracted common factor : " << factorsOnSameLV.front()->get_pc_string() <<  " \n";
    return const_piece( factorsOnSameLV.front().get() );

  } else {
    // Cross-compare and add

    for (auto i = 0u; i < nElems; i++) {
      for (auto j = i + 1u; j < nElems; j++) {
        if (contains_piece( factorsOnSameLV[i].get(), factorsOnSameLV[j].get() )) {
          reducedFactors.emplace_back( const_piece( factorsOnSameLV.at(j) ) );
        } else if (contains_piece( factorsOnSameLV[j].get(), factorsOnSameLV[i].get() )) {
          reducedFactors.emplace_back( const_piece( factorsOnSameLV.at(i) ) );
        } else {
          // Non-dominance between RHS and LHS, but maybe they share a factor(s)
          reducedFactors.emplace_back( extract_common_factors( factorsOnSameLV[i].get(), factorsOnSameLV[j].get() ) );
        }
      }
    }
  }
  
  if (reducedFactors.size() > 1) {

    auto fnSamePc = [] (const own_cpiece_t& pcA, const own_cpiece_t& pcB) { return are_equal( pcA.get(), pcB.get() ); };

    reducedFactors.erase( std::unique(std::begin(reducedFactors), std::end(reducedFactors), fnSamePc ), std::end(reducedFactors));

    return extract_common_factor( reducedFactors );

  } else {

    if (reducedFactors.empty()) {
      throw std::logic_error("Empty vector got in extract_common_factor");
    }

    // std::cout << "Extracted common factor : " << reducedFactors.front()->get_pc_string() <<  " \n";
    return const_piece( reducedFactors.front() );
  }
}


dim_own_cpiece_t mem_guard<mem_ak::affine>::make_global_embeddings( unsigned maxDims, const std::vector<const affine_access*>& affs ) const {

  // Only consider those that have dimensions = MaxDims

  auto affineFactorsMaxDim = transform_vec_if(affs, 
      [maxDims] (const affine_access * aff) { return aff->get_dimensions() == maxDims; }, 
      [] (const affine_access * aff) {
        return aff->get_candidate_embeddings();
      } // Sensible to an eventual downstream guard
    );


  dim_own_cpiece_t globalEmbeds(maxDims);

  for (auto d = 0u; d < maxDims; d++) {

    auto factorsInThisPos = transform_vec( affineFactorsMaxDim,
      [d] (const auto& facs) {
        return const_piece( facs.get_elem(d) );
      });

    globalEmbeds.edit_elem(d) = extract_common_factor( factorsInThisPos );
  }

#ifdef REGION_LOG
  std::cout << "Made global embeddings of size " << globalEmbeds.size() << '\n';
#endif // REGION_LOG

  return globalEmbeds;
}

dim_own_ctoken_t<kind::range>
mem_guard<mem_ak::affine>::make_global_mem_ranges( unsigned nDim, const digest_collection& digCollection) const {

  dim_own_ctoken_t<kind::range> retRanges(nDim);

  // std::cout << "MAKING " << nDim << "-dimensional mem ranges\n";

  for (auto d = 0u; d < nDim; d++) {

    // Get all local ranges across 'd' dimension ...
    auto allLocalRangesInThisDim = transform_vec( digCollection.get_all_digest_accesses(),
      [d] (const digest_access * digAcc) {

        return static_unique_pointer_cast< const token<kind::range> >( transform_to_range( digAcc->get_mem_ranges().get_elem(d) ) );
      } );

    retRanges.edit_elem(d) = 
        extend_ranges_uniform(
          transform_vec( allLocalRangesInThisDim, [] (const own_ctoken_t<kind::range>& ownRng) { return ownRng.get(); } )
        );
  }


#ifdef REGION_LOG
  std::cout << "Made global ranges of size " << retRanges.size() << '\n';
#endif // REGION_LOG

  return retRanges;
}



dim_own_ctoken_t<kind::range> mem_guard<mem_ak::affine>::make_call_ranges( unsigned nDim, const digest_collection& digCollection) const {

  dim_own_ctoken_t<kind::range> retRanges(nDim);
#ifndef PARSER_TEST
  bool isDirectMesh = (this->get_mesh_type_str() == "dep::mesh::direct");
  auto digestedSet = digCollection.get_primary_digest_accesses();
  // auto digestedSet = digCollection.get_all_digest_accesses();
  // std::cout << "ALLLLL\n";
#else
  auto digestedSet = digCollection.get_all_digest_accesses();
#endif // PARSER_TEST


  if (digestedSet.empty()) {
    // This guard does not have primary digests. This will typically belong to a pure kernel guard, so no need to set call ranges
    for (auto d = 0u; d < nDim; d++) {
      retRanges.edit_elem(d) = static_unique_pointer_cast< const token<kind::range> >( make_token< kind::range >( make_token< kind::undefined >(), make_token< kind::undefined >() ) );
    }

    return retRanges;
  }

  for (auto d = 0u; d < nDim; d++) {

    // Get all local ranges across 'd' dimension ...
    auto primaryCallRangesInThisDim = transform_vec( digestedSet,
      [d] (const digest_access * digAcc) {

        return static_unique_pointer_cast< const token<kind::range> >( simplify_piece( transform_to_range( digAcc->get_call_ranges().get_elem(d) ) ) ); // FIXME OMIT SIMPLIFY here
      } );

    // for (auto& rng : primaryCallRangesInThisDim) {
    //   std::cout << "PRI RANGES : " << rng->get_pc_string() << '\n';
    // }

#ifndef PARSER_TEST
    if (isDirectMesh) {

      auto commonLocEmbeds = digestedSet.front()->get_local_embeddings();

      auto secondaryDigests = digCollection.get_secondary_digest_accesses();

      if (not secondaryDigests.empty()) {

        auto secondaryCallRangesInThisDim = transform_vec( secondaryDigests,
          [d, commonLocEmbeds] (const digest_access * digAcc) {
 
            return static_unique_pointer_cast< const token<kind::range> >( digAcc->get_induced_call_range( d, commonLocEmbeds.get_elem(d) ) );
          }
        );

        // for (auto& rng : secondaryCallRangesInThisDim) {
        //   std::cout << "SEC RANGES : " << rng->get_pc_string() << '\n';
        // }

        std::move(std::begin(secondaryCallRangesInThisDim), std::end(secondaryCallRangesInThisDim), std::back_inserter(primaryCallRangesInThisDim));
      }
    }
#endif // PARSER_TEST

    // std::cout << "------------------------------------------BEFORE SIMPLIFYINGGGGGGGGGGGGG-------\n";

    // We will need these call ranges during the wrap.
    retRanges.edit_elem(d) = 
      static_unique_pointer_cast< const token<kind::range> >(
        simplify_piece(
          extend_ranges_to_context( 
            transform_vec( primaryCallRangesInThisDim, [] (const own_ctoken_t<kind::range>& ownRng) { return ownRng.get(); } ),
            super_type::get_local_context()
          )
        )
      );

    // auto rng = retRanges.get_elem(d);
    // std::cout << "RET_RANGE : " << rng->get_pc_string() << " : SimplSTART : " << simplify_piece( rng )->get_pc_string() << " SimplEND\n";
    // std::cout << "RET RANGE min : " << rng->get_limit<range_limit::min>()->get_pc_string() << " kind : " << rng->get_limit<range_limit::min>()->get_kind() << '\n';
    // std::cout << "RET RANGE max : " << rng->get_limit<range_limit::max>()->get_pc_string() << " kind : " << rng->get_limit<range_limit::max>()->get_kind() << '\n';
    // auto maxPc = rng->get_limit<range_limit::max>();
    // if (maxPc->get_kind() == kind::cs_list) {
    //   auto listTokens = static_cast<ctoken_t<kind::cs_list>>(maxPc)->get_tokens();
    //   for (auto lt : listTokens) {
    //     std::cout << "list token : " << lt->get_pc_string() << " kind : " << lt->get_kind() << " : Simpl : " << simplify_piece(lt)->get_pc_string() << '\n';
    //   }
    // }

  }


  return retRanges;
}


vec_own_cpiece_t mem_guard<mem_ak::affine>::make_all_offsets( const digest_collection& digCollection) const {

  vec_own_cpiece_t retVec;

  auto allAffAccs = digCollection.get_all_digest_accesses(); 

  // auto t2cFn = super_type::get_fn_transform2context();

  for (auto digAcc : allAffAccs) {

#ifdef REGION_LOG
    std::cout << "Making affine access \n";
#endif // REGION_LOG

    auto digAccOffsets = digAcc->get_aggregated_offsets();

    for (auto offPc : digAccOffsets) {

#ifdef REGION_LOG
    std::cout << "---from off : " << offPc->get_pc_string() << "\n";
#endif // REGION_LOG

      // auto newOff = simplify_piece( t2cFn(offPc) );
      auto newOff = simplify_piece( offPc );

      // Only add if there is no equivalent
      if (std::find_if(std::begin(retVec), std::end(retVec), [&] (const auto& pc) { return are_equal( pc.get(), newOff.get() ); }) == std::end(retVec)) {
        retVec.push_back( std::move(newOff) );
      } 
    }
  }

  return retVec;
}


///// Core class : guard

mem_guard<mem_ak::affine>::mem_guard( const std::vector<const affine_access*>& affs, cso_t<obj::data_decl> dDecl ) :
super_type(dDecl),
// Make global embeds considering only those affs that have maxDims :
m_embeddings( make_global_embeddings( get_max_dimensions(affs), affs ) ),
// From the globalEmbeds we can derive the local triple (embeddings, coordinates, ranges) for each aff:
m_affinesCollection( m_embeddings.get_vec(), affs ),
m_memRanges( make_global_mem_ranges( get_max_dimensions(affs), m_affinesCollection ) ),
m_callRanges( make_call_ranges( get_max_dimensions(affs), m_affinesCollection ) ),
m_offsets( make_all_offsets( m_affinesCollection ) )
{

#ifdef REGION_LOG
  std::cout << "@@@@@@@@@ Built Guard from " << affs.size() << " affines " << this->get_info() << '\n';
#endif // REGION_LOG
}


mem_guard<mem_ak::affine>::~mem_guard() {}


mem_ak mem_guard<mem_ak::affine>::get_mem_guard_kind() const {
  return mem_ak::affine; 
}


std::string mem_guard<mem_ak::affine>::get_info() const {
  std::string retStr = "V\n\tGUARD Obj with " + std::to_string(this->get_dimensions()) + " dimensions\n";

  retStr += "\tEmbeddings : ";
  for (auto& e : m_embeddings) { retStr += e->get_pc_string() + ","; }
  retStr += '\n';

  retStr += "\tRanges : ";
  for (auto& r : m_memRanges) { retStr += r->get_pc_string() + ","; }
  retStr += '\n';

  retStr += "\tCall Ranges : ";
  for (auto& r : m_callRanges) { retStr += r->get_pc_string() + ","; }
  retStr += '\n';

  retStr += "\tOffsets : ";
  for (auto& o : m_offsets) { retStr += o->get_pc_string() + ","; }
  retStr += '\n';

#ifndef PARSER_TEST
  retStr += "\tRoot fun arg : " + super_type::m_dDeclRoot->get_identifier() + '\n';
#endif // PARSER_TEST

  retStr += "\tDigested accesses :\n";
  for (auto da : m_affinesCollection.get_all_digest_accesses()) { retStr += da->get_info() + "\n"; }

  // retStr += m_affinesCollection.get_info();
  return retStr;
}


unsigned mem_guard<mem_ak::affine>::get_dimensions() const {
  if (m_embeddings.size() != m_memRanges.size()) {
    throw std::logic_error("Could not get dimensions of guard. global embeddings -- global ranges mismatch");
  }
  // return multiple::get_token_count();
  return m_embeddings.size();
}


// Return the factors that map (n-d <---> 1-d)
dim_cpiece_t mem_guard<mem_ak::affine>::get_global_embeddings() const {

  return dim_cpiece_t( m_embeddings.get_vec() );
}


dim_ctoken_t<kind::range> mem_guard<mem_ak::affine>::get_global_mem_ranges() const {

  return dim_ctoken_t<kind::range>( m_memRanges.get_vec() );
}


dim_ctoken_t<kind::range> mem_guard<mem_ak::affine>::get_global_call_ranges() const {

  return dim_ctoken_t<kind::range>( m_callRanges.get_vec() );
}


vec_cpiece_t mem_guard<mem_ak::affine>::get_all_offsets( ) const {

  return transform_vec(m_offsets, [] (const auto& pc) { return pc.get(); });
}




dim_cpiece_t mem_guard<mem_ak::affine>::get_local_embeddings( const affine_access * aff ) const {

  return m_affinesCollection.get_digest_access(aff)->get_local_embeddings();
}


dim_cpiece_t mem_guard<mem_ak::affine>::get_local_coordinates( const affine_access * aff ) const {

  return m_affinesCollection.get_digest_access(aff)->get_coordinates();
}


dim_ctoken_t<kind::range> mem_guard<mem_ak::affine>::get_local_mem_ranges( const affine_access * aff ) const {

  return m_affinesCollection.get_digest_access(aff)->get_mem_ranges();
}


own_cpiece_t mem_guard<mem_ak::affine>::get_local_offset( const affine_access * aff ) const {

  return fold_caddends( m_affinesCollection.get_digest_access(aff)->get_local_offsets() );
}

// private
unsigned mem_guard<mem_ak::affine>::try_get_id_matching_global_embed( cpiece_t upstreamGlobalEmbedInCallee ) const {

  auto thisGlobalEmbeds = this->get_global_embeddings();

  unsigned d = 0;
  for (auto thisGlobalEmbed : thisGlobalEmbeds) {
    if ( are_equal( thisGlobalEmbed, upstreamGlobalEmbedInCallee ) ) {
      return d;
    }
    d++;
  }
  return d;
}

// private
unsigned mem_guard<mem_ak::affine>::get_id_matching_global_embed( cpiece_t upstreamGlobalEmbed ) const {

  auto d = this->try_get_id_matching_global_embed( upstreamGlobalEmbed );

  if (d == this->get_global_embeddings().size()) {
    throw std::logic_error("Could not get_range_matching_global_embed : not found . upstreamGlobalEmbed : " + upstreamGlobalEmbed->get_pc_string() + ". This guard : " + this->get_info());
  }

  return d;
}


// public
bool mem_guard<mem_ak::affine>::has_range_matching_global_embed( cpiece_t upstreamGlobalEmbed ) const {

  auto d = this->try_get_id_matching_global_embed( upstreamGlobalEmbed );

  return (d < this->get_global_embeddings().size());
}

// public
ctoken_t<kind::range> mem_guard<mem_ak::affine>::get_range_matching_global_embed( cpiece_t upstreamGlobalEmbed ) const {

  return this->get_global_mem_ranges().get_elem( this->get_id_matching_global_embed(upstreamGlobalEmbed) );
}

dim_cpiece_t
mem_guard<mem_ak::affine>::get_unique_local_embeds( ) const {
  return this->get_unique_local_embeds( m_affinesCollection.get_all_digest_accesses() );
}

dim_cpiece_t
mem_guard<mem_ak::affine>::get_unique_local_embeds( std::vector<const digest_access *> digAccs ) const {

  auto srcCtxt = super_type::get_local_context();

  // this is a vector<dim_cpiece_t>
  auto locEmbeds = transform_vec( digAccs, [srcCtxt] (const digest_access * digAcc) { return digAcc->get_local_embeddings(); } );

  // Make sure all are equivalent after srcCtxt transformation TODO
  // XXX AND DEPRECATE UNIQUENESS VIA get_vec_string_unique_local_embeds
  // XXX AND DEPRECATE get_local_embeddings_string
  // std::cout << "ENSURE-ME\n";

  // Return first, 
  return locEmbeds.front();
  // return dim_own_cpiece_t( transform_vec( locEmbeds.front(), [] (cpiece_t pc) { return const_piece(pc); } ) );
}

vec_string_t
mem_guard<mem_ak::affine>::get_vec_string_unique_local_embeds( ) const {
  return this->get_vec_string_unique_local_embeds( m_affinesCollection.get_all_digest_accesses() );
}

vec_string_t
mem_guard<mem_ak::affine>::get_vec_string_unique_local_embeds( std::vector<const digest_access *> digAccs ) const {

  auto srcCtxt = super_type::get_local_context();

  // auto digAccs = m_affinesCollection.get_all_digest_accesses();

  auto digAccsString = transform_vec( digAccs, [srcCtxt] (const digest_access * digAcc) { return digAcc->get_local_embeddings_string(srcCtxt); } );

  if (digAccsString.empty()) {
    throw std::logic_error("Could not get_vec_string_unique_local_embeds. Empty vec");
  }

  // Lexicogr sort...
  std::sort(std::begin(digAccsString), std::end(digAccsString));

  // And remove contiguous same
  digAccsString.erase( std::unique(std::begin(digAccsString), std::end(digAccsString)), std::end(digAccsString) );

  // std::cout << "Unique string descriptors\n";
  // for (auto str : digAccsString) {
  //   std::cout  << str << ',';
  // }
  // std::cout << '\n';
  
  return digAccsString;
}





#ifndef PARSER_TEST


std::string mem_guard<mem_ak::affine>::get_mesh_type_str() const {

  // Ensure also that all hold the same global embeds TODO TODO TODO 

  // if (this->get_vec_string_unique_local_embeds().size() == 1) {

  auto primaryDigests = this->m_affinesCollection.get_primary_digest_accesses();
  auto secondaryDigests = this->m_affinesCollection.get_secondary_digest_accesses();


  if (primaryDigests.empty()) {
    if (secondaryDigests.size() == 1) {
      // No primaries, only one secondary
      return "dep::mesh::single";
    } else {
      // No primaries, several secondary
      return "dep::mesh::tree";
    }
  }
  // Here we know that there is at least one primary

  auto areAllPrimaryInternallyDisjoint = std::all_of( std::begin(primaryDigests), std::end(primaryDigests),
      [] (const digest_access * primaryDigAcc) {
        return primaryDigAcc->are_blocks_internally_disjoint();
      });

  if (not areAllPrimaryInternallyDisjoint) {
    return "dep::mesh::tree";
  }
  // Here we know that all primary digests are internally disjoint.

  auto uniqueLocEmbeds = this->get_vec_string_unique_local_embeds( primaryDigests );

  if (uniqueLocEmbeds.size() > 1) {
    return "dep::mesh::tree";
  }

  // Here we know that primary digests have common local embeds (they refer to the same mesh).

  // Now see if the secondary digests, satisfy the non-overlapping relations under these common local embeds,

  if (secondaryDigests.empty()) {
    // No secondary, and all primary share local embeds, so everything OK.
    return "dep::mesh::direct";
  }

  // There is at least one secondary digest

  auto commonLocEmbeds = primaryDigests.front()->get_local_embeddings();

  auto areAllSecondaryDisjoint = std::all_of(std::begin(secondaryDigests), std::end(secondaryDigests),
      [commonLocEmbeds] (const digest_access * secDigAcc) {
        return secDigAcc->are_blocks_disjoint_under( commonLocEmbeds );
      }
    );

  // Finally, return true, if secondary are disjoint under common loc embeds.
  if (areAllSecondaryDisjoint) {
    return "dep::mesh::direct";
  } else {
    return "dep::mesh::tree";
  }
}



std::string mem_guard<mem_ak::affine>::get_wrap_command() const {

  auto wrapVarName = super_type::m_dDeclRoot->get_wrap_variable_name();
  auto varName = super_type::m_dDeclRoot->get_variable_name(); 

  if (this->get_dimensions() == 0) {
    return "auto " + wrapVarName + " = dep::wrap_region<0>(" + varName + ")";
  }

  std::string meshKindStr = this->get_mesh_type_str();


  std::string retStr;
  retStr = "auto " + wrapVarName + " = dep::wrap_region<" + std::to_string(this->get_dimensions()) + "," + meshKindStr + ">(" + varName;

  auto locCtxt = this->get_local_context();

  if (meshKindStr == "dep::mesh::direct" or meshKindStr == "dep::mesh::tree" or (this->get_dimensions() > 0 and meshKindStr == "dep::mesh::single")) {

    retStr += ", " + adapt_to_string( this->get_global_embeddings().get_vec(),
        [locCtxt] (const cpiece_t pc) {
          // return static_unique_pointer_cast<const piece>( simplify_piece( pc) );
          return static_unique_pointer_cast<const piece>( simplify_piece( extend_piece( pc, locCtxt ) ) );
        },
        embeddings_to_bracket_string
      );
  }

  if (meshKindStr == "dep::mesh::direct") {

    // Then insert local embeds information, so that block coords can be computed while emitting bnds
    auto uniqueLocEmbeds = this->get_vec_string_unique_local_embeds( m_affinesCollection.get_primary_digest_accesses() );
    retStr += ", " + uniqueLocEmbeds.front();
    // auto uniqueLocEmbeds = this->get_unique_local_embeds( m_affinesCollection.get_primary_digest_accesses() );
    // retStr += ", " + adapt_to_string( uniqueLocEmbeds.get_vec(),
    //     [locCtxt] (const cpiece_t pc) {
    //       // return static_unique_pointer_cast<const piece>( simplify_piece( pc) );
    //       // return static_unique_pointer_cast<const piece>( extend_piece( pc, locCtxt ) );
    //       return static_unique_pointer_cast<const piece>( simplify_piece( extend_piece( pc, locCtxt ) ) );
    //     },
    //     embeddings_to_bracket_string
    //   );

    // Then insert number of blocks information, so that block coords can be computed while emitting bnds
    auto callRanges = dim_own_piece_t( transform_vec( this->get_global_call_ranges().get_vec(), std::bind( transform_to_local_context, std::placeholders::_1, super_type::get_local_context() ) ) );
    retStr += ", " + ranges_to_bracket_string( transform_vec( callRanges.get_vec(), [] (cpiece_t pc) { return static_cast<ctoken_t<kind::range>>(pc); } ) );
  } else {
    // No need to append anything. We only need global embeds to compute the pointer offset and pointer range from coords and ranges in emit_bnd
  }

  retStr += ")";

  return retStr;
}


std::string mem_guard<mem_ak::affine>::get_emit_arguments( const access * acc ) const {


  auto aff = static_cast<const mem_access<mem_ak::affine>*>( acc );

  auto thisAffAcc = this->m_affinesCollection.get_digest_access( aff );

  // std::cout << "Emmiting for : " << " : " << offsets_to_bracket_string( thisAffAcc->get_aggregated_offsets() ) << '\n';

  // std::cout << fold_caddends( thisAffAcc->get_aggregated_offsets() )->get_pc_string() << '\n';

  // std::cout << thisAffAcc->get_info() << '\n';

  if (this->get_dimensions() == 0) {

    if (thisAffAcc->has_downstream_offsets()) {

      auto aggOffsets = thisAffAcc->get_aggregated_offsets();

      // return "(" + fold_caddends( aff->get_offsets() )->get_pc_string() + offsets_to_bracket_string(aggOffsets)+ ")";
      return "(" + fold_caddends( aff->get_offsets() )->get_pc_string() + ", /*ds-off*/" + fold_caddends( aggOffsets )->get_pc_string() + ")";
    } else { 

      return "(" + fold_caddends( aff->get_offsets() )->get_pc_string() + ")";

    }

  }


  std::string retStr;
  retStr += "(";

  auto procCoordinates = dim_own_cpiece_t( transform_vec( thisAffAcc->get_coordinates().get_vec(), [] (cpiece_t coord) { return static_unique_pointer_cast< const piece >( simplify_piece(coord) ); } ) );

  retStr += coordinates_to_bracket_string( procCoordinates.get_vec() );
  // retStr += coordinates_to_bracket_string( thisAffAcc->get_coordinates().get_vec() );

  retStr += ",";

  retStr += ranges_to_bracket_string( thisAffAcc->get_mem_ranges().get_vec() );

  retStr += ")";

  // Add offsets here if existing too, TODO TODO TODO

  return retStr;
}

std::string mem_guard<mem_ak::affine>::serial() const {

  return make_serial<4>(
    {"globalEmbeds:","globalRanges:","globalCallRanges:","globalOffsets:"},
    this->get_global_embeddings().get_vec(),
    this->get_global_mem_ranges().get_vec(),
    this->get_global_call_ranges().get_vec(),
    this->get_all_offsets()
  );
}

#endif // PARSER_TEST




} // namespace bld::src::pc
