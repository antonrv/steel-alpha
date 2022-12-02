
#include "source/serial/locate.hpp"

namespace bld::src {

template <>
sob_t get_satisfying( const std::string& targetId, std::integer_sequence<obj> ) {
  throw std::logic_error("get_satisfying reached end during serialization");
  return nullptr;
}

} // namespace bld::src
