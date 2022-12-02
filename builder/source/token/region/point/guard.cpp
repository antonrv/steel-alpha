
#include "source/token/region/point/guard.hpp"

#include "source/object/data/decl.hpp"


namespace bld::src::pc {


mem_guard<mem_ak::point>::mem_guard( const std::vector<const point_access*>& pts, cso_t<obj::data_decl> dDecl ) :
super_type(dDecl),
m_pointAccesses(pts)
{}

mem_guard<mem_ak::point>::~mem_guard() {}

mem_ak mem_guard<mem_ak::point>::get_mem_guard_kind() const {
  return mem_ak::point; 
}

#ifndef PARSER_TEST


std::string mem_guard<mem_ak::point>::get_wrap_command() const {

  auto wrapVarName = super_type::m_dDeclRoot->get_wrap_variable_name();
  auto varName = super_type::m_dDeclRoot->get_variable_name(); 


  return "auto " + wrapVarName + " = dep::wrap(" + varName + ")";
}


std::string mem_guard<mem_ak::point>::get_emit_arguments( const access * acc ) const {

  if (acc->get_mem_access_kind() != mem_ak::point) {
    throw std::logic_error("Could not get_emit_arguments on mem_guard point. Access is not a mem_ak::point");
  }

  return "()";

  // std::string retStr;

  // if (dsGuard != nullptr) {

  //   if (not dsGuard->all_are_statically_determined()) {

  //     retStr += "_full()";

  //   } else {

  //     auto ptAcc = static_cast<const mem_access<mem_ak::point>*>( acc );

  //     retStr += "(";

  //     retStr += ptAcc->get_original()->get_pc_string(); // Original / Local ptr access

  //     auto dsGuard = ptAcc->get_downstream_guard();

  //     if (dsGuard != nullptr) {
  //       retStr += ",";

  //     }

  //     retStr += ")";

  //   }

  // }

  // return retStr;
}

std::string mem_guard<mem_ak::point>::serial() const {

  return "serialized:mem_guard<mem_ak::point>:no-fields";
}


#endif // PARSER_TEST

} // namespace bld::src::pc
