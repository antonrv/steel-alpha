
#include "source/token/make/copy.hpp"

#include "source/token/make/token.hpp"

#include <iostream>

namespace bld::src::pc {




///////////////
//
// INTERFACE
//
///////////////
own_piece_t edit_piece_core( cpiece_t inputPc ) {

  if (inputPc == nullptr) {
    throw std::logic_error("edit_piece received nullptr");
  }


  if (inputPc->get_kind() == kind::num) {

    return make_token< kind::num >( *static_cast<ctoken_t<kind::num>>(inputPc) );

  } else if (inputPc->get_kind() == kind::var) {

    auto var = static_cast<ctoken_t<kind::var>>(inputPc);

    if (var->is_loop()) {

      // return std::make_unique< loop_var >( *static_cast<const loop_var*>(var) );
      return std::make_unique< loop_var >( *var->get_loop_variable() );

    } else if (var->is_raw()) {

      return std::make_unique< raw_str >( *static_cast<const raw_str*>(var) );

    } else if (var->is_synth()) {

      return std::make_unique< synth_var >( *static_cast<const synth_var*>(var) );

    } else {

      return make_token< kind::var >( *static_cast<ctoken_t<kind::var>>(inputPc) );
    }

  } else if (inputPc->get_kind() == kind::addends) {

    return make_token< kind::addends >( *static_cast<ctoken_t<kind::addends>>(inputPc) );

  } else if (inputPc->get_kind() == kind::factors) {

    return make_token< kind::factors >( *static_cast<ctoken_t<kind::factors>>(inputPc) );

  } else if (inputPc->get_kind() == kind::cs_list) {

    return make_token< kind::cs_list >( *static_cast<ctoken_t<kind::cs_list>>(inputPc) );

  } else if (inputPc->get_kind() == kind::fraction) {

    return make_token< kind::fraction >( *static_cast<ctoken_t<kind::fraction>>(inputPc) );

  } else if (inputPc->get_kind() == kind::address) {

    return make_token< kind::address >( *static_cast<ctoken_t<kind::address>>(inputPc) );

  } else if (inputPc->get_kind() == kind::offset) {

    return make_token< kind::offset >( *static_cast<ctoken_t<kind::offset>>(inputPc) );

  } else if (inputPc->get_kind() == kind::range) {

    return make_token< kind::range >( *static_cast<ctoken_t<kind::range>>(inputPc) );

  } else if (inputPc->get_kind() == kind::call) {

    return make_token< kind::call >( *static_cast<ctoken_t<kind::call>>(inputPc) );

  } else if (inputPc->get_kind() == kind::binop) {

    return make_token< kind::binop >( *static_cast<ctoken_t<kind::binop>>(inputPc) );

  } else if (inputPc->get_kind() == kind::undefined) {

    return make_token< kind::undefined >( *static_cast<ctoken_t<kind::undefined>>(inputPc) );

  } else {
    throw std::logic_error("Unreachable in clone piece : " + std::string(util::enum_convert<kind>::to_string_rt(inputPc->get_kind())));
  }

}


///////////////
//
// INTERFACE
//
///////////////
own_cpiece_t const_piece_core( cpiece_t inputPc ) {
  return static_unique_pointer_cast< const piece >( edit_piece(inputPc) );
}


} // namespace bld::src::pc
