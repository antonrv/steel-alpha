
export module SteelRT.Learn.Interface.Pilot.Midend;

  export import SteelRT.Learn.Interface.Message.Pack;
  export import SteelRT.Learn.Interface.Message.Typed;

  export import SteelRT.Learn.Agent.Pilot.Threader.Single;
  export import SteelRT.Learn.Agent.Pilot.Implementer;
  export import SteelRT.Learn.Agent.Pilot.Backend;


import SteelRT.Learn.Interface.Pilot.Aux;



import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Instrument;

export import <map>;
export import <thread>;



///// Async interface that holds one thread per each pilot backend

namespace learn::intf::pilot {



export
template <msg::ctg MsgCtg, typename NativeT>
class midend {
private:

  template <typename BackendT>
  using own_backend_of = std::unique_ptr<BackendT>;

  using this_backends_t = typename intf::pilot::aux<MsgCtg, NativeT>::backends;

  using own_backends_t = util::tuple::lift_t< this_backends_t, own_backend_of >;

  template <typename BackendT>
  struct proc_of_backend { static constexpr plat::processor value = BackendT::processor_id; };

  template <typename BackendT>
  using input_state_of = typename BackendT::input_state_type;

  using backends_proc_seq = util::sequence::from_tuple_t< this_backends_t, proc_of_backend >;

  using backends_input_states = util::tuple::lift_t< this_backends_t, input_state_of >; 

  // Spawn a thread for each one for async processing
  using std_own_backends_t = util::tuple::as_std_t< own_backends_t >;
  std_own_backends_t m_ownBackends;

  static constexpr std::size_t NBackends = this_backends_t::size();

  std::array< std::thread, NBackends > m_threads;

  std::mutex m_exceptionMtx;
  std::array<std::exception_ptr, NBackends> m_backendExceptions;

  using rethrow_callback_t = std::function<void(std::exception_ptr)>;

private: // Private initialization methods

  template <std::size_t... BndIds>
  std_own_backends_t make_all_backends( const learn::pilot::cfg& pilotCfg, util::sequence::index_t<BndIds...> ) {

    return std::make_tuple( std::make_unique<util::tuple::element_t<BndIds, this_backends_t>>( pilotCfg, std::bind( &midend::rethrow_callback, this, BndIds, std::placeholders::_1 ) ) ... );
  }



  template <std::size_t... BndIds>
  void spawn_all( util::sequence::index_t<BndIds...> ) {

    instr::trace<instr::event::global_pilot::init>( "Spawning threads", sizeof...(BndIds) );

    ( (m_threads[BndIds] = std::thread( &util::tuple::element_t<BndIds, this_backends_t>::loop, std::get<BndIds>(m_ownBackends).get(), BndIds )), ... );
  }


public:

  midend( const learn::pilot::cfg& pilotCfg ) {

    instr::trace<instr::event::global_pilot::init>( "Backends ", NBackends );
    m_ownBackends = make_all_backends( pilotCfg, util::sequence::make_index_t<NBackends>{} );

    m_backendExceptions.fill(nullptr);
  }

  void spawn( ) {
    spawn_all( util::sequence::make_index_t<NBackends>{} );
  }

public: // To be accessed by thread pilots in case of exception
  
  // Possibly append ProcId, AppGroupT info with:
  // template <plat::processor ProcId, typename AppGroupT>

  void rethrow_callback( std::size_t backendId, std::exception_ptr excPtr ) {
    std::lock_guard<std::mutex> gLck(m_exceptionMtx);
    m_backendExceptions[ backendId ] = excPtr;
  }

private:

  template <std::size_t... BndIds>
  void tear_all_down( util::sequence::index_t<BndIds...> ) {

    instr::trace<instr::event::global_pilot::fini>( "Tearing down threads of category ", static_cast<uint_t>(MsgCtg) );
    ( std::get<BndIds>(m_ownBackends)->tear_down(), ... );

  }

  template <std::size_t... BndIds>
  void join_all( util::sequence::index_t<BndIds...> ) {

    instr::trace<instr::event::global_pilot::fini>( "Joining threads of category ", static_cast<uint_t>(MsgCtg) );

    ( m_threads[BndIds].join(), ... );
  }

public:

  void finalize() {

    tear_all_down( util::sequence::make_index_t<NBackends>{} );

    join_all( util::sequence::make_index_t<NBackends>{} );

    instr::trace<instr::event::global_pilot::fini>( "Verifying threads correctness of category ", static_cast<uint_t>(MsgCtg) );
    for (auto bndId = 0u; bndId < NBackends; bndId++) {
      try {
        if (m_backendExceptions[bndId]) {
          std::rethrow_exception( m_backendExceptions[bndId] );
        }
      } catch ( const std::exception& excRef ) {

        instr::trace<instr::event::global_pilot::fini>( "Got backend id ", bndId,  " exception : ", excRef.what() );
      } catch ( ... ) {
        instr::trace<instr::event::global_pilot::fini>( "Got backend id ", bndId,  " unknwon exception" );
      }
    }
  }


public: //// ACCESSED BY MASTER THREAD -- PROCESS GENERIC MSG WITHOUT KEY

