
#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#include "source/token/simplify/interface.hpp"

#include "source/token/region/affine/access.hpp"

#include "source/token/combine/interface.hpp"

#include "source/token/region/affine/dim/container.hpp"

#include "common/util.hpp"

#include <iostream>

namespace bld::src::pc {


// First : A vector of bool for each of the previous addends. Each bool element correspond to a 'd' in globalEmbeds and localEmbeds.
// Second : whether that addend has been already assigned / mapped to a 'd' bin or not. Initially not
using match_info_t = std::pair< dim_bool_t, bool >;

static
std::vector< match_info_t >
extract_dimensional_info( const dim_cpiece_t& globalEmbeds, const dim_cpiece_t& localEmbeds, const vec_cpiece_t& affAddends ) {

  // Returns a vector from the addends vector.
  // Each element correspond to an addend, and holds :
  // 1. a bool vector specifying whether that addend contains each global and local embed in each dimension.
  // 2. An initialized-to-false boolean, used in the following function, to mark whether that addend has been assigned or not. Initially not (false)
  

  auto retVec = transform_vec( affAddends,
      [&globalEmbeds, &localEmbeds] (cpiece_t addendPc) {
        // Each element specifies whether the addend contains each global embed
        auto addContainsGlobalEmbeds = transform_vec( globalEmbeds.ref_vec(), std::bind( contains_piece, addendPc, std::placeholders::_1 ) );
        // Each element specifies whether the addend contains each local embed
        auto addContainsLocalEmbeds = transform_vec( localEmbeds.ref_vec(), std::bind( contains_piece, addendPc, std::placeholders::_1 ) );

        return match_info_t( {
          dim_bool_t( compose_vecs( addContainsGlobalEmbeds, addContainsLocalEmbeds, std::logical_and<bool>{} ) ), // fwd bool vector
          /*mapped*/false
        });
      }
    );

  // std::cout << "DEBUGGING MATCH START\n";
  // for (auto a = 0u; a < affAddends.size(); a++) {

  //   std::cout << "addend : " << affAddends[a]->get_pc_string() << " contains :\n";

  //   for (auto d = 0u; d < globalEmbeds.size(); d++) {
  //     std::cout << "\t Ge : " << globalEmbeds.get_elem(d)->get_pc_string() << " and Le : " << localEmbeds.get_elem(d)->get_pc_string() << " ? " << (std::get<dim_bool_t>(retVec[a]).get_elem(d) ? "true" : "false") << '\n';
  //   }
  // }
  // std::cout << "DEBUGGING MATCH END\n";

  return retVec;
}

static
dim_container< vec_cpiece_t >
assign_addends_to_dimensions( const unsigned nDims, std::vector< match_info_t >& addendsMatchInfo, const vec_cpiece_t& affAddends ) {

  // Each element corresponds to a 'd', holding all addends matched to that 'd'.
  dim_container< vec_cpiece_t > addendsAssignedToDimensions( nDims );

  for (auto a = 0u; a < affAddends.size(); a++) {

    if ( not std::get<bool>(addendsMatchInfo.at(a)) ) { // Not already assigned to any dimension

      const auto& containsBothVec = std::get< dim_bool_t >( addendsMatchInfo.at(a) );
      if (containsBothVec.size() != nDims) { throw std::logic_error("Dimensions mismatch in assign_addends_to_dimensions"); }

      for (auto d = 0u; d < nDims; ++d) {

        if (std::all_of( std::begin(containsBothVec.ref_vec()) + d, std::end(containsBothVec.ref_vec()), [] (bool b) { return b; })) {

          // Addend 'a' contains all from 'd' to nDim - 1, so it will be placed in the 'd' bucket, assigned to dimension 'd'.
          addendsAssignedToDimensions.edit_elem(d).push_back( affAddends.at(a) );

          std::get<bool>( addendsMatchInfo.at(a) ) = true; // Mark as assigned, so it cannot be assigned to any other dimension.

          break; // Get out of the loop, this addend must not be assigned to any other dimension.

        } else {
          // Addend 'a' cannot be assigned to dimension 'd', so keep looping (maybe it can be assigned to the next dimension)
        }
      }

    } else {
      // Addend 'a' has already been assigned, so keep looping on addends.
    }
  }

  return addendsAssignedToDimensions;
}

