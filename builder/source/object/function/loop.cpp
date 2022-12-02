#include "source/object/function/loop.hpp"


namespace bld::src {

sobject<obj::fun_loop>::~sobject() {}

obj sobject<obj::fun_loop>::get_obj() const {
  return obj::fun_loop;
}


void sobject<obj::fun_loop>::set_parent_loop(cso_t<obj::fun_loop> fLoop) {
  if (m_parentLoop != nullptr) {
    throw std::logic_error("Function parent loop already set in loop");
  }
  m_parentLoop = fLoop;

}


loop sobject<obj::fun_loop>::get_loop_kind() const {
  return m_loopKind;
}

bool sobject<obj::fun_loop>::is_top() const {
  return m_parentLoop == nullptr;
}

void sobject<obj::fun_loop>::print(std::ostream& os) const {
  super_type::print(os);

  os  << "\tKind : " << m_loopKind << '\n'
      << "\tTop ? : " << this->is_top() << '\n';
  if (not this->is_top()) {
    os << "\tParent loop : " << m_parentLoop << '\n';
  }
}


} // namespace bld::src
