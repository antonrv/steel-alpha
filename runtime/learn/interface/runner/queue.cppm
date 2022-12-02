
export module SteelRT.Learn.Interface.Runner.Queue;

  export import SteelRT.Learn.Interface.Message.Pack;
  // export import SteelRT.Learn.Interface.Message.Queue;

import SteelRT.Learn.IPC;

import SteelRT.Util.Types;

export import <fstream>; /// TMP XXX


export
namespace learn::intf::runner {


class queue : public ipc::queue {
public:

  queue(const str_t& queueIdStr) :
    ipc::queue(queueIdStr)
  {}

  ~queue() {
    // ipc::queue::remove(); done in pilot
  }

  template <std::size_t MessageSize>
  bool try_send( void const * msgAddr ) {
    return ipc::queue::try_send<MessageSize>( msgAddr );
  }

public:

/// XXX DEBUG
  uint_t m_msgCounter = 0;

  template <std::size_t MsgSize> 
  void write_file_msg( void const * msgContent ) {

    auto fname = "orig_msgs/msg_" + std::to_string(m_msgCounter) + ".dat";

    {
      std::ofstream ofsMsg( fname.c_str(), std::ios::out | std::ios::binary | std::ios::trunc );

      ofsMsg.write( static_cast<const char*>(msgContent), MsgSize );
    }

    m_msgCounter++;
  }

};

} // namespace learn::intf::runner
