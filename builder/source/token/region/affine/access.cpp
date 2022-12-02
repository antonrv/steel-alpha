
#include "source/token/region/affine/access.hpp"


#include "source/token/region/affine/guard.hpp"

#include "source/token/region/affine/dim/permute.hpp"

#include "source/token/factorize.hpp"
#include "source/token/simplify/interface.hpp"

#include "source/token/combine/interface.hpp"

#include "common/util.hpp"

#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#ifndef PARSER_TEST

// #include "source/object/data/piece_limit.hpp"

// #include "source/object/data/use.hpp"
// #include "source/object/data/transform/interface.hpp"
// #include "source/object/data/decl.hpp"


#endif // PARSER_TEST

#include "source/serial/make_serial.hpp"

#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream> // DBG XXX

namespace bld::src::pc {


// --------- Aux function for constructor
static
std::set<std::string>
get_unique_loop_var_names(cpiece_t pc, std::function<bool(cpiece_t)> lvLambda) {

  std::set<std::string> retSet;

  if (pc == nullptr) { return retSet; }

  if (pc->get_kind() == kind::var and lvLambda(pc)) {

    retSet.insert( pc->get_pc_string() );

  } else if (pc->is_multiple()) {
    auto terms = static_cast<const multiple*>(pc)->get_flatten_terminals();

    transform_if(std::begin(terms), std::end(terms), std::inserter(retSet, std::end(retSet)), lvLambda, [] (cterminal_t trm) { return trm->get_pc_string(); } );
  } else {
    // A terminal not satisfyinf lvLambda, so do nothing
  }

  return retSet;
}


using fac_id_t = std::tuple<own_cpiece_t, const loop_var*, unsigned>;

// --------- Aux function for constructor
static
std::pair< dim_own_cloopvar_t, dim_own_cpiece_t >
sort_vectors( const dim_cloopvar_t& inLVs, const dim_cpiece_t& inLVFactors, std::vector<fac_id_t>& idxFactsTransformed ) {

  // std::cout << "Before Sorting : ";
  // for (auto &fc : idxFactsTransformed) {
  //   std::cout << std::get<0>(fc)->get_pc_string() << ". Size : " << get_children_factors(std::get<0>(fc).get()).size() << ". Pck : " << std::get<0>(fc)->get_kind() << ". Id : " << std::get<1>(fc) << " ; ";
  // }
  // std::cout << '\n';


  // Sort them according to nesting factors
  std::sort( std::begin(idxFactsTransformed), std::end(idxFactsTransformed),
    [] (const fac_id_t& facIdLHS, const fac_id_t& facIdRHS) {
      // std::cout << "WITHIN SORT : \n";
      // std::cout << "lhs : " << std::get<0>(facIdLHS)->get_pc_string() << ", LV : " << std::get<1>(facIdLHS)->get_pc_string() << '\n';
      // std::cout << "rhs : " << std::get<0>(facIdRHS)->get_pc_string() << ", LV : " << std::get<1>(facIdRHS)->get_pc_string() << '\n';
      if (contains_piece(std::get<0>(facIdLHS).get(), std::get<0>(facIdRHS).get())) {
        return true; // Factors that encompass other factors go first
      } else if (contains_piece(std::get<0>(facIdRHS).get(), std::get<0>(facIdLHS).get())) {
        return false;
      } else if ( get_children_factors(std::get<0>(facIdLHS).get()).size() != get_children_factors(std::get<0>(facIdRHS).get()).size() ) {
        // When lhs not contained in rhs and viceversa, sort according the sheer number of factors. (more factors ---> go first)
        return get_children_factors(std::get<0>(facIdRHS).get()).size() < get_children_factors(std::get<0>(facIdLHS).get()).size();
      } else {
        // Same number of factors. Higher order vars go first (loopvars in outermost loops go first)
        auto lvLhs = std::get<1>(facIdLHS);
        auto lvRhs = std::get<1>(facIdRHS);
        return lvRhs->nested_in( lvLhs ); // If true, then lhs goes before rhs
      }
    });


  return std::make_pair(
    dim_own_cloopvar_t(
      transform_vec( idxFactsTransformed,
        [&inLVs] (const fac_id_t& fact) {
          return static_unique_pointer_cast< const loop_var >( const_piece( inLVs.get_elem( std::get<unsigned>(fact) ) ) );
        })
      ),
    dim_own_cpiece_t(
      transform_vec( idxFactsTransformed,
        [&inLVFactors] (const fac_id_t& fact) {
          return const_piece( inLVFactors.get_elem( std::get<unsigned>(fact) ) );
        })
      )
    );
}



///////////////
//
// MAIN CONSTRUCTOR
//
///////////////
mem_access<mem_ak::affine>::mem_access( cpiece_t inputPc, std::function<bool(cpiece_t)> lvLambda, cso_t<obj::data_use> dUse ) :
super_type(inputPc, dUse)
{
  if (inputPc == nullptr) {
    // We no longer accept nullptrs // return;
    throw std::logic_error("Affine constructor receiving nullptr");
  }

  // First get all the lv names
  auto lvNames = get_unique_loop_var_names(inputPc, lvLambda);

  // If no loop vars, create a basic affine with just an offset
  if (lvNames.empty()) {
    // 0-Dim Affine expr holding only an offset
    m_offsets = unfold_caddends( inputPc );
    return;
  }

  auto nDims = lvNames.size();

  // Second, gather all the lvs and factors
  dim_own_cloopvar_t ownedLVs(nDims);
  dim_own_cpiece_t ownedFactors(nDims);
  std::vector<fac_id_t> ownedSortFactors;

  // Need highest_local_context to represent LV factors as a product of variables defined at the dDecl definition, not temporary vars.
  // Note that we only need it for sorting, however not any transformed piece is being stored

  auto targetLocalCtxt = super_type::get_highest_local_context();
  // lvNames non-empty
  // std::cout << "LVnames : " << lvNames.size() << '\n';
  unsigned idCount = 0;
  for (auto lvStr : lvNames) {

    auto currLVLambda = [&] (cpiece_t pivPc) {
        if (lvLambda(pivPc)) {
          return pivPc->get_pc_string() == lvStr;
        }
        return false;
      };

    ownedFactors.edit_elem(idCount) = extract_factors( inputPc, currLVLambda );

    if (ownedFactors.get_elem(idCount)->get_pc_string() == "0") {
      throw std::logic_error("Owned factor cannot be zero. While trying to extract factors in : " + inputPc->get_pc_string() + " of LV " + lvStr);
    }

    auto lvPc = inputPc->find_piece_satisfying( currLVLambda );

    if (lvPc == nullptr) { throw std::logic_error("Could not find current LV piece while make_affine"); }

    if (lvPc->get_kind() != kind::var) {

      throw std::logic_error("Unreachable in make_affine, trying to identify LV with name, not found : " + lvStr);
    }

    auto var = static_cast<ctoken_t<kind::var>>(lvPc);
#ifdef PARSER_TEST
    ownedLVs.edit_elem(idCount) = std::make_unique< const loop_var >( *var );
#else // PARSER_TEST
    ownedLVs.edit_elem(idCount) = std::make_unique< const loop_var >( *(var->get_loop_variable()) );
#endif // PARSER_TEST


    ownedSortFactors.emplace_back( std::make_tuple( extend_piece( ownedFactors.get_elem(idCount), targetLocalCtxt ), ownedLVs.get_elem(idCount), idCount) );

    idCount++;
  }

  auto [lvs, lvfs] = sort_vectors(ownedLVs.get_vec(), ownedFactors.get_vec(), ownedSortFactors);
  // ownedLVs.clear();
  // ownedFactors.clear();
  // ownedSortFactors.clear();

  m_loopVars = dim_own_cloopvar_t( std::move(lvs) );

  m_loopVarsFactors = dim_own_cpiece_t( std::move(lvfs) );

  m_offsets = unfold_caddends( extract_non_factors(inputPc, lvLambda).get() );

  // Check. Don't do it, not general enough yet
  // auto fullExprPc = this->get_full_expression();
  // if (not are_equal( simplify_piece(fullExprPc).get(), simplify_piece(inputPc).get() )) {
  //   throw std::runtime_error("Building affine mem access. Parsed expression not matching inputPc. \n\tInput : " + inputPc->get_pc_string() + "\n\tParsed: " + fullExprPc->get_pc_string());
  // }

}


// DEPRECATED
// mem_access<mem_ak::affine>::mem_access( cpiece_t inputPc, std::function<bool(cpiece_t)> lvLambda, const mem_access& other ) :
// mem_access(inputPc, lvLambda
// #ifndef PARSER_TEST
// ,other.get_root_data_use()
// #endif // PARSER_TEST
// )
// {
// #ifdef PARSER_TEST
//   super_type::set_downstream_guard( other.get_downstream_guard() );
// #endif // PARSER_TEST
// }


// DEPRECATED
///////////////
//
// COPY CONSTRUCTOR
//
///////////////
// mem_access<mem_ak::affine>::mem_access(const mem_access& other) :
// super_type(other),
// m_loopVars( transform_vec(other.m_loopVars.ref_vec(), [] (const auto& ownLv) { return static_unique_pointer_cast<const loop_var>( const_piece(ownLv.get()) ); } )),
// m_loopVarsFactors(const_piece_vector(other.m_loopVarsFactors.ref_vec())),
// m_offset(const_piece(other.m_offset.get()))
// { }


mem_ak mem_access<mem_ak::affine>::get_mem_access_kind() const {
  return mem_ak::affine;
}


std::string mem_access<mem_ak::affine>::get_info() const {

  auto loopVars = this->get_loop_vars();
  auto loopVarFactors = this->get_loop_vars_factors();

  std::string retStr = "V\n\tAffine access START\n";
  retStr += "\tFull expr : " + this->get_full_expression()->get_pc_string() + "\n";
  retStr += "\tLoc dim : " + std::to_string( this->get_this_dimensions() ) + "\n";
  auto dsGuard = this->get_downstream_guard();
  retStr += "\tDS dim : " + std::to_string( dsGuard != nullptr and dsGuard->get_mem_guard_kind() == mem_ak::affine ? static_cast<const mem_guard<mem_ak::affine>*>(dsGuard)->get_dimensions() : 0 ) + "\n";

  auto offs = this->get_offsets();
  for (auto off : offs) {  retStr += "\tOffset : " + off->get_pc_string() + '\n'; }
  for (auto i = 0u; i < this->get_this_dimensions(); ++i) {
    retStr += "\tLoopVar : " + loopVars.get_elem(i)->get_pc_string() + ". Factor : " + loopVarFactors.get_elem(i)->get_pc_string() + '\n';
  }

  retStr += super_type::get_info();

  retStr += "\tAffine access END\n";

  return retStr; 
}


unsigned mem_access<mem_ak::affine>::get_this_dimensions() const {

  if (m_loopVars.size() != m_loopVarsFactors.size()) {
    throw std::logic_error("Dimensions mismatch in affine");
  }

  return (unsigned)m_loopVars.size();
}


unsigned mem_access<mem_ak::affine>::get_dimensions() const {

  auto dsGuard = this->get_downstream_guard();

  if (dsGuard != nullptr and dsGuard->get_mem_guard_kind() == mem_ak::affine) {

      
    // return dsGuard->get_dimensions();
    auto dsDims = static_cast<const mem_guard<mem_ak::affine>*>(dsGuard)->get_dimensions();
    return std::max( this->get_this_dimensions(), dsDims );
  }

  return this->get_this_dimensions();
}

struct mask_offset {
  using result_type = cpiece_t;
  result_type operator()(bool b, cpiece_t off) const { return b ? off : nullptr; }
};

static
vec_own_cpiece_t get_offset_permutations( vec_cpiece_t offsets ) {

  vec_own_cpiece_t retPermutationSet;

  if (offsets.empty()) {
    retPermutationSet.emplace_back( make_num(0) );
    return retPermutationSet;
  }

  std::vector< vec_bool_t > boolPerms = make_binary_permutations( offsets.size() );

  // For each bin permutation, mask the offsets : true -> cpiece OK, false -> nullptr
  std::vector< vec_cpiece_t > addendsPerms = transform_vec( boolPerms,
      [offsets] (vec_bool_t boolMask) {
        return compose_vecs( boolMask, offsets, mask_offset() );
      }
    );

  // Remove nullptrs
  for (auto& addendsPerm : addendsPerms) {
    addendsPerm.erase( std::remove_if(std::begin(addendsPerm), std::end(addendsPerm), [] (cpiece_t pc) { return pc == nullptr; }), std::end(addendsPerm));
  }

  return transform_vec( addendsPerms, [] (vec_cpiece_t adds) { return fold_caddends( adds ); } );
}


own_cpiece_t mem_access<mem_ak::affine>::get_match_coord( cpiece_t matchedAddend ) const {

  auto nDims = this->get_this_dimensions();

  auto ownOffsetPermutations = get_offset_permutations( this->get_offsets() );
  auto offsetPermutations = transform_vec( ownOffsetPermutations, [] (const own_cpiece_t& ownPc) { return ownPc.get(); } );

  for (auto d = 0u; d < nDims; d++) {

    for (auto off : offsetPermutations) {

      auto cmp = simplify_piece( make_token< kind::addends >( off, simplify_piece( make_token< kind::factors >( m_loopVars.get_elem(d), m_loopVarsFactors.get_elem(d) ) ) ) );

      if (are_equal(cmp.get(), matchedAddend)) {

        // Note that if this is true, then off is divisible by the lv factor, as lv*lvf + off ==  coord * globalEmbed == matchedAddend.
        return simplify_piece( make_token< kind::addends >( m_loopVars.get_elem(d), simplify_piece( make_token< kind::fraction >( off, m_loopVarsFactors.get_elem(d) ) ) ) );

      } else {
        // Not equal, keep looping
      }
    }
  }

  if (nDims == 0) {

    for (auto off : offsetPermutations) {
      if (are_equal(off, matchedAddend)) {
        return const_piece( off );
      } 
    }
  }

  throw std::logic_error("Could not get_match_coord from " + matchedAddend->get_pc_string() + ". In affine access : " + this->get_info());

}

// own_cpiece_t mem_access<mem_ak::affine>::get_matching( cpiece_t matchedAddend ) const {
// 
//   auto nDims = this->get_this_dimensions();
// 
//   auto zeroNum = make_num(0);
//   auto offs = this->get_offsets();
//   offs.push_back( zeroNum.get() );
// 
// 
//   for (auto d = 0u; d < nDims; d++) {
// 
//     for (auto off : offs) {
// 
//       auto cmp = simplify_piece( make_token< kind::addends >( off, simplify_piece( make_token< kind::factors >( m_loopVars.get_elem(d), m_loopVarsFactors.get_elem(d) ) ) ) );
// 
//       if (are_equal(cmp.get(), matchedAddend)) {
// 
//         std::cout << "Equal : "<< cmp->get_kind() << "->" << cmp->get_pc_string() << " == " << matchedAddend->get_kind() << "->" << matchedAddend->get_pc_string() << '\n';
//         // loopVar + off/lvf
//         auto retNaked = simplify_piece( make_token< kind::addends >( make_token< kind::factors >(m_loopVars.get_elem(d), m_loopVarsFactors.get_elem(d)), off ) ); // lv * lvf + off
//         std::cout << "Returning matched : " << retNaked->get_pc_string() << '\n';
//         return retNaked;
//         // return const_piece( m_loopVars.get_elem(d) );
//       } else {
//         std::cout << "Not equal : "<< cmp->get_kind() << "->" << cmp->get_pc_string() << " != " << matchedAddend->get_kind() << "->" << matchedAddend->get_pc_string() << '\n';
//       }
//     }
//   }

//   // Not possible nDims == 0 since this is called from the primary digest_access constructor
//   // if (nDims == 0) {
// 
//   //   for (auto off : offs) {
//   //     if (are_equal(off, matchedAddend)) {
//   //       
//   //       std::cout << "Returning matched : " << off->get_pc_string() << '\n';
//   //       return const_piece(off);
//   //     }
//   //   }
//   // }
// 
//   throw std::logic_error("Could not get_matching from " + matchedAddend->get_pc_string() + ". In affine access : " + this->get_info());
// }

// own_cpiece_t mem_access<mem_ak::affine>::get_factor_of_addend( cpiece_t matchedAddend ) const {
// 
//   auto nDims = this->get_this_dimensions();
// 
//   for (auto d = 0u; d < nDims; d++) {
// 
//     auto prod = simplify_piece( make_token< kind::factors >( m_loopVars.get_elem(d), m_loopVarsFactors.get_elem(d) ) );
// 
//     auto offs = this->get_offset();
// 
//     if (are_equal(prod.get(), matchedAddend)) {
// 
//       return const_piece( m_loopVarsFactors.get_elem(d) );
// 
//     } else if (offs->get_pc_string() != "0") {
// 
//       auto prodPlusOffs = simplify_piece( make_token< kind::addends >( make_token< kind::factors >( m_loopVars.get_elem(d), m_loopVarsFactors.get_elem(d) ), offs )  );
//       if (are_equal(prodPlusOffs.get(), matchedAddend)) {
// 
//         return const_piece( m_loopVarsFactors.get_elem(d) );
//       }
//     }
//   }
//   throw std::logic_error("Could not get_factorized from " + matchedAddend->get_pc_string() + ". In affine access : " + this->get_info());
// }

// std::pair<own_cpiece_t, own_cpiece_t> mem_access<mem_ak::affine>::get_factorized(cpiece_t matchedAddend) const {
// 
//   auto nDims = this->get_this_dimensions();
// 
//   for (auto d = 0u; d < nDims; d++) {
//     auto prod = simplify_piece( make_token< kind::factors >( m_loopVars.get_elem(d), m_loopVarsFactors.get_elem(d) ) );
//     if (are_equal(prod.get(), matchedAddend)) {
//       return std::make_pair(
//         const_piece( m_loopVars.get_elem(d) ),
//         const_piece( m_loopVarsFactors.get_elem(d) )
//       );
//     }
//   }
// 
//   auto offset = this->get_offset();
// 
//   if (offset->get_pc_string() == "0") {
//     throw std::logic_error("Could not get_factorized from " + matchedAddend->get_pc_string() + ". In affine access : " + this->get_info());
//   }
// 
//   for (auto d = 0u; d < nDims; d++) {
//     auto prodPlusOffs = simplify_piece( make_token< kind::addends >( make_token< kind::factors >( m_loopVars.get_elem(d), m_loopVarsFactors.get_elem(d) ) ), offset );
//     if (are_equal(prodPlusOffs.get(), matchedAddend)) {
//       return pair( lv + offset,
//       return std::make_pair( m_loopVars.get_elem(d), m_loopVarsFactors.get_elem(d) );
//     }
//   }
//   
//   throw std::logic_error("Could not get_factorized from " + matchedAddend->get_pc_string() + ". In affine access : " + this->get_info());
// }


dim_own_cpiece_t mem_access<mem_ak::affine>::get_dim_addends() const {

  auto nDims = this->get_this_dimensions();

  dim_own_cpiece_t retDim(nDims);

  for (auto d = 0u; d < nDims; d++) {
    retDim.edit_elem(d) = simplify_piece( make_token< kind::factors >( m_loopVars.get_elem(d), m_loopVarsFactors.get_elem(d) ) );
  }

  return retDim;
}

bool mem_access<mem_ak::affine>::has_offset() const {
  return (this->get_offset()->get_pc_string() != "0");
}

vec_cpiece_t mem_access<mem_ak::affine>::get_offsets() const {
  return transform_vec( m_offsets, [] (const own_cpiece_t& own) { return own.get(); } );
}

own_cpiece_t mem_access<mem_ak::affine>::get_offset() const {
  return fold_caddends( this->get_offsets() );
}


dim_cloopvar_t  mem_access<mem_ak::affine>::get_loop_vars() const {
  return m_loopVars.get_vec();
}


dim_cpiece_t mem_access<mem_ak::affine>::get_loop_vars_factors() const {
  return m_loopVarsFactors.get_vec();
}

// Static auxiliary function
void mem_access<mem_ak::affine>::verify_containing_relation( const dim_cpiece_t& lhsPieces, const dim_cpiece_t& rhsPieces ) {

  if (lhsPieces.size() != rhsPieces.size()) {
    throw std::logic_error("Could not verify_containing_relation : vectors size mismatch");
  }


  auto nDims = lhsPieces.size();
  for (auto d = 0u; d < nDims; d++) {
    auto lhsPc = lhsPieces.get_elem(d);
    auto rhsPc = rhsPieces.get_elem(d);
    if (not contains_piece( lhsPc, rhsPc )) {
      throw std::runtime_error("Could not get_candidate_embeddings : this embedding not containing ds embedding : " + lhsPc->get_pc_string() + " not fully contains " + rhsPc->get_pc_string() +  ". idx " + std::to_string(d));
    }
  }
}

// dim_own_cpiece_t TODO
dim_own_cpiece_t mem_access<mem_ak::affine>::get_candidate_embeddings() const {

  // Logic behind this function : If there is a dsGuard and its dimensions are greater than this, then adopt those global embeds.

  dim_own_cpiece_t retCandidateEmbeds;

  auto thisLVFactors = this->get_loop_vars_factors();

  auto dsGuard = this->get_downstream_guard();

  if (dsGuard != nullptr and dsGuard->get_mem_guard_kind() == mem_ak::affine) {

    // Then we must make sure that the embeddings of this aff and the global embeds of the affine_guard downstream fully match.
    // Otherwise, the multidim ranges propagation (ds->original) would not be consistent.


    auto targetLocalCtxt = super_type::get_local_context();

    auto dsGlobalEmbeds = dim_own_cpiece_t(
      transform_vec( static_cast<const mem_guard<mem_ak::affine>*>( dsGuard )->get_global_embeddings().get_vec(),
        [targetLocalCtxt] (cpiece_t dsGe) {
          return static_unique_pointer_cast< const piece >( extend_piece( dsGe, targetLocalCtxt ) );
        })
      );

    if (dsGlobalEmbeds.size() < thisLVFactors.size()) {

      // This must be tested
      retCandidateEmbeds = dim_own_cpiece_t( transform_vec( thisLVFactors.get_vec(), [] (const auto& pc) { return const_piece( pc ); } ) );

    } else if (dsGlobalEmbeds.size() > thisLVFactors.size()) {

      retCandidateEmbeds = dim_own_cpiece_t( transform_vec( dsGlobalEmbeds.get_vec(), [] (const auto& pc) { return const_piece( pc ); } ) );

    } else {
      // ie : dsGlobalEmbeds.size() == thisLVFactors.size()

      // Make sure thisLVFactors fully contain ds embeddings
      // TRANSFORM THEM TO THEIR CORE DEFINITIONS. Ideally, upto the context that is first in the code, not the super_type:: context TODO

      this->verify_containing_relation( thisLVFactors, dsGlobalEmbeds.get_vec() );

      retCandidateEmbeds = dim_own_cpiece_t( transform_vec( dsGlobalEmbeds.get_vec(), [] (const auto& pc) { return const_piece( pc ); } ) );
    }

  } else {

      retCandidateEmbeds = dim_own_cpiece_t( transform_vec( thisLVFactors.get_vec(), [] (const auto& pc) { return const_piece( pc ); } ) );
  }

  // std::cout << "Returned candidate embeds of " << this->get_pc_string() << " ---start\n";
  // for (auto pc : retCandidateEmbeds) {
  //   std::cout << pc->get_pc_string() << '\n';
  // }
  // std::cout << "Returned candidate embeds ---end\n";

  return retCandidateEmbeds;
}


vec_own_cpiece_t mem_access<mem_ak::affine>::get_full_expression_unfold() const {

  auto nDims = this->get_this_dimensions();

  vec_own_cpiece_t adds;

  for (auto d = 0u; d < nDims; d++) {

    adds.emplace_back( simplify_piece( make_token< kind::factors >( m_loopVars.get_elem(d), m_loopVarsFactors.get_elem(d) ) ) );
  }

  std::transform( std::begin(m_offsets), std::end(m_offsets), std::back_inserter(adds), [] (const own_cpiece_t& ownOff) { return const_piece(ownOff); } );

  if (adds.empty()) {
    adds.emplace_back( make_num(0) );
  }

  return adds;
}


own_cpiece_t mem_access<mem_ak::affine>::get_full_expression() const {

  auto unfoldVec = this->get_full_expression_unfold();

  return fold_addends( transform_vec( unfoldVec, [] (const own_cpiece_t& own) { return own.get(); } ) );
}

// own_cpiece_t mem_access<mem_ak::affine>::get_factor_containing( cpiece_t inPc ) const {
// 
//   auto lvfs = this->get_loop_vars_factors();
// 
//   auto id = 0u;
//   for (auto lvf : lvfs) {
//     if (contains_piece( lvf, inPc )) {
//       return const_piece( lvf );
//     }
//   }
// 
//   return make_num(1);
// }


#ifndef PARSER_TEST

bool mem_access<mem_ak::affine>::is_on_call_within_loop() const {
  if (this->get_this_dimensions() > 0) {
    return super_type::is_on_call_within_loop();
  }
  return false;
}

#endif // PARSER_TEST

// void mem_access<mem_ak::affine>::discard_tail() {
//   if (this->get_this_dimensions() <= 1) {
//     throw std::logic_error("Cannot discard_tail in affine access when local dimensions not greater than 1 ");
//   }
// 
//   m_loopVars.erase( std::begin( m_loopVars ) + 1, std::end( m_loopVars ) );
//   m_loopVarsFactors.erase( std::begin( m_loopVarsFactors ) + 1, std::end( m_loopVarsFactors ) );
// }


////// Serial
#ifndef PARSER_TEST
std::string mem_access<mem_ak::affine>::serial() const {

  return make_serial<2>(
    {"loopVars:","loovVarFactors:"},
    this->get_loop_vars().get_vec(),
    this->get_loop_vars_factors().get_vec()
  );
}
#endif // PARSER_TEST

} // namespace bld::src::pc
