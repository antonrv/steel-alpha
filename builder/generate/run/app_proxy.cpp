
#include "generate/generator.hpp"
#include "generate/run/enum_map.hpp"
#include "generate/run/head.hpp"

#include "common/inject/syntax_def.hpp"
#include "files/interface.hpp"

// #include "source/object/task/parameter.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/function/definition.hpp"

#include <string>
#include <vector>
#include <sstream>

namespace bld {


static
void fill_fwd_declarations(std::ostringstream& oss, const src::vec_ctask_t& tDefElems) {

  for (auto tDefPtr : tDefElems) {

    auto paramVec = tDefPtr->get_appended_type_parameters();

    for (auto dShared : tDefPtr->get_root_function_definition()->get_arguments()) {
      paramVec.push_back( dShared->get_translation_type() );
    }

    oss << tDefPtr->get_return_type_str() << " " << tDefPtr->get_app_implementation() << syn::stmt(syn::paren( syn::sequence(paramVec) ) ) << syn::endl();
  }
}

// defined in aux_template.cpp
void replace_keyword(std::string& targetStr, const char * kwToReplace, const std::string& newContent);

static constexpr const char * ImplNameKw = "INSERT_IMPL_NAME";

static constexpr const char * KernelRunProxyTemplate = 
"template <>\n"
"class kernel_proxy<impl::INSERT_IMPL_NAME> {\n"
"  static constexpr impl this_impl = impl::INSERT_IMPL_NAME;\n"
"  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;\n"
"public:\n"
"  template <typename... KernelArgs>\n"
"  static void run(KernelArgs&&... args) {\n"
"    INSERT_IMPL_NAME( std::forward<KernelArgs>(args) ... );\n"
"  }\n"
"};\n";

static constexpr const char * DispatcherCreateProxyTemplate = 
"template <>\n"
"class dispatcher_proxy<impl::INSERT_IMPL_NAME> {\n"
"public:\n"
"  static constexpr impl this_impl = impl::INSERT_IMPL_NAME;\n"
"  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;\n"
"  template <typename... DispatcherArgs>\n"
"  static\n"
"  std::shared_ptr<task::coro::dispatcher<this_impl>>\n"
"  create(DispatcherArgs&&... args) noexcept {\n"
"    return std::make_shared< task::coro::dispatcher<this_impl> >( INSERT_IMPL_NAME( std::forward<DispatcherArgs>(args) ... ) );\n"
"  }\n"
"};\n";

static
void fill_impl_proxy(std::ostringstream& oss, const src::vec_ctask_t& tDefElems) {

  for (auto tDefPtr : tDefElems) {

    std::string customStr = tDefPtr->is_dispatcher() ? DispatcherCreateProxyTemplate : KernelRunProxyTemplate;

    replace_keyword(customStr, ImplNameKw, tDefPtr->get_app_implementation());

    oss << customStr;
  }
}



template <>
cfileb_t generator::run<gen_kind::app_proxy>(key_path targetKp, state::filename sourceFn) {

  std::ostringstream oss;

  oss << HeaderTxt;

  oss << syn::exp_module(syn::str("App.Proxy")) << syn::endl()
      << syn::exp_imp_module(syn::str("App.Graph")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Util.Types")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Util.Sequence")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Util.FwDeclarations.App")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Util.Predicates.App")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Task.Descriptor")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Task.Dispatcher")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Work.Descriptor.Global")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Dep.MakeAsync")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Dep.Guard.Backend")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Dep.Guard.Frontend")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Dep.Wrap")) << syn::endl()
      << syn::exp_imp_module(syn::str("<type_traits>")) << syn::endl()
      << syn::exp_imp_module(syn::str("<stdexcept>")) << syn::endl();

  // Forward declarations (outside app namespace)
  fill_fwd_declarations(oss, m_taskDefinitions);

  oss << syn::nms(syn::str("app")) << "{" << syn::endl();

  fill_impl_proxy(oss, m_taskDefinitions);

  oss << "}";

  std::string stem = "proxy_" + sourceFn.get_stem();

  state::filename outFn(targetKp, stem + etraits<ext::autogen>::value + etraits<ext::module_interface>::value, path_require::create);

  auto agFile = state::files<file_kind::autogen>::record<code::interface>(outFn);

  agFile->dump_content( oss.str() );

  return agFile;
}

} // namespace bld
