
#include "common/inject/syntax_def.hpp"

#include "generate/run/enum_map.hpp"


#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

#include <iostream>
#include <sstream>


namespace bld {


static
auto make_syn_enum_definition(const std::string& enumTypeName, const values_t& values) {

  unsigned numVal = 2; // 0 and 1 are reserved for entry and termination tasks
  std::vector<std::string> enumValues;
  for (auto [valStr, valAssign] : values) {
    if (valAssign.empty()) {
      enumValues.push_back( valStr + " = " + std::to_string(numVal++) );
    } else {
      enumValues.push_back( valStr + " = " + valAssign);
    }
  }

  std::string enumClassStr = "enum class " + enumTypeName + " : enum_uint_t ";

  return syn::stmt(
    syn::cat(
      syn::str(enumClassStr),
      syn::curl_bracket(syn::sequence(enumValues))
    ));
}

static
auto make_syn_seq_definition(const std::string& enumTypeName, const values_t& values) {

  std::vector<std::string> seqVec;
  seqVec.push_back(enumTypeName);
  for (auto [valStr, valAssign] : values) {
    seqVec.push_back(enumTypeName + "::" + valStr);
  }

  std::string usingDefStr = "using enabled_" + enumTypeName + "s";

  std::ostringstream ossAssign;

  ossAssign << usingDefStr << " = " << syn::str("util::sequence::enum_t") << syn::bracket( syn::sequence( seqVec )); 

  return syn::stmt(ossAssign.str());
}

static
auto make_syn_type_traits_definition(const std::string& nms, const std::string& enumTypeName, const values_t& values, const unsigned typeId) {
  
  const std::string staticCnstName = "static constexpr const char * name = ";
  const std::string staticCnstId = "static constexpr const enum_type_id_t type_id = ";
  const std::string staticInstrBoolStmt = "static constexpr bool instrumentable = true";

  const std::string templInst = "template <> struct type";

  const std::string cmEnumTypeName = "\"" + enumTypeName + "\"";

  std::ostringstream ossStmts;
  ossStmts << syn::stmt(syn::str(staticCnstName + cmEnumTypeName)) << syn::endl()
          << syn::stmt(syn::str(staticCnstId + std::to_string(typeId))) << syn::endl()
          << syn::stmt(syn::str(staticInstrBoolStmt)) << syn::endl();
  

  std::ostringstream ossDef;
  ossDef << syn::str(templInst) << syn::bracket( syn::str(nms + "::" + enumTypeName) ) << syn::curl_bracket( syn::str(ossStmts.str()) );

  return syn::stmt( syn::str(ossDef.str()) );
}

static
auto make_syn_val_traits_definition(const std::string& nms, const std::string& enumTypeName, const values_t& values) {

  const std::string staticCnstName = "static constexpr const char * name = ";

  const std::string templInst = "template <> struct value";

  std::vector<std::string> valTraits;
  for (auto [valName, valAssign] : values) {
    auto cmValName = "\"" + valName + "\"";
    std::ostringstream oss;
    oss << syn::str(templInst)
      << syn::bracket(syn::str(nms + "::" + enumTypeName + "::" + valName))
      << syn::curl_bracket(
        syn::stmt(syn::cat(syn::str(staticCnstName + cmValName)))
      ) << syn::endl();

    valTraits.push_back( oss.str() );
  }

  return syn::stmt_sequence(valTraits);
}


void new_enum_class(std::ostringstream& os, std::string nms, const std::string& enumTypeName, const values_t& values, const unsigned typeId) {

  if (values.empty()) {
    throw std::runtime_error("No values for enum " + enumTypeName);
  }

  // Enum definition and enum sequence definition
  os << syn::nms(syn::str(nms))
    << syn::curl_bracket(
      syn::cat(
        make_syn_enum_definition(enumTypeName, values),
        make_syn_seq_definition(enumTypeName, values)
      )
    );

  os << syn::endl();

  // Enum type traits and enum values traits
  os << syn::nms(syn::str("instrument::event"))
    <<
    syn::curl_bracket(
      syn::cat(
        make_syn_type_traits_definition(nms, enumTypeName, values, typeId),
        make_syn_val_traits_definition(nms, enumTypeName, values)
      )
    );
}

} // namespace bld
