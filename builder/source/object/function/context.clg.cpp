#include "source/object/function/context.hpp"


namespace bld::src {

sobject<obj::fun_ctxt>::sobject(const clang::CompoundStmt* rs, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
sobject_base(rs, sm, ctxt)
{}


} // namespace bld::src

