

// This is a module similar to Instrument.
// It has an interface for the runner threads to send messages (eg kernel start, kernel end...) to the queues in the trainer.
// It is initialized once in the same way the logging module is.
// In this construction/destruction the trainer process spawn/joined by the runner.


// module; // Module global fragment
// 
// // boost includes for process and pipes
// 
// #include <boost/process/child.hpp>
// #include <boost/process/io.hpp>
module;

// #include <boost/process/pipe.hpp>
#include <boost/process/child.hpp>
#include <boost/process/io.hpp>


export module SteelRT.Learn.Interface.Runner.Master;


  export import SteelRT.Learn.Interface.Runner.Queue;
  export import SteelRT.Learn.Interface.Message.Pack;
  export import SteelRT.Learn.Interface.Message.Typed;

  export import SteelRT.Learn.Interface.Runner.Aux;


// Need to break circular deps
// import SteelRT.Learn.Agent.Runner.Threader.Single;
// import SteelRT.Learn.Agent.Runner.Implementer;

import SteelRT.Learn.Types;


import SteelRT.Learn.IPC;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Instrument;

import <string>;
import <vector>;

// Try if these are enough TODO
// import SteelRT.Util.Types;
// import SteelRT.Util.Tuple;


namespace learn::intf::runner {


export
class raii_master {
  using callback_t = std::function<void(void)>;
  callback_t m_finalizeCallback;
public:
  raii_master() = delete;
  raii_master(callback_t&& cb) : m_finalizeCallback(cb) {}

  ~raii_master() {
    m_finalizeCallback();
  }
};


// No need. Comment to avoid imports on agents and circular dependencies
// template <typename T> struct is_runner_context : std::false_type {};
// 
// template <plat::processor ProcId, typename AppGroupT, typename NativeT>
// struct is_runner_context< agent::runner::implementer<ProcId, AppGroupT, NativeT> > : std::true_type {};
// 
// template <plat::processor ProcId, typename NativeT>
// struct is_runner_context< agent::runner::threader_single<ProcId, NativeT> > : std::true_type {};



export
class core {
private:

  struct pipes {
  
    // boost::process::ipstream errStream;
    boost::process::ipstream outStream;
    // boost::process::opstream inStream;
    boost::process::child pilotProcess;
  };

protected:


  static std::unique_ptr<runner::queue> s_ownQueue;

private:

  static std::unique_ptr<pipes> s_ownPipes;

private:


  static bool has_error(const str_t& line) {
    return
      /*line.find("error") != std::string::npos or*/ line.find("exception") != std::string::npos or
      /*line.find("Error") != std::string::npos or*/ line.find("Exception") != std::string::npos or
      /*line.find("ERROR") != std::string::npos or*/ line.find("EXCEPTION") != std::string::npos;
  }


  static bool await_pilot_cue( const str_t& cueOkStr ) {

    std::string line;
    std::error_code ec;

    instr::trace<instr::event::global_runner::pipe>( "Awaiting for pilot cue:", cueOkStr );

    while (s_ownPipes->pilotProcess.running(ec) and std::getline(s_ownPipes->outStream, line)) {

      instr::trace<instr::event::global_runner::pipe>( "Received from alive pilot. ec:", ec," ===== ", line );

      if (line.find(cueOkStr) != std::string::npos) {

        instr::trace<instr::event::global_runner::pipe>( "Received cue to proceed" );
        return true;

      } else if (has_error(line)) {

        instr::trace<instr::event::global_runner::pipe>( "Received error" );
        return false;
      }
    }

    if (not s_ownPipes->pilotProcess.running(ec)) {
      instr::trace<instr::event::global_runner::pipe>( "Pilot finished. ec:", ec, "checking remaining stream" );
      // Process finished but still stuff to read in pipe
      while (std::getline(s_ownPipes->outStream, line)) {
        instr::trace<instr::event::global_runner::pipe>( "Received from ended pilot ===== ", line );
    
        if (line.find(cueOkStr) != std::string::npos) {
          return true;
        }
      }
    }

    return false;
  }
 

public:

  static raii_master initialize( const str_t& runnerIdStr, const str_t& vArgs, const str_t& queueIdStr, const str_t& cueOkStr, const str_t& exitStr ) {

    // boost::process::ipstream outStream;
    // boost::process::ipstream errStream;
    // boost::process::child pilotProcess;

    instr::trace<instr::event::global_runner::init>( "Creating pipes" );
    s_ownPipes = std::make_unique<pipes>();

    auto pilotProcessName = runnerIdStr + "_pilot";

    instr::trace<instr::event::global_runner::init>( "Spawning pilot process", pilotProcessName );

    // s_ownPipes->pilotProcess = boost::process::child( pilotProcessName, boost::process::std_out > s_ownPipes->outStream, boost::process::std_in < s_ownPipes->inStream );
    // s_ownPipes->pilotProcess = boost::process::child( pilotProcessName, boost::process::std_out > s_ownPipes->outStream, boost::process::std_err > s_ownPipes->errStream );
    s_ownPipes->pilotProcess = boost::process::child( pilotProcessName, vArgs.c_str(), boost::process::std_out > s_ownPipes->outStream );
    // s_ownPipes->pilotProcess = boost::process::child( "/usr/bin/valgrind",vArgsValg.c_str(), boost::process::std_out > s_ownPipes->outStream ); // XXX

    s_ownPipes->pilotProcess.detach();

    // raii_master retRaii( std::bind( &finalize, exitStr ) ); If we put it here, it segfaults in case of error FIXME

    if (not await_pilot_cue(cueOkStr)) {
      throw std::runtime_error("Pilot received an exception");
    }

    instr::trace<instr::event::global_runner::init>( "Creating message queue", queueIdStr );
    s_ownQueue = std::make_unique< runner::queue >( queueIdStr );

    raii_master retRaii( std::bind( &finalize, exitStr ) );

    return retRaii;
  }

private:

