

#include "source/object/function/call.hpp"

#include "source/object/function/definition.hpp"

#include "source/serial/make_serial.hpp"

namespace bld::src {

std::string sobject<obj::fun_call>::serial() const {


  return sobject_base::serial() +
      make_serial<3>(
      {"callee:","caller:","own:"},
      m_callee->get_identifier(),
      m_caller->get_identifier(),
      m_callPieceRoot
    );

}

} // namespace bld::src

