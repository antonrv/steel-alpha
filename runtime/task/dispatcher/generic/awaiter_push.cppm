
export module SteelRT.Task.Dispatcher.Awaiter.Push;

import SteelRT.Util.App;


import SteelRT.Task.Dispatcher.Promise.Base;

import <functional>;



namespace task::coro {

//////////////////////////////// DISPATCH AWAITER

export
template <class OwnDescT, app::impl AppImpl>
class dispatch_push_awaiter {
private:


  using promise_type = dispatcher_promise_base<AppImpl>;

  OwnDescT m_ownDesc;

  promise_type& m_promiseRef;

public:

  // This should be very fast to build, since we are just initializing references from existing objects
  dispatch_push_awaiter(OwnDescT&& d, promise_type& promiseRef) :
    m_ownDesc(std::forward<OwnDescT>(d)),
    m_promiseRef(promiseRef)
  {
    // instr::trace<instr::event::coro_awaiter::constructor>()
  }

  ~dispatch_push_awaiter() {
    // instr::trace<instr::event::coro_awaiter::destructor>();
  }


  // --------- AWAIT READY ---------
  bool await_ready() noexcept {

    if (not m_promiseRef.template get_push_local< AppImpl >()) {

      // Function is nullptr, so descriptor cannot be pushed to local queue. Push it to the global queue

      // instr::trace<instr::event::coro_awaiter::not_compatible_task>();

      m_promiseRef.get_push_global()( std::move(m_ownDesc) );

      // Keep working on the coroutine
      return true;

    } else if (m_promiseRef.push_greed_unsatisfied()) {

      // Descriptor will be pushed to the local queue, and will keep extracting tasks until the limit is reached.

      m_promiseRef.template get_push_local< AppImpl >()( std::move(m_ownDesc) );

      // Keep working on the coroutine
      return true;

    } else {

      // Descriptor will be pushed to local queue. Suspend the coroutine and push the last one in await_suspend
      // instr::trace<instr::event::coro_awaiter::compatible_task>();

      // False, so it will call await_suspend right away and the last task will be pushed
      return false;
    }
  }


  // --------- AWAIT SUSPEND ---------
  template <typename CoroHandleT>
  void await_suspend(CoroHandleT handle) noexcept {

    // instr::trace<instr::event::coro_awaiter::await_suspend>();

    // Push last task
    m_promiseRef.template get_push_local< AppImpl >()( std::move(m_ownDesc) );
  }


  // --------- AWAIT RESUME ---------
  void await_resume() noexcept {
    // No action, nothing to return
  }

};

} // namespace task::coro
