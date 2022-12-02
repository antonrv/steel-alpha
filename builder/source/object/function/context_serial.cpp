
#include "source/object/function/context.hpp"

#include "source/serial/make_serial.hpp"

namespace bld::src {

std::string sobject<obj::fun_ctxt>::serial() const {

  return sobject_base::serial() +
      make_serial<1>(
        {"parent:"},
        std::string(m_parentFunctionCtxt ? m_parentFunctionCtxt->get_identifier() : "NULL")
      );
}

} // namespace bld::src
