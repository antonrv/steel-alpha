#ifndef STEEL_CMP_TRANSLATION_CB_AUX_MAKE_CORO_RAII_HPP
#define STEEL_CMP_TRANSLATION_CB_AUX_MAKE_CORO_RAII_HPP

#include "source/object/typedef.hpp"

#include <string>

namespace bld {


// std::string make_wrap_name(const std::string& varName);

std::string make_cororaii_create(src::ctask_t tDef);

std::string make_wrap(src::cso_t<src::obj::data_decl> dDeclCaller);

std::string make_cororaii_destroy(src::ctask_t tDef);

std::string make_cororaii_destroy_over_data_decls(const src::set_cso_t<src::obj::data_decl>& dDecls);

std::string make_emit_bnd(src::cso_t<src::obj::data_use> dUseInCall);


} // namespace bld

#endif // STEEL_CMP_TRANSLATION_CB_AUX_MAKE_CORO_RAII_HPP
