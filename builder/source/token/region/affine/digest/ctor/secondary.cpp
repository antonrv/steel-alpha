
#include "source/token/region/affine/digest/access.hpp"

#include "source/token/region/affine/digest/functors.hpp"
#include "source/token/region/affine/dim/matching.hpp"

#include "source/token/region/affine/access.hpp"

#include "options/state/log.hpp"

#include "common/util.hpp"


namespace bld::src::pc {

digest_access::digest_access( const dim_cpiece_t globalEmbeds, const dim_cpiece_t localEmbeds, const affine_access* inputAff ) :
m_inputAffAccess(inputAff)
{

  // std::cout <<  "----BUILDING DIGEST ACCESS----(SECONDARY constructor) from " << inputAff->get_full_expression()->get_pc_string() << "\n";


  if (not are_proper_global(globalEmbeds)) {
    throw std::logic_error("Could not digest affine access : require proper global embeds in this constructor");
  }


  // m_globalEmbeddings = dim_own_cpiece_t( transform_vec( globalEmbeds.get_vec(), [] (cpiece_t ge) { return const_piece(ge); } ) );
  m_globalEmbeddings = dim_own_cpiece_t( const_piece_vector(globalEmbeds.get_vec() ) );

  m_localEmbeddings = dim_own_cpiece_t( const_piece_vector(localEmbeds.get_vec()) );// dim_own_cpiece_t( compose_vecs( m_coordinates.get_vec(), nakedCoords.get_vec(), make_local_embedding() ) );

  auto [matchedAddends, remainOffsets] = make_dim_matching( globalEmbeds, localEmbeds, inputAff );

  // std::cout << "\tMatched : " << coordinates_to_bracket_string( matchedAddends.get_vec() ) << '\n';

  // init_coord_from_input_local_embeds( matchedAddends.get_vec(), localEmbeds, inputAff );

  m_coordinates = dim_own_cpiece_t( compose_tri( matchedAddends.get_vec(), m_globalEmbeddings.get_vec(), m_localEmbeddings.get_vec(), make_local_coord_deduced() ) );

  // std::cout << "\tCoordinates : " << coordinates_to_bracket_string( this->get_coordinates().get_vec() ) << '\n';

  // auto nakedCoords = dim_own_cpiece_t( transform_vec( matchedAddends.get_vec(), [inputAff] (cpiece_t matchedAddend) { return inputAff->get_match_coord(matchedAddend); } ) );
  // auto nakedCoords = dim_own_cpiece_t( compose_tri(matchedAddends.get_vec(), m_globalEmbeddings.get_vec(), localEmbeds.get_vec(), make_naked_coord() ) );

  // std::cout << "\tNaked coordinates : " << coordinates_to_bracket_string( nakedCoords.get_vec() ) << '\n';



  // std::cout << "\tLocal embeddings : " << embeddings_to_bracket_string( this->get_local_embeddings().get_vec() ) << '\n';


  m_localOffsets = std::move(remainOffsets);

  this->init_downstream_offsets( inputAff ); 

  this->init_ranges( inputAff );


  state::log<opt_kind::log_digest_access>( "Secondary ctor\n", this->get_info() );

  state::log<opt_kind::log_access>( "Associated input acc:\n", inputAff->get_info() );

}

} // namespace bld::src::pc
