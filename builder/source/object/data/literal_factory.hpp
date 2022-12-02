
#include "clang/AST/Expr.h"
#include "clang/AST/ExprCXX.h"
#include "clang/AST/ASTContext.h"

#include "source/sequences.hpp"

#include <string>

namespace bld::src {
  template <obj>
  class sobject;

} // namespace bld::src

#include "source/object/typedef.hpp"
#include "source/object/state/decl.hpp"

namespace bld::src {



template <obj Obj, typename... Args>
so_t<Obj> register_from_literal(const clang::Expr* litExpr, const clang::SourceManager& srcMng, const clang::ASTContext& astCtxt, Args&&... args) {

  if (clang::IntegerLiteral::classof(litExpr)) {
    // INTEGER
    return state<Obj>::make(static_cast<const clang::IntegerLiteral*>(litExpr), srcMng, astCtxt, std::forward<Args>(args) ... );
  } else if (clang::FixedPointLiteral::classof(litExpr)) {
    // FIXED POINT
    return state<Obj>::make(static_cast<const clang::FixedPointLiteral*>(litExpr), srcMng, astCtxt, std::forward<Args>(args) ...);
  } else if (clang::ImaginaryLiteral::classof(litExpr)) {
    // IMAGINARY
    return state<Obj>::make(static_cast<const clang::ImaginaryLiteral*>(litExpr), srcMng, astCtxt, std::forward<Args>(args) ...);
  } else if (clang::FloatingLiteral::classof(litExpr)) {
    // FLOATING POINT
    return state<Obj>::make(static_cast<const clang::FloatingLiteral*>(litExpr), srcMng, astCtxt, std::forward<Args>(args) ...);
  } else if (clang::CharacterLiteral::classof(litExpr)) {
    // CHARACTER
    return state<Obj>::make(static_cast<const clang::CharacterLiteral*>(litExpr), srcMng, astCtxt, std::forward<Args>(args) ...);
  } else if (clang::StringLiteral::classof(litExpr)) {
    // STRING 
    return state<Obj>::make(static_cast<const clang::StringLiteral*>(litExpr), srcMng, astCtxt, std::forward<Args>(args) ...);
  } else if (clang::CXXBoolLiteralExpr::classof(litExpr)) {
    // BOOL
    return state<Obj>::make(static_cast<const clang::CXXBoolLiteralExpr*>(litExpr), srcMng, astCtxt, std::forward<Args>(args) ...);
  } else if (clang::CXXNullPtrLiteralExpr::classof(litExpr)) {
    // NULLPTR
    return state<Obj>::make(static_cast<const clang::CXXNullPtrLiteralExpr*>(litExpr), srcMng, astCtxt, std::forward<Args>(args) ...);
  } else {
    return nullptr;
  }

}

} // namespace bld::src
