#include "source/object/function/loop.hpp"



namespace bld::src {

sobject<obj::fun_loop>::sobject(const clang::ForStmt* forStmtPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
sobject_base(forStmtPtr, sm, ctxt),
m_loopKind(loop::for_kw)
{ }


// sobject<obj::fun_loop>::sobject(const clang::WhileStmt* stmtPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
// super_type(stmtPtr, sm, ctxt),
// m_loopKind(loop::while_kw)
// {
//   throw std::logic_error("Range deduction from while loop not implemented");
// 
// }

} // namespace bld::src
