#include "source/sequences.hpp"

#include "source/object/typedef.hpp"

#include <vector>

namespace clang {

class DeclStmt;
class Expr;
class SourceManager;
class ASTContext;

} // namespace clang


namespace bld::src {

class sobject_base;

namespace pc {
  class terminal;
} // namespace pc

template <obj>
class sobject;

void
register_data_uses(const clang::DeclStmt* dstmt, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclCalleeOrOp, pc::vec_terminal_t& flattenTerminals);


void
register_data_uses(const clang::Expr* expr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclCalleeOrOp, pc::vec_terminal_t& flattenTerminals);


// void
// register_call_argument(const clang::Expr* expr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sobject<obj::data_decl> * dDeclCallee);

} // namespace bld::src
