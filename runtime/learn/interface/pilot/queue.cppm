
export module SteelRT.Learn.Interface.Pilot.Queue;

  export import SteelRT.Learn.Interface.Message.Pack;
  // export import SteelRT.Learn.Interface.Message.Queue;

export import SteelRT.Learn.IPC;

import SteelRT.Util.Types;
import SteelRT.Util.Tuple;

import SteelRT.Instrument;

export import <fstream>; /// TMP XXX

export
namespace learn::intf::pilot {


// Pilot (ie trainer)
template <std::size_t MaxPayloadSize>
class queue : public ipc::queue {
private:


  using max_buffer_t = msg::pack_buffer_t<MaxPayloadSize>;

  max_buffer_t m_recBuffer;

public:
 // Note that buffer_t size is greater than MaxPayloadSize
  static constexpr std::size_t MaxMsgSize = sizeof(max_buffer_t);

private:

  static_assert( MaxMsgSize == sizeof(msg::pack<MaxPayloadSize>) );


  std::size_t m_maxNumMsg = 0;

public:

  // create_only
  queue(const str_t& queueIdStr, std::size_t maxNumMsg) :
    ipc::queue(queueIdStr, maxNumMsg, MaxMsgSize)
  {
    m_recBuffer.fill(uchar_t(0));
    instr::trace<instr::event::ipc_msg_queue::init>( "success" );
  }

  ~queue() {
    if (ipc::queue::remove()) {
      instr::trace<instr::event::ipc_msg_queue::fini>( "success" );
    } else {
      instr::trace<instr::event::ipc_msg_queue::fini>( "fail" );
    }
  }

  static void pre_remove( const str_t& queueIdStr ) {
    if (ipc::queue::pre_remove(queueIdStr)) {
      instr::trace<instr::event::ipc_msg_queue::fini>( "pre-remove: success" );
    } else {
      instr::trace<instr::event::ipc_msg_queue::fini>( "pre-remove: not existing" );
    }
  }


  std::pair<max_buffer_t, std::size_t> receive() {

    m_recBuffer.fill(0);
  
    // Blocks until message is received
    auto receivedSize = ipc::queue::receive<MaxMsgSize>( m_recBuffer.data() );

    instr::trace<instr::event::ipc_msg_queue::receive>( "bytes", receivedSize );

    // Copy buffer
    return std::make_pair( m_recBuffer, receivedSize );
  }


private:

/// XXX DEBUG

  uint_t m_msgCounter = 0;

  std::size_t get_file_size( const std::string& fname ) {
    std::ifstream file( fname.c_str(), std::ios::binary | std::ios::ate);
    return file.tellg();
  }

public:
  std::pair<max_buffer_t, std::size_t> read_file_msg() {

    auto fname = "orig_msgs/msg_" + std::to_string(m_msgCounter) + ".dat";

    m_recBuffer.fill(0);
    
    auto receivedSize = get_file_size( fname );

    {
      std::ifstream ifsMsg( fname.c_str(), std::ios::in | std::ios::binary );

      ifsMsg.read( m_recBuffer.data(), receivedSize );
    }

    m_msgCounter++;

    // Copy buffer
    return std::make_pair( m_recBuffer, receivedSize );
  }

};



} // namespace learn::intf::pilot
