#include "source/object/function/definition.hpp"


namespace bld::src {

sobject<obj::fun_def>::sobject(const clang::FunctionDecl* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxtPtr, const std::string funcName) :
sobject_base(cPtr, sm, ctxtPtr),
m_functionName(funcName)
{}

} // namespace bld::src
