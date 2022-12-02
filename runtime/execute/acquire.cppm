
export module SteelRT.Execute.Acquire;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Dep.Dim.View;
import SteelRT.Dep.Guard.Backend;


// import SteelRT.Instrument;

export
namespace exe {

  // A guard backend over view type. Return via get_ptr
  template <
    typename KernelArgT,
    typename CallArgT,
    util::req_t<
      std::conjunction<
        dep::guard::bnd::is<std::decay_t<CallArgT>>,
        dep::guard::bnd::is_view<std::decay_t<CallArgT>>
      >
    >...
  >
  KernelArgT acquire(CallArgT& arg) {
    // instr::trace<instr::event::dep_acquire::getting_wrapped_view>();
    return arg.acquire().get_ptr();
  }

  // A guard backend over non-view type. Return via acquire
  template <
    typename KernelArgT,
    typename CallArgT,
    util::req_t<
      std::conjunction<
        dep::guard::bnd::is<std::decay_t<CallArgT>>,
        std::negation<dep::guard::bnd::is_view<std::decay_t<CallArgT>>>
      >
    >...
  >
  KernelArgT acquire(CallArgT& arg) {
    // instr::trace<instr::event::dep_acquire::getting_wrapped>();
    return arg.acquire();
  }

  // Not a guard backend. Return as is.
  template <
    typename KernelArgT,
    typename CallArgT,
    util::req_t< std::negation<dep::guard::bnd::is<std::decay_t<CallArgT>>> >...
  >
  KernelArgT acquire(CallArgT& arg) noexcept {
    // instr::trace<instr::event::dep_acquire::getting_non_wrapped>();
    return arg;
  }

} // namespace exe
