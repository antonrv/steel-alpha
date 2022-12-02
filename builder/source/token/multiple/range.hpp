#ifndef MULTIPLE_RANGE_DECL_HPP_HPP
#define MULTIPLE_RANGE_DECL_HPP_HPP

#include "source/token/multiple/multiple.hpp"


namespace bld::src::pc {

// using owned_range_t = own_token_t<kind::range>;
// 
// using owned_ranges_t = std::vector<owned_range_t>;

// owned_ranges_t make_zero_point_ranges(unsigned n);



template <>
class token<kind::range> : public binary {

public:

  token();

  token(own_piece_t&& pcMin, own_piece_t&& pcMax);

  token(vec_own_piece_t&& f);

  token(const token& other);

  token(const token * rangeA, const token * rangeB);

  virtual kind get_kind() const final override;

  bool is_arith() const final override;

  std::string get_pc_string() const final override;

  template <range_limit RL>
  cpiece_t get_limit() const;


  own_piece_t get_net_range() const;

  template <range_limit RL>
  own_piece_t get_printable() const;


  std::string get_pair_string() const;
};

} // namespace bld::src::pc

#endif // MULTIPLE_RANGE_DECL_HPP_HPP

