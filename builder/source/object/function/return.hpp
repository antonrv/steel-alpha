#ifndef STEEL_COMPILER_ELEMENT_FUNCTION_RETURN_HPP
#define STEEL_COMPILER_ELEMENT_FUNCTION_RETURN_HPP

#include "source/sequences.hpp"

#include "source/object/base.hpp"

namespace clang {
  class ReturnStmt;
  class SourceManager;
  class ASTContext;
} // namespace clang



namespace bld::src {


template <obj CtgK>
class sobject;

template <>
class sobject<obj::fun_ret> : public sobject_base {
public:
  static constexpr obj sobject_kind = obj::fun_ret;

  static constexpr opt_kind log_record = opt_kind::log_fun_ret_record;
private:

  using super_type = sobject_base;

  cso_t<obj::fun_ctxt> m_functionCtxt = nullptr;

public:

  // General constructor
  sobject(const clang::ReturnStmt* rs, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

  ~sobject() final override;

  virtual obj get_obj() const override;

  virtual void print(std::ostream& os) const final override;

  virtual std::string serial() const final override;

  cso_t<obj::fun_ctxt> get_parent_function_context() const;

   void set_parent_function_context(cso_t<obj::fun_ctxt> fCtxt);
};

} // namespace bld::src

#endif // STEEL_COMPILER_ELEMENT_FUNCTION_RETURN_HPP
