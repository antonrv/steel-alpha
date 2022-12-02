
#include "source/object/function/return.hpp"

#include "source/object/function/context.hpp"

#include "source/serial/make_serial.hpp"

namespace bld::src {

std::string sobject<obj::fun_ret>::serial() const {

  return sobject_base::serial() +
      make_serial<1>(
        {"context:"},
        std::string(m_functionCtxt ? m_functionCtxt->get_identifier() : "NULL")
      );
}

} // namespace bld::src
