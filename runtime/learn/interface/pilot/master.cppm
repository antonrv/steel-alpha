
export module SteelRT.Learn.Interface.Pilot.Master;


  export import SteelRT.Learn.Interface.Pilot.Queue;
  export import SteelRT.Learn.Interface.Pilot.Midend;

  export import SteelRT.Learn.Interface.Pilot.Aux;


import SteelRT.Util.Basic;
import SteelRT.Util.Meta;


import SteelRT.Instrument;
// import SteelRT.Learn.Types;


namespace learn::intf::pilot {

export
template <typename NativeT>
class master {
private:


  template <msg::ctg MsgCtg>
  using input_states_of = typename intf::pilot::aux<MsgCtg, NativeT>::input_states;


  template <msg::ctg MsgCtg>
  using input_states_ids_of = typename intf::pilot::aux<MsgCtg, NativeT>::input_states_ids;

  template <msg::ctg MsgCtg>
  static constexpr std::size_t VoidContentId = input_states_ids_of<MsgCtg>::size();


  template <msg::ctg MsgCtg, msg::kind MsgKind, std::size_t ContextId>
  using input_state_of_id = 
      std::conditional_t<
        MsgKind != msg::kind::inference_end,
        void, // void whenever MsgKind is not inference_end
        util::tuple::element_t< ContextId, input_states_of<MsgCtg> > // chosen ContextId
      >;



  template <msg::ctg MsgCtg> 
  struct bytes_in {
    template <typename InputStateT> 
    struct of_message {
      static constexpr std::size_t inf_start_bytes = sizeof( msg::typed<MsgCtg, msg::kind::inference_start, void>);
      static constexpr std::size_t inf_end_bytes = sizeof( msg::typed<MsgCtg, msg::kind::inference_end, InputStateT>);
      static constexpr std::size_t end_bytes = sizeof( msg::typed<MsgCtg, msg::kind::end, void>);
      static constexpr std::size_t value = util::sequence::max_v< util::sequence::index_t< inf_start_bytes, inf_end_bytes, end_bytes > >;
    };
  };
  

  template <msg::ctg MsgCtg>
  using input_states_sizes_of = util::sequence::from_tuple_t< input_states_of<MsgCtg>, bytes_in<MsgCtg>::template of_message >;


  using input_states_sizes = util::sequence::cat_t< input_states_sizes_of<msg::ctg::tasking>, input_states_sizes_of<msg::ctg::threading> >;

  static constexpr std::size_t MaxMsgPayloadSize = util::sequence::max_v< input_states_sizes >;

  

  using received_key_t = std::tuple< msg::ctg, msg::kind, ushort_t, std::size_t >;

  using process_fn_t = std::function<void(void const*)>;

  using process_map_t = std::map< received_key_t, process_fn_t >;

  process_map_t m_processMapFuns;

  using queue_t = pilot::queue< MaxMsgPayloadSize >;

  std::unique_ptr<queue_t> m_ownQueue;

  static constexpr std::size_t MaxNumMsg = 1000000; // NativeT param

  template <msg::ctg MsgCtg>
  using midend_of = std::unique_ptr< pilot::midend<MsgCtg, NativeT> >;

  using midends_t =
    std::tuple<
      midend_of<msg::ctg::tasking>,
      midend_of<msg::ctg::threading>
    >;

  midends_t m_midends;

  bool m_finalized = false;

private:


public:


