#include "options/state/def.hpp"


namespace bld::state {

// template class options;

stored_opt_t options::s_storedOptions = stored_opt_t();


template <opt_kind... OpKs>
void options::set_all_if_existing( const option_map_t& optMap, std::integer_sequence<opt_kind, OpKs...> ) {

  ( options::set_if_existing< OpKs >( optMap ), ... );
}

///////////////
//
// INTERFACE
//
///////////////
void options::set_all( const option_map_t& optMap ) {

  options::set_all_if_existing( optMap, enabled::Sequence_opt_kind{} );
}





template <opt_kind... OpKs>
bool options::verify_any_valid( const std::string& inputOpt, std::integer_sequence<opt_kind, OpKs...> ) {
  return ( options::verify_valid< OpKs >( inputOpt ) || ... );
}


///////////////
//
// INTERFACE
//
///////////////
std::vector<std::string> options::get_undefined( const option_map_t& optMap ) {
  std::vector<std::string> retVec;
  for (auto& optPair : optMap) {
    if ( not verify_any_valid( optPair.first, enabled::Sequence_opt_kind{} ) ) {
      retVec.push_back( optPair.first );
    }
  }
  return retVec;
}


template typename otraits<opt_kind::app>::value_type options::get_value<opt_kind::app>();
template typename otraits<opt_kind::plat>::value_type options::get_value<opt_kind::plat>();
template typename otraits<opt_kind::runtime_test>::value_type options::get_value<opt_kind::runtime_test>();
template typename otraits<opt_kind::builder_test>::value_type options::get_value<opt_kind::builder_test>();

template typename otraits<opt_kind::log_fun_def_record>::value_type options::get_value<opt_kind::log_fun_def_record>();
template typename otraits<opt_kind::log_fun_call_record>::value_type options::get_value<opt_kind::log_fun_call_record>();
template typename otraits<opt_kind::log_fun_loop_record>::value_type options::get_value<opt_kind::log_fun_loop_record>();
template typename otraits<opt_kind::log_fun_ret_record>::value_type options::get_value<opt_kind::log_fun_ret_record>();
template typename otraits<opt_kind::log_fun_ctxt_record>::value_type options::get_value<opt_kind::log_fun_ctxt_record>();
template typename otraits<opt_kind::log_binop_record>::value_type options::get_value<opt_kind::log_binop_record>();
template typename otraits<opt_kind::log_data_decl_record>::value_type options::get_value<opt_kind::log_data_decl_record>();
template typename otraits<opt_kind::log_data_use_record>::value_type options::get_value<opt_kind::log_data_use_record>();


template bool options::is_set<opt_kind::app>();
template bool options::is_set<opt_kind::plat>();
template bool options::is_set<opt_kind::runtime_test>();
template bool options::is_set<opt_kind::builder_test>();
template bool options::is_set<opt_kind::parser_test>();

template bool options::is_set<opt_kind::log_simplify>();
template bool options::is_set<opt_kind::log_access>();
template bool options::is_set<opt_kind::log_digest_access>();
template bool options::is_set<opt_kind::log_file_record>();
template bool options::is_set<opt_kind::log_module_record>();

template bool options::is_set<opt_kind::log_fun_def_record>();
template bool options::is_set<opt_kind::log_fun_call_record>();
template bool options::is_set<opt_kind::log_fun_loop_record>();
template bool options::is_set<opt_kind::log_fun_ret_record>();
template bool options::is_set<opt_kind::log_fun_ctxt_record>();
template bool options::is_set<opt_kind::log_binop_record>();
template bool options::is_set<opt_kind::log_data_decl_record>();
template bool options::is_set<opt_kind::log_data_use_record>();

template bool options::is_set<opt_kind::print_create>();
template bool options::is_set<opt_kind::print_parse_inspect>();
template bool options::is_set<opt_kind::print_ast_inspect>();
template bool options::is_set<opt_kind::print_ast_translate>();
template bool options::is_set<opt_kind::print_app_graph>();
template bool options::is_set<opt_kind::print_dep_events>();
template bool options::is_set<opt_kind::log_scan>();
template bool options::is_set<opt_kind::log_compile>();
template bool options::is_set<opt_kind::log_link>();
template bool options::is_set<opt_kind::log_steps>();


} // namespace bld::state
