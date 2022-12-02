
#include "source/token/typedef.hpp"

#include "source/token/multiple/range.hpp"
#include "source/token/multiple/addends.hpp"

#include "source/token/combine/extend_arith.hpp"

#ifdef PARSER_TEST
  #include "source/token/make/copy.hpp"
#else
  #include "source/object/data/transform/interface.hpp"
#endif // PARSER_TEST


#include <numeric>
#include <iostream> // DBG XXX


namespace bld::src::pc {


///////////////
//
// INTERFACE
//
///////////////
own_ctoken_t<kind::range> extend_range_from_coord( cpiece_t localCoord, ctoken_t<kind::range> dsRange, piece_context targetCtxt ) {

  // Make new range, aggregating local coord with dsRange, NOT min/max aggregation, but PLUS aggregation
  // Also, both ranges are addable because they share the globalEmbed

  vec_cpiece_t minVec({localCoord, dsRange->get_limit<range_limit::min>()});
  vec_cpiece_t maxVec({localCoord, dsRange->get_limit<range_limit::max>()});

  // std::cout << "EXTENDING RANGE FROM COORD " << dsRange->get_pc_string() << '\n';

  return make_token< kind::range >(
      extend_arith<kind::addends>( minVec, targetCtxt ),
      extend_arith<kind::addends>( maxVec, targetCtxt )
    );
}


#ifdef PARSER_TEST
vec_own_piece_t align_contexts_uniform( vec_cpiece_t inVec ) {
  return edit_piece_vector(inVec);
}

own_piece_t transform_to_local_context( cpiece_t pc, piece_context targetCtxt ) {
  return edit_piece( pc );
}
#endif // PARSER_TEST


own_token_t<kind::range> extend_ranges_to_context( vec_ctoken_t<kind::range> inputVecRanges, piece_context targetCtxt ) {

  return std::accumulate(
      std::begin(inputVecRanges), std::end(inputVecRanges),
      own_token_t<kind::range>(),
      [targetCtxt] ( const own_token_t<kind::range>& cum, ctoken_t<kind::range> inRng ) {

        auto trfRange = static_unique_pointer_cast< token<kind::range> >( transform_to_local_context(inRng, targetCtxt) );

        if (cum.get() == nullptr) {
          // std::cout << "In range : " << inRange->get_pc_string() << ", cum is nullptr\n";
          return trfRange;
        } else {
          // Constructor will deal with the proper aggregation
          // std::cout << "In range : " << inRange->get_pc_string() << ", cum is " << cum->get_pc_string() << '\n';
          return make_token< kind::range >( cum.get(), trfRange.get() );
        }
      }
    );

}


// Needed ? TODO
own_token_t<kind::range> extend_ranges_uniform( vec_ctoken_t<kind::range> inputVecRanges ) {


  auto trfOwnVecRanges = align_contexts_uniform( transform_vec( inputVecRanges, [] (ctoken_t<kind::range> rng) { return static_cast<cpiece_t>(rng); } ) );


  using own_range_t = own_token_t<kind::range>;

  auto retRange = std::accumulate(
      std::begin(trfOwnVecRanges), std::end(trfOwnVecRanges),
      own_range_t(),
      [] ( const own_range_t& cum, const own_piece_t& ownPc ) {

        if (ownPc->get_kind() != kind::range) {
          throw std::logic_error("kind consistency broken in aggregate_ranges. Expected kind::range, got " + ownPc->get_kind_str());
        }

        auto inRange = static_cast<ctoken_t<kind::range>>( ownPc.get() );

        if (cum.get() == nullptr) {
          // std::cout << "In range : " << inRange->get_pc_string() << ", cum is nullptr\n";
          return make_token< kind::range >( *inRange );
        } else {
          // Constructor will deal with the proper aggregation
          // std::cout << "In range : " << inRange->get_pc_string() << ", cum is " << cum->get_pc_string() << '\n';
          return make_token< kind::range >( cum.get(), inRange );
        }
      }
    );

  // std::cout << "Aggregated range : " << retRange->get_pc_string() << '\n';
  return retRange;
}

} // namespace bld::src::pc
