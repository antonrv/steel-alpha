
export module SteelRT.Opt.Parser;

 export import SteelRT.Opt.Predef;

import SteelRT.Util.Types;
import SteelRT.Util.Meta;

import SteelRT.Learn.Types;


import <map>;
import <vector>;
import <string>;



namespace opt {


export
class parser {
private:

  // Stored options
  const std::string m_binFn;

  using parsed_args_t = std::vector< std::string >;
  const parsed_args_t m_vArgs;

  using option_map_t = std::map<std::string, std::string>;

  option_map_t m_optionMap;



  // Processed values
  template <opt::kind OptKind>
  using value_type_of_t = typename opt::traits<OptKind>::value_type;

  using tuple_values_t = util::tuple::lift_enums_t< opt::all_seq, value_type_of_t >;

  using std_tuple_values_t = util::tuple::as_std_t< tuple_values_t >;

  std_tuple_values_t m_optValues;


private:

  template <typename OptSeqT>
  void register_option(const std::string& argElem);

public:

  // RUNNER constructor
  parser(int argc, const char** argv);

  // PILOT constructor
  parser( const char* argv );

  const option_map_t& get_map_ref() const;

  template <typename ParseSeqT>
  void parse_sequence();

  // std::string get_info( ) const;

  template <opt::kind OptKind>
  value_type_of_t<OptKind> get_option_value() const {
    return std::get< util::sequence::get_index_v<typename opt::all_seq, OptKind> >( m_optValues ); 
  }

  std::string get_args() const;


};

} // namespace opt
