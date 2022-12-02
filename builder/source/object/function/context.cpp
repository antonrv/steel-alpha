#include "source/object/function/context.hpp"



namespace bld::src {

sobject<obj::fun_ctxt>::~sobject() {}

obj sobject<obj::fun_ctxt>::get_obj() const {
  return obj::fun_ctxt;
}

void sobject<obj::fun_ctxt>::print(std::ostream& os) const {
  super_type::print(os);

  os << "\tParent context : " << m_parentFunctionCtxt << '\n';
}

cso_t<obj::fun_ctxt> sobject<obj::fun_ctxt>::get_parent_function_context() const {
  return m_parentFunctionCtxt;
}

void sobject<obj::fun_ctxt>::set_parent_function_context(cso_t<obj::fun_ctxt> fCtxt) {
  m_parentFunctionCtxt = fCtxt;
}

bool sobject<obj::fun_ctxt>::is_top() const {
  return m_parentFunctionCtxt == nullptr;
}

} // namespace bld::src
