

#include "source/object/data/transform/interface.hpp"

#include "source/object/data/use.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/function/definition.hpp"

#include "source/token/make/copy.hpp"
#include "source/token/transform/multiple.hpp"

#include "source/object/state/def.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <functional>

namespace bld::src {

static
void check_on_same_global_context(cso_t<obj::fun_def> globCtxt, csob_t locCtxt) {

  ///////////////////////////// BASIC CHECK START
  // Must be on the same function_definition
  auto fDefOfThisCtxt = state<obj::fun_def>::get_containing( locCtxt );

  if (fDefOfThisCtxt == nullptr) {
    throw std::logic_error("check_on_same_global_context : fDef of context is nullptr : " + locCtxt->get_identifier());
  }

  if (fDefOfThisCtxt->get_identifier() != globCtxt->get_identifier()) {
    throw std::logic_error("check_on_same_global_context, not on same : " + fDefOfThisCtxt->get_identifier() + " != " + globCtxt->get_identifier());
  }
  ///////////////////////////// BASIC CHECK END
}

// This function is used to know whether a piece can be transformed in terms of variables set from outside the function, or variables statically set inside the function (ie not set from a function call or set from an array indirection)
///////////////
//
// INTERFACE
//
///////////////
bool is_statically_defined( pc::cpiece_t inputPc ) {

  if (inputPc->is_terminal() and inputPc->get_kind() == pc::kind::var ) {

    auto var = static_cast<pc::ctoken_t<pc::kind::var>>(inputPc);

    if (var->is_loop()) {
#ifdef TRANSFORM_LOG
  std::cout << "\t\t----RETURN:::::is_statically_defined : " << inputPc->get_pc_string() << " : true\n"; 
#endif // TRANSFORM_LOG
      return true;
    }

    // No need to handle loop vars, following is_statically_set_once will return true if loop var

    auto dUse = var->get_data_use();

    auto dDeclRoot = dUse->get_root_data_decl();

    if (dDeclRoot->get_decl_kind() == decl_kind::fargument or dDeclRoot->get_decl_kind() == decl_kind::relaxed_fargument) {

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::is_statically_defined : " << inputPc->get_pc_string() << " : true\n"; 
#endif // TRANSFORM_LOG
      return true;

    } else if (dDeclRoot->is_set_once()) {

      // If the setting comes from a call or an array indir, then it will trigger false.
      // If it comes from an expr
      auto fwRet = is_statically_defined( dDeclRoot->get_initialization() );
#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::is_statically_defined : " << inputPc->get_pc_string() << " : " << (fwRet ? "true" : "false") << "\n"; 
#endif // TRANSFORM_LOG
      return fwRet;

    } else {

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::is_statically_defined : " << inputPc->get_pc_string() << " : false\n";
#endif // TRANSFORM_LOG
      return false;
    }

  } else if (inputPc->is_terminal() and inputPc->get_kind() == pc::kind::num ) {

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::is_statically_defined : " << inputPc->get_pc_string() << " : true\n";
#endif // TRANSFORM_LOG
    return true;

  } else if (inputPc->is_multiple()) {

    if (inputPc->is_arith() or inputPc->get_kind() == pc::kind::range or inputPc->get_kind() == pc::kind::cs_list) {

      auto toks = static_cast<const pc::multiple *>( inputPc )->get_tokens();

      auto fwRet = std::all_of( std::begin(toks), std::end(toks), is_statically_defined );

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::is_statically_defined : " << inputPc->get_pc_string() << " : " << (fwRet ? "true" : "false") << "\n"; 
#endif // TRANSFORM_LOG

      return fwRet;

    } else {

      // A call or an array offset, which is a runtime value, so false

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::is_statically_defined : " << inputPc->get_pc_string() << " defaulted to : false\n";
#endif // TRANSFORM_LOG

      return false;
    }

  } else {
    throw std::logic_error("Unreachable in is_statically_defined");
  }

}



///////////////
//
// INTERFACE
//
///////////////
pc::own_piece_t transform_to_local_context( pc::cpiece_t inputPc, csob_t locCtxt ) {

  if (inputPc == nullptr) {
    throw std::logic_error("transform_to_local_context received nullptr as inputPc");
  }

  if (locCtxt == nullptr) {
    throw std::logic_error("transform_to_local_context received nullptr as locCtxt");
  }

  if (not is_statically_defined( inputPc )) {
    throw std::logic_error("Cannot transform_to_local_context : not statically defined : " + inputPc->get_pc_string() + " in context " + locCtxt->get_identifier());
  }


#ifdef TRANSFORM_LOG
  std::cout << "\t\t----ENTRY:::::Transform to Context : " << inputPc->get_pc_string() << " : " << locCtxt->get_obj() << " -> " << locCtxt->get_identifier() << '\n';
#endif // TRANSFORM_LOG

  if (inputPc->is_terminal() and inputPc->get_kind() == pc::kind::var ) {

    // std::cout << "Transforming BODY -> LPARAM : " << inputPc->get_pc_string() << '\n';

    auto var = static_cast<pc::ctoken_t<pc::kind::var>>(inputPc);

    auto dUse = var->get_data_use();

    auto dDeclRoot = dUse->get_root_data_decl();

    check_on_same_global_context( dDeclRoot->get_global_context(), locCtxt );

    if (var->is_loop()) {

      auto lv = var->get_loop_variable(); // static_cast<const pc::loop_var*>( var );

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::Transform to Context : as loop var " << var->get_pc_string() << '\n';
#endif // TRANSFORM_LOG

      return std::make_unique< pc::loop_var >( var,
          transform_to_local_context( lv->get_expression<pc::lv_trait::start>(), locCtxt ), lv->get_opkind<pc::lv_trait::start>(),
          transform_to_local_context( lv->get_expression<pc::lv_trait::bound>(), locCtxt ), lv->get_opkind<pc::lv_trait::bound>(),
          transform_to_local_context( lv->get_expression<pc::lv_trait::sweep>(), locCtxt ), lv->get_opkind<pc::lv_trait::sweep>()
        );

    } else if (locCtxt->is_before( dDeclRoot )) {
      // The definition of inputPc is defined after the required locCtxt, then we have to represent the input pc in terms of something that is before the locCtxt, not after, otherwise the translated code will cause an 'undefined var' compilation error.
#ifdef TRANSFORM_LOG
    std::cout << "\t\t----CMNT:::::Transform to Context : locCtxt " << locCtxt->get_identifier() << ", " << locCtxt->get_obj() << " is placed before fun arg root " << dDeclRoot->get_identifier() << " of " << inputPc->get_pc_string() << '\n';
#endif // TRANSFORM_LOG

      auto initPc = edit_piece( dDeclRoot->get_initialization() );

      // if (initPc->get_sign() == pc::sign::neg) { initPc->flip_sign(); }

      return transform_to_local_context( initPc.get(), locCtxt );

    } else {
      // locCtxt is after dDeclRoot, so already resolved in locCtxt, so do nothing
      return edit_piece( inputPc );
    }

  } else if (inputPc->is_terminal() and inputPc->get_kind() == pc::kind::num ) {

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::Transform to Context : as literal " << inputPc->get_pc_string() << '\n';
#endif // TRANSFORM_LOG
  
    return edit_piece( inputPc );

  } else if (inputPc->is_multiple()) {

#ifdef TRANSFORM_LOG
      std::cout << "\t\t----RETURN:::::Transform to Context : as multiple " << inputPc->get_kind() << '\n';
#endif // TRANSFORM_LOG

    return transform_piece_multiple( static_cast<const pc::multiple *>(inputPc), std::bind( transform_to_local_context, std::placeholders::_1, locCtxt ) );

  } else {
    throw std::logic_error("Unreachable in transform_to_local_context");
  }
}

} // namespace bld::src
