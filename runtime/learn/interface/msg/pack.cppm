
export module SteelRT.Learn.Interface.Message.Pack;

// No need to import Typed.

import SteelRT.Util.Types;

import SteelRT.Learn.Types;

import <chrono>; 

// Change name: pack is misleading -> wrap, wrapped ... TODO


export
namespace learn::intf::msg {

// Chrono types
// using delay_t = std::chrono::duration<float>;// std::chrono::milliseconds
inline constexpr std::size_t SecondFraction = 1000; // milliseconds
using delay_t = std::chrono::duration<fp_t, std::ratio<1, SecondFraction>>;
using clock_t = std::chrono::high_resolution_clock;
using time_point_t = std::chrono::time_point<clock_t>;


// using id_t = uint_t;

struct id_t {
  msg::ctg vCtg = msg::ctg::undef;
  msg::kind vKind = msg::kind::undef;
  ctxt_id_t vContext = msg::UndefContext;
};


template <std::size_t PayloadSize>
using payload_t = std::array<uchar_t, PayloadSize>;


template <std::size_t PayloadSize>
struct pack {

  msg::id_t identifier;
  msg::time_point_t timePoint;
  msg::payload_t<PayloadSize> payload; // Payload encapsulates the typed message content, which can be casted to typed messages in the server depending on identifier;

  // Constructor with a typed message as a payload
  pack( msg::ctg vCtg, msg::kind vKind, ctxt_id_t vContext, void * typedMsgPtr ) :
    identifier( {vCtg, vKind, vContext} ),
    timePoint( msg::clock_t::now() )
  {
    std::memcpy( payload.data(), typedMsgPtr, PayloadSize );
  }

  // Constructor for custom ctg message
  pack( msg::ctg msgCtg ) :
    identifier( {msgCtg, msg::kind::undef, msg::UndefContext} )
  {}
};


// Message buffer. Able to encapsulate message header + payload
template <std::size_t PayloadSize>
// using pack_buffer_t = std::array<uchar_t, sizeof(pack<PayloadSize>)>;
using pack_buffer_t = std::array<char, sizeof(pack<PayloadSize>)>;




} // namespace learn::intf::msg
