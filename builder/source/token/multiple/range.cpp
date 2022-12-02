#include "source/token/multiple/range.hpp"

#include "source/token/multiple/cs_list.hpp"
#include "source/token/multiple/addends.hpp"
#include "source/token/multiple/call.hpp"
#include "source/token/terminal/var.hpp"
#include "source/token/terminal/num.hpp"

#include "source/token/make/piece.hpp"
#include "source/token/make/token.hpp"
#include "source/token/make/copy.hpp"

#include <numeric>
#include <iostream>

namespace bld::src::pc {

// vec_own_ctoken_t<kind::range> make_zero_point_ranges( unsigned n ) {
// 
//   vec_own_ctoken_t<kind::range> retVec;
// 
//   for (auto d = 0u; d < n; d++) {
//     retVec.push_back( make_token< kind::range >() );
//   }
// 
//   return retVec;
// }




///////////////// OFFSET  <--- MULTIPLE

token<kind::range>::token() :
binary( tokens_to_vector(make_num(0), make_num(0)) )
{}

token<kind::range>::token(own_piece_t&& min, own_piece_t&& max) :
binary(tokens_to_vector(std::move(min), std::move(max)))
{}

token<kind::range>::token(vec_own_piece_t&& f) :
binary(std::move(f))
{}

token<kind::range>::token(const token * rangeA, const token * rangeB) :
binary(tokens_to_vector(
  make_token< kind::cs_list >( rangeA->get_limit<range_limit::min>(), rangeB->get_limit<range_limit::min>() ),
  make_token< kind::cs_list >( rangeA->get_limit<range_limit::max>(), rangeB->get_limit<range_limit::max>() )
))
{ }



token<kind::range>::token(const token<kind::range>& other) :
binary(other)
{ }

kind token<kind::range>::get_kind() const { return kind::range; }

std::string token<kind::range>::get_pc_string() const {
  return "range[ Min" + this->get_limit<range_limit::min>()->get_pc_string() + "; Max" + this->get_limit<range_limit::max>()->get_pc_string() + " ]";
}

bool token<kind::range>::is_arith() const {
  return false;
}

std::string token<kind::range>::get_pair_string() const {

  auto minPc = this->get_limit<range_limit::min>();
  auto maxPc = this->get_limit<range_limit::max>();

  // Return an initializer list which is castable to rt::array_uint_t<2>
  return "{" +
    std::string(minPc->get_kind() == kind::cs_list ? "rt::min" : "" ) + minPc->get_pc_string() + ", " +
    std::string(maxPc->get_kind() == kind::cs_list ? "rt::max" : "" ) + maxPc->get_pc_string() + 
    "}";
}

template <range_limit RL>
own_piece_t token<kind::range>::get_printable() const {
  if (this->get_limit<RL>()->get_kind() == kind::cs_list) {
    // If it is a list of arguments, return a call 'rt::min(args) or rt::max(args)'
    return make_token< kind::call >(
      std::make_unique<synth_var>(std::string(util::enum_convert<range_limit>::to_string<RL>())),
      edit_piece( this->get_limit<RL>() )
    );
  } else {
    return edit_piece( this->get_limit<RL>() );
  }
}


template own_piece_t token<kind::range>::get_printable<range_limit::min>() const;
template own_piece_t token<kind::range>::get_printable<range_limit::max>() const;

template <range_limit RL>
cpiece_t token<kind::range>::get_limit() const {
  return binary::get_token<static_cast<unsigned>(RL)>();
}

template cpiece_t token<kind::range>::get_limit<range_limit::min>() const;
template cpiece_t token<kind::range>::get_limit<range_limit::max>() const;

own_piece_t
token<kind::range>::get_net_range() const {

  return make_substract( this->get_printable<range_limit::max>().get(), this->get_printable<range_limit::min>().get() );
}


} // namespace bld::src::pc