  // static
  // own_cpiece_t make_addends_from_vec(const vec_cpiece_t& adds) {
  // 
  //   if (adds.empty()) {
  //     return make_num( 0 );
  //   } else if (adds.size() == 1) {
  //     return edit_piece( adds.front() );
  //   } else {
  //     return simplify_piece( make_token< kind::addends >( edit_piece_vector( adds ) ) );
  //   }
  // }

// Final return
static
dim_own_cpiece_t
reduce_to_addend_tokens( const dim_container< vec_cpiece_t >& addendsAssignedToDimensions ) {

  return dim_own_cpiece_t(
      transform_vec(
        addendsAssignedToDimensions.get_vec(),
        fold_caddends
      )
    );
}

// Final return
static
vec_own_cpiece_t extract_unassigned( const std::vector< match_info_t >& addendsMatchInfo, const vec_cpiece_t& affAddends ) {

  vec_own_cpiece_t unassignedAddends;
  for (auto a = 0u; a < affAddends.size(); a++) {

    if ( not std::get<bool>( addendsMatchInfo.at(a) ) ) { // Not already assigned
      // ie, std::get<std::vector<bool>> have all 'false'
      // if (std::get< dim_bool >( addendsMatchInfo.at(a) ).ref_vec() != std::vector<bool>(nDim, false)) {
      //   throw std::logic_error("Could not make_dim_matching. Unassigned addends do have at least one dimensional matching possible, but not mapped");
      // }
      
      unassignedAddends.emplace_back( simplify_piece( affAddends.at(a) ) );
      // std::cout << "Including unassigned addend : " << unassignedAddends.back()->get_pc_string() << '\n';
    }
  }

  return unassignedAddends;
}



///////////////
//
// INTERFACE
//
///////////////
// Used to quantify the quality of the matching of a given aff expr against local embeds.
unsigned score_dim_matching( const dim_cpiece_t globalEmbeds, const dim_cpiece_t localEmbeds, const mem_access<mem_ak::affine> * aff ) {

  if (globalEmbeds.size() != localEmbeds.size()) {
    throw std::logic_error("Cannot make_dim_matching : local - global embeddings dimensions mismatch");
  }

  auto ownAffAddends = aff->get_full_expression_unfold();
  auto affAddends = transform_vec( ownAffAddends, [] (const own_cpiece_t& ownPc) { return ownPc.get(); } );

  auto addendsMatchInfo = extract_dimensional_info( globalEmbeds, localEmbeds, affAddends );

  std::vector<unsigned> dimsAssigned( globalEmbeds.size(), 0 );

  auto nDims = globalEmbeds.size();

  for (auto a = 0u; a < affAddends.size(); a++) {

    if ( not std::get<bool>(addendsMatchInfo.at(a)) ) { // Not already assigned to any dimension

      const auto& containsBothVec = std::get< dim_bool_t >( addendsMatchInfo.at(a) );

      for (auto d = 0u; d < nDims; ++d) {

        if (std::all_of( std::begin(containsBothVec.ref_vec()) + d, std::end(containsBothVec.ref_vec()), [] (bool b) { return b; })) {
          std::get<bool>( addendsMatchInfo.at(a) ) = true; // Mark as assigned
          dimsAssigned[d] += 1;
        }
      }

    } else {

    }
  }

  // The score is the amount of dims assigned.
  return std::count_if( std::begin(dimsAssigned), std::end(dimsAssigned), [] (unsigned dCount) { return dCount > 0; } );
}

// static
// bool is_defaulted( const dim_cpiece_t embeds ) {
// 
//   if (embeds.empty()) {
//     return false;
//   }
// 
//   auto vec = embeds.get_vec();
// 
//   auto ownOnePc = make_num(1);
//   auto onePc = ownOnePc.get();
// 
//   return std::all_of( std::begin(vec), std::end(vec), [onePc] (cpiece_t pc) { return are_equal(pc, onePc); } );
// }

///////////////
//
// INTERFACE 
//
///////////////
// If localEmbeds = globalEmbeds, this is used to deduce the addends in a complete/primary affine expression.
// If localEmbeds != globalEmbeds, this is used to deduce the addends in a incomplete/secondary affine expression). This local embeds are built from other primary affine expression.
std::pair<
  dim_own_cpiece_t, // Addends assigned to each dimension
  vec_own_cpiece_t // Remaining addends not matched to anything (offset)
>
make_dim_matching( const dim_cpiece_t globalEmbeds, const dim_cpiece_t localEmbeds, const mem_access<mem_ak::affine> * aff ) {

  if (globalEmbeds.size() != localEmbeds.size()) {
    throw std::logic_error("Cannot make_dim_matching : local - global embeddings dimensions mismatch");
  }

  // if (is_defaulted(globalEmbeds) or is_defaulted(localEmbeds) and globalEmbeds.size() == aff->get_this_dimensions()) {
  //   // Useful for testing
  //   return std::make_pair( aff->get_dim_addends(), const_piece_vector( aff->get_offsets() ) );
  // }

  auto ownAffAddends = aff->get_full_expression_unfold();
  auto affAddends = transform_vec( ownAffAddends, [] (const own_cpiece_t& ownPc) { return ownPc.get(); } );

  auto addendsMatchInfo = extract_dimensional_info( globalEmbeds, localEmbeds, affAddends );

  auto addendsAssignedToDimensions = assign_addends_to_dimensions( globalEmbeds.size(), addendsMatchInfo, affAddends );

  return std::make_pair(
      reduce_to_addend_tokens( addendsAssignedToDimensions ),
      extract_unassigned( addendsMatchInfo, affAddends )
    );
}


#ifndef PARSER_TEST
struct make_frac {
  using result_type = own_cpiece_t;

  result_type operator()( cpiece_t loopVarFactor, cpiece_t globalEmbed ) const {
    if (not contains_piece(loopVarFactor, globalEmbed)) {
      throw std::logic_error("Could not deduce local embeds while dim matching, from loop var factors. LVF : " + loopVarFactor->get_pc_string() + " not containing global embed : " + globalEmbed->get_pc_string());
    }
    return simplify_piece( make_token< kind::fraction >( loopVarFactor, globalEmbed ) );
  }
};
#endif // PARSER_TEST

std::pair<
  dim_own_cpiece_t, // Addends assigned to each dimension
  vec_own_cpiece_t // Remaining addends not matched to anything (offset)
>
make_dim_matching( const dim_cpiece_t globalEmbeds, const mem_access<mem_ak::affine> * aff ) {

#ifndef PARSER_TEST
  auto lvfs = aff->get_loop_vars_factors();

  if (lvfs.size() == globalEmbeds.size()) {

    auto localEmbeds = dim_own_cpiece_t( compose_vecs( lvfs.get_vec(), globalEmbeds.get_vec(), make_frac() ) );

    return make_dim_matching( globalEmbeds, localEmbeds.get_vec(), aff );

  } else {
    return make_dim_matching( globalEmbeds, globalEmbeds, aff );
  }

#else // PARSER_TEST

    return make_dim_matching( globalEmbeds, globalEmbeds, aff );

#endif // PARSER_TEST


}



} // namespace bld::src::pc
