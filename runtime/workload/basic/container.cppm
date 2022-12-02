

export module SteelRT.Work.Container;

import SteelRT.Util.Values;

import SteelRT.Util.Work;


import SteelRT.Task.DescriptorState; // Not needed...
import SteelRT.Task.Descriptor;
import SteelRT.Task.Dispatcher;

export import SteelRT.Work.Queue;
export import SteelRT.Util.Work;
// export import SteelRT.Util.FwDeclarations.Work;

// import SteelRT.Util.Require;
import SteelRT.Util.Tuple;
import SteelRT.Instrument;

import <array>;

export
namespace workload {

// Container storing polymorphic objects, ignoring ImplSeqT
// template < workload::kind WorkKind, typename ImplSeqT >
template < workload::kind WorkKind >
class container {
private:

  using own_poly_t = typename wtraits< WorkKind >::own_poly_type;


  using queue_t = queue< WorkKind >;

  std::array< queue_t, global::DepthLimit > m_queues;


public:

  container() {}

  void push( own_poly_t&& ownPoly ) noexcept {

      // instr::trace<instr::event::workload_container::push_start>();

    auto d = static_cast<task::attr::descriptor*>(ownPoly.get())->depth;

    m_queues[ d ].push( std::forward<own_poly_t>(ownPoly) );

      // instr::trace<instr::event::workload_container::push_end>();
  }


  own_poly_t try_pop( ) noexcept {

      // instr::trace<instr::event::workload_container::try_pop>();

    auto d = 0;
    while ( d < global::DepthLimit ) {
      auto db = global::DepthLimit - 1 - d;
      if (not m_queues[ db ].empty()) {
        if (auto poped = m_queues[ db ].try_pop()) {
          // instr::trace<instr::event::workload_container::pop_success>();
          return poped;
        }
      }
      d++;
    }
    // instr::trace<instr::event::workload_container::pop_fail>();
    return nullptr;
  }


  bool empty() const noexcept {
    for (auto d = 0; d < global::DepthLimit; d++) {
      if (not m_queues[ d ].empty()) {
        return false;
      }
    }
    return true;
  }

  bool has_work() const noexcept {
    return (not this->empty());
  }

};


} // namespace workload
