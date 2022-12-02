#ifndef STEEL_COMPILER_ELEMENT_FUNCTION_ARGUMENT_HPP
#define STEEL_COMPILER_ELEMENT_FUNCTION_ARGUMENT_HPP

#include "source/sequences.hpp"

#include "source/object/data/use.hpp"

#include "source/token/terminal/loopvar.hpp"
#include "source/token/region/affine/guard.hpp"

#include <iostream>

namespace clang {
  class VarDecl;
  class SourceManager;
  class ASTContext;
  class QualType;
  class ForStmt;
} // namespace clang

namespace bld::src {

template <obj CtgK>
class sobject;

// A data declaration that resides in a function
// * Declared as a parameter
// * Declared as a temporary in the function body

struct compare_use_same_callee {
  bool operator()(cso_t<obj::data_use> dUseA, cso_t<obj::data_use> dUseB) const;
};


template <>
class sobject<obj::data_decl> : public sobject_base {
public:
  static constexpr obj sobject_kind = obj::data_decl;

  static constexpr opt_kind log_record = opt_kind::log_data_decl_record;

private:

  using super_type = sobject_base;

  decl_kind m_declarationKind;

  std::string m_variableName;
  std::string m_typeName;
  std::string m_translationType;
  qual m_typeQual;
  indir m_indirect;
  qual m_indirectQual;
  access_kind m_allowedAccess;

  set_so_t<obj::data_use> m_dataUses;

  // std::unique_ptr<pc::loop_variable> m_ownedLoopVariable = nullptr;
  pc::own_cloopvar_t m_ownedLoopVar = nullptr;

  pc::own_cguard_t m_ownedGuard = nullptr;


  void initialize_fields();

  void check_valid() const;

  void normalize_original();

  set_so_t<obj::data_use>& edit_data_uses();

public:

  sobject(const clang::VarDecl* declStmt, const clang::SourceManager& sm, const clang::ASTContext & ctxt);


  sobject(const clang::SourceRange& sr, const clang::SourceManager& sm, const clang::ASTContext& ctxt, const clang::QualType retType);

  virtual ~sobject() override;

  virtual obj get_obj() const override;

  virtual void print(std::ostream& os) const final override;

  std::string serial() const final override;

  decl_kind get_decl_kind() const;

  void set_decl_kind(decl_kind dk);

  const std::string& get_type_name() const;

  std::string get_qualified_type_name() const;

  const std::string& get_variable_name() const;
  std::string get_wrap_variable_name() const;

  const std::string& get_translation_type() const;

  qual get_type_qual() const;

  indir get_indirect() const;

  qual get_indirect_qual() const;

  access_kind get_allowed_access() const;

  void add_data_use(sobject<obj::data_use> * drAcc);

  // void update_data_use(sobject<obj::data_use> * dUseToReplace, sobject<obj::data_use> * newDataUse);

  set_cso_t<obj::data_use> get_data_uses() const;

  cso_t<obj::fun_def> get_root_function_definition() const;

public:


////////////////////////// LOOP-RELATED STUFF

  bool check_loop_inner_properties() const;

  void maybe_detect_loop_variable();

  pc::cloopvar_t get_loop_variable( ) const;

  // template <pc::lv_trait LVTrait>
  // pc::opkind get_loop_pc::opkind() const;

  bool has_guard() const;

  pc::cguard_t get_guard() const;
  void set_guard();

  bool require_guard() const;

  cso_t<obj::fun_def> get_global_context() const;
  csob_t get_local_context() const;


  pc::cpiece_t get_initialization() const;

  bool is_set_once() const;
public:

////////////////////////// WRAP-RELATED STUFF

  bool require_wrap() const;
};


} // namespace bld::src

#endif // STEEL_COMPILER_ELEMENT_FUNCTION_ARGUMENT_HPP
