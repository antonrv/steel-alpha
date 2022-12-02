#include "source/object/function/call.hpp"

#include "source/object/function/definition.hpp"
#include "source/object/data/use.hpp"


namespace bld::src {


sobject<obj::fun_call>::~sobject() {}

obj sobject<obj::fun_call>::get_obj() const {
  return obj::fun_call;
}

void sobject<obj::fun_call>::print(std::ostream& os) const {
  super_type::print(os);

  os << "\tCallee : " << m_callee << '\n';
  os << "\tCaller : " << m_caller << '\n';
  os << "\tPiece : " << m_callPieceRoot->get_pc_string() << '\n';
}



cso_t<obj::fun_def> sobject<obj::fun_call>::get_caller() const {
  return m_caller;
}

cso_t<obj::fun_def> sobject<obj::fun_call>::get_callee() const {
  return m_callee;
}

pc::ctoken_t<pc::kind::call> sobject<obj::fun_call>::get_call_piece() const {
  return m_callPieceRoot.get();
}


std::string sobject<obj::fun_call>::get_app_call_translation() const {

  auto callId = m_caller->get_call_id(this);

  auto callerAsTask = m_caller->get_task();
  auto calleeAsTask = m_callee->get_task();

  return callerAsTask->get_app_implementation() + "_" + calleeAsTask->get_app_identifier() + "_" + std::to_string(callId);
}

} // namespace bld::src

