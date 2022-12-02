#include "source/object/function/task.hpp"

#include "source/object/function/definition.hpp"


#include <algorithm>

namespace bld::src {


task::task(cso_t<obj::fun_def> funDef) :
m_rootFunDef(funDef),
m_appIdentifier(funDef->get_function_name()),
m_appImplementation(funDef->get_function_name())
{ }

task::task(cso_t<obj::fun_def> funDef, const std::string& appId, const std::string& appImpl) :
m_rootFunDef(funDef),
m_appIdentifier(appId),
m_appImplementation(appImpl)
{ }


cso_t<obj::fun_def> task::get_root_function_definition() const {
  return m_rootFunDef;
}

bool task::need_translate_void_return() const {
  return m_rootFunDef->get_return_argument() != nullptr;
}


bool task::is_dispatcher() const {
  return not m_rootFunDef->get_body_calls().empty();
}

const std::string& 
task::get_app_identifier() const {
  return m_appIdentifier;
}

const std::string& 
task::get_app_implementation() const {
  return m_appImplementation;
}


void task::set_return_type_str(const std::string& str) {
  m_returnTypeStr = str;
}

const std::string& task::get_return_type_str() const {
  return m_returnTypeStr;
}


void task::add_appended_type_parameter( const std::string& str ) {
  m_appendedTypeParameters.push_back(str);
}

const std::vector<std::string>& task::get_appended_type_parameters() const {
  return m_appendedTypeParameters;
}


} // namespace bld::src
