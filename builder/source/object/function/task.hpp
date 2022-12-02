#ifndef STEEL_COMPILER_TASK_DEFINITION_HPP
#define STEEL_COMPILER_TASK_DEFINITION_HPP

#include "source/sequences.hpp"

#include "source/object/typedef.hpp"

#include <vector>



namespace bld::src {

template <obj CtgK>
class sobject;


class task {
private:

  cso_t<obj::fun_def> const m_rootFunDef = nullptr;

  const std::string m_appIdentifier;
  const std::string m_appImplementation;
  std::string m_returnTypeStr;

  std::vector<std::string> m_appendedTypeParameters;

public:


  // To construct task definitions non-tagged functions
  task(cso_t<obj::fun_def> funDef);

  // To construct task definitions from tagged functions
  task(cso_t<obj::fun_def> funDef, const std::string& appId, const std::string& appImpl);

  cso_t<obj::fun_def> get_root_function_definition() const;

  bool need_translate_void_return() const;


  const std::string& get_app_identifier() const;

  const std::string& get_app_implementation() const;

  bool is_dispatcher() const;




  void set_return_type_str(const std::string& str);

  const std::string& get_return_type_str() const;

  void add_appended_type_parameter( const std::string& str );

  const std::vector<std::string>& get_appended_type_parameters() const;

  std::string serial() const;

};

} // namespace bld::src


#endif // STEEL_COMPILER_TASK_DEFINITION_HPP
