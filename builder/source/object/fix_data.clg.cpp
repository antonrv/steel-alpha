
#include "clang/AST/ASTContext.h"
#include "clang/AST/DeclBase.h"
#include "clang/AST/Decl.h"
#include "clang/AST/Expr.h"
#include "clang/AST/ExprCXX.h"
#include "clang/AST/Stmt.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Basic/SourceLocation.h"

#include <string>
#include <iostream> // DBG XXX

namespace bld::src {

///////////////////////
///////////////////////
///////////////////////
///////////////////////


std::pair<std::string, std::string>
get_sides_of_decl_stmt(const clang::DeclStmt * cPtr, const clang::ASTContext & ctxt) {

  clang::SourceRange srcRange = cPtr->getSourceRange();
  clang::FullSourceLoc beginFullLoc = ctxt.getFullLoc(srcRange.getBegin());
  clang::FullSourceLoc endFullLoc = ctxt.getFullLoc(srcRange.getEnd());
  
  std::string gotStr = std::string(beginFullLoc.getCharacterData(), std::distance(beginFullLoc.getCharacterData(), endFullLoc.getCharacterData()));

  std::string lhsStr;
  std::string rhsStr;

  // Organize this better, to also handle VarDecl with object constructions TODO
  
  auto eqPos = gotStr.find("=");
  if (eqPos != std::string::npos) {

    auto rhsPosStart = gotStr.find_first_not_of(' ', eqPos + 1);
    auto rhsPosEnd = gotStr.find_first_of(';', rhsPosStart);

    lhsStr = gotStr.substr(0, eqPos);
    rhsStr = gotStr.substr(rhsPosStart, rhsPosEnd - rhsPosStart);

    auto lhsPosEnd = eqPos - 1;

    auto varNameEndPos = gotStr.find_last_not_of(' ', lhsPosEnd);
    auto varNameStartPos = gotStr.find_last_not_of("_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", varNameEndPos);

    lhsStr = gotStr.substr(varNameStartPos, varNameEndPos - varNameStartPos + 1);

  } else {
    auto lhsPosEnd = gotStr.size() - 1;

    auto varNameEndPos = gotStr.find_last_not_of(' ', lhsPosEnd);
    auto varNameStartPos = gotStr.find_last_not_of("_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", varNameEndPos);

    lhsStr = gotStr.substr(varNameStartPos, varNameEndPos - varNameStartPos + 1);
  }

  // std::cout << "get_sides_of_decl_stmt : LHS: " << lhsStr << ". RHS:" << rhsStr << ". From : " << gotStr << '\n';

  return std::make_pair(lhsStr, rhsStr);
}

