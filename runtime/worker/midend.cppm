
export module SteelRT.Worker.Midend;

  export import SteelRT.Worker.Backend;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Work.Container;

import SteelRT.Instrument;


// The worker::midend layer makes threads constantly loop to get available workload to execute, forwarding it to the backend layer.
// Worker threads look for work according to a mission, specified on the frontend layer
// For the moment this midend layer is very basic though.


namespace worker {

export
template < plat::processor ProcId, class NativeT >
class midend {
private:


  template <workload::kind WorkKind>
  using ref_cont_t = std::reference_wrapper<workload::container<WorkKind>>;

  using containers_t = std::pair< ref_cont_t<workload::kind::desc>, ref_cont_t<workload::kind::disp> >;

  containers_t m_containers;


  template <workload::kind WorkKind>
  inline
  workload::container<WorkKind>& edit_container() noexcept {
    return std::get< ref_cont_t<WorkKind> >( m_containers ).get();
  }

  template <workload::kind WorkKind>
  inline
  const workload::container<WorkKind>& get_container() const noexcept {
    return std::get< ref_cont_t<WorkKind> >( m_containers ).get();
  }



  using backend_t = worker::backend<ProcId, NativeT>;

  backend_t m_workerBackend;


 // XXX TMP XXX   TERMINATION STUFF (CONSIDER POISON PILL)
  std::mutex m_mutex;
  std::condition_variable m_condVar;

  std::atomic<uint_t> m_nAlive = 0;
  std::atomic<uint_t> m_nAwaiting = 0;

  bool m_doTerminate = false;

public:


  midend( const learn::runner::cfg& runnerCfg, workload::container<workload::kind::desc>& descContRef, workload::container<workload::kind::disp>& dispContRef) :
    m_containers( std::make_pair( std::ref(descContRef), std::ref(dispContRef) ) ),
    m_workerBackend( runnerCfg, std::bind( &workload::container<workload::kind::disp>::push, &edit_container<workload::kind::disp>(), std::placeholders::_1 ) )
  {}

  midend(midend&&) = delete;
  midend(const midend&) = delete;

private:
  // --------- do_after_operate. Terminal function

  template <
    workload::kind WorkKind,
    util::req_t< util::same<WorkKind, workload::kind::desc> > ...
  >
  void do_after_operate( thread_id_t thId, workload::own_poly_desc_t&& ownPolyDesc ) {

    if (ownPolyDesc) {

      // Not ready, repush
      edit_container<workload::kind::desc>().push( std::move(ownPolyDesc) );


    } else {

      // Executed. Do nothing
    }

    // Notify in all cases bc if nullptr it may be transformed into a dispatcher
    m_condVar.notify_all();
  }

  template <
    workload::kind WorkKind,
    util::req_t< util::same<WorkKind, workload::kind::disp> > ...
  >
  void do_after_operate( thread_id_t thId, workload::own_poly_desc_t&& ownPolyDesc ) {

    if (ownPolyDesc) {

      // Dispatcher resume succeeded
      do_after_operate<workload::kind::desc>( thId, m_workerBackend.template operate<workload::kind::desc>( thId, std::move(ownPolyDesc) ) );

    } else {

      // Dispatcher resume failed. Do nothing
    }
  }


  // --------- process_workload. Intermediate functions

  
  template <
    workload::kind WorkKind,
    util::req_t< util::same<WorkKind, workload::kind::desc> > ...
  >
  void process_workload( thread_id_t thId, workload::own_poly_desc_t&& ownPolyDesc ) {

    if (ownPolyDesc) {

      do_after_operate<WorkKind>( thId, m_workerBackend.template operate<WorkKind>( thId, std::move(ownPolyDesc) ) );

    } else {

      // no poly, do nothing
    }
  }

  template <
    workload::kind WorkKind,
    util::req_t< util::same<WorkKind, workload::kind::disp> > ...
  >
  void process_workload( thread_id_t thId, workload::own_poly_disp_t&& ownPolyDisp ) {

    while (ownPolyDisp) {

      auto retOperate = m_workerBackend.template operate<WorkKind>( thId, ownPolyDisp );

      if (retOperate) {

        // Managed to extract a task from the coroutine

        do_after_operate<WorkKind>( thId, std::move(retOperate) );

      } else {

        // Didn't manage to extract a task from the coroutine. Get out
        return;
      }
    }
  }



  template < workload::kind WorkKind >
  void work_loop( thread_id_t thId ) {

    while (edit_container<WorkKind>().has_work()) {

      if (auto ownPoly = edit_container<WorkKind>().try_pop()) {

        process_workload< WorkKind >( thId, std::move(ownPoly) );
      }
    }
  }

private:

  bool has_work_any( ) const {

    return get_container<workload::kind::desc>().has_work() or get_container<workload::kind::disp>().has_work();
  }

  void await_for_work() {

    std::unique_lock<std::mutex> uLck(m_mutex);

    if (not has_work_any() and m_nAwaiting.load() == m_nAlive.load() - 1) {

      m_doTerminate = true;

      uLck.unlock();

      m_condVar.notify_all();

    } else if (not has_work_any() and m_nAwaiting.load() < 3) {

      m_nAwaiting++;

      m_condVar.wait( uLck, [this]() { return (m_doTerminate or has_work_any()); } );

      m_nAwaiting--;
    }

    return;
  }

public:

  void loop( thread_id_t thId ) {

    m_nAlive++;

    if (thId != global::MainThreadId) {

      instr::subscribe_thread(thId, NativeT::template get_proc_str<ProcId>() + "_th" + std::to_string(thId));
    } else {

      thId = 0; // To avoid overflow in user arrays
    }

    while (not m_doTerminate or has_work_any()) {

      await_for_work( );

      work_loop<workload::kind::desc>( thId );

      work_loop<workload::kind::disp>( thId );
    }
    
    instr::trace<instr::event::worker_backend::ready_to_join>();
  }


public:


  template <typename TrueEncoderT>
  void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {
    m_workerBackend.initialize_true_encoder( trueEncoderRef );
  }


};

} // namespace worker
