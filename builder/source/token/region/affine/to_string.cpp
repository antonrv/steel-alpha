
#include "source/token/region/affine/to_string.hpp"

#include "source/token/region/affine/dim/container.hpp"
#include "source/token/make/token.hpp"
#include "source/token/simplify/interface.hpp"
#include "source/token/multiple/range.hpp"

#include "source/token/combine/interface.hpp"

namespace bld::src::pc {


std::string embeddings_to_bracket_string(vec_cpiece_t embeds) {

  std::string retStr;

  retStr += "{/*embeds*/";
  for (auto pc : embeds) {
    retStr += pc->get_pc_string() + ",";
  }
  retStr.pop_back(); // pop last comma

  retStr += "}";

  return retStr;
}

// std::string embeddings_to_bracket_string(const vec_own_cpiece_t& embeds) {
//   return embeddings_to_bracket_string( transform_vec(embeds, [] (const own_cpiece_t& own) { return own.get(); } ) );
// }


std::string ranges_to_bracket_string(vec_ctoken_t<kind::range> rngs) {

  std::string retStr;

  // Global ranges
  retStr += "{/*ranges*/";
  for (auto& rng : rngs) {
    // We need the two range numbers. Even though 'min' is usually equal to coord, it is not in general.
    retStr += "range_t(" + rng->get_pair_string() + "),";  
    // auto subs = make_substract( rng->get_limit<range_limit::max>(), rng->get_limit<range_limit::min>() );
    // retStr += simplify_piece( subs )->get_pc_string() + ",";
  }
  retStr.pop_back(); // pop last comma

  retStr += "}";

  return retStr;
}

std::string coordinates_to_bracket_string(vec_cpiece_t vec) {

  std::string retStr;

  if (vec.empty()) {
    return "()";
  }

  retStr += "{/*coord*/";
  for (auto& coord : vec) {
    retStr += coord->get_pc_string() + ",";
  }
  retStr.pop_back(); // pop last comma

  retStr += "}";

  return retStr;
}


std::string offsets_to_bracket_string(vec_cpiece_t vec) {

  std::string retStr;

  if (vec.empty()) {
    return "";
  }

  if (vec.size() == 1 and are_equal( vec.front(), make_num(0).get()) ) {

    return retStr;

  } else if (vec.size() == 1) {

    retStr += ", /*lc-off*/" + vec.front()->get_pc_string();

    return retStr;

  } else {
    // More ds offsets, dump them
    vec.erase( std::begin(vec) );
  }

  
  retStr += ", {/*ds-offs*/";
  for (auto& off : vec) {
    retStr += off->get_pc_string() + ",";
  }
  retStr.pop_back(); // pop last comma

  retStr += "}";

  return retStr;
}

} // namespace bld::src::pc
