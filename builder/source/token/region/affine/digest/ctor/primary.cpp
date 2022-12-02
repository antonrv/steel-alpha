
#include "source/token/region/affine/digest/access.hpp"

#include "source/token/region/affine/digest/functors.hpp"
#include "source/token/region/affine/dim/matching.hpp"

#include "source/token/region/affine/access.hpp"

#include "source/token/region/affine/to_string.hpp"

#include "options/state/log.hpp"

#include "common/util.hpp"


namespace bld::src::pc {

// Constructor for primaries
digest_access::digest_access( const dim_cpiece_t globalEmbeds, const affine_access* inputAff ) :
m_inputAffAccess(inputAff)
{

  // std::cout <<  "----BUILDING DIGEST ACCESS----(PRIMARY constructor) from " << inputAff->get_full_expression()->get_pc_string() << "\n";

  if (not are_proper_global(globalEmbeds)) {
    throw std::logic_error("Could not digest affine access : require proper global embeds in this constructor : " + embeddings_to_bracket_string( globalEmbeds.get_vec() ));
  }

  // Tolerate this if global embeds coming from ds guard TRYING TODO
  //if (inputAff->get_this_dimensions() != globalEmbeds.size()) {
  //  throw std::logic_error("Could not digest affine access : dimensions mismatch");
  //}


  m_globalEmbeddings = dim_own_cpiece_t( transform_vec( globalEmbeds.get_vec(), [] (cpiece_t ge) { return const_piece(ge); } ) );

  auto [matchedAddends, remainOffsets] = make_dim_matching( globalEmbeds, inputAff );

  // std::cout << "\tMatched addends : " << coordinates_to_bracket_string( matchedAddends.get_vec() ) << " from global embeds " << embeddings_to_bracket_string( globalEmbeds.get_vec() ) << '\n';
  // std::cout << "\tMatched remain : " << offsets_to_bracket_string( transform_vec(remainOffsets, [] (const auto& own) { return own.get(); } ) ) << '\n';

  if (not inputAff->has_offset()) {

    init_coord_no_offsets( matchedAddends.get_vec(), inputAff );

  } else {

    init_coord_offsets( matchedAddends.get_vec(), inputAff );
  }


  // std::cout << "\tCoordinates : " << coordinates_to_bracket_string( this->get_coordinates().get_vec() ) << '\n';

  auto nakedCoords = dim_own_cpiece_t( transform_vec( matchedAddends.get_vec(), [inputAff] (cpiece_t matchedAddend) { return inputAff->get_match_coord(matchedAddend); } ) );

  // std::cout << "\tNaked coordinates : " << coordinates_to_bracket_string( nakedCoords.get_vec() ) << '\n';


  m_localEmbeddings = dim_own_cpiece_t( compose_vecs( m_coordinates.get_vec(), nakedCoords.get_vec(), make_local_embedding() ) );

  // std::cout << "\tLocal embeddings : " << embeddings_to_bracket_string( this->get_local_embeddings().get_vec() ) << '\n';


  m_localOffsets = std::move(remainOffsets);

  this->init_downstream_offsets( inputAff ); 

  this->init_ranges( inputAff );

  state::log<opt_kind::log_digest_access>( "Primary ctor\n", this->get_info() );

  state::log<opt_kind::log_access>( "Associated input acc:\n", inputAff->get_info() );

}

} // namespace bld::src::pc
