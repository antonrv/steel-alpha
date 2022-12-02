

export module SteelRT.Task.Dispatcher.Awaiter.Guard;



namespace task::coro {

export
template <typename GuardFndT>
class guard_awaiter {
private:

  GuardFndT& m_guardFndRef;

public:
  guard_awaiter(GuardFndT& gfr) : m_guardFndRef(gfr) {}

  // --------- AWAIT READY ---------
  bool await_ready() const noexcept {
    // If it is destroyable, then the coroutine will not suspend and will destroy the guard::fnd.
    // If it is not destroyable, it means that we must wait for kernels to execute, so the coroutine will suspend.
    return m_guardFndRef.is_destroyable();
  }

  // --------- AWAIT SUSPEND ---------
  template <typename CoroHandleT>
  void await_suspend(CoroHandleT handle) const noexcept {
    // Do nothing, no actions to perform upon suspension
  }

  // --------- AWAIT RESUME ---------
  void await_resume() const noexcept {
    // No action, nothing to return
  }
};


} // namespace task::coro
