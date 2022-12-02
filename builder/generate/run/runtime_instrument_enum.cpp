
#include "generate/generator.hpp"

#include "common/inject/syntax_def.hpp"

#include "files/interface.hpp"

#include "generate/run/enum_map.hpp"
#include "generate/run/head.hpp"


#include <iostream>
#include <stdexcept>


namespace bld {

// defined in aux_rt
event_map_t build_map_from_file(std::string filename);


// defined in aux_enum
void new_enum_class(std::ostringstream& os, std::string nms, const std::string& enumTypeName, const values_t& values, const unsigned typeId);

template <>
cfileb_t generator::run<gen_kind::runtime_instrument>(key_path targetKp, state::filename rtInstrumentEventsFn) {

  auto instrEnums = build_map_from_file(rtInstrumentEventsFn.get_full_name());

  std::ostringstream oss;

  oss << HeaderTxt;

  oss << syn::exp_module(syn::str("SteelRT.Instrument.AllEvents")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Types")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Values")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Sequence")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Instrument.FwDeclarations")) << syn::endl();

  unsigned eventTypeId = 0;
  for (const auto& [key, valSet] : instrEnums) {
    new_enum_class(oss, "instrument::event", key, valSet, eventTypeId++);
  }

  std::string stem = "events";

  state::filename outFn(targetKp, stem + etraits<ext::autogen>::value + etraits<ext::module_interface>::value, path_require::create);

  auto agFile = state::files<file_kind::autogen>::record<code::interface>(outFn);

  agFile->dump_content( oss.str() );

  return agFile;
}

} // namespace bld
