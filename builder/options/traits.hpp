#ifndef STEEL_COMPILER_COMMON_OPTION_TRAITS_HPP
#define STEEL_COMPILER_COMMON_OPTION_TRAITS_HPP

#include "options/enum.hpp"

#include <string>
#include <vector>

namespace bld {

template <opt_kind OpK>
struct otraits;

template <>
struct otraits<opt_kind::app> {
  bool is_set = false;
  static constexpr bool need_prepare = true;
  static constexpr const char * id = "-app";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::plat> {
  bool is_set = false;
  static constexpr bool need_prepare = true;
  static constexpr const char * id = "-plat";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::runtime_test> {
  bool is_set = false;
  static constexpr bool need_prepare = true;
  static constexpr const char * id = "-runtime-test";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::builder_test> {
  bool is_set = false;
  static constexpr bool need_prepare = true;
  static constexpr const char * id = "-builder-test";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::parser_test> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-parser-test";
  using value_type = bool;
  value_type value;
};

// template <>
// struct otraits<opt_kind::inspect_to_propagate_tasks> {
//   bool is_set = true; // enabled by default
//   static constexpr const char * id = "";
// };

// template <>
// struct otraits<opt_kind::builder_test> {
//   bool is_set = false;
//   static constexpr const char * id = "-builder-test";
// };

template <>
struct otraits<opt_kind::log_simplify> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-simplify";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::log_access> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-access";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::log_digest_access> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-digest-access";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::log_file_record> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-file-record";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::log_module_record> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-module-record";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::log_fun_def_record> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-fun-def-record";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::log_fun_call_record> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-fun-call-record";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::log_fun_loop_record> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-fun-loop-record";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::log_fun_ret_record> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-fun-ret-record";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::log_fun_ctxt_record> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-fun-ctxt-record";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::log_binop_record> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-binop-record";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::log_data_decl_record> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-data-decl-record";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::log_data_use_record> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-data-use-record";
  using value_type = std::string;
  value_type value;
};

template <>
struct otraits<opt_kind::print_create> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-print-create";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::print_parse_inspect> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-print-parse-inspect";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::print_ast_inspect> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-print-ast-inspect";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::print_ast_translate> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-print-ast-translate";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::print_app_graph> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-print-app-graph";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::print_dep_events> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-print-dep-events";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::log_scan> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-scan";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::log_compile> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-compile";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::log_link> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-link";
  using value_type = bool;
  value_type value;
};

template <>
struct otraits<opt_kind::log_steps> {
  bool is_set = false;
  static constexpr bool need_prepare = false;
  static constexpr const char * id = "-log-steps";
  using value_type = bool;
  value_type value;
};


} // namespace bld

#endif // STEEL_COMPILER_COMMON_OPTION_TRAITS_HPP
