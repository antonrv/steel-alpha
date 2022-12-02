#ifndef PARSER_REGION_STRING_HPP
#define PARSER_REGION_STRING_HPP

#include "source/token/typedef.hpp"

#include "common/util.hpp"

namespace bld::src::pc {


std::string embeddings_to_bracket_string(vec_cpiece_t vec);
// std::string embeddings_to_bracket_string(const vec_own_cpiece_t& embeds);

std::string coordinates_to_bracket_string(vec_cpiece_t vec);

std::string ranges_to_bracket_string(vec_ctoken_t<kind::range> vec);


std::string offsets_to_bracket_string(vec_cpiece_t vec);


template <typename InVecT, typename FunAdaptT, typename FunStringT>
static
std::string adapt_to_string( InVecT vec, FunAdaptT&& adaptPcFun, FunStringT&& finalFun ) {

  auto adaptPcVec = transform_vec( vec, adaptPcFun );

  auto adaptPcVecRaw = transform_vec( adaptPcVec, [] (const auto& ownPc) { return ownPc.get(); } );

  return finalFun( adaptPcVecRaw );

}

} // namespace bld::src::pc

#endif // PARSER_REGION_STRING_HPP