  // Standalone constructor (to manually run the pilot process)
  master( const learn::pilot::cfg& pilotCfg ) {

    instr::trace<instr::event::global_pilot::init>( "Learn config", pilotCfg.get_string());


    // 0. Make midends
    instr::trace<instr::event::global_pilot::init>( "Making midends" );
    std::get< midend_of<msg::ctg::tasking> >( m_midends ) = std::make_unique< pilot::midend<msg::ctg::tasking, NativeT> >( pilotCfg );
    // std::get< midend_of<msg::ctg::threading> >( m_midends ) = std::make_unique< pilot::midend<msg::ctg::threading, NativeT> >( pilotCfg ); TODO OMITTED XXX DEBUG
 
    using msg_kind_seq = util::sequence::enum_t<msg::kind, msg::kind::inference_start, msg::kind::inference_end, msg::kind::end>;

    // 1. Bind msg ids with process message functions

    instr::trace<instr::event::global_pilot::init>( "Binding message categories with process callbacks" );


    set_process_functions_1st<msg::ctg::tasking>( msg_kind_seq{} );
    // set_process_functions_1st<msg::ctg::threading>( msg_kind_seq{} ); TODO OMITTED XXX DEBUG


    // 2. Create queue 
    str_t queueIdStr = NativeT::get_str_msg_queue();
    // Ensure it does not exist
    queue_t::pre_remove( queueIdStr );
    instr::trace<instr::event::global_pilot::init>( "Creating IPC message queue with id" , queueIdStr , "MaxMsgPayload", MaxMsgPayloadSize, "MaxMsgize", queue_t::MaxMsgSize, "MaxNumMsg", MaxNumMsg);
    m_ownQueue = std::make_unique<queue_t>( queueIdStr, MaxNumMsg );

      // Cross check with update_step, update_result in backend
      instr::trace<instr::event::learn_monitor::delay_measure>( "1/" + std::to_string(learn::intf::msg::SecondFraction) + " seconds" );
      // instr::trace<instr::event::learn_monitor::header_update_step>( "Ctg", "Input", "Output", "Reward", "DelayInfer", "DelayCost" );
      // instr::trace<instr::event::learn_monitor::header_update_result>( "Ctg", "TDError", "AvgReward", "PrevStateValue", "CurStateValue" );

      instr::trace<instr::event::learn_monitor::header_backprop_start>("Sample", "PrevState", "PrevStateValue", "Reward", "TDError" );
      instr::trace<instr::event::learn_monitor::header_softmax>("Sample", "Errors", "ActionProbs", "ChosenId", "TDError" );
      instr::trace<instr::event::learn_monitor::header_stateval>("Sample", "Error", "StateValue", "TDError" );
      instr::trace<instr::event::learn_monitor::header_summary>("ActorKind", "InputState", "StateValue", "ActorActiv");

    // 3. Spawning threads
    std::get< midend_of<msg::ctg::tasking> >( m_midends )->spawn();
    // std::get< midend_of<msg::ctg::threading> >( m_midends )->spawn(); // TODO OMITTED XXX DEBUG
  }

  ~master() {
    if (m_finalized) {
      instr::trace<instr::event::global_pilot::fini>( "Master successfully finalized" );
    } else {
      instr::trace<instr::event::global_pilot::fini>( "Master failed to properly finalize" );
    }
  }

private:

  template <msg::ctg MsgCtg, msg::kind MsgKind, std::size_t ContextId>
  void set_process_function( ) {

    using input_state_type = input_state_of_id<MsgCtg, MsgKind, ContextId>;

    using typed_t = msg::typed<MsgCtg, MsgKind, input_state_type>;

    static constexpr std::size_t RecSize = sizeof(msg::pack< sizeof(typed_t) >);

    m_processMapFuns[ std::make_tuple(MsgCtg, MsgKind, ContextId, RecSize) ] = 
      std::bind( &master::template process<MsgCtg, MsgKind, ContextId, RecSize>, this, std::placeholders::_1 );
  }


  template <msg::ctg MsgCtg, msg::kind MsgKind, std::size_t... ContentIds>
  void set_process_functions_2nd( util::sequence::index_t<ContentIds...> ) {
    ( set_process_function<MsgCtg, MsgKind, ContentIds>( ), ... );
  }



  template <msg::ctg MsgCtg, msg::kind... MsgKinds>
  void set_process_functions_1st( util::sequence::enum_t<msg::kind, MsgKinds...> ) {

    using input_states_ids_seq = input_states_ids_of<MsgCtg>;

    ( set_process_functions_2nd<MsgCtg, MsgKinds>( input_states_ids_seq{} ), ... );
  }



private:


