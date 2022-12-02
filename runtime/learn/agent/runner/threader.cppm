
export module SteelRT.Learn.Agent.Runner.Threader;

  export import SteelRT.Learn.Agent.Runner.Threader.Single;


import SteelRT.Learn.Interface.Runner.Send; //Dont export XXX TODO

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;



namespace learn::agent::runner {


// This class holds objects to feat::kind::active_thread encoders, which are used by reference (feat::kind::ref) by thread_single agents.
// All other 'main' encoders (eg app_params encoder corresponding to the main task) are hold on master::frontend, and are passed via initialize_true_encoder interface

export
template <typename NativeT>
class threader {
private:

  using all_multithread_proc_ids = typename NativeT::all_multithread_proc_ids;

  static constexpr std::size_t NMultiThreadProcs = all_multithread_proc_ids::size();

  // ------ Ref main_param encoder (to be set). True object stored in master::frontend. No need to define the types here
  // using main_param_encoder = feat::encoder<feat::kind::app_params, app::tuple_call_feed_t<NativeT::main_call> >;

  // using main_param_ref_encoder = encoder_ref_of_t< main_param_encoder >;


  // ------  True active_threads encoders objects are hold here
  template <plat::processor AnyProcId> 
  using encoder_of_t = feat::encoder<feat::kind::active_threads, typename NativeT::template ptraits_of<AnyProcId>>;


  using tuple_thread_encoder = util::tuple::lift_enums_t< all_multithread_proc_ids, encoder_of_t >;

  using std_tuple_thread_encoder = util::tuple::as_std_t< tuple_thread_encoder >;

  std_tuple_thread_encoder m_threadEncoders;


  // ------  Individual threaders (one per ProcId)

  template <plat::processor ProcId>
  using threader_of_t = agent::runner::threader_single<ProcId, NativeT>;

  template <plat::processor ProcId>
  using own_threader_of_t = std::unique_ptr< threader_of_t<ProcId> >;

  using tuple_threader_agents = util::tuple::lift_enums_t< all_multithread_proc_ids, threader_of_t >;

  using own_tuple_threader_agents = util::tuple::lift_enums_t< all_multithread_proc_ids, own_threader_of_t >;

  using std_own_tuple_threader_agents = util::tuple::as_std_t< own_tuple_threader_agents >;

  std_own_tuple_threader_agents m_ownThreaderAgents;


  // The result of the threader operation, to be read by the caller

  using chosen_threads_t = std::array< uint_t, NMultiThreadProcs >;

  chosen_threads_t m_chosenThreads;


private: ///////////// INITIALIZE REF THREAD ENCODERS DEFINED IN THREADER_SINGLE FROM TRUE THREAD ENCODERS DEFINED HERE

  
  template <plat::processor ThreaderProcId, plat::processor... PrecedProcIds>
  void initialize_downstream_ref_encoders_of( util::sequence::enum_t<plat::processor, PrecedProcIds...> ) noexcept {
    
    ( std::get< own_threader_of_t<ThreaderProcId> >( m_ownThreaderAgents )->initialize_true_encoder( std::get<encoder_of_t<PrecedProcIds>>(m_threadEncoders) ), ... );

  }


  template <plat::processor ThreaderProcId>
  void initialize_downstream_ref_encoders( ) noexcept {

    using preced_proc_seq = typename threader_of_t<ThreaderProcId>::preceeding_proc_sequence;

    initialize_downstream_ref_encoders_of<ThreaderProcId>( preced_proc_seq{} );
  }


  template <plat::processor... ThreaderProcIds>
  void initialize_all_downstream_ref_encoders( util::sequence::enum_t<plat::processor, ThreaderProcIds...> ) noexcept {

    ( initialize_downstream_ref_encoders<ThreaderProcIds>(),  ... );
  }

private:

  template <plat::processor... ThreaderProcIds>
  static
  std_own_tuple_threader_agents
  make_threader_agents( const learn::runner::cfg& runnerCfg, util::sequence::enum_t<plat::processor, ThreaderProcIds...> ) {
    return std::make_tuple( std::make_unique<threader_of_t<ThreaderProcIds>>( runnerCfg ) ... );
  }

public: ///////////////// CONSTRUCTOR

  threader( const learn::runner::cfg& runnerCfg) :
    m_ownThreaderAgents( make_threader_agents( runnerCfg, all_multithread_proc_ids{} ) )
  {
    initialize_all_downstream_ref_encoders( all_multithread_proc_ids{} );
  }

private: ///////////// INITIALIZE REF ENCODERS DEFINED IN MASTER FRONTEND

  template <typename TrueEncoderT, plat::processor... ThreaderProcIds>
  void initialize_all_downstream_ref_encoders( TrueEncoderT& trueEncoderRef, util::sequence::enum_t<plat::processor, ThreaderProcIds...> ) noexcept {

    ( std::get< own_threader_of_t<ThreaderProcIds> >( m_ownThreaderAgents )->initialize_true_encoder( trueEncoderRef ), ... );
  }


public:

  // pass the main_call param encoder
  template <typename TrueEncoderT>
  void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {
    initialize_all_downstream_ref_encoders( trueEncoderRef, all_multithread_proc_ids{} );
  }

public: ///////////// RETRIEVE TRUE ENCODERS TO MASTER FRONTEND SO THAT THEY CAN BE PASSED TO INITIALIZE REF ENCODERS OF WORKER CONTEXTS

  template <plat::processor ThreaderProcId>
  const encoder_of_t<ThreaderProcId>& get_true_encoder() const noexcept {
    return std::get< encoder_of_t<ThreaderProcId> >( m_threadEncoders );
  }

private: ////////////// MAIN INTERFACE

  template <plat::processor ThreaderProcId>
  void choose_single( thread_id_t thId, float computeLoad ) noexcept {

    static constexpr std::size_t ProcIndex = util::sequence::get_index_v< all_multithread_proc_ids, ThreaderProcId >;

    m_chosenThreads[ ProcIndex ] = std::get< own_threader_of_t<ThreaderProcId> >( m_ownThreaderAgents )->choose( thId, computeLoad );

    // Set encoding, so that it is visible by successive threader agents
    std::get< encoder_of_t<ThreaderProcId> >( m_threadEncoders ).set_encoded_features( m_chosenThreads[ProcIndex] );
  }


  template <plat::processor... ProcIds>
  void choose_all( thread_id_t thId, float computeLoad, util::sequence::enum_t<plat::processor, ProcIds...> ) noexcept {

    // The preceed selections are the features of the future selections. First doesn't have preceed, second has 1 preceed, and so on.

    ( choose_single< ProcIds >( thId, computeLoad ), ... );
  }

public:

  const chosen_threads_t& choose( thread_id_t thId, float computeLoad ) noexcept {

    choose_all( thId, computeLoad, all_multithread_proc_ids{} );

    return m_chosenThreads;
  }

private:

  template <plat::processor... ProcIds>
  static void learn_notify_end_detail( util::sequence::enum_t<plat::processor, ProcIds...> ) {

    ( learn::intf::runner::send<NativeT, learn::intf::msg::ctg::threading, learn::intf::msg::kind::end, threader_of_t<ProcIds>>( /*nokey*/ ), ... );
  }

public:

  static void learn_notify_end( ) {
    learn_notify_end_detail( all_multithread_proc_ids{} );
  }


};

} // namespace learn::agent::runner
