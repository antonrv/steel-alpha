
export module SteelRT.Task.Dispatcher.Promise;

// import SteelRT.Util.FwDeclarations.Work;
import SteelRT.Util.Require;
import SteelRT.Util.App;
import SteelRT.Util.Work;

import SteelRT.Dep.Guard.Frontend;

export import SteelRT.Task.Dispatcher.Promise.Base;



export import SteelRT.Task.Dispatcher.Awaiter;

export import SteelRT.Task.Descriptor;



import <experimental/coroutine>;


namespace task::coro {


template <typename T>
struct is_awaitable_descriptor : std::false_type { };

template <app::call AppCall, typename ArgTupleT>
struct is_awaitable_descriptor< std::unique_ptr< task::descriptor<AppCall, ArgTupleT>, workload::wtraits<workload::kind::desc>::deleter_type> > : std::true_type { };

//////////////////////////////// DISPATCHER PROMISE (The runtime-side of a coroutine (ie the promise-like part) )
export
template <app::impl AppImpl>
class dispatcher_promise : public dispatcher_promise_base<AppImpl> {

  using super_type = dispatcher_promise_base<AppImpl>;

public:

  template <typename... Ts>
  dispatcher_promise( attr::descriptor& originalAttrs, Ts... ) :
    super_type(originalAttrs)
  {
    // instr::trace<instr::event::coro_promise::constructor>();
  }

  /////////////
  //
  // Functions called from compiler-generated calls within the coroutine body
  //
  /////////////

  // We want to transform co_await on polytasks (bndTuples with impl info) expressions into awaitables, so an executor can keep in the coroutine without suspending until it finds a task that it can put in its local queue.
  template <
    typename OwnDescT,
    util::req_t< is_awaitable_descriptor<OwnDescT> >...
  >
  auto await_transform(OwnDescT&& ownDesc) noexcept { // This can be const TODO

    // instr::trace<instr::event::coro_promise::await_transform>();

    using desc_type = typename OwnDescT::element_type;
    using group_impl_type = typename desc_type::group_impl_type;

    super_type::m_lastAwait = last_await::called;

    if (super_type::m_pushGreed > 0) {
  
      return dispatch_push_awaiter< OwnDescT, AppImpl >( std::forward<OwnDescT>(ownDesc), *this );

    } else {

      return dispatch_extract_awaiter< OwnDescT, AppImpl >( std::forward<OwnDescT>(ownDesc), *this );
    }
  }

  // Needed ?? 
  template <
    typename GuardFndT,
    util::req_t< dep::guard::fnd::is<GuardFndT> >...
  >
  guard_awaiter<GuardFndT> await_transform(GuardFndT& guardFndRef) noexcept {
    super_type::m_lastAwait = last_await::guard_destroy;
    return guard_awaiter<GuardFndT>(guardFndRef);
  }

  // Always suspend on suspend_always
  suspend await_transform(suspend&& s) noexcept {
    super_type::m_lastAwait = last_await::guard_destroy;
    return s;
  }
  

  // Called at the begining of the coroutine instance (a dispatcher instance)
  auto get_return_object() {
    // From promise returns a coroutine handle
    // which implicitly builds a dispatcher
    // instr::trace<instr::event::coro_promise::building_resumable>();
    return super_type::handle_type::from_promise(*this);
  }

  auto initial_suspend() { return std::experimental::suspend_always(); } // We could also suspend_never
  auto final_suspend() { return std::experimental::suspend_always(); } // Need to suspend always so that the 'done' method of the handle works fine

  // Need to be defined, because our coroutine is finite (runs until its end), but does not return anything at the end via co_return
  void return_void() noexcept {}

  void unhandled_exception() {
    // instr::trace<instr::event::coro_promise::captured_error>();
    auto exceptionPtr = std::current_exception();
    if (exceptionPtr) {
      std::rethrow_exception(exceptionPtr);
    }
  }

};

} // namespace task::coro
