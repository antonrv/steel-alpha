
#include "source/token/region/affine/digest/access.hpp"

#include "source/token/region/affine/digest/functors.hpp"

#include "source/token/region/affine/dim/matching.hpp"


#include "source/token/region/affine/access.hpp"
#include "source/token/region/affine/guard.hpp"

#include "source/token/factorize.hpp"
#include "source/token/simplify/interface.hpp"


#include "source/token/combine/interface.hpp"

#include "source/token/transform/range.hpp"

#include "common/util.hpp"

#include <vector>
#include <algorithm>
#include <memory>

#include "source/token/region/affine/to_string.hpp"

#ifndef PARSER_TEST
  #include "source/object/data/use.hpp"
  #include "source/object/data/transform/interface.hpp" // transform_to_local_context
#endif // PARSER_TEST

#ifdef REGION_LOG
#include <iostream> // DBG XXX
#endif // REGION_LOG


#include <iostream> // DBG XXX


namespace bld::src::pc {


bool are_proper_global( const dim_cpiece_t globalEmbeds ) {

  // Return true if non-zero elements are unique and nested. {a, b, c ...} are nested <=> c in b in a.

  if (globalEmbeds.empty()) {
    return false;
  }

  auto gePcs = globalEmbeds.get_vec();

  auto adjFoundIt = std::adjacent_find(std::begin(gePcs), std::end(gePcs), are_equal );

  if (adjFoundIt != std::end(gePcs)) {
    return false;
  } else {
    // Elements are unique (a != b != c != d)
  }

  // Elements hold a nesting relation {a, b, c ...} are nested <=> c in b in a. => return true
  return std::is_sorted( std::begin(gePcs), std::end(gePcs), contains_piece );
}


#ifdef PARSER_TEST
static
own_piece_t transform_to_local_context( cpiece_t pc, csob_t srcElem ) {
  return edit_piece( pc );
}
#endif // PARSER_TEST


void digest_access::init_downstream_offsets( const affine_access * aff ) {

  auto dsGuard = aff->get_downstream_guard();

  if (dsGuard != nullptr and dsGuard->get_mem_guard_kind() == mem_ak::affine) {

#ifdef REGION_LOG
    std::cout << "----Adding downstream offsets\n";
#endif // REGION_LOG

    // An access within a downstream function
    auto dsOffsets = static_cast<const mem_guard<mem_ak::affine>*>(dsGuard)->get_all_offsets();

    auto locOffsetFold = fold_caddends( this->get_local_offsets() );

    for (auto dsOffPc : dsOffsets) {

      auto adds = simplify_piece( extend_arith< kind::addends >( locOffsetFold.get(), dsOffPc, aff->get_local_context() ) );
#ifdef REGION_LOG
    std::cout << "----DS offset : " << dsOffPc->get_pc_string() << '\n';
#endif // REGION_LOG
      m_downstreamOffsets.push_back( std::move(adds) );
    }
  }

  // std::cout << "make_call_offsets : " << locOffset->get_pc_string() << " : " << locOffset->get_kind() << '\n';
}


void digest_access::init_ranges( const affine_access * inputAff) {

  m_memRanges = dim_own_ctoken_t<kind::range>( compose_vecs( m_coordinates.get_vec(), m_globalEmbeddings.get_vec(), make_mem_range(inputAff) ) );

  m_callRanges = dim_own_ctoken_t<kind::range>( compose_vecs( m_coordinates.get_vec(), m_localEmbeddings.get_vec(), make_call_range(inputAff) ) );
}



void digest_access::init_coord_no_offsets( dim_cpiece_t matchedAddends, const affine_access* inputAff ) {


  m_coordinates = dim_own_cpiece_t( compose_vecs( matchedAddends.get_vec(), m_globalEmbeddings.get_vec(), make_local_coord() ) );

}


void digest_access::init_coord_offsets( dim_cpiece_t matchedAddends, const affine_access* inputAff ) {


  auto lvFactors = inputAff->get_loop_vars_factors();

  if (lvFactors.empty()) {

    m_coordinates = dim_own_cpiece_t( compose_vecs( matchedAddends.get_vec(), m_globalEmbeddings.get_vec(), make_local_coord() ) );
    
  } else {
    m_coordinates = dim_own_cpiece_t( compose_tri( matchedAddends.get_vec(), m_globalEmbeddings.get_vec(), lvFactors.get_vec(), make_local_coord_offset() ) );
  }

}

// void digest_access::init_coord_from_input_local_embeds( dim_cpiece_t matchedAddends, dim_cpiece_t inputLocalEmbeds, const affine_access* inputAff ) {
// 
//   m_coordinates = dim_own_cpiece_t( compose_tri( matchedAddends.get_vec(), m_globalEmbeddings.get_vec(), inputLocalEmbeds.get_vec(), make_local_coord_offset() ) );
// 
// }





 
dim_cpiece_t digest_access::get_global_embeddings() const {
  return dim_cpiece_t( m_globalEmbeddings.get_vec() );
}

dim_cpiece_t digest_access::get_local_embeddings() const {
  return dim_cpiece_t( m_localEmbeddings.get_vec() );
}

dim_cpiece_t digest_access::get_coordinates() const {
  return dim_cpiece_t( m_coordinates.get_vec() );
}

dim_ctoken_t<kind::range> digest_access::get_mem_ranges() const {
  return dim_ctoken_t<kind::range>( m_memRanges.get_vec() );
}

dim_ctoken_t<kind::range> digest_access::get_call_ranges() const {
  return dim_ctoken_t<kind::range>( m_callRanges.get_vec() );
}

vec_cpiece_t digest_access::get_local_offsets() const {
  return transform_vec( m_localOffsets, [] (const own_cpiece_t& own) { return own.get(); } );
}

bool digest_access::has_downstream_offsets() const {
  return (not m_downstreamOffsets.empty());
}

vec_cpiece_t digest_access::get_aggregated_offsets() const {
  auto retVec = transform_vec( m_downstreamOffsets, [] (const auto& pc) { return pc.get(); } );
  if (retVec.empty()) {
    retVec = this->get_local_offsets();
  } else {
    // m_localOffset has already been aggregated into m_downstreamOffsets
  }
  return retVec;
}


bool digest_access::is_built_from( const affine_access * inAff ) const {
#ifdef PARSER_TEST
  return m_inputAffAccess == inAff; // ptr equality
#else
  return m_inputAffAccess->get_root_data_use()->get_identifier() == inAff->get_root_data_use()->get_identifier();
#endif
}


std::string digest_access::get_info() const {

  std::string retStr = "---digest_access info START V";

  retStr += "\n\tGlobal Embeddings : ";
  retStr += embeddings_to_bracket_string( this->get_global_embeddings().get_vec() );

  retStr += "\n\tLocal Embeddings : ";
  retStr += embeddings_to_bracket_string( this->get_local_embeddings().get_vec() );

  retStr += "\n\tCoordinates : ";
  retStr += coordinates_to_bracket_string( this->get_coordinates().get_vec() );

  retStr += "\n\tMem Ranges : "; 
  retStr += ranges_to_bracket_string( this->get_mem_ranges().get_vec() );

  retStr += "\n\tCall Ranges : "; 
  retStr += ranges_to_bracket_string( this->get_call_ranges().get_vec() );

  // if (this->has_offset()) {
  retStr += "\n\tLocal offsets: " + offsets_to_bracket_string( this->get_local_offsets() );
  // } else {
  //  retStr += "\n\tNo local\n";
  // }

  retStr += "\n\tAggregated offsets : " + offsets_to_bracket_string( this->get_aggregated_offsets() );

  auto dsGuard = m_inputAffAccess->get_downstream_guard();
  retStr += "\n\tHas DS guard : " + std::string(dsGuard != nullptr ? "true" : "false") + "\n";

#ifndef PARSER_TEST
  retStr += "\n\tIs on_loop_mesh : " + std::string(this->is_on_loop_mesh() ? "true" : "false");
  if (this->is_on_loop_mesh()) {
    retStr += "\n\tAre blocks internally disjoint : " + std::string(this->are_blocks_internally_disjoint() ? "true" : "false");
  }
#endif // PARSER_TEST


  retStr += "\n---digest_access info END. \n";


  return retStr;
}


std::string digest_access::get_local_embeddings_string( piece_context srcCtxt ) const {

  std::string retStr;

  auto t2cFn = std::bind( transform_to_local_context, std::placeholders::_1, srcCtxt );

  // std::cout << "LOC EMBEDS COUNT : " << this->get_local_embeddings().size() << '\n';

  auto transfEmbeddings = dim_own_cpiece_t(
      transform_vec(
        this->get_local_embeddings().get_vec(),
        [t2cFn] (cpiece_t pc) {
          return static_unique_pointer_cast< const piece >( simplify_piece( t2cFn(pc) ) );
        }
      )
    );

  return embeddings_to_bracket_string( transfEmbeddings.get_vec() ); 
}

////////////////// STUFF TO EVALUATE NON-OVERLAPPING CONDITION

#ifndef PARSER_TEST
unsigned digest_access::get_dimensions() const {
  return m_localEmbeddings.size();
}


bool digest_access::are_blocks_disjoint_detail(dim_cpiece_t locEmbeds) const {

  // std::cout << "TRYING TO GUESS WHETHER THIS DIGEST_ACCESS " << this << " IS DISJOINT WRT LOC EMBEDS : ";
  // for (auto le : locEmbeds) { std::cout << '\t' << le->get_pc_string() << '\n'; }

  auto callStarts = dim_own_cpiece_t( compose_vecs( m_memRanges.get_vec(), m_coordinates.get_vec(), make_call_start() ) );

  auto coordStarts = dim_own_cpiece_t( compose_vecs( locEmbeds.get_vec(), callStarts.get_vec(), make_coord_start() ) );

  auto evalBinOpsOwn = dim_own_ctoken_t<kind::binop>( compose_vecs( m_memRanges.get_vec(), coordStarts.get_vec(), make_eval_binop() ) );

  auto evalBinOps = evalBinOpsOwn.get_vec();

  // All coordinates have satisfied the non-overlap conditions
  return std::all_of(std::begin(evalBinOps), std::end(evalBinOps),
      [] (ctoken_t<kind::binop> binOp) {
        auto resEval = binOp->evaluate();
        if (resEval == res::tru) { return true; }
        else { return false; }
      }
    );

  // for (auto d = 0u; d < this->get_dimensions(); d++) {

  //   // --- If we have call( ptr[i*factor], start, span ) and range is (i*factor + start, i*factor + start + span)
  //   // Then we want to evaluate if net range : i*factor + start + span - (i*factor + start) = 'span', is '<=' than 'factor + start'
  //   // --- In most scenarios, we have 'call( ptr[i*factor], bSize )' and range 'i*factor, i*factor + bSize)'
  //   // The we evaluate if net range : 'i*factor + bSize - (i*factor) = 'bSize' is '<=' than 'factor + 0'.
  //   // If factor is precisely 'bSize', then it is true.

  //   // If result of evaluate returns res::fal or res::unk, then we cannot statically determine whether the blocks in this dim overlap
  //   // std::cout << "THIS COORD : " << this->get_coordinate(d)->get_pc_string() << '\n';
  //   auto coordOffset = make_substract( this->get_mem_range(d)->get_limit<range_limit::min>(), this->get_coordinate(d) );
  //   // std::cout << "COORD OFFSET : " << coordOffset->get_pc_string() << '\n';

  //   auto evalOpLEQ = make_token< kind::binop >(
  //       this->get_mem_range(d)->get_net_range(),
  //       make_token< kind::addends >( locEmbeds.at(d), coordOffset.get() ),
  //       opkind::leq
  //     );

  //   // std::cout << "BLOCKS DISJOINT IN DIM : " << d << " ? " << "\n\tLHS : " << evalOpLEQ->get_lhs()->get_pc_string();
  //   // std::cout << "\n\tRHS : " << evalOpLEQ->get_rhs()->get_pc_string();
  //   // std::cout << "\n\tOP " << opkind::leq;
  //   // std::cout << "\n\t" << evalOpLEQ->evaluate() << '\n';

  //   auto resEval = evalOpLEQ->evaluate();
  //   if (resEval != res::tru) {
  //     return false;
  //   }
  // }

  // // All coordinates have satisfied the non-overlap conditions
  // return true;
}


bool digest_access::are_blocks_internally_disjoint() const {
  if (not this->is_on_loop_mesh()) {
    throw std::logic_error("are_blocks_internally_disjoint are not supposed to be called for a primary digest_access");
  }
  return this->are_blocks_disjoint_detail( this->get_local_embeddings() );
}


bool digest_access::are_blocks_disjoint_under(dim_cpiece_t externLocEmbeds) const {
  // Check valid for uneven 1d cases, but not for uneven 2d
  // if (this->is_on_loop_mesh()) {
  //   throw std::logic_error("are_blocks_disjoint_under are not supposed to be called for a not-main digest_access");
  // }
  return are_blocks_disjoint_detail( externLocEmbeds );
}

bool digest_access::is_on_loop_mesh() const {
  return m_inputAffAccess->is_on_call_within_loop();
}


own_ctoken_t<kind::range> digest_access::get_induced_call_range(unsigned d, cpiece_t locEmbed) const {

  own_cpiece_t nakedCoord;
  
  auto coordInThisDim = m_coordinates.get_elem(d);

  if (contains_piece(coordInThisDim, locEmbed)) {

    // Here we are sure that locEmbed is contained within coordInThisDim. Then we get the naked coord ...
    nakedCoord = simplify_piece( make_token< kind::fraction >( coordInThisDim, locEmbed ) );

  } else if (are_equal(m_localEmbeddings.get_elem(d), locEmbed)) {

    nakedCoord = const_piece( coordInThisDim );

  } else {

    throw std::logic_error("Could not get_induced_call_range in dimension " + std::to_string(d) + " from induced piece " + locEmbed->get_pc_string() + " for digest_access. Coordinate in this dim " + coordInThisDim->get_pc_string() + " does not contain induced piece and local embed in this dim is not equal to induced piece\n" + this->get_info());
  }

  // std::cout << "RETURN INDUCED CALL RANGE : " << nakedCoord->get_pc_string() << '\n';

  // .. from which the induced 1-element range is deduced.
  return static_unique_pointer_cast< token<kind::range> >( simplify_piece( transform_to_range( nakedCoord.get() ) ) );
  // return make_range_plus_one( nakedCoord.get() );
}

  
#endif // PARSER_TEST


} // namespace bld::src::pc
