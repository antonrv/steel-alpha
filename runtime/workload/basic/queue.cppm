
export module SteelRT.Work.Queue;

import SteelRT.Util.Types;

import SteelRT.Util.FwDeclarations.Work;
import SteelRT.Util.Work;
import SteelRT.Util.Require;

import SteelRT.Task.Descriptor;
import SteelRT.Task.Dispatcher;

export import <queue>;
export import <mutex>;



export
namespace workload {


class worse_than_dispatcher {
  using compare_elem_t = typename wtraits< workload::kind::disp >::own_poly_type;
public:
  bool operator()(const compare_elem_t& lhs, const compare_elem_t& rhs) const noexcept {
    using dispatcher_state_type = task::state::dispatcher;
    using descriptor_attr_type = task::attr::descriptor;
    auto castedLhs = static_cast<const descriptor_attr_type*>( static_cast<const dispatcher_state_type*>(lhs.get()) );
    auto castedRhs = static_cast<const descriptor_attr_type*>( static_cast<const dispatcher_state_type*>(rhs.get()) );
    return castedLhs->depth < castedRhs->depth; // ie: lhs is worse than rhs according to depth if this is true (deeper is better)
  }
};

class worse_than_descriptor {

  using compare_elem_t = typename wtraits< workload::kind::desc >::own_poly_type;

public:

  bool operator()(const compare_elem_t& lhs, const compare_elem_t& rhs) const noexcept {
    // ptr_descriptor_t derives from poly_descriptor, which derives from attr::descriptor and state::descriptor
    using attr_desc_t = task::attr::descriptor;
    auto attrDescPtrLhs = static_cast<const attr_desc_t*>(lhs.get());
    auto attrDescPtrRhs = static_cast<const attr_desc_t*>(rhs.get());
    
    return attrDescPtrLhs->depth < attrDescPtrRhs->depth;
  }

};

template < kind WorkKind >
class queue {
private:

  using own_poly_t = typename wtraits< WorkKind >::own_poly_type;

  using worse_than_t = std::conditional_t< WorkKind == workload::kind::desc,
      worse_than_descriptor,
      worse_than_dispatcher
    >;

  using queue_t = std::priority_queue< own_poly_t, std::vector<own_poly_t>, worse_than_t >;

  // std::queue<own_poly_t>

  queue_t m_queue;

  std::mutex m_mutex;

  // std::condition_variable m_cv;

private:


  // --- Descriptors
  template <
    kind InputWorkKind,
    util::req_t< std::conjunction<util::same<InputWorkKind, workload::kind::desc>, util::same<WorkKind, workload::kind::desc> > > ...
  >
  own_poly_t custom_pop() noexcept {

    // own_poly_t ownTopDesc = std::move(const_cast<own_poly_t&>(m_queue.front()));
    own_poly_t ownTopDesc = std::move(const_cast<own_poly_t&>(m_queue.top()));

    m_queue.pop();

    return ownTopDesc;
  }


  // --- Dispatchers
  template <
    kind InputWorkKind,
    util::req_t< std::conjunction<util::same<InputWorkKind, workload::kind::disp>, util::same<WorkKind, workload::kind::disp> > > ...
  >
  own_poly_t custom_pop() noexcept {

    // if (m_queue.front()->get_status() == task::state::dispatcher_status::alive) {
    if (m_queue.top()->get_status() == task::state::dispatcher_status::alive) {

      if (m_queue.size() > 1) {


        // own_poly_t ownTopDisp = m_queue.front();
        own_poly_t ownTopDisp = m_queue.top();

        // Put it in the back, so that the same dispatcher is not blocking others
        m_queue.pop();

        m_queue.push( ownTopDisp );

        return ownTopDisp;

      } else {

        // return m_queue.front();
        return m_queue.top();
      }

    } else {

      // own_poly_t ownTopDisp = m_queue.front();
      own_poly_t ownTopDisp = m_queue.top();

      // Dispatcher is depleted or has an error
      m_queue.pop();

      return ownTopDisp;
    }
  }

public:

  queue() {}


  void push( own_poly_t&& ownElem ) noexcept {

    auto lck = std::lock_guard< std::mutex >( m_mutex );

    m_queue.push( std::forward<own_poly_t>(ownElem) );
  }

  // void push( own_poly_t&& ownElem ) noexcept {

  //   {
  //     auto lck = std::lock_guard< std::mutex >( m_mutex );

  //     m_queue.push( std::forward<own_poly_t>(ownElem) );
  //   }

  //   m_cv.notify_one();
  // }


  own_poly_t try_pop( ) noexcept {

    std::unique_lock<std::mutex> tryLck( m_mutex, std::try_to_lock );

    if (tryLck.owns_lock()) {

      if (m_queue.empty()) {
        return nullptr;
      }
  
      return custom_pop< WorkKind >();
    }
    return nullptr;
  }


  // own_poly_t try_pop( ) noexcept {

  //   own_poly_t retOwn = nullptr;

  //   {
  //     std::unique_lock<std::mutex> uLck( m_mutex );

  //     if (m_queue.empty()) {
  //       m_cv.wait( uLck, [this] () { return not m_queue.empty(); } );
  //     }
  // 
  //     retOwn = custom_pop< WorkKind >();
  //   }

  //   m_cv.notify_one();

  //   return retOwn;
  // }

  bool empty() const noexcept {
    return m_queue.empty();
  }
};

} // namespace workload
