#include "source/object/function/return.hpp"



namespace bld::src {

sobject<obj::fun_ret>::~sobject() {}

obj sobject<obj::fun_ret>::get_obj() const {
  return obj::fun_ret;
}

void sobject<obj::fun_ret>::print(std::ostream& os) const {
  super_type::print(os);

  os << "\tFun ctxt : " << m_functionCtxt << '\n';
  // do nothing
}

cso_t<obj::fun_ctxt> sobject<obj::fun_ret>::get_parent_function_context() const {
  return m_functionCtxt;
}

void sobject<obj::fun_ret>::set_parent_function_context(cso_t<obj::fun_ctxt> fCtxt) {
  m_functionCtxt = fCtxt;
}


} // namespace bld::src
