
#include "source/object/function/loop.hpp"

#include "source/serial/make_serial.hpp"

namespace bld::src {

std::string sobject<obj::fun_loop>::serial() const {

  return sobject_base::serial() +
      make_serial<1>(
        {"parent:"},
        std::string(m_parentLoop ? m_parentLoop->get_identifier() : "NULL")
      );
}

} // namespace bld::src
