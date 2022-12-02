
#include "source/object/data/transform/interface.hpp"

#include "source/object/data/use.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/function/definition.hpp"
#include "source/object/function/call.hpp"

#include "source/token/make/copy.hpp"
#include "source/token/transform/multiple.hpp"

#include "source/object/state/def.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <functional>


namespace bld::src {



static
bool is_resolved_in_call(pc::cpiece_t inputPc, cso_t<obj::fun_call> fCall) {

  if (inputPc->is_terminal()) {
    auto term = static_cast<pc::cterminal_t>(inputPc);

    if (term->get_kind() == pc::kind::var) {

      auto var = static_cast<pc::ctoken_t<pc::kind::var>>(inputPc);

      if (var->is_loop()) {

        auto lv = var->get_loop_variable(); // static_cast<const pc::loop_var*>( var );

        return
          is_resolved_in_call( lv->get_expression<pc::lv_trait::start>(), fCall ) and
          is_resolved_in_call( lv->get_expression<pc::lv_trait::bound>(), fCall ) and
          is_resolved_in_call( lv->get_expression<pc::lv_trait::sweep>(), fCall );

      } else {
        return fCall->contains( var->get_data_use() );
      }

    } else if (term->get_kind() == pc::kind::num) {
      return true;
    } else {
      throw std::logic_error("Unreachable in is_resolved_in_call");
    }

  } else {

    auto terminalVec = static_cast<const pc::multiple *>(inputPc)->get_flatten_terminals();

    return std::all_of(std::begin(terminalVec), std::end(terminalVec), std::bind(is_resolved_in_call, std::placeholders::_1, fCall) );
  }
}

///////////////
//
// INTERFACE
//
///////////////
pc::own_piece_t transform_from_callee_to_call(pc::cpiece_t inputPc, cso_t<obj::fun_call> fCallInCaller) {

  if (is_resolved_in_call(inputPc, fCallInCaller)) {
    return edit_piece( inputPc );
  }

#ifdef TRANSFORM_LOG
  std::cout << "\t\t----ENTRY:::::Transform Calle2Call : " << inputPc->get_pc_string() << '\n';
#endif // TRANSFORM_LOG

  if (inputPc->is_terminal() and inputPc->get_kind() == pc::kind::var) {

    auto var = static_cast<pc::ctoken_t<pc::kind::var>>(inputPc);
    auto dUseCallee = var->get_data_use();

    if (var->is_loop()) {

      auto lv = var->get_loop_variable(); // static_cast<const pc::loop_var*>( var );

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::Transform Calle2Call : as pc::loop_var\n";
#endif // TRANSFORM_LOG

      return std::make_unique< pc::loop_var >( var,
          transform_from_callee_to_call( lv->get_expression<pc::lv_trait::start>(), fCallInCaller ), lv->get_opkind<pc::lv_trait::start>(),
          transform_from_callee_to_call( lv->get_expression<pc::lv_trait::bound>(), fCallInCaller ), lv->get_opkind<pc::lv_trait::bound>(),
          transform_from_callee_to_call( lv->get_expression<pc::lv_trait::sweep>(), fCallInCaller ), lv->get_opkind<pc::lv_trait::sweep>()
        );

    // } else if (fCallInCaller->contains( *dUseCallee )) {
    } else if (fCallInCaller->get_caller()->contains( dUseCallee->get_root_data_decl() ) ) {
      // This block probably skippable TODO

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::Transform Calle2Call : as already resolved " << inputPc->get_pc_string() << "\n";
#endif // TRANSFORM_LOG

      // The use has a data_decl within the caller of the call, so already resolved in this context, then skip
      return edit_piece( inputPc );

    } else if (dUseCallee->has_root()) {

      auto dDeclRootCallee = dUseCallee->get_root_data_decl();

      auto fDefCallee = dDeclRootCallee->get_root_function_definition();

      auto argId = fDefCallee->get_argument_id( dDeclRootCallee );

      return edit_piece( fCallInCaller->get_call_piece()->get_argument( argId ) );

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::Transform Calle2Call : as transformation : " << dUseCallee->get_terminal()->get_pc_string() << "\n";
#endif // TRANSFORM_LOG

    } else {
      throw std::logic_error("Unreachable in transform_from_callee_to_call");
    }

  } else if (inputPc->is_terminal() and inputPc->get_kind() == pc::kind::num) {

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::Transform Calle2Call : as literal " << inputPc->get_pc_string() << "\n";
#endif // TRANSFORM_LOG

    // No dDeclRoot or loop variable -> Literal. Return as is
    return edit_piece( inputPc );

  } else if (inputPc->is_multiple()) {

    return transform_piece_multiple( static_cast<const pc::multiple *>(inputPc), std::bind(transform_from_callee_to_call, std::placeholders::_1, fCallInCaller) );

  } else {
    throw std::logic_error("Unreachable in transform_from_callee_to_call");
  }

}


static
bool is_resolved_in_function(pc::cpiece_t inputPc, cso_t<obj::fun_def> fDef) {

  bool retBool = false;

  if (inputPc->is_terminal()) {

    auto term = static_cast<pc::cterminal_t>(inputPc);

    if (term->get_kind() == pc::kind::var) {

      auto var = static_cast<pc::ctoken_t<pc::kind::var>>(inputPc);

      if (var->is_loop()) {

        throw std::logic_error("is_resolved_in_callee : Not expecting any loop variable");

      } else {

        retBool = fDef->contains( var->get_data_use()->get_root_data_decl() );
      }

    } else if (term->get_kind() == pc::kind::num) {
      retBool = true;
    } else {
      throw std::logic_error("Unreachable in is_is_resolved_in_function");
    }

  } else {

    auto terminalVec = static_cast<const pc::multiple *>(inputPc)->get_flatten_terminals();

    retBool = std::all_of(std::begin(terminalVec), std::end(terminalVec), std::bind(is_resolved_in_function, std::placeholders::_1, fDef) );
  }

  // std::cout << "RESOLVED IN FUNCTION : " << fDef->get_identifier() << " : " << inputPc->get_pc_string() << (retBool ? " true" : " false" ) << '\n';

  return retBool;
}


///////////////
//
// INTERFACE
//
///////////////
pc::own_piece_t transform_from_call_to_callee(pc::cpiece_t inputPc, cso_t<obj::fun_call> fCallInCaller) {

  // FROM : a piece expressed in terms of variables defined in the call,
  // TO : a piece expressed in terms of variables defined in the callee,
  // HOW : variables as direct call arguments can be transformed to variables as callee arguments

  if (is_resolved_in_function(inputPc, fCallInCaller->get_callee())) {
    return edit_piece( inputPc );
  }


  if (inputPc->is_terminal() and inputPc->get_kind() == pc::kind::var) {

    auto var = static_cast<pc::ctoken_t<pc::kind::var>>(inputPc);
    auto dUseToTransform = var->get_data_use();

    if (var->is_loop()) {
      throw std::logic_error("transform_from_call_to_callee : Not expecting any loop variable");
    }

    // Locate the use with same dDeclRoot passed as direct call argument ...

    auto dUseAsCallArg =
        state<obj::data_use>::get_satisfying(
            [&] (const auto& dUse) {
              if (dUse->has_root() and dUse->is_direct_call_argument() and fCallInCaller->contains( dUse.get() )) {
                return dUse->get_root_data_decl()->get_identifier() == dUseToTransform->get_root_data_decl()->get_identifier();
              }
              return false;
            }
          );
    if (dUseAsCallArg == nullptr) {
      throw std::runtime_error("Could not identify data use call argument associated with : " + var->get_pc_string() + ", in call " + fCallInCaller->get_identifier());
    }

    // ... then get its associated dDecl in the callee context ...
    auto dDeclCallee = dUseAsCallArg->get_callee_data_decl();

    // ... and get any use (get the initialization, for example, as we know it always exists) ... 
    auto dUseInCallee = state<obj::data_use>::get_satisfying(
            [&] (const auto& dUse) {
              if (dUse->has_root()) {
                return dUse->get_root_data_decl()->get_identifier() == dDeclCallee->get_identifier();
              }
              return false;
            }
          );
    if (dUseInCallee == nullptr) {
      throw std::logic_error("Could not transform_from_call_to_callee : dUse in callee of data decl : " + dDeclCallee->get_identifier() + " not found");
    }

    // ... To clone its terminal.
    return edit_piece( dUseInCallee->get_terminal() );

  } else if (inputPc->is_terminal() and inputPc->get_kind() == pc::kind::num) {

    return edit_piece( inputPc );

  } else if (inputPc->is_multiple()) {

    return transform_piece_multiple( static_cast<const pc::multiple *>(inputPc), std::bind(transform_from_call_to_callee, std::placeholders::_1, fCallInCaller) );

  } else {
    throw std::logic_error("Unreachable in transform_from_callee_to_call");
  }

}



} // namespace bld::src
