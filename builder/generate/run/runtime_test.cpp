
#include "generate/generator.hpp"

#include "common/inject/syntax_def.hpp"
#include "files/interface.hpp"

#include "generate/run/enum_map.hpp"
#include "generate/run/head.hpp"

#include <iostream>
#include <sstream>

#include <algorithm>
#include <stdexcept>

namespace bld {

static constexpr const char * CasesKw = "COMMA_SEPARATED_CASE_ID_SEQUENCE";

static constexpr const char * RunnerTemplateStr = 
"class runner :\n"
"public\n"
"base_runner<runner, COMMA_SEPARATED_CASE_ID_SEQUENCE> {\n"
"private:\n"
"  using super_type = base_runner<runner, COMMA_SEPARATED_CASE_ID_SEQUENCE>;\n"
"public:\n"
"  template <case_id CaseId>\n"
"  void run_case();\n"
"  template <case_id CaseId>\n"
"  void verify_case();\n"
"public:\n"
"  runner(const std::string& filename) : super_type(filename) {}\n"
"};\n";


// defined in aux_rt
event_map_t build_map_from_file(std::string filename);


// defined in aux_enum
void new_enum_class(std::ostringstream& os, std::string nms, const std::string& enumTypeName, const values_t& values, const unsigned typeId);

// defined in aux_template.cpp
void replace_keyword(std::string& targetStr, const char * kwToReplace, const std::string& newContent);


static void generate_runner_specialization(key_path targetKp, const values_t& valSet) {

  std::string commaSepEnumVals;
  {
    std::ostringstream ossValuesSequence; std::vector<std::string> caseIds;
    std::transform(std::begin(valSet), std::end(valSet), std::back_inserter(caseIds), [](const value_t& val){ return "case_id::" + val.first; } );

    
    for (auto s : caseIds) { commaSepEnumVals += s + ","; }
    commaSepEnumVals.pop_back();
    // ossValuesSequence << syn::sequence(caseIds);
    // commaSepEnumVals = ossValuesSequence.str();
  }

  std::ostringstream oss;

  oss << HeaderTxt;

  oss << syn::exp_module(syn::str("RunTestCases")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Test.BaseRunner")) << syn::endl()
      << syn::exp_imp_module(syn::str("TestCases")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Instrument.EnabledEvents")) << syn::endl()
      << syn::exp_imp_module(syn::str("SteelRT.Safe")) << syn::endl();

  oss << syn::nms(syn::str("test")) << "{" << syn::endl();

  std::string targetStr = RunnerTemplateStr;

  replace_keyword(targetStr, CasesKw, commaSepEnumVals);

  oss << targetStr;

  oss << "}";

  std::string stem = "run_cases";

  state::filename outFn(targetKp, stem + etraits<ext::autogen>::value + etraits<ext::module_interface>::value, path_require::create);

  auto agFile = state::files<file_kind::autogen>::record<code::interface>(outFn);

  agFile->dump_content( oss.str() );
}


template <>
cfileb_t generator::run<gen_kind::runtime_test>(key_path targetKp, state::filename rtTestCasesFn) {

  auto testEnums = build_map_from_file(rtTestCasesFn.get_full_name());

  if (testEnums.size() != 1) {
    throw std::runtime_error("Could not generate test enum module interface : expected 1 type in " + rtTestCasesFn.get_full_name());
  }

  std::ostringstream oss;

  oss << HeaderTxt;

  oss << syn::exp_module(syn::str("TestCases")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Types")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Values")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Util.Sequence")) << syn::endl()
      << syn::imp_module(syn::str("SteelRT.Instrument.FwDeclarations")) << syn::endl();

  const std::string keyStr = "case_id";
  const auto& valSet = testEnums.at(keyStr);

  new_enum_class(oss, "test", keyStr, valSet, 0);

  std::string stem = "cases";

  auto outFn = state::filename(targetKp, stem + etraits<ext::autogen>::value + etraits<ext::module_interface>::value, path_require::create);

  auto agFile = state::files<file_kind::autogen>::record<code::interface>(outFn);

  agFile->dump_content( oss.str() );

  generate_runner_specialization(targetKp, valSet);

  return agFile;
}

} // namespace bld
