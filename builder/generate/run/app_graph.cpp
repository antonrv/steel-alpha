
#include "generate/generator.hpp"

#include "common/inject/syntax_def.hpp"
#include "files/interface.hpp"

#include "generate/run/enum_map.hpp"
#include "generate/run/head.hpp"

#include "source/object/data/decl.hpp"
#include "source/object/function/definition.hpp"
#include "source/object/state/def.hpp"


#include <string>
#include <vector>
#include <sstream>

namespace bld {

static
std::string make_id_traits(const std::string& idStr, const std::set<std::string>& implStrSet) {


  std::ostringstream ossAssign;
  ossAssign << "using impl_sequence = util::sequence::enum_t" << syn::stmt(syn::bracket( syn::sequence(implStrSet) ));

  std::ostringstream oss;

  oss << "template <> struct traits<id::" << idStr << ">" << syn::curl_bracket( ossAssign.str() );
  
  return oss.str();
}

static
std::string make_impl_traits(
  const std::string& idStr,
  const std::string& implStr,
  const std::vector<std::string>& argTypeVec,
  const std::vector<std::string>& callVec,
  const std::vector<std::string>& dispatchVec
) {

  std::ostringstream oss;

  oss << "template <> struct traits<impl::" + implStr + "> {";

  oss << "static constexpr impl this_impl = impl::" << implStr << ";\n";

  oss << "static constexpr id belonging_id = id::" << idStr << ";\n";

  oss << "static constexpr plat::arch arch_value = " + std::string(dispatchVec.empty() ? "plat::arch::x86_64" : "plat::arch::dispatcher") + ";\n"; // To be extended TODO. May use plat::arch::test_isa while testing and a real one in production

  if (argTypeVec.empty()) {
    oss << "using arg_tuple_type = util::tuple_t<>;\n";
  } else {
    oss << "using arg_tuple_type = util::tuple_t" << syn::bracket( syn::sequence(argTypeVec) ) << ";\n";
  }

  oss << "using delegate_arg_indices = util::sequence::index_t<>;\n"; // TODO-RT

  oss << "using call_sequence = util::sequence::enum_t" << syn::bracket( syn::sequence(callVec) ) << ";\n";

  oss << "using dispatch_sequence = util::sequence::enum_t" << syn::bracket( syn::sequence(dispatchVec) ) << ";\n";

  oss << "}";

  return oss.str();
}


static
void fill_id_traits(std::ostringstream& oss, const src::vec_ctask_t& tDefElems) {

  using id_t = std::string;
  using impl_t = std::string;
  using vec_impl_t = std::set<impl_t>;

  std::map<id_t, vec_impl_t> id2implSet;

  for (auto tDefPtr : tDefElems) {

    auto idStr = tDefPtr->get_app_identifier();
    auto implStr = tDefPtr->get_app_implementation();

    if (id2implSet.find(idStr) == id2implSet.end()) {
      id2implSet[idStr] = vec_impl_t({"impl", "impl::" + implStr});
    } else {
      id2implSet[idStr].insert("impl::" + implStr);
    }
  }

  std::vector<std::string> traitsSet;
  for (auto [idStr, implSet] : id2implSet) {
    traitsSet.push_back( make_id_traits(idStr, implSet) );
  }

  oss << syn::stmt_sequence( traitsSet );
}

static
void fill_impl_traits(std::ostringstream& oss, const src::vec_ctask_t& tDefElems, const src::set_cso_t<src::obj::fun_call>& tCallElems) {

  
  std::vector<std::string> traitsSet;

  for (auto tDefPtr : tDefElems) {
    auto idStr = tDefPtr->get_app_identifier();
    auto implStr = tDefPtr->get_app_implementation();

    auto fDefRoot = tDefPtr->get_root_function_definition();

    std::vector<std::string> argTypeVec;
    if (auto kRetParamPtr = fDefRoot->get_return_argument()) {
      argTypeVec.push_back( kRetParamPtr->get_translation_type() );     
    }
    for (auto dShared : fDefRoot->get_arguments()) {
      argTypeVec.push_back( dShared->get_translation_type() );
    }

    src::set_cso_t<src::obj::fun_call> callElemsOfThisKDef;

    std::copy_if (tCallElems.begin(), tCallElems.end(),
        std::inserter(callElemsOfThisKDef, std::end(callElemsOfThisKDef)),
        [&] (src::cso_t<src::obj::fun_call> tCall) {
          return tCall->get_callee()->get_task()->get_app_implementation() == tDefPtr->get_app_implementation();
        }
      );

    std::vector<std::string> callVec({"call"});
    for (auto tCall : callElemsOfThisKDef) {
      callVec.push_back("call::" + tCall->get_app_call_translation());
    }


    std::vector<std::string> dispatchVec({"call"});
    for (auto tCall : fDefRoot->get_body_calls()) {
      dispatchVec.push_back("call::" + tCall->get_app_call_translation());
    }
    
    traitsSet.push_back( make_impl_traits(idStr, implStr, argTypeVec, callVec, dispatchVec) );
  }

  oss << syn::stmt_sequence( traitsSet );
}



static
std::string make_call_traits(
  const std::string& callStr,
  const std::string& implStr,
  const std::vector<std::string>& argTypeVec
) {

  std::ostringstream oss;

  oss << "template <> struct traits<call::" + callStr + "> {";

  oss << "static constexpr call this_call = call::" << callStr << ";\n";

  oss << "static constexpr impl belonging_impl = impl::" << implStr << ";\n";

  if (argTypeVec.empty()) {
    oss << "using arg_tuple_type = util::tuple_t<>;\n";
  } else {
    oss << "using arg_tuple_type = util::tuple_t" << syn::bracket( syn::sequence(argTypeVec) ) << ";\n";
  }

  oss << "using impl_indices = util::sequence::index_t<>;\n"; // TODO-RT

  oss << "}";

  return oss.str();
}

static
void fill_call_traits(std::ostringstream& oss, const src::set_cso_t<src::obj::fun_call>& tCallElems) {

  std::vector<std::string> traitsSet;
  for (auto tCall : tCallElems) {

    auto callStr = tCall->get_app_call_translation();
    auto implStr = tCall->get_callee()->get_task()->get_app_implementation();

    std::vector<std::string> argTypeVec;

    // TODO-G
    // if (auto retDepEvPtr = tCall->get_return_event()) {
    //   argTypeVec.push_back( retDepEvPtr->get_call_type_translation() );
    // }

    auto dUsesInCall = src::state<src::obj::data_use>::get_all_satisfying( [tCall] (const auto& dUseUptr) { return dUseUptr->is_direct_call_argument() and tCall->contains( dUseUptr.get() ); } );
    for (auto dUseInCall : dUsesInCall) {
      std::string typeNameStr;
      if (dUseInCall->has_root()) {
        typeNameStr = dUseInCall->get_root_data_decl()->get_qualified_type_name();
      } else {
        // If dUse is on a literal type
        typeNameStr = dUseInCall->get_callee_data_decl()->get_qualified_type_name();
      }
      if (dUseInCall->require_emit_backend() and dUseInCall->get_access() == src::access_kind::read_only) {
        if (not dUseInCall->on_callee_address()) {
          argTypeVec.push_back( "dep::guard::bnd::readable<" + typeNameStr + ">" );
        } else {
          auto memAccess = dUseInCall->get_mem_access();
          if (memAccess->get_mem_access_kind() == src::pc::mem_ak::affine) {
            argTypeVec.push_back( "dep::guard::bnd::readable<dep::dim::view<" + std::to_string( static_cast<const src::pc::mem_access<src::pc::mem_ak::affine>*>(memAccess)->get_dimensions() ) + "," + typeNameStr + ">>" );
          } else {
            throw std::runtime_error( "Could not fill_call_traits : Not implemented mem access " + std::string(util::enum_convert<src::pc::mem_ak>::to_string_rt(memAccess->get_mem_access_kind())) );
          }
        }
      } else if (dUseInCall->require_emit_backend() and dUseInCall->get_access() == src::access_kind::read_write) {
        if (not dUseInCall->on_callee_address()) {
          argTypeVec.push_back( "dep::guard::bnd::writable<" + typeNameStr + ">" );
        } else {
          auto memAccess = dUseInCall->get_mem_access();
          if (memAccess->get_mem_access_kind() == src::pc::mem_ak::affine) {
            argTypeVec.push_back( "dep::guard::bnd::writable<dep::dim::view<" + std::to_string( static_cast<const src::pc::mem_access<src::pc::mem_ak::affine>*>(memAccess)->get_dimensions() ) + "," + typeNameStr + ">>" );
          } else {
            throw std::runtime_error( "Could not fill_call_traits : Not implemented mem access " + std::string(util::enum_convert<src::pc::mem_ak>::to_string_rt(memAccess->get_mem_access_kind())) );
          }
        }
        
      } else if (not dUseInCall->require_emit_backend()) {
        argTypeVec.push_back( typeNameStr );
      } else {
        throw std::logic_error("Unhandled case filling call traits\n");
      }
    }
  
    traitsSet.push_back( make_call_traits(callStr, implStr, argTypeVec) );
  }

  oss << syn::stmt_sequence( traitsSet );
}



template <>
cfileb_t generator::run<gen_kind::app_graph>(key_path targetKp, state::filename sourceFn) {

  std::ostringstream oss;

  oss << HeaderTxt;

  oss << syn::exp_module(syn::str("App.Graph")) << syn::endl()
      << syn::exp_imp_module(syn::str("App.Enum")) << syn::endl()
      << syn::imp_module(syn::str("Plat.Enum")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Sequence")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Types")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Tuple")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.FwDeclarations.App")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Dep.Guard.Backend")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Dep.Dim.View")) << syn::endl();
 
  oss << syn::nms(syn::str("app")) << "{" << syn::endl();


  fill_id_traits(oss, m_taskDefinitions);

  fill_impl_traits(oss, m_taskDefinitions, m_taskCalls);

  fill_call_traits(oss, m_taskCalls);

  oss << "}";

  std::string stem = "graph_" + sourceFn.get_stem();

  state::filename outFn(targetKp, stem + etraits<ext::autogen>::value + etraits<ext::module_interface>::value, path_require::create);

  auto agFile = state::files<file_kind::autogen>::record<code::interface>(outFn);

  agFile->dump_content( oss.str() );

  return agFile;
}


} // namespace bld
