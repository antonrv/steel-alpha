#ifndef MULTIPLE_LOOPOPS_DECL_HPP_HPP
#define MULTIPLE_LOOPOPS_DECL_HPP_HPP

#include "source/sequences.hpp"

#include "source/token/terminal/var.hpp"

#include <memory>

#ifndef PARSER_TEST
#include "source/object/typedef.hpp"
#endif // PARSER_TEST


namespace bld::src::pc {

own_cpiece_t make_undefined_lv_piece();

class loop_var : public token<kind::var> {
public:

  using ops_t = std::array<own_cpiece_t, 3>;
  using opkinds_t = std::array<opkind, 3>;

  using super_type = token<kind::var>;

private:

  ops_t m_operations;

  opkinds_t m_opkinds;


public:

  // Main constructor
  loop_var(ctoken_t<kind::var> var, own_cpiece_t startOp, opkind startOpk, own_cpiece_t boundOp, opkind boundOpk, own_cpiece_t sweepOp, opkind sweepOpk);

#ifdef PARSER_TEST
  // Testing purposes
  loop_var(const token<kind::var>& inVar);

#endif // PARSER_TEST

  // Normal copy constructor
  loop_var(const loop_var& other);


  bool all_defined() const;


  template <lv_trait LVTrait>
  cpiece_t get_expression() const {
    return m_operations[ static_cast<unsigned>(LVTrait) ].get();
  }

  template <lv_trait LVTrait>
  opkind get_opkind() const {
    return m_opkinds[ static_cast<unsigned>(LVTrait) ];
  }

  bool nested_in( const loop_var * lv ) const;

  bool is_loop() const final override;

  const loop_var * get_loop_variable() const final override;

  opkinds_t get_opkinds() const;

  std::string get_info() const;
};

} // namespace bld::src::pc

#endif // MULTIPLE_LOOPOPS_DECL_HPP_HPP
