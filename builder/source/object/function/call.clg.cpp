#include "source/object/function/call.hpp"

#include "source/object/function/definition.hpp"
#include "source/object/data/decl.hpp"

#include "source/token/make/piece.hpp"

#include "source/object/state/def.hpp"


#include "clang/AST/Expr.h"
#include "clang/AST/ASTContext.h"
#include "clang/Basic/SourceManager.h"

#include "source/object/data/register_bind.hpp"

namespace bld::src {


sobject<obj::fun_call>::sobject(const clang::CallExpr* callExpr, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
sobject_base(callExpr, sm, ctxt),
m_callee(state<obj::fun_def>::edit( callExpr->getDirectCallee(), sm, ctxt)),
m_caller(state<obj::fun_def>::edit_containing( this )),
m_callPieceRoot( static_unique_pointer_cast<pc::token<pc::kind::call>>( pc::make_piece( this->get_data() ) ) )
// m_returnEvent(nullptr)
{

  if (m_callPieceRoot->get_kind() != pc::kind::call) {
    throw std::logic_error("kind consistency broken in function_call constructor. Expected pc::kind::call, got : " + m_callPieceRoot->get_kind_str());
  }

  // std::cout << ">>>>>>>>>>>>>function_call constructor (CallExpr): " << this->get_data() << '\n';


  // std::cout << "built function call piece from : " << this->get_data() << ". Got : " << m_callPieceRoot->get_pc_string() << '\n';
  if (not callExpr->getDirectCallee()->hasBody()) {
    throw std::logic_error(std::string("Function does not have body (add matcher to call body-less functions) ") + callExpr->getStmtClassName());
  }

  if (m_callee == nullptr) {
    throw std::logic_error(std::string("Could not find kernel definition for call ") + callExpr->getStmtClassName());
  } 
  if (m_caller == nullptr) {
    throw std::logic_error(std::string("Could not find parent dispatcher of ") + callExpr->getStmtClassName());
  }

  if (m_callPieceRoot == nullptr) {
    throw std::logic_error("Could not build pc::kind::call in function_call from : " + this->get_data());
  }

  m_callee->add_extern_call(this);
  m_caller->add_body_call(this);


  auto numArgs = callExpr->getNumArgs();

  for (auto argId = 0u; argId < numArgs; ++argId) {

    auto argPc = m_callPieceRoot->edit_argument(argId);

    auto terminalsVec = argPc->edit_flatten_terminals();

    register_and_bind( callExpr->getArg(argId), sm, ctxt, m_callee->edit_argument(argId), terminalsVec );
  }

  // std::cout << "<<<<<<<<<function_call constructor (CallExpr).\n";
}



// REDO XXX
// // Special constructor for 'main' artificial call.
// sobject<obj::fun_call>::sobject(const clang::FunctionDecl* callExpr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sobject<obj::fun_def> * defCallee, data_event* retEv, std::string name) :
// sobject_base(callExpr, sm, ctxt),
// m_callee(defCallee),
// m_caller(nullptr),
// m_returnEvent(retEv)
// {
//   defCallee->add_extern_call(this);
// }

} // namespace bld::src
