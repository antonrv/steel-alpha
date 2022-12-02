
#include "source/object/data/decl.hpp"

#include "source/object/function/definition.hpp"


// Needs wrapping
#include "source/object/data/use.hpp"

#include "source/token/terminal/terminal.hpp"
#include "source/token/terminal/var.hpp"
#include "source/token/multiple/offset.hpp"


#include "source/object/state/def.hpp"

#include <iostream>

namespace bld::src {

// public interface

sobject<obj::data_decl>::~sobject() {}

obj sobject<obj::data_decl>::get_obj() const {
  return obj::data_decl;
}

decl_kind sobject<obj::data_decl>::get_decl_kind() const {
  return m_declarationKind;
}

void sobject<obj::data_decl>::print(std::ostream& os) const {
  super_type::print(os);

  os << "\tType token : " << m_typeName << '\n'
      << "\tType qual : " << m_typeQual << '\n'
      << "\tIndirect token : " << m_indirect << '\n'
      << "\tIndir qual : " << m_indirectQual << '\n'
      << "\tAllowed access : " << m_allowedAccess << '\n'
      << "\tVar name : " << m_variableName << '\n'
      << "\tDecl kind : " << m_declarationKind << '\n'
      << "\t# data uses : " << m_dataUses.size() << '\n';

  for (auto dUse : m_dataUses) {
    os << "\t\t" << dUse << " : " << dUse->get_obj() << '\n';
  }

  
  // os << "\tOwned loop variable : " << m_ownedLoopVariable.get() << '\n';

  // if (m_ownedLoopVariable.get() != nullptr) {
  //   m_ownedLoopVariable->print(os);
  // }
}

void sobject<obj::data_decl>::set_decl_kind(decl_kind dk) {
  if (dk == decl_kind::relaxed_fargument or dk == decl_kind::make_implicit) {
    if (m_declarationKind != decl_kind::fargument) {
      throw std::logic_error("Cannot set decl kind to relaxed_fargument on " + std::string(util::enum_convert<decl_kind>::to_string_rt(m_declarationKind)));
    }
  } else {

    throw std::logic_error("Unexpected decl kind to set " + std::string(util::enum_convert<decl_kind>::to_string_rt(dk)));
  }
  m_declarationKind = dk;
}

const std::string& sobject<obj::data_decl>::get_type_name() const {
  return m_typeName;
}

std::string sobject<obj::data_decl>::get_qualified_type_name() const {
  return (m_typeQual == qual::cnst ? "const " : "") + m_typeName;
}

const std::string& sobject<obj::data_decl>::get_variable_name() const {
  return m_variableName;
}
std::string sobject<obj::data_decl>::get_wrap_variable_name() const {
  return "wrap_" + this->get_variable_name();
}
const std::string& sobject<obj::data_decl>::get_translation_type() const {
  return m_translationType;
}

qual sobject<obj::data_decl>::get_type_qual() const {
  return m_typeQual;
}
indir sobject<obj::data_decl>::get_indirect() const {
  return m_indirect;
}
qual sobject<obj::data_decl>::get_indirect_qual() const {
  return m_indirectQual;
}
access_kind sobject<obj::data_decl>::get_allowed_access() const {
  return m_allowedAccess;
}

void sobject<obj::data_decl>::add_data_use(so_t<obj::data_use> dUse) {
  m_dataUses.insert( dUse );
}

// void sobject<obj::data_decl>::update_data_use(so_t<obj::data_use> dUseToReplace, so_t<obj::data_use> newDataUse) {
//   state::erase_copy( m_dataUses, dUseToReplace);
//   this->add_data_use(newDataUse);
// }



//
//
//
// private interface for member initialization
//
//
//

static
void clean_type(std::string& line) {
  const char * specChars = " ";
  const auto lineSize = std::string(specChars).size();
  for (auto id = 0u; id < lineSize; ++id) {
    // line.erase(std::remove(line.begin(), line.end(), &(specChars[id])), line.end());
    line.erase(std::remove(line.begin(), line.end(), specChars[id]), line.end());
  }
}

static
std::tuple<std::string, qual, access_kind>
split_type(std::string rawTypeStr) {


  std::string constKw("const");

  qual qualToken = qual::undefined;
  access_kind retAcc = access_kind::undefined;

  auto posCnst = rawTypeStr.find(constKw);
  if (posCnst != std::string::npos) {
    qualToken = qual::cnst;
    rawTypeStr.erase(posCnst, constKw.size());
    retAcc = access_kind::read_only;
  } else {
    qualToken = qual::var;
    retAcc = access_kind::read_write;
  }


  clean_type(rawTypeStr);


  return std::make_tuple(rawTypeStr, qualToken, retAcc);
}

static
qual
parse_ind(std::string rawTypeStr) {

  qual qualToken = qual::undefined;


  if (rawTypeStr.find("const") != std::string::npos) {
    qualToken = qual::cnst;
  } else {
    qualToken = qual::var;
  }

  return qualToken;
}

static
std::string make_translation_type(qual typeQual, indir indirect, const std::string& typeName) {
  std::string retStr;

  if (typeQual == qual::cnst and indirect == indir::copy) {

    retStr = "std::add_const_t<" + typeName + ">";

  } else if(typeQual == qual::cnst and indirect == indir::ref) {

    retStr = "std::add_lvalue_reference_t<std::add_const_t<" + typeName + ">>";

  } else if(typeQual == qual::cnst and indirect == indir::ptr) {

    retStr = "std::add_pointer_t<std::add_const_t<" + typeName + ">>";

  } else if(typeQual == qual::var and indirect == indir::copy) {

    retStr = typeName;

  } else if (typeQual == qual::var and indirect == indir::ref) {

    retStr = "std::add_lvalue_reference_t<" + typeName + ">";

  } else if (typeQual == qual::var and indirect == indir::ptr) {

    retStr = "std::add_pointer_t<" + typeName + ">";

  } else {
    throw std::logic_error(std::string("Unhandled case while making translation type : qual ") + util::enum_convert<qual>::to_string_rt(typeQual) + ", indirect " + util::enum_convert<indir>::to_string_rt(indirect) + ", typename " + typeName);
  }

  return retStr;
}

void
sobject<obj::data_decl>::normalize_original() {
  // std::cout << "Pre normalize original : " << super_type::m_original << '\n';
  sobject_base::m_data = 
    (m_typeQual == qual::cnst ? "const " : "") +
    m_typeName + 
    (m_indirect == indir::ptr ? "*" : (m_indirect == indir::ref ? "&" : "")) + 
    (m_indirectQual == qual::cnst ? "const" : "") + " " + 
    m_variableName;
  // std::cout << "Post normalize original : " << super_type::m_original << '\n';
}

static
std::string clean_var_name(std::string str) {
  auto eqPos = str.find('=');
  if (eqPos != std::string::npos) {
    // There is an equal, so there is a variable name
    auto spacePos = str.find_last_of(' ', eqPos - 1);
    auto varNameLastPos = str.find_last_not_of(' ', eqPos - 1);
    if (spacePos < varNameLastPos) {
      // T a=
      return str.substr(0, spacePos);
    } else {
      // T a =
      auto varNameFirstPos = str.find_last_of(' ', varNameLastPos);
      return str.substr(0, varNameFirstPos);
    }
  } else {
    // Not an equal, just find the last space
    auto spacePos = str.find_last_of(' ');
    if (spacePos != std::string::npos) {
      return str.substr(0, spacePos);
    } else {
      return str;
    }
  }
}

void
sobject<obj::data_decl>::initialize_fields() { 
 // std::cout << "========Initializing fields from original " << sobject_base::m_data << '\n';

  std::string typeName;
  // qual typeQual = qual::var;
  m_allowedAccess = access_kind::undefined;

  m_indirect = indir::undefined;
  m_indirectQual = qual::undefined;

  auto cleanOriginal = clean_var_name(sobject_base::m_data);

  auto indPos = cleanOriginal.rfind('*');
  if (indPos != std::string::npos) {
    m_indirect = indir::ptr;
  } else {
    indPos = cleanOriginal.rfind('&');
    if (indPos != std::string::npos) {
      m_indirect = indir::ref;
    } else {
      m_indirect = indir::copy;
      // No indirection. we cut on next space to discard variable name if existing. DEPRECATED. Done before when we encounter a '='
      // indPos = cleanOriginal.rfind(' ');
    }
  }

    
    auto typeInfo = cleanOriginal.substr(0, indPos);
    auto [tName, tQual, tAcc] = split_type(typeInfo);

    m_typeName = tName;
    m_typeQual = tQual;
    m_allowedAccess = (tAcc == access_kind::read_write and m_indirect == indir::copy ? access_kind::read_only : tAcc);

  if (indPos != std::string::npos) {
    auto indInfo = cleanOriginal.substr(indPos, cleanOriginal.size() - indPos);
    auto indQual = parse_ind(indInfo);

    m_indirectQual = indQual;
  }

  m_translationType = make_translation_type(m_typeQual, m_indirect, m_typeName);

  this->check_valid();

  // Normalize original if there is an '=' token
  if (sobject_base::m_data.find('=') != std::string::npos) {
    normalize_original();
  }
}

void sobject<obj::data_decl>::check_valid() const {

  if (m_typeName.empty()) {
    throw std::runtime_error("Error in parsed_type : empty typename in " + sobject_base::m_data);
  }

  if (m_typeQual == qual::undefined) {
    throw std::runtime_error("Error in parsed_type : undefined typeQual in " + sobject_base::m_data);
  }

  if (m_indirect == indir::undefined) {
    throw std::runtime_error("Error in parsed_type : undefined indirect in " + sobject_base::m_data);
  }

  if (m_indirectQual == qual::undefined and m_indirect != indir::copy) {
    throw std::runtime_error("Error in parsed_type : undefined indirectQual in " + sobject_base::m_data);
  }

  if (m_allowedAccess == access_kind::undefined) {
    throw std::runtime_error("Could not infer access in " + sobject_base::m_data);
  }
}

set_cso_t<obj::data_use>
sobject<obj::data_decl>::get_data_uses() const {

  set_cso_t<obj::data_use> retSet;

  std::copy(std::begin(m_dataUses), std::end(m_dataUses), std::inserter(retSet, std::end(retSet)));

  return retSet;
}

set_so_t<obj::data_use>&
sobject<obj::data_decl>::edit_data_uses() {
  return m_dataUses;
}


///////////////////////
///////////////////////
/////////////////////// Identification as a loop variable
///////////////////////
///////////////////////

// Called from the pc::loop_variable factory
bool sobject<obj::data_decl>::check_loop_inner_properties() const {

  return
    (m_typeName.find("int") != std::string::npos or
    m_typeName.find("signed") != std::string::npos or
    m_typeName.find("unsigned") != std::string::npos or
    m_typeName.find("long") != std::string::npos or
    m_typeName.find("short") != std::string::npos) and
    m_indirect == indir::copy and
    m_indirectQual == qual::undefined;// and
    // m_allowedAccess == access_kind::read_write;
}





bool sobject<obj::data_decl>::require_wrap() const {

  // Ideally do this V, but we need to avoid infinite recursion with require_emit_backend
  // return std::any_of(
  //     std::begin(m_dataUses), std::end(m_dataUses),
  //     [] (const so_t<obj::data_use> dUseSibling) {
  //       return dUseSibling->require_emit_backend();
  //     });
  auto nCallUseSiblingsRWTask = std::count_if(std::begin(m_dataUses), std::end(m_dataUses),
      [] (const so_t<obj::data_use> dUseSibling) {

        if (not dUseSibling->is_direct_call_argument()) {
          return false;
        }

        // dUseSibling is a use in a call. Let's see if this call is to a an async func (ie a task)
        
        auto dDeclCalleeSibling = dUseSibling->get_callee_data_decl();

        auto fDefCalleeSibling = state<obj::fun_def>::get_containing( dDeclCalleeSibling );

        if (fDefCalleeSibling->is_task()) {


          // The callee is a task
          auto calleeAccess = dDeclCalleeSibling->get_allowed_access();
          auto calleeIndir = dDeclCalleeSibling->get_indirect();

          if (calleeAccess == access_kind::read_write) {

            // This is a sibling use in a RW task call, so count it
            // std::cout << "Use : " << dUseSibling->get_identifier() << " makes dDecl wrappable\n";
            return true;

          } else if (calleeAccess == access_kind::read_only and calleeIndir == indir::ptr) {

            // std::cout << "Use : " << dUseSibling->get_identifier() << " makes dDecl wrappable\n";
            return true;

          } else if (calleeAccess == access_kind::read_only and calleeIndir == indir::ref) {

            // std::cout << "Use : " << dUseSibling->get_identifier() << " makes dDecl wrappable\n";
            return true;
          }

        }         

        // std::cout << "Use : " << dUseSibling->get_identifier() << " makes dDecl NOT wrappable\n";
        return false;
      }
    );
  return (nCallUseSiblingsRWTask > 0);

}


cso_t<obj::fun_def>
sobject<obj::data_decl>::get_root_function_definition() const {

  auto fDefContext = state<obj::fun_def>::get_containing( this );

  if (fDefContext == nullptr) {
    throw std::logic_error("Could not find function context of dDecl : " + this->get_variable_name());
  }

  return fDefContext;
}


} // namespace bld::src
