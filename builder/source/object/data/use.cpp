#include "source/object/data/use.hpp"

#include "source/object/base.hpp"

#include "source/object/data/decl.hpp"
#include "source/object/function/call.hpp"
#include "source/object/function/loop.hpp"


#include "source/object/function/binary.hpp"
#include "source/token/terminal/terminal.hpp"
#include "source/token/multiple/multiple.hpp"

#include "source/object/state/def.hpp"


namespace bld::src {

///////////////////////////////////////////
//////////////
////////////// BASE STUFF
//////////////
///////////////////////////////////////////


sobject<obj::data_use>::~sobject() {}

obj sobject<obj::data_use>::get_obj() const {
  return obj::data_use;
}


void sobject<obj::data_use>::print(std::ostream& os) const {
  super_type::print(os);

  os << "\tdata decl ROOT : " << m_dDeclRoot << '\n';
  os << "\tAccess : " << this->get_access() << '\n';
  if (m_dDeclCalleeOrOperation != nullptr) {
    os << "\tdata decl CALLEE/OPERATION : " << m_dDeclCalleeOrOperation->get_obj() << " : " << m_dDeclCalleeOrOperation << '\n';
  }
  if (m_dDeclRoot == nullptr) {
    os << "\tLiteral : " << sobject_base::m_data << '\n';
  }
  os << "\tTerminal : " << m_terminalRoot->get_pc_string() << '\n';
  // os << "\tPointer terminals : ";
  // for (auto term : m_pointerTerminals) { os << term->get_pc_string() << ";"; }
  os << '\n';
  os << "\tDirect call argument ? " << this->is_direct_call_argument() << '\n';
  os << "\tDirect operator argument ? " << this->is_direct_operator_argument() << '\n';
  os << "\tOn address ? " << this->on_address() << '\n';
  os << "\tOn ptr address ? " << this->on_ptr_address() << '\n';
  os << "\tOn loop variable ? " << this->on_loop_variable() << '\n';
  os << "\tRequire emit backend : " << this->require_emit_backend() << '\n';
  os << "\tSingle access piece : " << this->get_single_access_piece()->get_pc_string() << '\n';
  if (this->has_mem_access()) {
    os << "\tMem access kind : " << this->get_mem_access()->get_mem_access_kind() << '\n';
  } else {
    os << "\tNo mem access\n";
  }
}

///////////////////////////////////////////
//////////////
////////////// CORE STUFF
//////////////
///////////////////////////////////////////


bool sobject<obj::data_use>::has_root() const {
  return m_dDeclRoot != nullptr;
}

cso_t<obj::data_decl>
sobject<obj::data_use>::get_root_data_decl() const {
  if (not this->has_root()) {
    throw std::logic_error("Data use not associated to a root data decl : " + this->get_identifier());
  }

  return m_dDeclRoot;
}

bool sobject<obj::data_use>::has_callee() const {
  if (m_dDeclCalleeOrOperation != nullptr) {
    return m_dDeclCalleeOrOperation->get_obj() == obj::data_decl;
  } else {
    return false;
  }
}

cso_t<obj::fun_call> sobject<obj::data_use>::get_function_call() const {

  if (not this->is_direct_call_argument()) {
    throw std::logic_error("Cannot retrieve function call of use without callee");
  }

  auto fCall = state<obj::fun_call>::get_containing( this );
  if (fCall == nullptr) {
    throw std::logic_error("fCall of dUse not found (make_coro_raii)");
  }

  return fCall;
}


bool sobject<obj::data_use>::is_direct_call_argument() const {
  if (not this->has_callee()) {
    // std::cout << "DATA_USE : " << this->get_identifier() << " does NOT have callee\n";
    return false;
  }
  // std::cout << "DATA_USE : " << this->get_identifier() << " is_direct_call_arg : " << m_terminalRoot->is_direct_call_argument() << "\n";
  return m_terminalRoot->is_direct_call_argument();
}

bool sobject<obj::data_use>::is_direct_operator_argument() const {
  if (not this->has_operation()) {
    return false;
  }
  return m_terminalRoot->is_direct_operator_argument();
}

bool sobject<obj::data_use>::is_direct_call_argument_within_loop() const {

  if (this->is_direct_call_argument()) {
    return (state<obj::fun_loop>::get_containing(this) != nullptr);
  }
  return false;
}

cso_t<obj::data_decl>
sobject<obj::data_use>::get_callee_data_decl() const {
  if (not this->has_callee()) {
    throw std::logic_error("Data use not associated to a callee data decl : " + this->get_identifier());
  }
  return static_cast<const sobject<obj::data_decl>*>(m_dDeclCalleeOrOperation);
}

bool sobject<obj::data_use>::has_operation() const {
  if (m_dDeclCalleeOrOperation != nullptr) {
    return m_dDeclCalleeOrOperation->get_obj() == obj::bin_op;
  } else {
    return false;
  }
}

cso_t<obj::bin_op> sobject<obj::data_use>::get_operation() const {
  if (not this->has_operation()) {
    throw std::logic_error("Cannot get_operation on data_use. Query has_operation first");
  }
  return static_cast<const sobject<obj::bin_op>*>(m_dDeclCalleeOrOperation);
}

pc::cterminal_t sobject<obj::data_use>::get_terminal() const {
  return m_terminalRoot;
}


access_kind sobject<obj::data_use>::get_access() const {



  // root terminal is a pc::kind::var
  if (not this->has_root()) {
    // A literal
    return access_kind::read_only;
  }

  if (m_dDeclCalleeOrOperation->get_obj() == obj::bin_op) {

    if (not m_terminalRoot->is_direct_operator_argument()) {
      return access_kind::read_only;
    }

    return static_cast<const sobject<obj::bin_op>*>(m_dDeclCalleeOrOperation)->get_operator_piece()->get_use_access( this );

  } else if (m_dDeclCalleeOrOperation->get_obj() == obj::data_decl) {

    if (not m_terminalRoot->is_direct_call_argument()) {
      return access_kind::read_only;
    }

    return static_cast<const sobject<obj::data_decl>*>(m_dDeclCalleeOrOperation)->get_allowed_access();

  } else {
    throw std::logic_error("Could not retrieve access from dDeclOrOperation in data_use");
  }

}


} // namespace bld::src
