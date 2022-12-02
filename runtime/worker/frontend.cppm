

export module SteelRT.Worker.Frontend;

  export import SteelRT.Worker.Midend;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Work.Container;

export import <thread>;


// The worker::frontend layer interfaces with the master frontend layer, providing an interface to spawn worker threads and make worker threads to await for missions.

import <tuple>;
import <array>;


namespace worker {


export
template < plat::processor ProcId, class NativeT >
class frontend {
private:

  static constexpr std::size_t NMaxThreads = NativeT::template max_threads<ProcId>;


  uint_t m_nActiveThreads = 0;

  using midend_t = worker::midend<ProcId, NativeT>;
  midend_t m_workerMidend;

  std::array< std::thread, NMaxThreads > m_threads;

public:

  // friend template class master::frontend<NativeT>;

  midend_t& get_ref_midend() noexcept {
    return m_workerMidend;
  }

public:

  frontend( const learn::runner::cfg& runnerCfg, workload::container<workload::kind::desc>& descContRef, workload::container<workload::kind::disp>& dispContRef) :
    m_workerMidend(runnerCfg, descContRef, dispContRef)
  {}

  frontend(frontend&&) = delete;
  frontend(const frontend&) = delete;


  void spawn( uint_t nActiveThreads ) {

    m_nActiveThreads = nActiveThreads;

    if (m_nActiveThreads == 0) {
      return;
    }

    for (thread_id_t thId = 0u; thId < m_nActiveThreads; thId++) {
      m_threads[ thId ] = std::thread( &midend_t::loop, &m_workerMidend, thId );
    }
  }


  void join( ) {

    for (thread_id_t thId = 0u; thId < m_nActiveThreads; thId++) {
      m_threads[ thId ].join();
    }

    m_nActiveThreads = 0;
  }


public:

  template <typename TrueEncoderT>
  void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {
    m_workerMidend.initialize_true_encoder( trueEncoderRef );
  }

};


template <typename NativeT, plat::processor... ProcIds>
using tuple_frontends = std::tuple< std::unique_ptr< worker::frontend<ProcIds, NativeT> > ... >;


export
template <typename NativeT, plat::processor... ProcIds>
tuple_frontends<NativeT, ProcIds...> make_frontends( const learn::runner::cfg& runnerCfg, workload::container<workload::kind::desc>& descContRef, workload::container<workload::kind::disp>& dispContRef, util::sequence::enum_t<plat::processor, ProcIds...> ) {
  return std::make_tuple( std::make_unique< worker::frontend<ProcIds, NativeT> >( runnerCfg, descContRef, dispContRef) ... );
}


} // namespace worker
