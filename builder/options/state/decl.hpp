#ifndef STEEL_COMPILER_STATE_OPTIONS_HPP
#define STEEL_COMPILER_STATE_OPTIONS_HPP

#include "options/typedef.hpp"

#include "options/traits.hpp"

#include <tuple>

namespace bld::state {

#define OBJS fun_def, fun_call, fun_loop, fun_ret, fun_ctxt, bin_op, data_decl, data_use 

using stored_opt_t = 
    std::tuple<
      otraits<opt_kind::app>,
      otraits<opt_kind::plat>,
      otraits<opt_kind::runtime_test>,
      otraits<opt_kind::builder_test>,
      otraits<opt_kind::parser_test>,
      otraits<opt_kind::log_simplify>,
      otraits<opt_kind::log_fun_def_record>, 
      otraits<opt_kind::log_fun_call_record>, 
      otraits<opt_kind::log_fun_loop_record>, 
      otraits<opt_kind::log_fun_ret_record>, 
      otraits<opt_kind::log_fun_ctxt_record>, 
      otraits<opt_kind::log_binop_record>, 
      otraits<opt_kind::log_data_decl_record>, 
      otraits<opt_kind::log_data_use_record>,
      otraits<opt_kind::log_access>,
      otraits<opt_kind::log_digest_access>,
      otraits<opt_kind::log_file_record>,
      otraits<opt_kind::log_module_record>,
      otraits<opt_kind::print_create>,
      otraits<opt_kind::print_parse_inspect>,
      otraits<opt_kind::print_ast_inspect>,
      otraits<opt_kind::print_ast_translate>,
      otraits<opt_kind::print_app_graph>,
      otraits<opt_kind::print_dep_events>,
      otraits<opt_kind::log_scan>,
      otraits<opt_kind::log_compile>,
      otraits<opt_kind::log_link>,
      otraits<opt_kind::log_steps>
    >;


class options {
private:

  template <opt_kind OpK>
  static void prepare( typename otraits<OpK>::value_type val );

public:

  template <opt_kind OpK>
  static bool is_set();

  template <opt_kind OpK>
  static typename otraits<OpK>::value_type get_value();

  template <opt_kind OpK>
  static void set_value( typename otraits<OpK>::value_type );

private:
  template <opt_kind OpK>
  static void set_if_existing(const option_map_t& optMap);
  
  template <opt_kind... OpKs>
  static void set_all_if_existing( const option_map_t& optMap, std::integer_sequence<opt_kind, OpKs...> );

public:

  static void set_all( const option_map_t& optMap );


private:

  template <opt_kind OpK>
  static bool verify_valid(const std::string& opt);

  template <opt_kind... OpKs>
  static bool verify_any_valid( const std::string& inputOpt, std::integer_sequence<opt_kind, OpKs...> );

public:

  static std::vector<std::string> get_undefined( const option_map_t& optMap );

private:

  static stored_opt_t s_storedOptions;

}; 


} // namespace bld::state


#endif // STEEL_COMPILER_STATE_OPTIONS_HPP