  static void finalize( const str_t& exitStr ) {

    using shutdown_msg_t = msg::pack<0>;

    std::error_code ec;

    if (s_ownPipes->pilotProcess.running(ec)) {

      instr::trace<instr::event::global_runner::fini>( "Sending termination message to pilot" );
      shutdown_msg_t terminateMsg( msg::ctg::terminate );

      // core::s_ownQueue->template write_file_msg< sizeof(shutdown_msg_t) >( &terminateMsg ); // XXX DEBUG TMP

      if (not s_ownQueue->template try_send< sizeof(shutdown_msg_t) >( &terminateMsg )) {
        instr::trace<instr::event::global_runner::fini>( "Warning : Could not send shutdown message to finalize queue" );
      }

      if (not await_pilot_cue(exitStr)) {

        instr::trace<instr::event::global_runner::fini>( "Warning : Didn't receive pilot exit cue" );

      } else {

        // s_ownPipes->inStream << "OK"; // Send something to pilot to unblock it until final termination
      }

      instr::trace<instr::event::global_runner::fini>( "Awaiting for pilot exit" );


      // 3. Wait until pilot process finishes
      s_ownPipes->pilotProcess.wait();

    } else {
      instr::trace<instr::event::global_runner::fini>( "Pilot is not running" );
    }

    s_ownQueue.reset();

    int exitCode = s_ownPipes->pilotProcess.exit_code();
    instr::trace<instr::event::global_runner::fini>( "Pilot exit code : ", exitCode );

    // 5. Delete pipes and child process object
    s_ownPipes.reset();
  }
};



export
template <typename NativeT>
class master : public core {

private: // Meta functions to get the Id of a runner context (runner::backend or runner::frontend)

  template <msg::ctg MsgCtg>
  using contexts_of = typename intf::runner::aux<MsgCtg, NativeT>::backends;

  template <msg::ctg MsgCtg, typename ContextT>
  static constexpr std::size_t context_id_of = util::tuple::index_v< ContextT, contexts_of<MsgCtg> >;


  template <msg::kind MsgKind, typename ContextT>
  using content_type_of = 
      std::conditional_t<
        MsgKind != msg::kind::inference_end,
        void, // void whenever MsgKind is not inference_end
        typename ContextT::input_state_type
      >;


public:

  // Context is either a agent::runner::implementer<P,AG,NT> or a agent::runner::threader_single<P, NT>

  template <msg::ctg MsgCtg, msg::kind MsgKind, typename ContextT, typename... Args>
  static void send( Args&&... args ) {

    // Check pilot is running and s_ownQueue is initialized

    // static_assert( is_runner_context<ContextT>::value );

    using TypedContentT = content_type_of< MsgKind, ContextT >;// ContextT::input_state_type;

    // Create typed message
    using typed_t = msg::typed<MsgCtg, MsgKind, TypedContentT>;

    typed_t msgTyped( std::forward<Args>(args) ... );

    static constexpr std::size_t PayloadSize = sizeof(typed_t);

    // Pack typed message
    using pack_t = msg::pack< PayloadSize >;

    static constexpr std::size_t ContextId = context_id_of<MsgCtg, ContextT>;

    const pack_t msgToSend( MsgCtg, MsgKind, ContextId, &msgTyped );

    static constexpr std::size_t MsgSize = sizeof(pack_t);

    // TMP XXX XXX XXX DEBUG
    // core::s_ownQueue->template write_file_msg< MsgSize >( &msgToSend );
    
    auto sendResult = core::s_ownQueue->template try_send< MsgSize >( &msgToSend );

    if (not sendResult) {
      
      instr::trace<instr::event::ipc_msg_queue::send>("Failed. Count", core::s_ownQueue->get_num_msg());
    }
  }

};

} // namespace learn::intf::runner



export
namespace learn::intf::runner {

// Call example:
// learn::intf::send<NativeT, msg::ctg::tasking, msg::kind::inference_end, backend<P0, AppGroupT, NativeT>( std::uintptr_t(ownTask.get()), inputStateType, chosenImpl );


// template <typename NativeT>
// std::unique_ptr<runner::queue> master<NativeT>::s_ownQueue = nullptr;


raii_master initialize( const str_t& strId, const str_t& parsedArgs, const str_t& queueIdStr, const str_t& cueOkStr, const str_t& exitStr );


} // namespace learn::intf::runner