  template <
    std::size_t ContextId, typename MsgTypedT,
    util::req_t< msg::no_key<MsgTypedT> > ...
  >
  void process_message( const msg::time_point_t& timePoint, const MsgTypedT& msgTyped ) {

    push_to_backend<ContextId>( timePoint, msgTyped );
  }

public: //// ACCESSED BY MASTER THREAD -- PROCESS INFERENCE_START




  // Forward a msg::kind::inference_start message
  template <
    std::size_t ContextId, typename MsgTypedT,
    util::req_t< std::conjunction< msg::is_inference_start<MsgTypedT>, msg::has_key<MsgTypedT> > > ...
  >
  void process_message( const msg::time_point_t& timePoint, const MsgTypedT& inferenceStartMsg ) {

    push_to_backend<ContextId>( timePoint, inferenceStartMsg );
  }


private:

  struct no_fwd_map {};

  template <msg::ctg InMsgCtg, typename EnableT = util::enabler_t>
  struct map_of;

  template <msg::ctg InMsgCtg>
  struct map_of <InMsgCtg, util::req_t< std::is_same<typename intf::msg::traits<InMsgCtg>::key_type, void> > >{ using type = no_fwd_map; };

  template <msg::ctg InMsgCtg>
  struct map_of< InMsgCtg, util::req_t< std::negation< std::is_same<typename intf::msg::traits<InMsgCtg>::key_type, void> > > > {
    using type = std::map<
      typename intf::msg::traits<InMsgCtg>::key_type,
      std::function<void(const msg::time_point_t&, const msg::typed<InMsgCtg, msg::kind::end, void>&)>
    >;
  };


  // Used only if 
  using forward_end_map_t = typename map_of<MsgCtg>::type;

  forward_end_map_t m_forwardEndMap;


public: //// ACCESSED BY MASTER THREAD -- PROCESS INFERENCE_END

  // Forward a msg::kind::inference_end message WITH KEY
  template <
    std::size_t ContextId, typename MsgTypedT,
    util::req_t< std::conjunction< msg::has_content<MsgTypedT>, msg::has_key<MsgTypedT> > > ...
  >
  void process_message( const msg::time_point_t& timePoint, const MsgTypedT& inferenceEndMsg ) {

    static_assert( std::is_same_v<typename MsgTypedT::input_state_type, util::tuple::element_t<ContextId, backends_input_states> > );

    push_to_backend<ContextId>( timePoint, inferenceEndMsg );

    // msg::kind::end may have a mismatch in ContextId (if a dispatcher ends in a processor where it wasn't inferred and created)

    using end_msg_t = msg::typed<MsgCtg, msg::kind::end, void>;

    m_forwardEndMap[ inferenceEndMsg.keyValue ] = std::bind( &midend::push_to_backend<ContextId, end_msg_t>, this, std::placeholders::_1, std::placeholders::_2 );
  }





public: //// ACCESSED BY MASTER THREAD -- PROCESS END


  // Forward a msg::ctg::end message WITH KEY
  template <
    std::size_t ContextId_Discarded, typename MsgTypedT,
    util::req_t< std::conjunction< msg::is_end<MsgTypedT>, msg::has_key<MsgTypedT> > > ...
  >
  void process_message( const msg::time_point_t& timePoint, const MsgTypedT& endMsg ) {

    // Note that we neglect ContextId here, since this ContextId may be different from the ContextId of the associated inference_start and inference_end events. (dispatcher ending in different context where it was inferred and created)

    auto pushEndFnIt = m_forwardEndMap.find( endMsg.keyValue );

    if (pushEndFnIt == std::end(m_forwardEndMap)) {

      throw std::runtime_error("Could not find push function for msg::kind::end with key value : " + std::to_string(endMsg.keyValue));
    }

    // We instead use the function referenced by endMsgl.keyValue set by the associated inference_end message.
    pushEndFnIt->second( timePoint, endMsg );

    m_forwardEndMap.erase( pushEndFnIt );
  }


private: 

  template <std::size_t ContextId, typename MsgTypedT>
  void push_to_backend( const msg::time_point_t& timePoint, const MsgTypedT& msgTyped ) {

    std::get< ContextId >( m_ownBackends )->push( std::make_pair(timePoint, msgTyped) );
  }

};


} // namespace learn::intf::pilot