  template <typename ClangT>
  static
  std::string
  make_var_decl_type_string(const ClangT * cPtr, const clang::ASTContext& ctxt) {
  

    auto [lhsStr, rhsStr] = get_sides_of_decl_stmt(cPtr, ctxt);
  
    // std::cout << "RAW VARDECL type STR : " << lhsStr << '\n';
  
    return lhsStr;
  }

std::string fix_data(const clang::DeclStmt * cPtr, const clang::ASTContext & ctxt) {
  return make_var_decl_type_string(cPtr, ctxt);
}


///////////////////////
///////////////////////
///////////////////////
///////////////////////
//  static
//  std::string
//  make_arit_expr_string(const clang::BinaryOperator * cPtr, const clang::ASTContext& ctxt) {
//  
//    clang::SourceRange srcRange = cPtr->getSourceRange();
//    clang::FullSourceLoc beginFullLoc = ctxt.getFullLoc(srcRange.getBegin());
//    clang::FullSourceLoc endFullLoc = ctxt.getFullLoc(srcRange.getEnd());
//  
//    std::string varDeclTypeStr = std::string(beginFullLoc.getCharacterData(), std::distance(beginFullLoc.getCharacterData(), endFullLoc.getCharacterData()));
//  
//    auto eqPos = varDeclTypeStr.find(";");
//    if (eqPos == std::string::npos) {
//      eqPos = varDeclTypeStr.find("]");
//    }
//  
//    if (eqPos != std::string::npos) {
//      return varDeclTypeStr.substr(0, eqPos);
//    }
//    return "";
//  }

std::string fix_data(const clang::BinaryOperator * binOp, const clang::ASTContext & ctxt) {
  // DOES SOMETHING??? TODO XXX
  // auto retStr = make_arit_expr_string(cPtr, ctxt);

  const char * startData = ctxt.getFullLoc(binOp->getBeginLoc()).getCharacterData();

  const char * charPtr = startData;

  // if (binOp->isAssignmentOp()) {

    // std::cout << "Assign op\n";
  // ; ---> break
  // , ---> break
  // ) and openParen == 0 ---> break

  auto openParen = 0u;
  while ( not (*charPtr == ';' or *charPtr == ',' or (*charPtr == ')' and openParen == 0)) ) {
    if (*charPtr == '(') { openParen++; }
    else if (*charPtr == ')') { openParen--; }
    ++charPtr;
  }

  // } else {
  //   // Arith + * op assumed
  //   // std::cout << "Arith op assumed\n";
  //   while(
  //       *charPtr != ']' &&
  //       *charPtr != ';'
  //     ){ ++charPtr; }
  // }

  auto retStr = std::string(startData, std::distance(startData, charPtr));
  // std::cout << "Binop. Fix data : " << retStr << '\n';
  return retStr;
}

///////////////////////
///////////////////////
///////////////////////
///////////////////////

std::string fix_data(const clang::UnaryOperator * binOp, const clang::ASTContext & ctxt) {

  const char * startData = ctxt.getFullLoc(binOp->getBeginLoc()).getCharacterData();

  const char * charPtr = startData;

    while(
        *charPtr != ';' &&
        *charPtr != ')' &&
        *charPtr != ']'
      ){ ++charPtr; }
  auto retStr = std::string(startData, std::distance(startData, charPtr));
  // std::cout << "Unop. Fix data : " << retStr << '\n';
  return retStr;
}

///////////////////////
///////////////////////
///////////////////////
///////////////////////

std::string fix_data(const clang::DeclRefExpr * dre, const clang::ASTContext & ctxt) {

  const char * startData = ctxt.getFullLoc(dre->getBeginLoc()).getCharacterData();

  const char * charPtr = startData;

    while(
        *charPtr != ' ' &&
        *charPtr != ',' &&
        *charPtr != '+' &&
        *charPtr != '-' &&
        *charPtr != '*' &&
        *charPtr != '/' &&
        *charPtr != ';' &&
        *charPtr != '(' &&
        *charPtr != ')' &&
        *charPtr != '[' &&
        *charPtr != ']'
      ){ ++charPtr; }

  auto retStr = std::string(startData, std::distance(startData, charPtr));
  // std::cout << "DeclRefExpr. Fix data : " << retStr << '\n';
  return retStr;

}

std::string fix_data(const clang::ImplicitCastExpr * binOp, const clang::ASTContext & ctxt) {

  const char * startData = ctxt.getFullLoc(binOp->getBeginLoc()).getCharacterData();

  const char * charPtr = startData;

    while(
        *charPtr != ' ' &&
        *charPtr != ';' &&
        *charPtr != ')' &&
        *charPtr != ']'
      ){ ++charPtr; }

  auto retStr = std::string(startData, std::distance(startData, charPtr));
  // std::cout << "ImplCast. Fix data : " << retStr << '\n';
  return retStr;
}




///////////////////////
///////////////////////
///////////////////////
///////////////////////

bool is_castable_to_literal(const clang::Expr * expr) {

  return
    clang::IntegerLiteral::classof(expr) or 
    clang::FixedPointLiteral::classof(expr) or
    clang::ImaginaryLiteral::classof(expr) or
    clang::FloatingLiteral::classof(expr) or
    clang::CharacterLiteral::classof(expr) or
    clang::StringLiteral::classof(expr) or
    clang::CXXBoolLiteralExpr::classof(expr) or
    clang::CXXNullPtrLiteralExpr::classof(expr);
}

  std::string set_literal_data(const clang::Expr * litExpr, const clang::ASTContext& astCtxt) {
  
    const char * startData = astCtxt.getFullLoc(litExpr->getBeginLoc()).getCharacterData();
  
    const char * cPtr = startData;
    while(
      *cPtr != ';' &&
      *cPtr != ',' &&
      *cPtr != ' ' &&
      *cPtr != '+' &&
      *cPtr != '-' &&
      *cPtr != '*' &&
      *cPtr != '/' &&
      *cPtr != ')' &&
      *cPtr != '}' &&
      *cPtr != ']'
      ){ ++cPtr; }
    
    return std::string(startData, std::distance(startData, cPtr));
  }

template <typename ClangLitT>
std::string fix_data_lit(const ClangLitT * cPtr, const clang::ASTContext & ctxt) {

  if (not is_castable_to_literal(cPtr)) {
    throw std::logic_error("fix_data_lit received ptr not castable to literal");
  }

  auto retData = set_literal_data(cPtr, ctxt);
  // std::cout << "Castable to literal. Fix data : " << retData << '\n';
  return retData;
}

std::string fix_data(const clang::IntegerLiteral* cPtr, const clang::ASTContext & ctxt) {
  return fix_data_lit(cPtr, ctxt);
}
std::string fix_data(const clang::FixedPointLiteral* cPtr, const clang::ASTContext & ctxt) {
  return fix_data_lit(cPtr, ctxt);
}
std::string fix_data(const clang::FloatingLiteral* cPtr, const clang::ASTContext & ctxt) {
  return fix_data_lit(cPtr, ctxt);
}
std::string fix_data(const clang::ImaginaryLiteral* cPtr, const clang::ASTContext & ctxt) {
  return fix_data_lit(cPtr, ctxt);
}
std::string fix_data(const clang::CharacterLiteral* cPtr, const clang::ASTContext & ctxt) {
  return fix_data_lit(cPtr, ctxt);
}
std::string fix_data(const clang::StringLiteral* cPtr, const clang::ASTContext & ctxt) {
  return fix_data_lit(cPtr, ctxt);
}
std::string fix_data(const clang::CXXBoolLiteralExpr* cPtr, const clang::ASTContext & ctxt) {
  return fix_data_lit(cPtr, ctxt);
}
std::string fix_data(const clang::CXXNullPtrLiteralExpr* cPtr, const clang::ASTContext & ctxt) {
  return fix_data_lit(cPtr, ctxt);
}



} // namespace bld::src
