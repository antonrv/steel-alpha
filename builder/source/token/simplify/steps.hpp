#ifndef COMMON_IT_SOURCE_PIECE_SIMPLIFY_STEPS_HPP
#define COMMON_IT_SOURCE_PIECE_SIMPLIFY_STEPS_HPP

#include "source/sequences.hpp"

#include "options/state/log.hpp"


ENUM_DEFINITION( bld, reduce_step,
  addends_numbers,
  addends_numbers_with_fractions,
  addends_inner,
  // addends_vars,
  // addends_factors,
  addends_num_factors,
  factors_numbers,
  factors_terminals_inner,
  factors_inner,
  factors_addends,
  factors_fractions,
  fraction_zero,
  // fraction_signs,
  fraction_unit_denominator,
  fraction_numbers,
  fraction_inner,
  fraction_numbers_in_factors,
  fraction_vars_in_factors,
  fraction_addends_single_den,
  fraction_raw_strings,
  range_numeric_args,
  range_equal_args,
  range_zero_args
)

namespace bld::src::pc {

static unsigned RecLevel = 0;
static unsigned RecLimit = 10;

template <kind MulKind>
struct simplify_traits;

template <reduce_step... RedSteps>
struct sequence {};

template <>
struct simplify_traits<kind::addends> {
  using steps = sequence<
      reduce_step::addends_numbers,
      reduce_step::addends_numbers_with_fractions,
      reduce_step::addends_inner,
      // reduce_step::addends_vars,
      // reduce_step::addends_factors,
      reduce_step::addends_num_factors
    >;
};

template <>
struct simplify_traits<kind::factors> {
  using steps = sequence<
      reduce_step::factors_numbers,
      reduce_step::factors_inner,
      reduce_step::factors_addends,
      reduce_step::factors_fractions
    >;
};

template <>
struct simplify_traits<kind::fraction> {
  using steps = sequence<
      reduce_step::fraction_zero,
      // reduce_step::fraction_signs,
      reduce_step::fraction_unit_denominator,
      reduce_step::fraction_numbers,
      reduce_step::fraction_inner,
      reduce_step::fraction_numbers_in_factors,
      reduce_step::fraction_vars_in_factors,
      reduce_step::fraction_addends_single_den,
      reduce_step::fraction_raw_strings
    >;
};

template <>
struct simplify_traits<kind::range> {
  using steps = sequence<
      reduce_step::range_numeric_args,
      reduce_step::range_equal_args,
      reduce_step::range_zero_args
    >;
};

void log_change(cpiece_t inputPc, cpiece_t outputPc, std::string opStep);

template <kind MulKind>
class simplify {

private:
  // Defined in .cpp
  template <reduce_step RedStep>
  static
  own_piece_t run_step( ctoken_t<MulKind> mulPc );

  // End case template
  static
  own_piece_t run_sequence( ctoken_t<MulKind> mulPc, sequence<> ) {
    return edit_piece( mulPc );
  }


  template <reduce_step RedStep, reduce_step... RedSteps>
  static
  own_piece_t run_sequence( ctoken_t<MulKind> mulPc, sequence<RedStep, RedSteps...> ) {
 
    auto result = run_step<RedStep>( mulPc );

    log_change(mulPc, result.get(), util::enum_convert<reduce_step>::to_string<RedStep>());
  
    if (result->get_kind() == MulKind) {
      result = run_sequence( static_cast<ctoken_t<MulKind>>( result.get() ), sequence<RedSteps...>{} );
    }
  
    return result;
  }

public:
  static
  own_piece_t
  on( ctoken_t<MulKind> mulPc ) {

    if (mulPc->get_pc_string() == "(b*(a*c*(b/d)))") {
      throw std::runtime_error("HEYYYY");
    }

    if (mulPc->get_tokens().empty()) {
      throw std::logic_error("Simplifying_on, Token with no elements");
    }

    RecLevel++;

    if (RecLevel > RecLimit) {
      throw std::runtime_error("Exceeded number of recursions while simplifying : " + mulPc->get_pc_string());
    }
  
    if (mulPc->get_token_count() == 1) {
      auto retPc = edit_piece( mulPc->get_tokens().front() );

      if (mulPc->get_sign() == sign::neg) { retPc->flip_sign(); }

      log_change(mulPc, retPc.get(), "Mul2Term");

      RecLevel--;
      return retPc;
    }

    using seq_t = typename simplify_traits<MulKind>::steps;

    auto retPc = edit_piece( mulPc );
    auto& tks = static_cast<multiple*>(retPc.get())->edit_own_tokens();


    for (auto& tk : tks) {
      tk = simplify_piece( tk.get() );
    }

    log_change(mulPc, retPc.get(), "InnerTokens");
  
    RecLevel--;

    return run_sequence( static_cast<ctoken_t<MulKind>>(retPc.get()), seq_t{} );
  }

  static
  own_piece_t
  on( own_ctoken_t<MulKind>&& pc ) {

    auto retPc = simplify::on( pc.get() );

    log_change(pc.get(), retPc.get(), "DirectOn");

    return retPc;
  }

};

} // namespace bld::src::pc

#endif // COMMON_IT_SOURCE_PIECE_SIMPLIFY_STEPS_HPP
