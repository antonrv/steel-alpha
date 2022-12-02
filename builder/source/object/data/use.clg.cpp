#include "source/object/data/use.hpp"

#include "source/object/data/decl.hpp"

#include "source/token/make/piece.hpp"

#include "source/object/data/factory.hpp"
#include "source/object/data/literal_factory.hpp"

#include "common/aux.hpp"

#include "source/object/state/def.hpp"


#include "clang/AST/Stmt.h"
#include "clang/AST/Decl.h"
#include "clang/AST/Expr.h"
#include "clang/AST/ExprCXX.h"
#include "clang/AST/ASTContext.h"

namespace bld::src {


static
sobject<obj::data_decl> * locate_root_data_decl(const clang::DeclStmt * declStmt, const clang::SourceManager& sm, const clang::ASTContext& ac) {


  if (declStmt->isSingleDecl() and clang::VarDecl::classof(declStmt->getSingleDecl())) {

    return state<obj::data_decl>::make( static_cast<const clang::VarDecl*>(declStmt->getSingleDecl()), sm, ac );
  }

  throw std::runtime_error("Unable to create root fun arg from declstmt (in data_use construction)");
}

static
sobject<obj::data_decl> * locate_root_data_decl(const clang::Expr * expr, const clang::SourceManager& sm, const clang::ASTContext& ac) {

  if (clang::ImplicitCastExpr::classof(expr)) {

    auto implCastExpr = static_cast<const clang::ImplicitCastExpr*>(expr);

    return locate_root_data_decl(implCastExpr->getSubExpr(), sm, ac);

  } else if (clang::UnaryOperator::classof(expr)) {

    auto unOpExpr = static_cast<const clang::UnaryOperator*>(expr);

    return locate_root_data_decl( unOpExpr->getSubExpr(), sm, ac );
    
  } else if (clang::ArraySubscriptExpr::classof(expr)) {

    auto asExpr = static_cast<const clang::ArraySubscriptExpr*>(expr);

    return locate_root_data_decl( asExpr->getBase(), sm, ac );

  } else if (clang::DeclRefExpr::classof(expr)) {

    auto declRefExpr = static_cast<const clang::DeclRefExpr*>(expr);

    if (clang::VarDecl::classof(declRefExpr->getDecl())) {

      auto dDeclRoot = state<obj::data_decl>::make( static_cast<const clang::VarDecl*>(declRefExpr->getDecl()), sm, ac );
      if (dDeclRoot == nullptr) {
        throw std::runtime_error("data decl of declrefexpr not found");
      }
      
      return dDeclRoot;
    }

    throw std::runtime_error("Unable to create root fun arg from declrefexpr (in data_use construction)");

  } else if (clang::BinaryOperator::classof(expr)) {
    // eg the side 'j + 3' in 'int i = j + 3;'

    // sobject_base tmpSrcElem( expr, sm, ac );
    // throw std::runtime_error("Handle this"   + tmpSrcElem.get_identifier() + "\n" + tmpSrcElem.get_data());
    throw std::runtime_error("Unable to create root fun arg from binary op (in data_use construction)");

  } else if (is_castable_to_literal(expr)) {

    throw std::logic_error("Unreachable while constructing data_use sobject (Bypassed literal constructors)");
    return nullptr;

  } else {
    // sobject_base tmpSrcElem( expr, sm, ac );
    // throw std::logic_error("Could not deduce locate_root_data_decl for data_use constructor : "  + tmpSrcElem.get_identifier() + "\n" + tmpSrcElem.get_data());
    throw std::logic_error("Could not deduce locate_root_data_decl for data_use constructor");
  }
}

// const-ify this function ? Check if data decl needs sobject_set_t or can have sobject_cset_t TODO
void sobject<obj::data_use>::add_this_data_use(pc::terminal_t term) {
  if (m_dDeclRoot != nullptr) {

    m_dDeclRoot->add_data_use(this);

  } else {
    // Literal. no farg root to notify
  }

  term->set_data_use(this);


  // No longer needed to notify the operation or the callee farg about this data use. They are associated via piece src-objects.

  // NOT DONE HERE ANYMORE, as the vars of affine have not been bound yet to the data uses, so data uses wont be visible from class affine objects!!!
  // // std::cout << "Adding this data use : " << this->get_identifier() << '\n';
  // if (this->on_address()) {
  //   // std::cout << "... and setting affine\n";
  //   this->set_affine();
  // }
}


sobject<obj::data_use>::sobject(const clang::DeclRefExpr * cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm) :
sobject_base(cPtr, sm, ctxt),
m_dDeclRoot(locate_root_data_decl(cPtr, sm, ctxt)),
m_dDeclCalleeOrOperation(dDeclOrOp),
m_terminalRoot(trm)
{
  // std::cout << "data_use constructor : declrefexpr : " << sobject_base::get_data() << '\n';
  this->add_this_data_use(trm);
}


// DEPRECATE TODO
sobject<obj::data_use>::sobject(const clang::UnaryOperator * cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm) :
sobject_base(cPtr, sm, ctxt),
m_dDeclRoot(locate_root_data_decl(cPtr, sm, ctxt)),
m_dDeclCalleeOrOperation(dDeclOrOp),
m_terminalRoot(trm)
{
  this->add_this_data_use(trm);
}


sobject<obj::data_use>::sobject(const clang::DeclStmt * cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm) :
sobject_base(cPtr, sm, ctxt),
m_dDeclRoot(locate_root_data_decl(cPtr, sm, ctxt)),
m_dDeclCalleeOrOperation(dDeclOrOp),
m_terminalRoot(trm)
{
  sobject_base::m_data = split_string(sobject_base::m_data, ' ').back(); // from 'const int var' -> m_data is set to 'var'
  // Here the arguments are used only for the literal case
  this->add_this_data_use(trm);
}



sobject<obj::data_use>::sobject(const clang::IntegerLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm) :
sobject_base(cPtr, sm, ctxt),
m_dDeclRoot(nullptr),
m_dDeclCalleeOrOperation(dDeclOrOp),
m_terminalRoot(trm)
{
  this->add_this_data_use(trm);
}

sobject<obj::data_use>::sobject(const clang::FixedPointLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm) :
sobject_base(cPtr, sm, ctxt),
m_dDeclRoot(nullptr),
m_dDeclCalleeOrOperation(dDeclOrOp),
m_terminalRoot(trm)
{
  this->add_this_data_use(trm);
}

sobject<obj::data_use>::sobject(const clang::FloatingLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm) :
sobject_base(cPtr, sm, ctxt),
m_dDeclRoot(nullptr),
m_dDeclCalleeOrOperation(dDeclOrOp),
m_terminalRoot(trm)
{
  this->add_this_data_use(trm);
}

sobject<obj::data_use>::sobject(const clang::ImaginaryLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm) :
sobject_base(cPtr, sm, ctxt),
m_dDeclRoot(nullptr),
m_dDeclCalleeOrOperation(dDeclOrOp),
m_terminalRoot(trm)
{
  this->add_this_data_use(trm);
}

sobject<obj::data_use>::sobject(const clang::CharacterLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm) :
sobject_base(cPtr, sm, ctxt),
m_dDeclRoot(nullptr),
m_dDeclCalleeOrOperation(dDeclOrOp),
m_terminalRoot(trm)
{
  this->add_this_data_use(trm);
}

sobject<obj::data_use>::sobject(const clang::StringLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm) :
sobject_base(cPtr, sm, ctxt),
m_dDeclRoot(nullptr),
m_dDeclCalleeOrOperation(dDeclOrOp),
m_terminalRoot(trm)
{
  this->add_this_data_use(trm);
}

sobject<obj::data_use>::sobject(const clang::CXXBoolLiteralExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm) :
sobject_base(cPtr, sm, ctxt),
m_dDeclRoot(nullptr),
m_dDeclCalleeOrOperation(dDeclOrOp),
m_terminalRoot(trm)
{
  this->add_this_data_use(trm);
}

sobject<obj::data_use>::sobject(const clang::CXXNullPtrLiteralExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm) :
sobject_base(cPtr, sm, ctxt),
m_dDeclRoot(nullptr),
m_dDeclCalleeOrOperation(dDeclOrOp),
m_terminalRoot(trm)
{
  this->add_this_data_use(trm);
}





} // namespace bld::src


