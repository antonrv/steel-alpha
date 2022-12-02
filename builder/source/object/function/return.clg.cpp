#include "source/object/function/return.hpp"


namespace bld::src {

sobject<obj::fun_ret>::sobject(const clang::ReturnStmt* rs, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
sobject_base(rs, sm, ctxt)
{}


} // namespace bld::src
