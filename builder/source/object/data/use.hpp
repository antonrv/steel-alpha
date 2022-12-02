#ifndef STEEL_CMP_ELEMENT_DATA_USE_HPP
#define STEEL_CMP_ELEMENT_DATA_USE_HPP

#include "source/object/base.hpp"

#include "source/sequences.hpp"

#include "source/sequences.hpp"

#include "source/token/terminal/terminal.hpp"
#include "source/token/region/affine/access.hpp"

#include "source/object/function/binary.hpp"

namespace bld::src {

  class piece;

} // namespace bld::src



namespace bld::src {


template <obj CtgK>
class sobject;


// This represents an access associated to a data_decl
template <>
class sobject<obj::data_use> : public sobject_base {
public:

  static constexpr obj sobject_kind = obj::data_use;

  static constexpr opt_kind log_record = opt_kind::log_data_use_record;

private:

  const so_t<obj::data_decl> m_dDeclRoot = nullptr; // Always set to non-null as long as it is not a literal


  const csob_t m_dDeclCalleeOrOperation = nullptr; // Not null if this use lies in a function call

  pc::cterminal_t const m_terminalRoot = nullptr; // Always not null

  pc::own_caccess_t m_ownedMemAccess;

private:

  using super_type = sobject_base;

  void add_this_data_use(pc::terminal_t term);

public:

///////////////////////////////////////////
//////////////
////////////// CONST/DEST STUFF
//////////////
///////////////////////////////////////////

  sobject(const clang::DeclRefExpr * cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm);
  sobject(const clang::UnaryOperator * cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm);
  // DEPRECATE TODO
  sobject(const clang::DeclStmt * cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm);

  sobject(const clang::IntegerLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm);
  sobject(const clang::FixedPointLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm);
  sobject(const clang::FloatingLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm);
  sobject(const clang::ImaginaryLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm);
  sobject(const clang::CharacterLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm);
  sobject(const clang::StringLiteral* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm);
  sobject(const clang::CXXBoolLiteralExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm);
  sobject(const clang::CXXNullPtrLiteralExpr* cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclOrOp, pc::terminal_t trm);


  sobject( const std::string& serialStr, const serial_map_t& serialMap );

  virtual ~sobject();

///////////////////////////////////////////
//////////////
////////////// BASE STUFF
//////////////
///////////////////////////////////////////

  virtual obj get_obj() const override;

  virtual void print(std::ostream& os) const final override;


///////////////////////////////////////////
//////////////
////////////// CORE STUFF
//////////////
///////////////////////////////////////////

  cso_t<obj::data_decl> get_root_data_decl() const;

  cso_t<obj::data_decl> get_callee_data_decl() const;

  cso_t<obj::bin_op> get_operation() const;

  cso_t<obj::fun_call> get_function_call() const;

  pc::cterminal_t get_terminal() const;


  std::string serial() const final override;

  bool has_root() const;

private:
  bool has_callee() const;

  bool has_operation() const;
public:

  bool is_direct_call_argument() const;
  bool is_direct_operator_argument() const;

  bool is_direct_call_argument_within_loop() const;

  access_kind get_access() const;


  csob_t get_local_context() const;
///////////////////////////////////////////
//////////////
////////////// LOOP VARIABLE STUFF
//////////////
///////////////////////////////////////////


  bool on_loop_variable() const;

private:


  pc::own_cpiece_t get_single_access_piece() const;


public:

  void set_mem_access();

  bool has_mem_access() const;

  pc::caccess_t get_mem_access() const;


public:


  bool on_address() const;  // (is_indirect_ref_arg or is_task_ref_arg) and access_kind is not init;
  bool on_ptr_address() const;  // (is_indirect_ref_arg or is_task_ref_arg) and access_kind is not init;

  bool on_callee_address() const; // Is a pointer and memory address is altered in the callee

  bool is_task_ref_argument() const; // The callee dDecl is a ref or a ptr

  bool is_indirect_ref_argument() const; // The root dDecl is a pointer or a ref TODO
  bool is_indirect_ptr() const; // The root dDecl is a pointer

  bool is_callee_arg_copy() const;
  bool is_callee_arg_ref() const;
  bool is_callee_arg_ptr() const;


///////////////////////////////////////////
//////////////
////////////// TRANSLATION STUFF
//////////////
///////////////////////////////////////////

  bool require_emit_backend() const;

};

} // namespace bld::src

#endif // STEEL_CMP_ELEMENT_DATA_USE_HPP
