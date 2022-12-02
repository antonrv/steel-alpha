
#include "generate/generator.hpp"


#include "source/object/function/task.hpp"

#include "common/inject/syntax_def.hpp"
#include "files/interface.hpp"

#include "generate/run/enum_map.hpp"
#include "generate/run/head.hpp"


#include <iostream>
#include <sstream>

#include <stdexcept>


namespace bld {


static
event_map_t build_app_enum_map(
  const src::vec_ctask_t& tDefSet,
  const src::set_cso_t<src::obj::fun_call>& tCallSet
) {

  event_map_t retMap;

  insert_to_map(
      retMap, "id",
      tDefSet,
      [](src::ctask_t ePtr) {
        auto idVal = ePtr->get_app_identifier();
        auto idDef = idVal == "main_entry" ? "global::EntryAppIndex" : "";
        return value_t({idVal, idDef});
      }
    );

  insert_to_map(
      retMap, "impl",
      tDefSet,
      [](src::ctask_t ePtr) {
        auto implVal = ePtr->get_app_implementation();
        auto implDef = implVal == "main_entry" ? "global::EntryAppImpl" : "";
        return value_t({implVal, implDef});
      }
    );


  insert_to_map(
      retMap, "call",
      tCallSet,
      [](src::cso_t<src::obj::fun_call> ePtr) {
        auto callVal = ePtr->get_app_call_translation();
        auto callDef = "";
        return value_t({callVal, callDef});
      }
    );

  return retMap;
}


// defined in aux_enum
void new_enum_class(std::ostringstream& os, std::string nms, const std::string& enumTypeName, const values_t& values, const unsigned typeId);


template <>
cfileb_t generator::run<gen_kind::app_enum>(key_path targetKp, state::filename sourceFn) {

  std::string stem = "enum_" + sourceFn.get_stem();

  state::filename outFn(targetKp, stem + etraits<ext::autogen>::value + etraits<ext::module_interface>::value, path_require::create);

  auto agFile = state::files<file_kind::autogen>::record<code::interface>(outFn);

  if (m_taskDefinitions.empty()) {
    agFile->dump_content( "// Empty file. No task definitions" );
    return agFile;
  }

  if (m_taskCalls.empty()) {
    agFile->dump_content( "// Empty file. No task calls" );
    return agFile;
  }


  auto appEnums = build_app_enum_map(m_taskDefinitions, m_taskCalls);

  std::ostringstream oss;

  oss << HeaderTxt;

  oss << syn::exp_module(syn::str("App.Enum")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Types")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Values")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Sequence")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Instrument.FwDeclarations")) << syn::endl()
      << syn::imp_module(syn::str("<cstdio>")) << syn::endl(); // Needed? TODO

  unsigned eventTypeId = 0;
  for (const auto& [key, valSet] : appEnums) {
    new_enum_class(oss, "app", key, valSet, eventTypeId++);
  }

  agFile->dump_content( oss.str() );

  return agFile;
}

} // namespace bld
