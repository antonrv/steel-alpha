#include "source/object/data/decl.hpp"

#include "clang/AST/DeclBase.h"
#include "clang/AST/Type.h"
#include "clang/AST/Decl.h"
#include "clang/AST/Stmt.h"


namespace bld::src {

// VarDecl::getDefinition returns another VarDecl

// A list parameter or a body parameter
sobject<obj::data_decl>::sobject(const clang::VarDecl* varDecl, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
super_type(varDecl->getDefinition(), sm, ctxt),
m_declarationKind( clang::ParmVarDecl::classof(varDecl) ? decl_kind::fargument : decl_kind::body ),
m_variableName(get_name_as_string(varDecl->getDefinition()))
{
  this->initialize_fields();
}

// Normal return parameter
sobject<obj::data_decl>::sobject(const clang::SourceRange& sr, const clang::SourceManager& sm, const clang::ASTContext& ctxt, const clang::QualType retType) :
super_type(sr, sm, ctxt),
m_declarationKind( decl_kind::return_parameter ),
m_variableName("")
{
  super_type::m_data = retType.getAsString() + "&";
  this->initialize_fields();
}

} // namespace bld::src
