
#include "source/object/data/use.hpp"

#include "source/object/data/decl.hpp"

#include "source/serial/make_serial.hpp"
#include "source/serial/make_deserial.hpp"

namespace bld::src {

sobject<obj::data_use>::sobject( const std::string& serialStr, const serial_map_t& serialMap ) :
sobject_base(serialStr, serialMap),
m_dDeclRoot( make_deserial< so_t<obj::data_decl> >(serialStr, "root:", serialMap) ),
m_dDeclCalleeOrOperation( make_deserial< csob_t >(serialStr, "callee_or_op:", serialMap)),
m_terminalRoot(nullptr), // TODO
m_ownedMemAccess(nullptr) // TODO
// m_terminalRoot( make_deserial< pc::cterminal_t >(serialStr, "terminal_root:", serialMap) ),
// m_ownedMemAccess( make_deserial< pc::own_caccess_t >(serialStr, "mem_access:", serialMap) ),
{ }

std::string sobject<obj::data_use>::serial() const {

  return sobject_base::serial() +
      make_serial<4>(
        {"root:", "callee_or_op:", "terminal_root:", "memAccess:"},
        std::string(m_dDeclRoot ? m_dDeclRoot->get_identifier() : "NULL"),
        std::string(m_dDeclCalleeOrOperation ? m_dDeclCalleeOrOperation->get_identifier() : "NULL"),
        m_terminalRoot,
        m_ownedMemAccess
      );

}

} // namespace bld::src
