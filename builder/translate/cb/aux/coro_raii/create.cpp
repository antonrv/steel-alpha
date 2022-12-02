
#include "translate/cb/aux/coro_raii/interface.hpp"

#include "source/object/function/definition.hpp"
#include "source/object/data/decl.hpp"

#include "source/token/region/affine/guard.hpp"

#include "common/inject/syntax_def.hpp"

#include "common/util.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <numeric>


namespace bld {

///////////////
//
// INTERFACE
//
///////////////
std::string make_wrap(src::cso_t<src::obj::data_decl> dDeclCaller) {

  auto wrapVarName = dDeclCaller->get_wrap_variable_name();
  auto varName = dDeclCaller->get_variable_name();

  auto makeWrapStr = dDeclCaller->get_guard()->get_wrap_command();

  std::ostringstream oss;

  oss << syn::endl() <<
    syn::stmt(
      syn::str(makeWrapStr)
    );
  return oss.str();
}


///////////////
//
// INTERFACE
//
///////////////
std::string make_cororaii_create(src::ctask_t tDefCaller) {

  auto wrapStmts = transform_vec_if(
      tDefCaller->get_root_function_definition()->get_arguments(),
      [] (src::cso_t<src::obj::data_decl> dDecl) {
        return dDecl->require_wrap();
      },
      make_wrap );

  return std::accumulate(std::begin(wrapStmts), std::end(wrapStmts), std::string());
}

} // namespace bld
