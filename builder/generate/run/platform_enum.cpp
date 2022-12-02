
#include "generate/generator.hpp"

#include "files/interface.hpp"

#include "common/inject/syntax_def.hpp"

#include "generate/run/enum_map.hpp"
#include "generate/run/head.hpp"

#include <iostream>
#include <sstream>

#include <stdexcept>

namespace bld {

static
event_map_t build_plat_enum_map( ) {

  event_map_t retMap;

  std::vector<std::string> procSet({"smp0"}); // From lscpu TODO
  std::vector<std::string> archSet({"dispatcher, x86_64"}); // From lscpu TODO
  std::vector<std::string> freqSet({"mhz0800","mhz2400"}); // From cpufreq-info TODO
  std::vector<std::string> memspaceSet({"smp0","disk"}); // From lscpu (#sockets) and option (eg -mem-disk=MOUNT)
  std::vector<std::string> memkindSet({"volat","non_volat"});
  std::vector<std::string> hostSet({"hp_envy"}); // uname -n TODO. Useful for distributed

  auto createPair = [](const std::string& name) { return value_t({name, ""}); };

  insert_to_map( retMap, "processor", procSet, createPair );

  insert_to_map( retMap, "arch", archSet, createPair );

  insert_to_map( retMap, "freq", freqSet, createPair ); 

  insert_to_map( retMap, "memspace", memspaceSet, createPair );

  insert_to_map( retMap, "memkind", memkindSet, createPair );

  insert_to_map( retMap, "host", hostSet, createPair );

  return retMap;
}


// defined in aux_enum
void new_enum_class(std::ostringstream& os, std::string nms, const std::string& enumTypeName, const values_t& values, const unsigned typeId);


template <>
cfileb_t generator::run<gen_kind::plat_enum>(key_path targetKp, state::filename sourceFn) {

  std::string stem = "enum_" + sourceFn.get_stem();

  state::filename outFn(targetKp, stem + etraits<ext::autogen>::value + etraits<ext::module_interface>::value, path_require::create);

  auto agFile = state::files<file_kind::autogen>::record<code::interface>(outFn);
  

  auto platEnums = build_plat_enum_map();


  std::ostringstream oss;

  oss << HeaderTxt;

  oss << syn::exp_module(syn::str("Plat.Enum")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Types")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Values")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Sequence")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Instrument.FwDeclarations")) << syn::endl()
      << syn::imp_module(syn::str("<cstdio>")) << syn::endl(); // Needed? TODO

  unsigned eventTypeId = 0;

  for (const auto& [key, valSet] : platEnums) {
    new_enum_class(oss, "plat", key, valSet, eventTypeId++);
  }

  agFile->dump_content( oss.str() );

  return agFile;
}

} // namespace bld
