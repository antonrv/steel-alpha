
#include "generate/generator.hpp"

#include "generate/run/head.hpp"

#include "common/inject/syntax_def.hpp"
#include "files/interface.hpp"

#include <iostream>
#include <sstream>

#include <algorithm>
#include <stdexcept>


namespace bld {

template <>
cfileb_t generator::run<gen_kind::plat_graph>(key_path targetKp, state::filename sourceFn) {


  std::ostringstream oss;

  oss << HeaderTxt;

  oss << syn::exp_module(syn::str("Platform.Traits")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Sequence")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Types")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Tuple")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.FwDeclarations.Plat")) << syn::endl()
      << syn::imp_module(syn::str("<cstdio>")) << syn::endl(); // Needed? TODO

  oss << syn::nms(syn::str("plat")) << "{" << syn::endl();

  // fill_proc_traits( oss, TODO );

  // fill_memspace_traits( oss, TODO );

  oss << "}";


  std::string stem = "graph_" + sourceFn.get_stem();

  state::filename outFn(targetKp, stem + etraits<ext::autogen>::value + etraits<ext::module_interface>::value, path_require::create);

  auto agFile = state::files<file_kind::autogen>::record<code::interface>(outFn);

  agFile->dump_content( oss.str() );

  return agFile;
}

} // namespace bld
