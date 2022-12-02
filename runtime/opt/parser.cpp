

module SteelRT.Opt.Parser;


import SteelRT.Opt.Predef;


import SteelRT.Util.Types;
import SteelRT.Util.Meta;
import SteelRT.Learn.Types;


import <sstream>;
import <map>;
import <vector>;
import <string>;



namespace opt {



static std::vector<std::string> split_string(const std::string& input, const char div) {

  std::vector<std::string> ret;
  std::istringstream iss(input);
  std::string s;
  // std::cout << input << '\n';
  while(std::getline(iss, s, div)) {
    if (not s.empty()) {
      // std::cout << s << '\n';
      ret.push_back(s);
    }
  }
  return ret;
}

static bool is_option(const std::string& str) {
  return str[0] == '-';
}


template <typename OptValuesT, opt::kind... OptKinds>
static
void set_default_option_values( OptValuesT& optValuesRef, util::sequence::enum_t<opt::kind, OptKinds...> ) {
  ( (std::get< util::sequence::get_index_v<typename opt::all_seq, OptKinds> >( optValuesRef ) = opt::traits<OptKinds>::get_default()), ... );
}


template <typename OptValuesT>
static
void set_option_value( OptValuesT& optValuesRef, const std::string& keyStr, const std::string& valueStr, util::sequence::enum_t<opt::kind> ) {
  // Do nothing. Option not in the requested sequence
}

template <typename OptValuesT, opt::kind OptKind, opt::kind... OptKinds>
static
void set_option_value( OptValuesT& optValuesRef, const std::string& keyStr, const std::string& valueStr, util::sequence::enum_t<opt::kind, OptKind, OptKinds...> ) {

  std::string thisOptKey(opt::traits<OptKind>::string_value);

  if ( keyStr == thisOptKey ) {
    std::get< util::sequence::get_index_v<typename opt::all_seq, OptKind> >( optValuesRef ) = opt::traits<OptKind>::convert( valueStr );
  } else {
    set_option_value( optValuesRef, keyStr, valueStr, util::sequence::enum_t<opt::kind, OptKinds...>{} );
  }
}

template <typename OptSeqT>
void parser::register_option(const std::string& argElem) {

  if (argElem.find("=") != std::string::npos) {

    auto splitOpt = split_string(argElem, '=');

    if (splitOpt.size() != 2) {
      throw std::runtime_error("Cannot parse option : " + argElem);
    }

    m_optionMap[ splitOpt[0] ] = splitOpt[1];

    set_option_value( m_optValues, splitOpt[0], splitOpt[1], OptSeqT{} );

  } else {
    m_optionMap[argElem] = "ENABLED";
    // state::parser::enable(argElem); DEPRECATED
    // m_flags.push_back(argElem);
  }
}

parser::parser( const char * opts ) :
  m_binFn(""),
  m_vArgs(split_string(std::string(opts), ' '))
{}

parser::parser(int argc, const char** argv) :
  m_binFn(argv[0]),
  m_vArgs(argv, argv + argc)
{}

template <typename ParseSeqT>
void parser::parse_sequence() {

  set_default_option_values( m_optValues, ParseSeqT{} );

  for (auto argElem : m_vArgs) {
    if (is_option(argElem)) {
      this->register_option<ParseSeqT>(argElem);
    } else if (argElem == m_binFn) {
      // do nothing
    } else {
      throw std::runtime_error("Ignored argument : " + argElem);
    }
  }
}


template void parser::parse_sequence< opt::runner_seq >( );
template void parser::parse_sequence< opt::pilot_seq >( );


const parser::option_map_t& parser::get_map_ref() const {
  return m_optionMap;
}


std::string parser::get_args( ) const {

  std::string retStr;
  // Start in 1 to skip exe name
  for (auto i = 1; i < m_vArgs.size(); i++) {
    retStr += m_vArgs[i] + " ";
  }
  retStr.pop_back(); // pop last space

  return retStr;
}

// std::string parser::get_info( ) const {
// 
//   std::string retStr;
// 
//   retStr += "Arguments:";
//   retStr += std::accumulate(std::begin(m_vArgs), std::end(m_vArgs), std::string(), [] (const std::string& cum, const std::string& arg) { return cum + "\n\t" + arg; } );
// 
//   return retStr;
// }

} // namespace opt
