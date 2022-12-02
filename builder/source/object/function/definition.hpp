#ifndef STEEL_COMPILER_ELEMENT_FUNCTION_DEFINITION_HPP
#define STEEL_COMPILER_ELEMENT_FUNCTION_DEFINITION_HPP

#include "source/sequences.hpp"

// #include "source/object/data/parse_type.hpp"
#include "source/object/base.hpp"

#include "source/object/function/task.hpp"


namespace clang {
  class SourceManager;
  class ASTContext;
  class FunctionDecl;
} // namespace clang

namespace bld::src {

template <obj CtgK>
class sobject;

template <>
class sobject<obj::fun_def> : public sobject_base {
public:
  static constexpr obj sobject_kind = obj::fun_def;

  static constexpr opt_kind log_record = opt_kind::log_fun_def_record;

private:

  using super_type = sobject_base;

  const std::string m_functionName;

  set_so_t<obj::data_decl> m_arguments;
  so_t<obj::data_decl> m_argumentReturn = nullptr;


  set_so_t<obj::fun_call> m_bodyCalls;
  set_so_t<obj::fun_call> m_externCalls;


  // set_so_t<obj::fun_ret> m_bodyReturns;

  own_task_t m_ownedTask;

public:

  sobject(const clang::FunctionDecl* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxtPtr, const std::string funcName);

  virtual ~sobject() override;

  virtual obj get_obj() const override;

  virtual void print(std::ostream& os) const final override;

  std::string serial() const final override;

  const std::string& get_function_name() const;

  void set_task();
  void set_task(const std::string& appId, const std::string& appImpl);

  bool is_task() const;

  ctask_t get_task() const;
  task_t edit_task();

  // Parameters
  cso_t<obj::data_decl> get_data_decl(unsigned argId) const;
  void add_argument( so_t<obj::data_decl> dShared);

  set_cso_t<obj::data_decl> get_arguments() const;

  so_t<obj::data_decl> edit_argument(unsigned i);

  cso_t<obj::data_decl> get_argument(unsigned i) const;

  unsigned get_argument_id( cso_t<obj::data_decl> dDecl ) const;

  void set_return_argument( so_t<obj::data_decl> dShared);

  so_t<obj::data_decl> get_return_argument() const;


  // Calls
  void add_body_call( so_t<obj::fun_call> fCall );

  set_cso_t<obj::fun_call> get_body_calls() const;

  void add_extern_call( so_t<obj::fun_call> fCall );

  set_cso_t<obj::fun_call> get_extern_calls() const;

  unsigned get_call_id( cso_t<obj::fun_call> fCall) const;

  bool does_call( cso_t<obj::fun_def> fDef ) const;

  cso_t<obj::fun_call> get_call_to( cso_t<obj::fun_def> fDef ) const;

  cso_t<obj::fun_ctxt> get_body_context() const;

};

} // namespace bld::src


#endif // STEEL_COMPILER_ELEMENT_FUNCTION_DEFINITION_HPP
