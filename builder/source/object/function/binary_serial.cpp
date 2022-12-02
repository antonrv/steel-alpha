
#include "source/object/function/binary.hpp"

#include "source/serial/make_serial.hpp"


namespace bld::src {

std::string sobject<obj::bin_op>::serial() const {

  return sobject_base::serial() +
      make_serial<1>(
        {"own:"},
        m_ownedPiece
    );
}

} // namespace bld::src
