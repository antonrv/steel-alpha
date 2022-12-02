#include "source/object/base.hpp"

#include "clang/AST/ASTContext.h"
#include "clang/AST/DeclBase.h"
#include "clang/AST/Decl.h"
#include "clang/AST/Expr.h"
#include "clang/AST/ExprCXX.h"
#include "clang/AST/Stmt.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Basic/SourceLocation.h"

// #include "clang/Lex/Lexer.h"

// #include <stdexcept>
#include <iostream> // debug TODO

namespace bld::src {

// Used from source/object/task/clang_dependency.cpp
// std::string get_name_as_string(const clang::Decl * vd) {
//   if (clang::VarDecl::classof(vd)) {
//     return static_cast<const clang::VarDecl*>(vd)->getNameAsString();
//   }
//   throw std::runtime_error("Cannot get_name_as_atring. Decl not castable to VarDecl");
// }



std::string get_name_as_string(const clang::VarDecl * vd) {
  return vd->getNameAsString();
}

std::string zero_pad(unsigned n) {
  std::string nStr = std::to_string(n);
  static constexpr unsigned NDigits = 6;
  if (NDigits < nStr.size()) {
    throw std::logic_error("Error padding zeros while source id construction. Digits exceeded");
  }
  nStr.insert(0, NDigits - nStr.size(), '0');

  return nStr;
}


template <typename ClangT>
static std::string fix_data(const ClangT * cPtr, const clang::ASTContext & ctxt) {
  return "";
}

std::string fix_data(const clang::DeclStmt * cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::DeclRefExpr * cPtr, const clang::ASTContext & ctxt);
// std::string fix_data(const clang::ParmVarDecl * cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::BinaryOperator * cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::UnaryOperator * cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::ImplicitCastExpr * cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::Expr * cLiteralPtr, const clang::ASTContext & ctxt);

std::string fix_data(const clang::IntegerLiteral* cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::FixedPointLiteral* cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::FloatingLiteral* cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::ImaginaryLiteral* cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::CharacterLiteral* cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::StringLiteral* cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::CXXBoolLiteralExpr* cPtr, const clang::ASTContext & ctxt);
std::string fix_data(const clang::CXXNullPtrLiteralExpr* cPtr, const clang::ASTContext & ctxt);


template <typename ClangT>
object_id_t sobject_base::build_id(const ClangT * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt) {

  clang::SourceRange srcRange = cPtr->getSourceRange();
  const clang::FullSourceLoc beginFullLoc = ctxt.getFullLoc(srcRange.getBegin());
  auto lineNo = beginFullLoc.getSpellingLineNumber();
  auto colNo = beginFullLoc.getSpellingColumnNumber();

  auto retSrcRange = cPtr->getSourceRange().printToString(sm);

  // We want to discard the line-colum start-end range, in the id, just using the initial row and col to build the identifier, so source src-objects are ordered in the state::set_t in order of appearance.
  // We want to add padding zeros in the column id so that when comparing src.cpp:lineno:13 with src.cpp:lineno:7 the code in column 7 goes before code in column 13
  auto firstCln = retSrcRange.find(':');
  auto endId = retSrcRange.find('>');


  auto locationStr = zero_pad(lineNo) + "-" + zero_pad(colNo);
  retSrcRange.replace(firstCln + 1, endId - firstCln - 1, locationStr);

  return retSrcRange;
}

// Constructor for specific clang ptrs
// Both clang::Decl* and clang::Stmt* expose getBegin/EndLoc and getSourceRange
template <typename ClangT>
sobject_base::sobject_base(const ClangT * cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
m_identifier(build_id(cPtr, sm, ctxt))
{


  // clang::FullSourceLoc beginFullLoc = ctxt.getFullLoc(cPtr->getBeginLoc());
  // clang::FullSourceLoc endFullLoc = ctxt.getFullLoc(cPtr->getEndLoc());

  clang::SourceRange srcRange = cPtr->getSourceRange();
  clang::FullSourceLoc beginFullLoc = ctxt.getFullLoc(srcRange.getBegin());
  clang::FullSourceLoc endFullLoc = ctxt.getFullLoc(srcRange.getEnd());


  const char * startData = beginFullLoc.getCharacterData();
  auto d = std::distance(startData, endFullLoc.getCharacterData());
//  if (d == 0) {
//    llvm::SmallVector<char, 256> buff;
//    clang::Lexer::getSpelling(srcRange.getBegin(), buff, sm, ctxt.getLangOpts());
//    m_data = std::string(buff.begin(), std::distance(buff.begin(), buff.end()));
//    // throw std::runtime_error("Could not capture source data of " + m_identifier::get_identifier());
//  } else {
//  }
  auto fixedData = fix_data(cPtr, ctxt);
  // std::cout << "DEFAULT DATA : " <<  std::string(startData, d + 1) << "... FIXED DATA : " << fixedData << '\n';
  m_data = fixedData.empty() ? std::string(startData, d + 1) : fixedData;

  m_begin[(unsigned)pos::line] = beginFullLoc.getSpellingLineNumber();
  m_begin[(unsigned)pos::column] = beginFullLoc.getSpellingColumnNumber();
  m_end[(unsigned)pos::line] = endFullLoc.getSpellingLineNumber();
  m_end[(unsigned)pos::column] = endFullLoc.getSpellingColumnNumber();


  this->set_source_filename();
  // std::cout << "begin line : " << m_begin[(unsigned)pos::line] << " end line : " <<  m_end[(unsigned)pos::line] << '\n';
  // std::cout << "begin column : " << m_begin[(unsigned)pos::column] << " end column : " <<  m_end[(unsigned)pos::column] << '\n';

  // std::cout << "source sobject constructor1 for " << " Id : " << this->get_identifier() << " data :\n " << m_data << '\n';
}

// Constructor for specific clang ptrs
// Both clang::Decl* and clang::Stmt* expose getBegin/EndLoc and getSourceRange
// template <>
// sobject_base::sobject_base(const clang::VarDecl * cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
// m_identifier(build_id(cPtr, sm, ctxt))
// {
// 
// 
//   clang::SourceRange srcRange = cPtr->getSourceRange();
//   clang::FullSourceLoc beginFullLoc = ctxt.getFullLoc(srcRange.getBegin());
//   clang::FullSourceLoc endFullLoc = ctxt.getFullLoc(srcRange.getEnd());
// 
// 
//   const char * startData = beginFullLoc.getCharacterData();
//   auto d = std::distance(startData, endFullLoc.getCharacterData());
// //  if (d == 0) {
// //    llvm::SmallVector<char, 256> buff;
// //    clang::Lexer::getSpelling(srcRange.getBegin(), buff, sm, ctxt.getLangOpts());
// //    m_data = std::string(buff.begin(), std::distance(buff.begin(), buff.end()));
// //    // throw std::runtime_error("Could not capture source data of " + m_identifier::get_identifier());
// //  } else {
// //  }
//   m_data = std::string(startData, d + 1);
// 
//   m_begin[(unsigned)pos::line] = beginFullLoc.getSpellingLineNumber();
//   m_begin[(unsigned)pos::column] = beginFullLoc.getSpellingColumnNumber();
//   m_end[(unsigned)pos::line] = endFullLoc.getSpellingLineNumber();
//   m_end[(unsigned)pos::column] = endFullLoc.getSpellingColumnNumber();
// 
// 
//   // std::cout << "source sobject constructor1 for " << " Id : " << this->get_identifier() << " data :\n " << m_data << '\n';
// }

// Constructor template instantiations for previous template
// template sobject_base::sobject_base<clang::Decl> (const clang::Decl* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);




// Needed to construct task_definition src-objects
// template sobject_base::sobject_base<clang::FunctionDecl>(const clang::FunctionDecl* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base(const clang::Decl* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
// template sobject_base::sobject_base(const clang::Expr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt); XXX
template sobject_base::sobject_base(const clang::FunctionDecl* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
// Needed to construct data_usages src-objects
// template sobject_base::sobject_base (const clang::ParmVarDecl* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base (const clang::VarDecl* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

// template sobject_base::sobject_base<clang::Stmt> (const clang::Stmt* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
// template sobject_base::sobject_base<clang::Expr> (const clang::Expr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

// template sobject_base::sobject_base<clang::ValueDecl> (const clang::ValueDecl* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

template sobject_base::sobject_base (const clang::DeclStmt* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

template sobject_base::sobject_base (const clang::ValueDecl* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
// Needed to construct task_call src-objects
// template sobject_base::sobject_base<clang::CallExpr> (const clang::CallExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base(const clang::CallExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

// template sobject_base::sobject_base<clang::BinaryOperator> (const clang::BinaryOperator* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base(const clang::UnaryOperator* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base(const clang::BinaryOperator* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

template sobject_base::sobject_base (const clang::ReturnStmt* rsPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

template sobject_base::sobject_base (const clang::ForStmt* rsPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base (const clang::WhileStmt* rsPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base (const clang::CompoundStmt* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

// Needed to construct data_use src-objects
template sobject_base::sobject_base (const clang::DeclRefExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base (const clang::ArraySubscriptExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

template sobject_base::sobject_base (const clang::ImplicitCastExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

template sobject_base::sobject_base(const clang::IntegerLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base(const clang::FixedPointLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base(const clang::FloatingLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base(const clang::ImaginaryLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base(const clang::CharacterLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base(const clang::StringLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base(const clang::CXXBoolLiteralExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);
template sobject_base::sobject_base(const clang::CXXNullPtrLiteralExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);



// Static func template instantiations
template std::string sobject_base::build_id<clang::DeclStmt>(const clang::DeclStmt * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt);
template std::string sobject_base::build_id<clang::FunctionDecl>(const clang::FunctionDecl * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt);
template std::string sobject_base::build_id<clang::ParmVarDecl>(const clang::ParmVarDecl * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt);
template std::string sobject_base::build_id<clang::VarDecl>(const clang::VarDecl * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt);
template std::string sobject_base::build_id<clang::DeclRefExpr>(const clang::DeclRefExpr * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt);
template std::string sobject_base::build_id<clang::ValueDecl>(const clang::ValueDecl * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt);
template std::string sobject_base::build_id<clang::CallExpr>(const clang::CallExpr * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt);
template std::string sobject_base::build_id<clang::ForStmt>(const clang::ForStmt * sPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt);

template std::string sobject_base::build_id<clang::WhileStmt>(const clang::WhileStmt * sPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt);
template std::string sobject_base::build_id<clang::CompoundStmt>(const clang::CompoundStmt * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt);

// Constructor from source range
sobject_base::sobject_base(const clang::SourceRange& sr, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
m_identifier(sr.printToString(sm)),
m_data(sr.printToString(sm))
{

  clang::SourceLocation beginLoc = sr.getBegin();
  clang::SourceLocation endLoc = sr.getEnd();
  clang::FullSourceLoc beginFullLoc = ctxt.getFullLoc(beginLoc);
  clang::FullSourceLoc endFullLoc = ctxt.getFullLoc(endLoc);

  m_begin[(unsigned)pos::line] = beginFullLoc.getSpellingLineNumber();
  m_begin[(unsigned)pos::column] = beginFullLoc.getSpellingColumnNumber();
  m_end[(unsigned)pos::line] = endFullLoc.getSpellingLineNumber();
  m_end[(unsigned)pos::column] = endFullLoc.getSpellingColumnNumber();

  this->set_source_filename();
  // std::cout << "source sobject constructor2 for " << this->get_identifier() << " data : " << m_data << '\n';
}

// sobject_base::~sobject_base() {}

//// Plain lexicographical compare between [start-line, start-column] arrays
//bool sobject_base::operator<(const sobject_base& srcLoc) const {
//  return this->m_begin < srcLoc.m_begin;
//}
//bool sobject_base::operator<=(const sobject_base& srcLoc) const {
//  return this->m_begin <= srcLoc.m_begin;
//}




} // namespace bld::src

