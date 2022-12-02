
#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"
#include "source/token/transform/multiple.hpp"
#include "source/token/transform/loopvar.hpp"

#ifdef TRANSFORM_LOG
#include <iostream>
#endif // TRANSFORM_LOG

namespace bld::src::pc {


///////////////
//
// INTERFACE (substitution of old get_expr_range_limit)
//
///////////////
template <range_limit RL>
own_piece_t transform_range_limit(cpiece_t inputPc) {

#ifdef TRANSFORM_LOG
  std::cout << "\t\t----ENTRY:::::Transform RANGE_LIMIT : " << inputPc->get_pc_string() << " : " << inputPc->get_kind() << '\n';
#endif // TRANSFORM_LOG

  if (inputPc == nullptr) {
    throw std::logic_error("transform_range_limit received nullptr");
  }

  if (inputPc->is_terminal()) {

    if (inputPc->get_kind() == kind::var) {

      auto var = static_cast<ctoken_t<kind::var>>(inputPc);

      if (var->is_loop()) {

#ifdef TRANSFORM_LOG
        std::cout << "\t\t----RETURN:::::Transform RANGE_LIMIT : as loop var\n";
#endif // TRANSFORM_LOG

        // Don't be tempted to do this : make_piece_limit< RL >( static_cast<const loop_var*>( var ) );
        return make_piece_limit< RL> ( var->get_loop_variable() );

      } else {

#ifdef TRANSFORM_LOG
        std::cout << "\t\t----RETURN:::::Transform RANGE_LIMIT : as var\n";
#endif // TRANSFORM_LOG

        // A kind::var on non-loop var
        return edit_piece( inputPc );
      }

    } else if (inputPc->get_kind() == kind::num) {

      // A kind::num
      return edit_piece( inputPc );
    }

  } else if (inputPc->is_multiple()) {

    // std::cout << "\t\tChain\n";
    // return transform_piece_multiple( static_cast<const multiple*>(inputPc), std::bind(transform_range_limit< RL >, std::placeholders::_1) );
    return transform_piece_multiple( static_cast<const multiple*>(inputPc), &transform_range_limit< RL > );

  }

  throw std::logic_error("Unreachable in transform range limit");
}


///////////////
//
// INTERFACE
//
///////////////
own_token_t<kind::range> transform_to_range( cpiece_t inputPc ) {

#ifdef TRANSFORM_LOG
  std::cout << "\t\t----ENTRY:::::Transform TO_RANGE : " << inputPc->get_pc_string() << " : " << inputPc->get_kind() << '\n';
#endif // TRANSFORM_LOG

  if (inputPc->get_kind() == kind::range) {
    auto inputRange = static_cast<ctoken_t<kind::range>>( inputPc );

#ifdef TRANSFORM_LOG
    std::cout << "\t\t----RETURN:::::Transform TO_RANGE : as range\n";
#endif // TRANSFORM_LOG

    return make_token< kind::range >(
        transform_range_limit<range_limit::min>( inputRange->get_limit<range_limit::min>() ),
        transform_range_limit<range_limit::max>( inputRange->get_limit<range_limit::max>() )
      );
    
  } else {

#ifdef TRANSFORM_LOG
    std::cout << "\t\t----RETURN:::::Transform TO_RANGE : as other. Making range\n";
#endif // TRANSFORM_LOG

    bool hasLoopVar = (inputPc->find_piece_satisfying(
      [] (cpiece_t pc) {
        if (pc->get_kind() == kind::var) {
          return static_cast<ctoken_t<kind::var>>(pc)->is_loop();
        }
        return false;
      }) != nullptr);


    if (hasLoopVar) {

      return make_token< kind::range >(
          transform_range_limit<range_limit::min>(inputPc),
          transform_range_limit<range_limit::max>(inputPc)
        );
    } else {
      return static_unique_pointer_cast< token<kind::range> >( edit_piece( make_range_plus_one( inputPc ) ) ); // need to edit_piece bc make_range_plus_one returns const FIXME
    }
  }
}

} // namespace bld::src::pc
