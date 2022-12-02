#ifndef SOURCE_OBJECT_STATE_SERIAL_DECL_HPP
#define SOURCE_OBJECT_STATE_SERIAL_DECL_HPP

#include "source/object/typedef.hpp"

namespace bld::src {

template <typename TargetClassT>
struct serialize;

template <>
struct serialize <std::string> {
  static std::string serial( const std::string& inPair );
  // static std::string deserial( std::string serialField );
};

template <>
struct serialize <u_pair_t> {
  static std::string serial( const u_pair_t& inPair );
  // static u_pair_t deserial( std::string serialField );
};

} // namespace bld::src

#endif // SOURCE_OBJECT_STATE_SERIAL_DECL_HPP
