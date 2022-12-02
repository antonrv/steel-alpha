#ifndef STEEL_COMPILER_ELEMENT_FUNCTION_CALL_HPP
#define STEEL_COMPILER_ELEMENT_FUNCTION_CALL_HPP

#include "source/object/base.hpp"

#include "source/token/multiple/call.hpp"

#include "source/sequences.hpp"


#include <memory>


namespace clang {
  class SourceManager;
  class ASTContext;
  class CallExpr;
  class Expr;
  class FunctionDecl;
} // namespace clang


namespace bld::src {

class data_event;

template <obj CtgK>
class sobject;

template <>
class sobject<obj::fun_call> : public sobject_base {
public:
  static constexpr obj sobject_kind = obj::fun_call;

  static constexpr opt_kind log_record = opt_kind::log_fun_call_record;

private:

  using super_type = sobject_base;

  using fun_def_t = sobject<obj::fun_def>;

  so_t<obj::fun_def> m_callee = nullptr;

  so_t<obj::fun_def> m_caller = nullptr;

  pc::own_token_t<pc::kind::call> m_callPieceRoot = nullptr;

public:

  sobject(const clang::CallExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

  // main_entry constructor. REDO XXX
//  sobject(const clang::FunctionDecl* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sobject<obj::fun_def> * defCallee, data_event* retEv, std::string name);

  virtual ~sobject() override;

  virtual obj get_obj() const override;

  virtual void print(std::ostream& os) const final override;

  std::string serial() const final override;

  // bool returns() const;

  cso_t<obj::fun_def> get_callee() const;

  cso_t<obj::fun_def> get_caller() const;

  pc::ctoken_t<pc::kind::call> get_call_piece() const;


  std::string get_app_call_translation() const;
};


} // namespace bld::src

#endif // STEEL_COMPILER_ELEMENT_FUNCTION_CALL_HPP
