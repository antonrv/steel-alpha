#ifndef STEEL_COMPILER_ELEMENT_FUNCTION_LOOP_HPP
#define STEEL_COMPILER_ELEMENT_FUNCTION_LOOP_HPP

#include "source/object/base.hpp"

#include "source/sequences.hpp"

#include "source/sequences.hpp"


namespace bld::src {


template <obj CtgK>
class sobject;

// UNIFY WITH fun_ctxt TODO
// UNIFY WITH fun_ctxt TODO
// UNIFY WITH fun_ctxt TODO

template <>
class sobject<obj::fun_loop> : public sobject_base {
public:
  static constexpr obj sobject_kind = obj::fun_loop;

  static constexpr opt_kind log_record = opt_kind::log_fun_loop_record;

private:

  using super_type = sobject_base;

  const loop m_loopKind = loop::undefined;

  cso_t<obj::fun_loop> m_parentLoop = nullptr;


public:

  // General constructor
  sobject(const clang::ForStmt* stmtPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

  virtual ~sobject() override;

  virtual obj get_obj() const override;

  virtual void print(std::ostream& os) const final override;

  std::string serial() const final override;

  void set_parent_loop(cso_t<obj::fun_loop> fLoop);

  loop get_loop_kind() const;

  bool is_top() const;

};


} // namespace bld::src

#endif // STEEL_COMPILER_ELEMENT_FUNCTION_LOOP_HPP
