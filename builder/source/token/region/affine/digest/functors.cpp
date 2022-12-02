
#include "source/token/region/affine/digest/functors.hpp"

#include "source/token/region/affine/access.hpp"
#include "source/token/region/affine/guard.hpp"

#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#include "source/token/combine/interface.hpp"
#include "source/token/simplify/interface.hpp"

#include "source/token/transform/range.hpp"
#include "source/token/transform/loopvar.hpp"


namespace bld::src::pc {

////////////////// STUFF TO BUILD MAIN digest/access.cpp members

typename make_local_coord::result_type make_local_coord::operator() ( cpiece_t matchedAddend, cpiece_t globalEmbed/*, cpiece_t lvFactor*/ ) const {

  auto oneNum = make_num(1);

  return simplify_piece(
      make_token< kind::fraction >(
        matchedAddend, // Numerator
        globalEmbed // Denominator
      )
    );
};

typename make_local_coord_offset::result_type make_local_coord_offset::operator() ( cpiece_t matchedAddend, cpiece_t globalEmbed, cpiece_t lvFactor ) const {

  auto oneNum = make_num(1);

  if (are_equal(globalEmbed, oneNum.get()) and not are_equal(lvFactor, oneNum.get())) {

    return simplify_piece(
        make_token< kind::fraction >(
          matchedAddend, // Numerator
          lvFactor // Denominator
        )
      );

  } else {

    return simplify_piece(
        make_token< kind::fraction >(
          matchedAddend, // Numerator
          globalEmbed // Denominator
        )
      );
  }
};

typename make_local_coord_deduced::result_type make_local_coord_deduced::operator() ( cpiece_t matchedAddend, cpiece_t globalEmbed, cpiece_t lvFactor ) const {

  auto oneNum = make_num(1);

  if (are_equal(globalEmbed, oneNum.get()) and not are_equal(lvFactor, oneNum.get())) {

    return simplify_piece( matchedAddend );

  } else {

    return simplify_piece(
        make_token< kind::fraction >(
          matchedAddend, // Numerator
          globalEmbed // Denominator
        )
      );
  }

}


typename make_local_embedding::result_type make_local_embedding::operator() ( cpiece_t localCoord, cpiece_t nakedCoord ) const {

  auto zeroNum = make_num(0);

  own_cpiece_t tentative;

  if (are_equal( nakedCoord, zeroNum.get() )) {

    // return const_piece( localCoord );
    tentative = const_piece( localCoord );

  } else {

    tentative = simplify_piece( make_token< kind::fraction >( localCoord, nakedCoord ) );

  }

  // Local embedding must never be 0
  if (are_equal(tentative.get(), zeroNum.get())) {
    return make_num(1);
  } else {
    return tentative;
  }
}

// typename make_naked_coord::result_type make_naked_coord::operator() ( cpiece_t matchedCoord, cpiece_t globalEmbed, cpiece_t localEmbed ) const {
// 
//   return simplify_piece(
//       make_token< kind::fraction >(
//         matchedCoord, // Numerator
//         simplify_piece( make_token< kind::factors >( globalEmbed, localEmbed ) ) // Denominator
//       )
//     );
// }




make_mem_range::make_mem_range(const affine_access * aff) : inputAff(aff) {}



typename make_mem_range::result_type make_mem_range::operator() (cpiece_t localCoord, cpiece_t callGlobalEmbed ) const {

  auto dsGuardBase = inputAff->get_downstream_guard();

  if (dsGuardBase != nullptr and dsGuardBase->get_mem_guard_kind() == mem_ak::affine) {

    auto dsGuard = static_cast<const mem_guard<mem_ak::affine>*>(dsGuardBase);

    auto callTargetCtxtToExtend = inputAff->get_local_context();

    if (dsGuard->get_dimensions() >= inputAff->get_dimensions()) {

      // An access within a downstream function

#ifdef REGION_LOG
      std::cout << "Deducing local range from affine " << inputAff->get_info() << " and DS affine_guard : " << dsGuard->get_info() << '\n';
#endif // REGION_LOG


      // Locate the proper range in the proper dimension in the range of the downstream affine_guard. using localCoord

      auto dsRangeInThisDim = dsGuard->get_range_matching_global_embed( callGlobalEmbed );

      // We extend range to a call target
      return static_unique_pointer_cast< const token<kind::range> >( extend_range_from_coord( localCoord, dsRangeInThisDim, callTargetCtxtToExtend ) );

    } else { // (dsGuard->get_dimensions() < inputAffff->get_dimensions())

#ifdef REGION_LOG
      std::cout << "Deducing local range from affine " << inputAff->get_info() << " and DS affine_guard : " << dsGuard->get_info() << '\n';
#endif // REGION_LOG

       own_ctoken_t<kind::range> plusRange = nullptr;

       if ( dsGuard->has_range_matching_global_embed( callGlobalEmbed ) ) {

         // This dimension extended with a downstream range

         auto dsRangeInThisDim = dsGuard->get_range_matching_global_embed( callGlobalEmbed );

         plusRange = extend_range_from_coord( localCoord,  dsRangeInThisDim, callTargetCtxtToExtend );

       } else {
         // This dimension not extended with any downstream range
         plusRange = make_range_plus_one( localCoord );
       }

       return plusRange;
     }

   } else if (inputAff->is_task_ref_argument()) {

     return make_range_plus_one( localCoord );

   } else {

     return transform_to_range( localCoord );

   }
 }


make_call_range::make_call_range(const affine_access * aff) : inputAff(aff) {}

typename make_call_range::result_type make_call_range::operator() ( cpiece_t localCoord, cpiece_t localEmbed ) const {

  if (inputAff->get_downstream_guard() == nullptr and (not inputAff->is_task_ref_argument())) {
    // No call range for guards inside pure kernels
    return make_range_plus_one( make_num(0).get() );
  }

  // Then has a DS guard

  // Has LV ? -> get loop count
    // localCoord->find_piece_satisfying(
    //   [] (cpiece_t pc) {
    //     if (pc->get_kind() == kind::var) { return static_cast<ctoken_t<kind::var>>(pc)->is_loop(); }
    //     return false;
    //   });

  // 'nakedCoord' a coord without the localEmbed. May be a loop variable
  if (localEmbed->get_pc_string() == "0") { // TMP XXX
    throw std::logic_error("Could not deduce_call_iteration_range . Local embed is zero");
  }

  

  // if (nakedCoord->get_kind() == kind::var) {
  if ( contains_piece(localCoord, localEmbed) ) {

    auto nakedCoord = simplify_piece( make_token< kind::fraction >( localCoord, localEmbed ) );

    if ( nakedCoord->get_kind() == kind::var and static_cast<ctoken_t<kind::var>>(nakedCoord.get())->is_loop() ){

      auto lvPc = static_cast<ctoken_t<kind::var>>(nakedCoord.get())->get_loop_variable();

      return make_token< kind::range >(
          make_piece_limit< range_limit::min >( lvPc ),
          make_piece_limit< range_limit::max >( lvPc )
        );

    } else {

      return make_range_plus_one( nakedCoord.get() );
    }
  }
  
  // std::cout << "Naked coord " << nakedCoord->get_pc_string() << '\n';
  // // Not a loop var. just 1 call.. TODO
  return make_range_plus_one( make_num(0).get() );
      // // Min:
      // edit_piece( nakedCoord ),
      // // Max:
      // edit_piece( nakedCoord )
}


#ifndef PARSER_TEST

////////////////// STUFF TO EVALUATE NON-OVERLAPPING CONDITION

typename make_call_start::result_type make_call_start::operator()( ctoken_t<kind::range> memRange, cpiece_t coord ) const {
  return make_substract( memRange->get_limit<range_limit::min>(), coord );
}

typename make_coord_start::result_type make_coord_start::operator()( cpiece_t localEmbed, cpiece_t callStart ) const {
  return make_token< kind::addends >( localEmbed, callStart );
}

typename make_eval_binop::result_type make_eval_binop::operator()( ctoken_t<kind::range> memRange, cpiece_t coordStart ) const {
  return make_token< kind::binop >(
      memRange->get_net_range(), // the range of an iteration
      coordStart, // the start of an iteration
      opkind::leq
    );
}

#endif // PARSER_TEST

} // namespace bld::src::pc
