
#include "source/object/function/definition.hpp"

#include "source/object/function/call.hpp"

#include "source/object/data/decl.hpp"

#include "source/object/function/context.hpp"

#include "source/object/state/set.hpp"
#include "source/object/state/def.hpp"



#include <algorithm>

namespace bld::src {

sobject<obj::fun_def>::~sobject() {}

obj sobject<obj::fun_def>::get_obj() const {
  return obj::fun_def;
}

void sobject<obj::fun_def>::print(std::ostream& os) const {
  super_type::print(os);

  os << "\tFun name : " << m_functionName << '\n';
  os << "\t# Arguments : " << m_arguments.size() << '\n';
  os << "\tArgument return : " << m_argumentReturn << '\n';
  os << "\t# Body calls : " << m_bodyCalls.size() << '\n';
  os << "\t# Extern calls : " << m_externCalls.size() << '\n';
  // os << "\t# Body returns : " << m_bodyReturns.size() << '\n';
  
  // do nothing
}

void sobject<obj::fun_def>::set_task() {
  if (this->is_task()) {
    throw std::logic_error("Cannot set_task. Already set");
  }
  m_ownedTask = std::make_unique< task >( this );
}

void sobject<obj::fun_def>::set_task(const std::string& appId, const std::string& appImpl) {
  if (this->is_task()) {
    throw std::logic_error("Cannot set_task. Already set");
  }
  m_ownedTask = std::make_unique< task >( this, appId, appImpl );
}

bool sobject<obj::fun_def>::is_task() const {
  return m_ownedTask.get() != nullptr;
}

task_t sobject<obj::fun_def>::edit_task() {
  if (not this->is_task()) {
    throw std::logic_error("Cannot edit_task. Not set");
  }
  return m_ownedTask.get();
}

ctask_t sobject<obj::fun_def>::get_task() const {
  if (not this->is_task()) {
    throw std::logic_error("Cannot get_task. Not set");
  }
  return m_ownedTask.get();
}


void sobject<obj::fun_def>::add_argument(so_t<obj::data_decl> dDecl) {
  m_arguments.insert( dDecl );
}

set_cso_t<obj::data_decl>
sobject<obj::fun_def>::get_arguments() const {
  
  set_cso_t<obj::data_decl> retSet;

  std::copy(std::begin(m_arguments), std::end(m_arguments), std::inserter(retSet, std::end(retSet)));

  return retSet;
}

so_t<obj::data_decl> 
sobject<obj::fun_def>::edit_argument(unsigned i) {
  return get_in_position(m_arguments, i);
}

cso_t<obj::data_decl> 
sobject<obj::fun_def>::get_argument(unsigned i) const {
  return get_in_position(m_arguments, i);
}

unsigned sobject<obj::fun_def>::get_argument_id( cso_t<obj::data_decl> dDecl ) const {
  return get_position( m_arguments, dDecl );
}

void sobject<obj::fun_def>::set_return_argument(so_t<obj::data_decl> dDecl) {
  m_argumentReturn = dDecl;
}

so_t<obj::data_decl>
sobject<obj::fun_def>::get_return_argument() const {
  return m_argumentReturn;
}


unsigned sobject<obj::fun_def>::get_call_id( cso_t<obj::fun_call> fCall) const {
  return get_position( m_bodyCalls, fCall );
}

void sobject<obj::fun_def>::add_body_call( so_t<obj::fun_call> fCall) {
  m_bodyCalls.insert( fCall );
}

set_cso_t<obj::fun_call>
sobject<obj::fun_def>::get_body_calls() const {

  set_cso_t<obj::fun_call> retSet;

  std::copy(std::begin(m_bodyCalls), std::end(m_bodyCalls), std::inserter(retSet, std::end(retSet)));

  return retSet;
}

void sobject<obj::fun_def>::add_extern_call( so_t<obj::fun_call> fCall) {
  m_externCalls.insert( fCall );
}

set_cso_t<obj::fun_call>
sobject<obj::fun_def>::get_extern_calls() const {

  set_cso_t<obj::fun_call> retSet;

  std::copy(std::begin(m_externCalls), std::end(m_externCalls), std::inserter(retSet, std::end(retSet)));

  return retSet;
}


bool sobject<obj::fun_def>::does_call( cso_t<obj::fun_def> fDef ) const {
  return (this->get_call_to(fDef) != nullptr);
}

cso_t<obj::fun_call> sobject<obj::fun_def>::get_call_to( cso_t<obj::fun_def> fDef ) const {

  auto thisCalls = this->get_body_calls();

  auto maybeCalleeCalls = fDef->get_extern_calls();

  set_cso_t<obj::fun_call> commonCalls;

  std::set_intersection(
    std::begin(thisCalls), std::end(thisCalls),
    std::begin(maybeCalleeCalls), std::end(maybeCalleeCalls),
    std::inserter( commonCalls, std::end(commonCalls) ),
    [] (cso_t<obj::fun_call> fCallLhs, cso_t<obj::fun_call> fCallRhs) {
      // std::cout << "Comparing calls : " << fCallLhs->get_identifier() << " with " << fCallRhs->get_identifier() << '\n';
      return fCallLhs->get_identifier() < fCallRhs->get_identifier();
    });

  if (not commonCalls.empty()) {
    // Emit Warning if several TODO
    return *commonCalls.begin();
  } else {
    return nullptr;
  }
}



const std::string& 
sobject<obj::fun_def>::get_function_name() const {
  return m_functionName;
}

cso_t<obj::data_decl>
sobject<obj::fun_def>::get_data_decl(unsigned argId) const {
  auto count = 0u;
  for (auto iter = m_arguments.begin(); iter != m_arguments.end(); iter++, count++) {
    if (count == argId) {
      return static_cast<cso_t<obj::data_decl>>(*iter);
    }
  }
  throw std::logic_error("Cannot get parsed type of parameter of kdef " + std::to_string(argId));
}

cso_t<obj::fun_ctxt> sobject<obj::fun_def>::get_body_context() const {

  return state<obj::fun_ctxt>::get_contained_by( this );
}

} // namespace bld::src
