export module SteelRT.Task.DescriptorState;

import SteelRT.Util.Basic;

// import SteelRT.Util.AppWork;



export import <atomic>; // So that atomic functions can be available for linking

namespace task::attr {


class init {
public:
  static std::atomic<counter_t> GlobalDescriptorCounter;
};

/////////////////////////// DESCRIPTOR ATTRIBUTES
export
struct alignas(4) descriptor {
  const youth_t youth;
  const enum_uint_t appId : util::bits_of(global::MaxAppIds);
  const enum_uint_t appCall : util::bits_of(global::MaxAppCalls);
  const depth_t depth : util::bits_of(global::DepthLimit);

  enum_uint_t get_app_index() const noexcept { return appId; }

  descriptor() noexcept :
    youth(global::MaxYouth),
    appId(global::PoisonPillAppIndex),
    appCall(global::PoisonPillCallIndex),
    depth(0)
  {}

  
  descriptor(app::id i, app::call c, depth_t d) noexcept :
    youth(init::GlobalDescriptorCounter++),
    appId( static_cast<enum_uint_t>(i) ),
    appCall( static_cast<enum_uint_t>(c) ),
    depth(d)
  { }

  // descriptor(const descriptor& d) = default; // Needed to copy updating the criticality state of the queue
};

} // namespace task::attr


namespace task::state {


export
class descriptor {
private:

//     enum_uint_t m_appImpl : util::bits_of(global::MaxAppImpls); // Probably not needed anymore. DEPRECATE TODO
//    defer_t m_defer = 0; // Reflects the amount of execution trials FROZEN FOR THE MOMENT
    solved_mask_t m_solvedMask = global::AllSolvedMask; // Init. For each arg, 0 if it is not solved and 1 if it is solved

public:

  descriptor() noexcept :
    // m_appImpl(global::PoisonPillImplIndex),
    // m_defer(0),
    m_solvedMask(global::AllSolvedMask)
  {}

  // descriptor(app::impl i, solved_mask_t sm) noexcept : 
  descriptor(solved_mask_t sm) noexcept : 
    // m_appImpl( static_cast<enum_uint_t>(i) ),
    // m_defer(0),
    m_solvedMask(sm) 
  {}

  descriptor(const descriptor&) = default; // Needed to copy updating the criticality state of the queue.

  // defer_t get_defer() const noexcept {
  //   return m_defer;
  // }

  // void increase_defer() noexcept {
  //   m_defer++;
  // }

  solved_mask_t get_solved_mask() const noexcept {
    return m_solvedMask;
  }

  void set_solved_mask(solved_mask_t sm) noexcept {
    m_solvedMask = sm;
  }

  // // TO BE DEPRECATED TODO
  // void set_implementation(const app::impl i) noexcept {
  //   m_appImpl = static_cast<enum_uint_t>(i);
  // }

  // // TO BE DEPRECATED TODO
  // app::impl get_implementation() const noexcept {
  //   return static_cast<app::impl>(m_appImpl);
  // }
  
};

} // namespace task::state

