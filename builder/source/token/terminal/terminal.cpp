#include "source/token/terminal/terminal.hpp"

#include "source/token/multiple/offset.hpp"
#include "source/token/multiple/cs_list.hpp"
#include "source/token/multiple/address.hpp"
#include "source/token/terminal/var.hpp"

#ifndef PARSER_TEST
#include "source/object/data/use.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/function/definition.hpp"
#endif // PARSER_TEST

#include <stdexcept>

#include <iostream> // DBG XXX

namespace bld::src::pc {


///////////////
//
// INTERFACE
//
///////////////

// Used by kind::num and kind::var
void validate_name_string(const std::string& str, kind kindKind) {
  if (kindKind == kind::num or kindKind == kind::var) {
    if (str.find_first_of("+-*/") != std::string::npos) {
      throw std::logic_error("Char operator not allowed in piece constructor : " + str);
    }
  } else {
    // An expr, allow anything
  }
}


///////////////// TERMINAL

terminal::terminal() {}



terminal::terminal(sign s) :
m_sign(s)
{}


bool terminal::has_data_use() const {
#ifndef PARSER_TEST
  return (m_dataUse != nullptr);
#else
  return false;
#endif // PARSER_TEST
}


#ifndef PARSER_TEST
piece_context terminal::get_global_context() const {
  // Need to verify that has_data_use first
  if (this->has_data_use() and this->get_data_use()->has_root()) {
    return this->get_data_use()->get_root_data_decl()->get_global_context();
  }
  return UniversalCtxt;
}

piece_context terminal::get_local_context() const {
  // Need to verify that has_data_use first
  if (this->has_data_use() and this->get_data_use()->has_root()) {
    return this->get_data_use()->get_local_context();
  }
  return UniversalCtxt;
}

void terminal::set_data_use(cso_t<obj::data_use> dUse) {
  if (m_dataUse != nullptr) {
    unsigned kindInt = static_cast<unsigned>( this->get_kind() );
    // std::cout << "This ptr terminal : " << this << ". Pck : " << this->get_kind() << '\n';
    throw std::logic_error("Data use already set in termina. Already set : " + this->get_pc_string() + " kind" + std::to_string(kindInt) + " input dUse : " + dUse->get_identifier()/* + ". Existing : " + m_dataUse->get_identifier()*/);
    // throw std::logic_error("Data use already set in terminal. Already set : " + m_dataUse->get_identifier() + ". Received : " + dUse->get_identifier());
  }

  // std::cout << "Binding terminal \'"<< this->get_pc_string() << "\'" << this->get_kind() << ". ptr." << this << " with PARENT: ptr " << this->get_parent() << " and kind : " << this->get_parent()->get_kind() << " , against data_use " << dUse << ". " << dUse->get_identifier() << " : " << (dUse->has_root() ? dUse->get_root_data_decl()->get_variable_name() : dUse->get_data()) << '\n';

  m_dataUse = dUse;
}


cso_t<obj::data_use>
terminal::get_data_use() const {
  if (not this->has_data_use()) {
    throw std::logic_error("Cannot get_data_use in terminal. " + this->get_pc_string());
  }
  return m_dataUse;
}


bool terminal::find_data_use(cso_t<obj::data_use> dUse) const {
  if (m_dataUse == nullptr) {
    // std::cout << "Data use NOT set : " << this << " : " << this->get_pc_string() << '\n';
    return false;
  } else {
    // std::cout << "Data use SET : " << this << " : " << this->get_pc_string() << '\n';
    return (dUse->get_identifier() == m_dataUse->get_identifier());
  }
}


#else

piece_context terminal::get_global_context() const {
  return UniversalCtxt;
}

piece_context terminal::get_local_context() const {
  return UniversalCtxt;
}


#endif // PARSER_TEST


vec_cpiece_t terminal::gather_pieces_satisfying( pred_fun_t&& satisfyLambda ) const {
  vec_cpiece_t retVec;
  if (satisfyLambda(this)) {
    retVec.push_back(this);
  }
  return retVec;
}

cpiece_t terminal::find_piece_satisfying( pred_fun_t satisfyLambda ) const {
  if (satisfyLambda(this)) {
    return this;
  }
  return nullptr;
}

bool terminal::is_multiple() const { return false; }
bool terminal::is_terminal() const { return true; }
bool terminal::is_arith() const { return true; }
bool terminal::is_rt() const { return false; }

sign terminal::get_sign() const {
  return m_sign;
}

void terminal::flip_sign() {
  if (m_sign == sign::pos) {
    m_sign = sign::neg;
  } else {
    m_sign = sign::pos;
  }
}


std::vector<terminal_t> terminal::edit_flatten_terminals() {
  return {this};
}

std::vector<cterminal_t> terminal::get_flatten_terminals() const {
  return {this};
}


vec_piece_t terminal::edit_tokens() {
  return {this};
}

vec_cpiece_t terminal::get_tokens() const {
  return {this};
}

bool terminal::is_direct_call_argument() const {
  // Parent is kind::call --> true
  if (this->get_parent()->get_kind() == kind::call) {
    // std::cout << "\tTERMINAL : " << this->get_pc_string() << " direct Call Arg\n";
    return true;
  }
  // Parent is kind::cs_list --> forward to it
  if (this->get_parent()->get_kind() == kind::cs_list) {
    auto cslistParent = static_cast<ctoken_t<kind::cs_list>>(this->get_parent());
    // std::cout << "\tTERMINAL : " << this->get_pc_string() << " direct. parent is CS_LIST. FW\n";
    return cslistParent->is_direct_call_argument();
  }
  // Parent is kind::offset --> forward to it if this is the base of the offset
  if (this->get_parent()->get_kind() == kind::offset) {
    auto offsetParent = static_cast<ctoken_t<kind::offset>>(this->get_parent());
    // std::cout << "\tTERMINAL : " << this->get_pc_string() << " direct. parent is OFFSET. FW\n";
    return offsetParent->get_base() == this and offsetParent->is_direct_call_argument();
  } else if (this->get_parent()->get_kind() == kind::address) {
    auto addressParent = static_cast<ctoken_t<kind::address>>(this->get_parent());
    return addressParent->is_direct_call_argument();
  }
  // std::cout << "\tTERMINAL : " << this->get_pc_string() << " direct parent: " << this->get_parent()->get_kind() << " parent string : " << this->get_parent()->get_pc_string() << "\n";
  return false;
}

bool terminal::is_direct_operator_argument() const {
  // Parent is kind::binop --> true
  if (this->get_parent()->get_kind() == kind::binop) {
    return true;
  }

  // Parent is kind::offset --> forward to it if this is the base of the offset
  if (this->get_parent()->get_kind() == kind::offset) {
    auto offsetParent = static_cast<ctoken_t<kind::offset>>(this->get_parent());
    return offsetParent->get_base() == this and offsetParent->is_direct_operator_argument();
  }
  return false;

}

} // namespace bld::src::pc
