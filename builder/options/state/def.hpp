#ifndef STEEL_COMPILER_STATE_OPTIONS_DEF_HPP
#define STEEL_COMPILER_STATE_OPTIONS_DEF_HPP

#include "options/state/decl.hpp"

#include "files/paths/decl.hpp"

#include "common/aux.hpp"

#include <iostream>

namespace bld::state {

template <opt_kind OpK>
bool options::is_set() {
  return std::get<otraits<OpK>>(s_storedOptions).is_set;
}


template <>
void options::prepare<opt_kind::app>( std::string appName ) {

  clean(appName, "-");

  // Set core
  state::paths<key_path::build_app>::set_path( state::paths<key_path::build_root>::get_path() + appName );
  // ... set derived
  state::paths<key_path::build_app_inspect>::set_as_derived(); // Location to put the inspection result
  state::paths<key_path::build_app_translate>::set_as_derived(); // Location to put the inspection result
  state::paths<key_path::build_app_autogen>::set_as_derived(); // Location to put the inspection result
  state::paths<key_path::build_app_run>::set_as_derived(); // Location to put the inspection result
}

template <>
void options::prepare<opt_kind::plat>( std::string platName ) {

  clean(platName, "-");

  // Set core
  state::paths<key_path::build_plat>::set_path( state::paths<key_path::build_root>::get_path() + platName );

  state::paths<key_path::build_plat_autogen>::set_as_derived(); // Location to put the inspection result
  state::paths<key_path::build_plat_precomp>::set_as_derived(); // Location to put the inspection result
}


template <>
void options::prepare<opt_kind::builder_test>( std::string testSuiteName ) {

  if (testSuiteName == "all") {
    // Do nothing. It will be specified with an existing folder for each test suite
    return;
  }

  // Where to put the test results:
  state::paths<key_path::build_builder_test_suite>::set_path( state::paths<key_path::build_builder_test>::get_path() + testSuiteName );
  // ... set derived
  state::paths<key_path::build_builder_test_suite_inspect>::set_as_derived(); // Location to put the inspection result
  state::paths<key_path::build_builder_test_suite_translate>::set_as_derived(); // Location to put the translateion result
  state::paths<key_path::build_builder_test_suite_autogen>::set_as_derived(); // Location to put the autogenion result

  // Where the original sources to test are:
  state::paths<key_path::steel_builder_test_suite>::set_path( state::paths<key_path::steel_builder_test>::get_path() + testSuiteName );
  // ... set derived. Where the reference results are stored:
  state::paths<key_path::steel_builder_test_suite_ref>::set_as_derived(); // Location of the reference result
  state::paths<key_path::steel_builder_test_suite_ref_inspect>::set_as_derived(); // Location of the reference result
  state::paths<key_path::steel_builder_test_suite_ref_translate>::set_as_derived(); // Location of the reference result
  state::paths<key_path::steel_builder_test_suite_ref_autogen>::set_as_derived(); // Location of the reference result
}


template <>
void options::prepare<opt_kind::runtime_test>( std::string testCaseName ) {

  // Where the original sources to test are:
  state::paths<key_path::steel_runtime_test_case>::set_path( state::paths<key_path::steel_runtime_test>::get_path() + testCaseName );

  // Where to put the test results:
  state::paths<key_path::build_runtime_test_case>::set_path( state::paths<key_path::build_runtime_test>::get_path() + testCaseName );
  // ... set derived
  state::paths<key_path::build_runtime_test_case_inspect>::set_as_derived();
  state::paths<key_path::build_runtime_test_case_translate>::set_as_derived();
  state::paths<key_path::build_runtime_test_case_autogen>::set_as_derived();
  state::paths<key_path::build_runtime_test_case_precomp>::set_as_derived();
  state::paths<key_path::build_runtime_test_case_run>::set_as_derived();
}



template <opt_kind OpK>
typename otraits<OpK>::value_type
options::get_value() {
  if (std::get<otraits<OpK>>(s_storedOptions).is_set) {
    return std::get<otraits<OpK>>(s_storedOptions).value;
  }
  throw std::logic_error("Cannot get value of " + std::string(util::enum_convert<opt_kind>::to_string<OpK>()) + ". Set first");
}

template <opt_kind OpK>
void options::set_value( typename otraits<OpK>::value_type val ) {

  std::get<otraits<OpK>>(s_storedOptions).value = val;

  if constexpr (otraits<OpK>::need_prepare) {
    prepare<OpK>( val );
  }
}


template <opt_kind OpK>
void options::set_if_existing(const option_map_t& optMap) {

  // std::cout << "SETTING IF EXISTING " << OpK << '\n';

  using val_t = typename otraits<OpK>::value_type;

  auto foundIt = optMap.find( otraits<OpK>::id );
  if (foundIt != std::end(optMap)) {
    if constexpr ( std::is_same_v<val_t, bool>) {
      set_value<OpK>( true );
    } else {
      set_value<OpK>( foundIt->second );
    }
    std::get<otraits<OpK>>(s_storedOptions).is_set = true;
  }
}

template <opt_kind OpK>
bool options::verify_valid(const std::string& opt) {
  return opt == otraits<OpK>::id;
}

} // namespace bld::state

#endif // STEEL_COMPILER_STATE_OPTIONS_HPP
