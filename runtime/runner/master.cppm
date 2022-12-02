
export module SteelRT.Runner.Master;

  export import SteelRT.Worker.Frontend;
  export import SteelRT.Work.Container;

  export import SteelRT.Learn.Agent.Runner.Threader;
  export import SteelRT.Learn.Feat.Encoder;

 
import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
import SteelRT.Util.AppWork;


import SteelRT.Instrument;


namespace runner {

// Episodic master: Single task framework
export
template <typename NativeT>
class master {
private:

  workload::container<workload::kind::desc> m_descriptorContainer;
  workload::container<workload::kind::disp> m_dispatcherContainer;


///////////// MAIN APP PARAM ENCODER (set when a new task arrives)

  // Here we could open to co-scheduling problems in which multiple independent apps are run in the same platform.
  // We would have a NativeT::max_concurrent_apps and one encoder tuple<app_param, app_id> for each.
  // Each app would have a reward function that specifies which behaviors are good/bad.
  // The threader agents would assign a specific number of threads / work queues to each.

  using main_param_encoder = learn::feat::encoder< learn::feat::kind::app_params, app::tuple_call_feed_t<NativeT::main_call> >;

  main_param_encoder m_mainParamEncoder;


///////////// THREADER AGENT

  using threader_agent_t = learn::agent::runner::threader< NativeT >;
  using own_threader_agent_t = std::unique_ptr<threader_agent_t>;

  own_threader_agent_t m_ownThreaderAgent;

  using all_multithread_proc_ids = typename NativeT::all_multithread_proc_ids;

  using chosen_threads_t = typename NativeT::chosen_threads_t;


///////////// WORKER FRONTENDS

  template <plat::processor ProcId>
  using frontend_of_t = std::unique_ptr< worker::frontend<ProcId, NativeT> >;

  using worker_frontends_t = util::tuple::lift_enums_t< all_multithread_proc_ids, frontend_of_t >;

  using tuple_worker_frontends_t = util::tuple::as_std_t< worker_frontends_t >;

  tuple_worker_frontends_t m_workerFrontends;

///////////// DEFAULT WORKER MIDDEND (when no workers are spawned, master thread uses these midend)

  worker::midend<NativeT::default_processor, NativeT>& m_defaultMidendRef;

private:

  template <std::size_t... ProcIdxs>
  uint_t count_threads_to_spawn( const chosen_threads_t& chosenThreads, util::sequence::index_t<ProcIdxs...> ) const noexcept {
    return (chosenThreads[ProcIdxs] + ... + 0);
  }

///////////////// SPAWN ALL
  template <plat::processor WorkerProcId>
  void spawn_on( const chosen_threads_t& chosenThreads )  {
    static constexpr std::size_t WorkerProcIdx = util::sequence::get_index_v< all_multithread_proc_ids, WorkerProcId >;
    std::get<frontend_of_t<WorkerProcId>>( m_workerFrontends )->spawn( chosenThreads[WorkerProcIdx] );
  }

  template <plat::processor... WorkerProcIds>
  void spawn_all(const chosen_threads_t& chosenThreads, util::sequence::enum_t<plat::processor, WorkerProcIds...> ) {
    ( spawn_on<WorkerProcIds>( chosenThreads ), ... );
  }

///////////////// JOIN ALL

  template <plat::processor... WorkerProcIds>
  void join_all( util::sequence::enum_t<plat::processor, WorkerProcIds...> ) { ( std::get<frontend_of_t<WorkerProcIds>>( m_workerFrontends )->join( ), ... ); }


///////////////// PASS TRUE MAIN ENCODER DOWNSTREAM TO WORKER FRONTENDS

  template <plat::processor... WorkerProcIds>
  void initialize_main_encoder_in_workers( util::sequence::enum_t<plat::processor, WorkerProcIds...> ) {

    ( std::get< frontend_of_t<WorkerProcIds> >( m_workerFrontends )->initialize_true_encoder( m_mainParamEncoder ), ... );
  }

///////////////// PASS TRUE THREADER ENCODER DOWNSTREAM TO WORKER FRONTENDS

  template <plat::processor WorkerProcId, plat::processor... ThreaderProcIds>
  void initialize_threader_encoders_in_workers( util::sequence::enum_t<plat::processor, ThreaderProcIds...> ) {

    ( std::get< frontend_of_t<WorkerProcId> >( m_workerFrontends )->initialize_true_encoder( m_ownThreaderAgent->template get_true_encoder<ThreaderProcIds>() ), ... );
  }

  // 1st pass
  template <plat::processor... WorkerProcIds>
  void initialize_all_threader_encoders_in_workers( util::sequence::enum_t<plat::processor, WorkerProcIds...> ) {
    ( initialize_threader_encoders_in_workers<WorkerProcIds>( all_multithread_proc_ids{}  ), ... );
  }



public:

  master( const learn::runner::cfg& runnerCfg ) :
    m_ownThreaderAgent( std::make_unique<threader_agent_t>( runnerCfg ) ),
    m_descriptorContainer(),
    m_dispatcherContainer(),
    m_workerFrontends( worker::make_frontends<NativeT>( runnerCfg, m_descriptorContainer, m_dispatcherContainer, typename NativeT::all_proc_ids{} ) ),
    m_defaultMidendRef( std::get< frontend_of_t<NativeT::default_processor> >( m_workerFrontends )->get_ref_midend() )
  {
    m_ownThreaderAgent->initialize_true_encoder( m_mainParamEncoder ); 

    initialize_main_encoder_in_workers( all_multithread_proc_ids{} ); 

    initialize_all_threader_encoders_in_workers( all_multithread_proc_ids{} ); 
  }



  void operate( workload::own_poly_desc_t&& ownPolyDesc ) {

    m_mainParamEncoder.set_encoded_features( static_cast< workload::wtraits<workload::kind::desc>::descriptor_type<NativeT::main_call> * >( ownPolyDesc.get() ) );


    float computeLoad = 1.f; // exe::estimate_load< MainAppCall >( ownPolyDesc.get() ); // TODO

    m_descriptorContainer.push( std::forward<workload::own_poly_desc_t>(ownPolyDesc) );

    thread_id_t mainThreadIdAsUser = 0; // Don't do global::MainThreadID

    const chosen_threads_t& chosenThreads = m_ownThreaderAgent->choose( mainThreadIdAsUser, computeLoad );

      instr::trace<instr::event::learn_agent::pick_threads_end>("threads to spawn", chosenThreads);

    // if (count_threads_to_spawn( chosenThreads, util::sequence::make_index_t<all_multithread_proc_ids::size()>{} ) > 0 ) {
    if (false) { // XXX FIXME TMP


      // 2. Spawn threads for each proc and set global active features on worker backends
      spawn_all( chosenThreads, all_multithread_proc_ids{} );

      join_all( all_multithread_proc_ids{} );

    } else {

      // no threads on any, don't spawn anything, DIY

      m_defaultMidendRef.loop( global::MainThreadId );
    }

    threader_agent_t::learn_notify_end();

  }


};


} // namespace runner
