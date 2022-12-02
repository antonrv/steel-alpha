#ifndef PARSER_REGION_AFFINE_ACCESS_HPP
#define PARSER_REGION_AFFINE_ACCESS_HPP

#include "source/token/typedef.hpp"


#include "source/token/region/access.hpp"
#include "source/token/region/guard.hpp"

#include "source/token/region/affine/dim/container.hpp"

#include "source/token/terminal/loopvar.hpp"

#include <vector>
#include <memory>

namespace bld::src::pc {

// class affine_guard;


// using loop_vars_t = dim_container<own_cloopvar_t>; // std::vector<std::unique_ptr<const loop_var>>;
// using loop_vars_factors_t = dim_own_cpiece_t; // vec_own_cpiece_t;
using transform_fn_t = std::function<own_piece_t(cpiece_t)>;


template <>
class mem_access<mem_ak::affine> : public access {

  using super_type = access;

public:
private:
  using offset_t = own_cpiece_t;
 
  dim_own_cloopvar_t m_loopVars;
  dim_own_cpiece_t m_loopVarsFactors;
  vec_own_cpiece_t m_offsets;

  
public:

  // Main constructor
  mem_access( cpiece_t inputPc, std::function<bool(cpiece_t)> lvLambda, cso_t<obj::data_use> dUse = nullptr );

  // To progressively build dim_info's  DEPRECATED
  // mem_access( cpiece_t inputPc, std::function<bool(cpiece_t)> lvLambda, const mem_access& other );

  // DEPRECATE
  // mem_access( const mem_access& other );

  // DEPRECATED mem_access( mem_access&& ) = default;

  mem_ak get_mem_access_kind() const final override;


  std::string get_info() const;

  // affine - specific

  unsigned get_dimensions() const;
  unsigned get_this_dimensions() const;

  bool has_offset() const;
  vec_cpiece_t get_offsets() const;
  own_cpiece_t get_offset() const;

  dim_cloopvar_t get_loop_vars() const;

  dim_cpiece_t get_loop_vars_factors() const;

private:
  
  static void verify_containing_relation( const dim_cpiece_t& lhsPieces, const dim_cpiece_t& rhsPieces );

public:

  dim_own_cpiece_t get_candidate_embeddings() const;


  own_cpiece_t get_match_coord( cpiece_t matchedAddend ) const;
  // own_cpiece_t get_factor_of_addend( cpiece_t matchedAddend ) const;
  // std::pair<own_cpiece_t, own_cpiece_t> get_factorized(cpiece_t matchedAddend) const;

  dim_own_cpiece_t get_dim_addends() const;

///// Used for affine_guard construction

  own_cpiece_t get_full_expression() const;
  vec_own_cpiece_t get_full_expression_unfold() const;

  // own_cpiece_t get_factor_containing( cpiece_t inPc ) const;
  // own_piece_t get_offset_containing( cpiece_t inPc ) const;


  // The argument that is passed during dep::affine_guard_region
  std::string get_wrap_argument_str() const;

#ifndef PARSER_TEST

  bool is_on_call_within_loop() const;

#endif // PARSER_TEST

  // void discard_tail(); DEPRECATED


#ifndef PARSER_TEST
  std::string serial() const final override;
#endif // PARSER_TEST
};


} // namespace bld::src::pc

#endif // PARSER_REGION_AFFINE_ACCESS_HPP