  template < msg::ctg MsgCtg, msg::kind MsgKind, std::size_t ContextId, std::size_t RecSize >
  void process( void const * data ) {

    static_assert( util::same<MsgCtg, msg::ctg::tasking>::value or util::same<MsgCtg, msg::ctg::threading>::value );

    using input_state_type = input_state_of_id<MsgCtg, MsgKind, ContextId>; // May be void

    static_assert( std::disjunction_v< util::tuple::is_std<input_state_type>, std::is_same<input_state_type, void> > ); // Either std tuple or void

    using typed_t = msg::typed<MsgCtg, MsgKind, input_state_type>;

    static constexpr std::size_t PayloadSize = sizeof(typed_t);

    using pack_t = msg::pack< PayloadSize >;

    static_assert( RecSize == sizeof(pack_t) );

    pack_t const * packPtr = static_cast<pack_t const*>( data );

    instr::trace<instr::event::ipc_msg_queue::receive>( "Forwarding to backend" );

    std::get< midend_of<MsgCtg> >( m_midends )->template process_message<ContextId, typed_t>( packPtr->timePoint, *static_cast<typed_t const*>( static_cast<void const*>(packPtr->payload.data()) ) );
  }




public:

  void run( ) {

    try {

    instr::trace<instr::event::global_pilot::init>( NativeT::get_str_pilot_ready() );

      while (true) {

        instr::trace<instr::event::ipc_msg_queue::await>( );

        // TMP XXX XXX XXX DEBUG DISABLED
        // Blocks until message is received
        // auto [buffer, recSize] = m_ownQueue->receive();

        
        // TMP XXX XXX XXX DEBUG
        auto [buffer, recSize] = m_ownQueue->read_file_msg();


        // First field of the msg::pack is always msg::id_t regardless of payload size
        msg::id_t const* msgId = static_cast<msg::id_t const*>( static_cast<void const*>(buffer.data()) );

        // Since every msgId is associated to a typed message, and every typed message corresponds to a recSize, there must exist a function receiving this specific tuple, becase for each msgId there is a unique recSize

        if (msgId->vCtg == msg::ctg::terminate) {
          instr::trace<instr::event::ipc_msg_queue::receive>( "terminate" );
          break;
        }

        instr::trace<instr::event::ipc_msg_queue::receive>( "ctg", "kind", "ctxt", "bytes", (uint_t)msgId->vCtg, (uint_t)msgId->vKind, (uint_t)msgId->vContext, recSize );


        auto foundFnIt = m_processMapFuns.find( std::make_tuple( msgId->vCtg, msgId->vKind, msgId->vContext, recSize ) );

        if (foundFnIt == std::end(m_processMapFuns)) {
          throw std::runtime_error("Could not find message processing function for message id");
        }

        // This processing may be done synchronously or asynchronously (eg threader msgs are sync, the other are async)
        foundFnIt->second( buffer.data() );
      }

      instr::trace<instr::event::global_pilot::fini>( "Exiting run function normally" );

    } catch (const std::runtime_error& rte) {

      // Received by the runner process pipe
      instr::trace<instr::event::global_pilot::fini>( "Runtime error caught : ", rte.what() );

      this->tear_down();

    } catch (const std::logic_error& le) {

      // Received by the runner process pipe
      instr::trace<instr::event::global_pilot::fini>( "Logic error caught : ", le.what() );

      this->tear_down();

    } catch ( ... ) {

      instr::trace<instr::event::global_pilot::fini>( "Unknown error caught" );

      this->tear_down();
    }

  }

public:

  void tear_down( ) {

    // Each midend sends termination messages and joins threads within tear_down
    if (not m_finalized) {

      instr::trace<instr::event::global_pilot::fini>( "Tearing down" );

      std::get< midend_of<msg::ctg::tasking> >( m_midends )->finalize();
      // std::get< midend_of<msg::ctg::threading> >( m_midends )->finalize(); TODO OMITTED XXX DEBUG

      m_finalized = true;

      instr::trace<instr::event::global_pilot::fini>( "Tearing down OK" );

    } else {

      instr::trace<instr::event::global_pilot::fini>( "Tear down already done" );
    }
  }

};

} // namespace learn::intf
