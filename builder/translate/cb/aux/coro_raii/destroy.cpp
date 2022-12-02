
#include "translate/cb/aux/coro_raii/interface.hpp"

#include "source/object/function/definition.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/function/context.hpp"
#include "source/object/state/def.hpp"


#include "common/inject/syntax_def.hpp"


#include "common/util.hpp"


#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <functional>

namespace bld {


std::string make_cororaii_destroy_over_data_decls( const src::set_cso_t<src::obj::data_decl>& dDecls ) {

  auto wrapNames = transform_vec_if( dDecls,
      [] (src::cso_t<src::obj::data_decl> dDecl) {
        return dDecl->require_wrap();
      },
      [] (src::cso_t<src::obj::data_decl> dDecl) {
        return dDecl->get_wrap_variable_name();
      } );

  if (not wrapNames.empty()) {

    std::ostringstream oss; oss << syn::endl();
    oss << syn::cororaii( syn::sequence(wrapNames) ) << syn::endl();

    return oss.str();

  } else {

    return "";
  }
}


std::string make_cororaii_destroy(src::ctask_t tDefCaller) {

  std::vector<std::string> wrapNames;

  auto allArgs = tDefCaller->get_root_function_definition()->get_arguments();

  // Append arguments whose initialization lies in this function_context.

  // 1. First locate the fun ctxt of this t def
  auto fCtxtThis = src::state<src::obj::fun_ctxt>::get_satisfying( 
    [&](const auto& uptr) {
      return uptr->is_top() and tDefCaller->get_root_function_definition()->contains( uptr.get() );
    }
  );

  // 2. Then get all the fun args that strictly belong to this fun ctxt
  auto bodyArgs = src::state<src::obj::data_decl>::get_all_satisfying(
    [&](const auto& dDeclUptr) {

        auto dDeclCaller = dDeclUptr.get();
        
        if (tDefCaller->get_root_function_definition()->contains(dDeclCaller) and dDeclCaller->get_decl_kind() == src::decl_kind::body) {
          auto fCtxt = src::state<src::obj::fun_ctxt>::get_innermost_of( dDeclCaller );

          // If the innermost f ctxt of this f arg is the same as the fun ctxt of the task def, return true.
          return fCtxt->get_identifier() == fCtxtThis->get_identifier();
        }
        return false;
      }
  );

  std::copy( std::begin(bodyArgs), std::end(bodyArgs), std::inserter(allArgs, std::end(allArgs)) );

  return make_cororaii_destroy_over_data_decls( allArgs );
}

} // namespace bld
