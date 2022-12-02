
#include "source/token/piece.hpp"

#include "source/serial/make_serial.hpp"

namespace bld::src::pc {

#ifndef PARSER_TEST
std::string piece::serial() const {

  return make_serial<2>(
      {"pcKind:","pcContent:"},
      this->get_kind(),
      this->get_pc_string()
    );
}
#endif // PARSER_TEST

} // namespace bld::src::pc
