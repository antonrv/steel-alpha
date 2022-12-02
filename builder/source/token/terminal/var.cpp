

#include "source/token/terminal/var.hpp"


#ifndef PARSER_TEST
#include "source/object/data/use.hpp"
#include "source/object/data/decl.hpp"
#endif // PARSER_TEST

namespace bld::src::pc {


void validate_name_string(const std::string& str, kind kindKind);

///////////////// VAR <--- TERMINAL

kind token<kind::var>::get_kind() const { return kind::var; }


token<kind::var>::token() :
  terminal()
{}

token<kind::var>::token(const std::string& is) :
  terminal(),
  m_name(is)
{
  validate_name_string(is, kind::var);
  // std::cout << "Created Var from string : " << this << ". " << this->get_pc_string() << ". This has data use : " << this->has_data_use() << '\n';
}

// token<kind::var>::token(const token& other) :
// terminal(other),
// m_name(other.m_name)
// {
//   std::cout << "Copied Var : " << this << ". " << this->get_pc_string() << " from other " << &other << " other has data use : " << other.has_data_use() << ". This has data use : " << this->has_data_use() << '\n';
// }

#ifdef PARSER_TEST

std::string token<kind::var>::get_pc_string() const {
  if (terminal::get_sign() == sign::neg) {
    return "(-" + this->m_name + ")";
  } else {
    return this->m_name;
  }
}

std::string token<kind::var>::get_unsigned_name() const {
  return this->m_name;
}

bool token<kind::var>::goes_after_than( const token<kind::var> * var ) const {
  // Lexicog on name
  return var->get_unsigned_name() < this->get_unsigned_name();
}

#else

// token<kind::var>::token(const std::string& is) : // DEPRECATE TODO
//   terminal()
// { }


std::string token<kind::var>::get_pc_string() const {

  std::string varName;
  if (this->has_data_use() and this->get_data_use()->has_root()) {
    varName = this->get_data_use()->get_root_data_decl()->get_variable_name();
  } else {
    varName = m_name;
  }
    
  if (terminal::get_sign() == sign::neg) {
    return "(-" + varName + ")";
  } else {
    return varName;
  }
}

std::string token<kind::var>::get_unsigned_name() const {
  return this->get_data_use()->get_root_data_decl()->get_variable_name();
}


bool token<kind::var>::goes_after_than( const token<kind::var> * var ) const {
  compare_base_source_objects opLess;
  return opLess( var->get_data_use(), this->get_data_use() );
}


#endif // PARSER_TEST

// Virtual
bool token<kind::var>::is_loop() const {
#ifndef PARSER_TEST
  if (terminal::has_data_use()) {
    return terminal::get_data_use()->on_loop_variable();
  }
#endif // PARSER_TEST
  return false;
}

// Virtual
const loop_var * token<kind::var>::get_loop_variable() const {
#ifndef PARSER_TEST
  // This return may match 'this' or not
  auto retLV = terminal::get_data_use()->get_root_data_decl()->get_loop_variable();

  // In any case, their underlying data decls of respective data uses must be the same
  if (retLV->get_data_use()->get_root_data_decl()->get_identifier() != this->get_data_use()->get_root_data_decl()->get_identifier()) {
    throw std::logic_error("data_decl mismatch in get_loop_variable : LV to return has : " + retLV->get_data_use()->get_root_data_decl()->get_identifier() + ". While this has a data use : " + this->get_data_use()->get_root_data_decl()->get_identifier());
  }

  return retLV;
#else
  throw std::logic_error("Unreachable. Expected call to override function. Otherwise previous is_loop() must have returned false");
  // return static_cast<const loop_var*>(this); Cannot do this, since here we don't know var <- loop_var derivation. Instead, we make this function virtual
#endif // PARSER_TEST
}

bool token<kind::var>::is_synth() const {
  return false;
}

bool token<kind::var>::is_raw() const {
  return false;
}


///////////////////////////////////// RT_VAR
synth_var::synth_var(std::string is) :
token<kind::var>(),
  m_name(is)
{}

std::string synth_var::get_pc_string() const {
  std::string retStr = "rt::" + m_name;
  if (terminal::get_sign() == sign::neg) {
    return "-" + retStr + "";
  } else {
    return retStr;
  }
}

bool synth_var::is_synth() const {
  return true;
}

///////////////////////////////////// RAW_STR
raw_str::raw_str(std::string is) :
synth_var(is)
{}

std::string raw_str::get_pc_string() const {
  return synth_var::m_name;
}

bool raw_str::is_raw() const {
  return true;
}


} // namespace bld::src::pc
