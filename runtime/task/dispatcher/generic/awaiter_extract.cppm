
export module SteelRT.Task.Dispatcher.Awaiter.Extract;

// import SteelRT.Util.FwDeclarations.Work;
import SteelRT.Util.App;
import SteelRT.Util.Work;

import SteelRT.Task.Dispatcher.Promise.Base;


import <functional>;


namespace task::coro {


export
template <class OwnDescT, app::impl AppImpl>
class dispatch_extract_awaiter {

private:

  using desc_type = typename OwnDescT::element_type;

  using group_impl_type = workload::wtraits< workload::kind::desc >::queue_parameter_type<AppImpl>;

  using promise_type = dispatcher_promise_base<AppImpl>;

  OwnDescT m_ownDesc;

  promise_type& m_promiseRef;

public:

  // This should be very fast to build, since we are just initializing references from existing objects
  dispatch_extract_awaiter(OwnDescT&& d, promise_type& promiseRef) :
    m_ownDesc(std::forward<OwnDescT>(d)),
    m_promiseRef(promiseRef)
  {
    // instr::trace<instr::event::coro_awaiter::constructor>()
  }

  ~dispatch_extract_awaiter() {
    // instr::trace<instr::event::coro_awaiter::destructor>();
  }


  // --------- AWAIT READY ---------
  bool await_ready() noexcept {

    if (not m_promiseRef.template get_enabled_extract< group_impl_type >()) {

      // Descriptor not compatible with the resumer, so push it to the global queue

      // instr::trace<instr::event::coro_awaiter::not_compatible_task>();

      m_promiseRef.get_push_global()( std::move(m_ownDesc) );

      return true; // so that thread can keep operating on the coroutine, looking for a compatible task to extract

    } else {

      // Descriptor will be pushed to local queue. Suspend the coroutine and push it to local queue in await_suspend
      // instr::trace<instr::event::coro_awaiter::compatible_task>();
      return false;
    }
  }


  // --------- AWAIT SUSPEND ---------
  template <typename CoroHandleT>
  void await_suspend(CoroHandleT handle) noexcept {

    // instr::trace<instr::event::coro_awaiter::await_suspend>();

    m_promiseRef.set_extract_descriptor( std::move(m_ownDesc) );
  }


  // --------- AWAIT RESUME ---------
  void await_resume() noexcept {
    // No action, nothing to return
  }



};

} // namespace task::coro
