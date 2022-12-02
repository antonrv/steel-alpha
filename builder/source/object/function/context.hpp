#ifndef STEEL_COMPILER_ELEMENT_FUNCTION_CONTEXT_HPP
#define STEEL_COMPILER_ELEMENT_FUNCTION_CONTEXT_HPP

#include "source/sequences.hpp"

#include "source/object/base.hpp"

namespace clang {
  class CompoundStmt;
  class SourceManager;
  class ASTContext;
} // namespace clang



namespace bld::src {


template <obj CtgK>
class sobject;

// UNIFY WITH fun_loop TODO
// UNIFY WITH fun_loop TODO
// UNIFY WITH fun_loop TODO

template <>
class sobject<obj::fun_ctxt> : public sobject_base {
public:
  static constexpr obj sobject_kind = obj::fun_ctxt;

  static constexpr opt_kind log_record = opt_kind::log_fun_ctxt_record;
private:

  using super_type = sobject_base;

  cso_t<obj::fun_ctxt> m_parentFunctionCtxt = nullptr;

public:

  // General constructor
  sobject(const clang::CompoundStmt* rs, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

  ~sobject() final override;

  virtual obj get_obj() const override;

  virtual void print(std::ostream& os) const final override;

  std::string serial() const final override;

  cso_t<obj::fun_ctxt> get_parent_function_context() const;

  void set_parent_function_context(cso_t<obj::fun_ctxt> fCtxt);

  bool is_top() const;
};

} // namespace bld::src

#endif // STEEL_COMPILER_ELEMENT_FUNCTION_CONTEXT_HPP
