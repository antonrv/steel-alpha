#include "source/object/function/task.hpp"

#include "source/object/function/definition.hpp"

#include "source/serial/make_serial.hpp"

namespace bld::src {

std::string task::serial() const {

  return make_serial<5>(
      {"rootFunDef:","appId:","appImpl:","returnType:","appendTypeParams:"},
      m_rootFunDef->get_identifier(),
      m_appIdentifier,
      m_appImplementation,
      m_returnTypeStr,
      m_appendedTypeParameters
    );
}

} // namespace bld::src
