
#include "source/token/region/affine/digest/access.hpp"

#include "source/token/region/affine/digest/functors.hpp"

#include "source/token/region/affine/access.hpp"


#include "options/state/log.hpp"

#include "common/util.hpp"

namespace bld::src::pc {

digest_access::digest_access( const affine_access * inputAff ) :
m_inputAffAccess(inputAff)
{

  // std::cout <<  "----BUILDING DIGEST ACCESS----(BASIC constructor) from " << inputAff->get_full_expression()->get_pc_string() << "\n";

  if (inputAff->get_this_dimensions() == 0) {

    // Do nothing

  } else {

    // several dims but global embeds not given
  
    m_localEmbeddings = const_piece_vector( inputAff->get_loop_vars_factors() );

    m_coordinates = const_piece_vector( inputAff->get_loop_vars() );

    m_globalEmbeddings = dim_own_cpiece_t(inputAff->get_this_dimensions());

    for (auto d = 0u; d < inputAff->get_this_dimensions(); d++) {
      m_globalEmbeddings.edit_elem(d) = make_num(1);
    }

  }


  m_localOffsets = const_piece_vector( inputAff->get_offsets() );

  this->init_downstream_offsets( inputAff );

  this->init_ranges( inputAff );

  state::log<opt_kind::log_digest_access>( "Basic ctor\n", this->get_info() );

  state::log<opt_kind::log_access>( "Associated input acc:\n", inputAff->get_info() );
}

} // namespace bld::src::pc
