
#include "files/paths/def.hpp"
// #include "common/aux.hpp" // WHAT FOR??

namespace bld::state {

template class paths<key_path::undefined>;
template class paths<key_path::pwd>;

template class paths<key_path::build_root>;
template class paths<key_path::build_std>;
template class paths<key_path::build_runtime>;
template class paths<key_path::build_runtime_gen>;
template class paths<key_path::build_runtime_precomp>;
template class paths<key_path::build_runtime_precomp_ctxt>;
template class paths<key_path::build_runtime_precomp_data>;
template class paths<key_path::build_runtime_precomp_dep>;
template class paths<key_path::build_runtime_precomp_instrument>;
template class paths<key_path::build_runtime_precomp_policy>;
template class paths<key_path::build_runtime_precomp_safe>;
template class paths<key_path::build_runtime_precomp_task>;
template class paths<key_path::build_runtime_precomp_util>;
template class paths<key_path::build_runtime_precomp_work>;
template class paths<key_path::build_runtime_test>;
template class paths<key_path::build_runtime_test_case>;
template class paths<key_path::build_runtime_test_case_inspect>;
template class paths<key_path::build_runtime_test_case_translate>;
template class paths<key_path::build_runtime_test_case_autogen>;
template class paths<key_path::build_runtime_test_case_precomp>;
template class paths<key_path::build_runtime_test_case_run>;
template class paths<key_path::build_builder_test>;
template class paths<key_path::build_builder_test_suite>;
template class paths<key_path::build_builder_test_suite_inspect>;
template class paths<key_path::build_builder_test_suite_translate>;
template class paths<key_path::build_builder_test_suite_autogen>;

template class paths<key_path::build_app>;
template class paths<key_path::build_app_inspect>;
template class paths<key_path::build_app_translate>;
template class paths<key_path::build_app_autogen>;
template class paths<key_path::build_app_precomp>;
template class paths<key_path::build_app_run>;

template class paths<key_path::build_plat>;
template class paths<key_path::build_plat_autogen>;
template class paths<key_path::build_plat_precomp>;


template class paths<key_path::steel_root>;
template class paths<key_path::steel_runtime>;
template class paths<key_path::steel_runtime_modules_ctxt>;
// template class paths<key_path::steel_runtime_modules_data>;
template class paths<key_path::steel_runtime_modules_dep>;
template class paths<key_path::steel_runtime_modules_instrument>;
template class paths<key_path::steel_runtime_modules_policy>;
template class paths<key_path::steel_runtime_modules_safe>;
template class paths<key_path::steel_runtime_modules_task>;
template class paths<key_path::steel_runtime_modules_util>;
template class paths<key_path::steel_runtime_modules_work>;
template class paths<key_path::steel_runtime_test>;
template class paths<key_path::steel_runtime_test_case>;
template class paths<key_path::steel_runtime_instrument>;
template class paths<key_path::steel_builder>;
template class paths<key_path::steel_builder_test>;
template class paths<key_path::steel_builder_test_suite>;
template class paths<key_path::steel_builder_test_suite_ref>;
template class paths<key_path::steel_builder_test_suite_ref_inspect>;
template class paths<key_path::steel_builder_test_suite_ref_translate>;
template class paths<key_path::steel_builder_test_suite_ref_autogen>;


template std::vector<filename> paths<key_path::steel_builder_test_suite>::get_filenames<path_scan::flat>();
// template std::vector<filename> paths<key_path::steel_builder_test>::get_filenames<path_scan::recurse>();
template std::vector<filename> paths<key_path::steel_runtime_test_case>::get_filenames<path_scan::recurse>();

template std::vector<filename> paths<key_path::steel_runtime_test>::get_filenames<path_scan::flat>();

// template std::vector<filename> paths<key_path::steel_runtime_modules>::get_filenames<path_scan::recurse>();
template std::vector<filename> paths<key_path::steel_runtime_modules_ctxt>::get_filenames<path_scan::recurse>();
template std::vector<filename> paths<key_path::steel_runtime_modules_dep>::get_filenames<path_scan::recurse>();
template std::vector<filename> paths<key_path::steel_runtime_modules_instrument>::get_filenames<path_scan::recurse>();
template std::vector<filename> paths<key_path::steel_runtime_modules_policy>::get_filenames<path_scan::recurse>();
template std::vector<filename> paths<key_path::steel_runtime_modules_safe>::get_filenames<path_scan::recurse>();
template std::vector<filename> paths<key_path::steel_runtime_modules_task>::get_filenames<path_scan::recurse>();
template std::vector<filename> paths<key_path::steel_runtime_modules_util>::get_filenames<path_scan::recurse>();
template std::vector<filename> paths<key_path::steel_runtime_modules_work>::get_filenames<path_scan::recurse>();

template std::vector<filename> paths<key_path::steel_runtime_include>::get_filenames<path_scan::recurse>();
template std::vector<filename> paths<key_path::steel_runtime_test>::get_filenames<path_scan::recurse>();
template std::vector<filename> paths<key_path::steel_runtime_instrument>::get_filenames<path_scan::recurse>();

template std::vector<filename> paths<key_path::build_plat_autogen>::get_filenames<path_scan::flat>();
  

// template class paths<key_path::build_autogen>;
// template class paths<key_path::build_obj>;
// template class paths<key_path::build_run>;
// template class paths<key_path::build_pcm>;
// template class paths<key_path::build_std>;
// template class paths<key_path::build_translate>;
// template class paths<key_path::compilable_autogen>;
// template class paths<key_path::compilable_translation>;
// template class paths<key_path::compilable_runtime>;
template class paths<key_path::user_include>;
// template class paths<key_path::source_inspected>;
// template class paths<key_path::source_input>;
// template class paths<key_path::steel_include>;
template class paths<key_path::steel_runtime_include>;

template  <>
bool paths<key_path::pwd>::set_if_existing(const option_map_t& optMap) {
  auto str = std::filesystem::current_path().string();
  append_char(str, '/');
  paths<key_path::pwd>::set_path( str );
  return true;
}

} // namespace bld::state

