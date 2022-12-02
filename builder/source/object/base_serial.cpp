
#include "source/object/base.hpp"

#include "source/serial/make_serial.hpp"
#include "source/serial/make_deserial.hpp"

namespace bld::src {

// Unify with token/tokenize.cpp XXX
// Opt
void clean_source_data(std::string& str) {

  // Erase white spaces XXX OPTIMIZE
  auto pos = str.find(' ', 0);
  while (pos != std::string::npos) {
    str.erase(pos, 1);
    pos = str.find(' ', pos);
  }

  // Erase carriage return XXX OPTIMIZE
  pos = str.find('\n', 0);
  while (pos != std::string::npos) {
    str.erase(pos, 1);
    pos = str.find('\n', pos);
  }

  // Erase tabs XXX OPTIMIZE
  pos = str.find('\t', 0);
  while (pos != std::string::npos) {
    str.erase(pos, 1);
    pos = str.find('\t', pos);
  }
}

sobject_base::sobject_base( const std::string& serialStr, const serial_map_t& serialMap ) :
m_identifier( make_deserial< std::string >( serialStr, "id:", serialMap ) ),
m_begin( make_deserial< u_pair_t >( serialStr, "begin_loc:", serialMap ) ),
m_end( make_deserial< u_pair_t >( serialStr, "end_loc:", serialMap ) ),
m_data( make_deserial< std::string >( serialStr, "data:", serialMap ) )
{ }


std::string sobject_base::serial() const {

  auto compactData = m_data;
  clean_source_data(compactData);

  return make_serial<7>(
    arr_str_t<7>({"path_str:", "path:", "file:", "begin_loc:", "end_loc:", "data:", "obj:"}),
    m_filename.get_head_str(),
    m_filename.get_head(),
    m_filename.get_tail(),
    m_begin,
    m_end,
    compactData,
    this->get_obj()
  );
}

} // namespace bld::src
