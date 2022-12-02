
export module SteelRT.Task.Dispatcher.Awaiter;

import SteelRT.Util.AppWork;

import SteelRT.Task.Dispatcher.Promise.Base;

import <functional>;


namespace task::coro {

export
template <class OwnDescT, app::impl AppImpl>
class awaiter_lite {
private:


  using promise_type = dispatcher_promise_base_lite<AppImpl>;

  OwnDescT m_ownDesc;

  promise_type& m_promiseRef;


public:

  awaiter_lite(OwnDescT&& d, promise_type& promiseRef) :
    m_ownDesc(std::forward<OwnDescT>(d)),
    m_promiseRef(promiseRef)
  {
    // instr::trace<instr::event::coro_awaiter::constructor>()
  }

  ~awaiter_lite() {
    // instr::trace<instr::event::coro_awaiter::destructor>();
  }

  // --------- AWAIT READY ---------
  bool await_ready() noexcept {
    // Suspend immediately
    return false;
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
