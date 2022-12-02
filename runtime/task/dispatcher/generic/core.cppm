
export module SteelRT.Task.Dispatcher;

export import SteelRT.Task.Dispatcher.Promise;


export import SteelRT.Util.Sequence;
import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.Require;
// import SteelRT.Util.FwDeclarations.Work;
import SteelRT.Util.App;
import SteelRT.Util.Work;

import SteelRT.Task.Descriptor;
export import SteelRT.Task.DescriptorState;
export import SteelRT.Task.DispatcherState;

// import SteelRT.Work.Descriptor.Global;
// import SteelRT.Work.FwDeclarations;

import SteelRT.Dep.Guard.Frontend;


// export import SteelRT.Instrument;

export import <experimental/coroutine>;


namespace task::coro {



//////////////////////////////// DISPATCHER (The user-side part (a future-like) of a coroutine 
export
template <app::impl AppImpl>
class dispatcher : public state::dispatcher {

  static_assert( app::is_dispatcher<AppImpl>::value );

  using own_poly_desc_t = workload::wtraits< workload::kind::desc >::own_poly_type;

public:

  using promise_type = dispatcher_promise<AppImpl>;

  using handle_type = std::experimental::coroutine_handle< promise_type >;

  dispatcher(handle_type h) :
    state::dispatcher( h.promise().get_attr_descriptor_ref(), AppImpl ),
    m_handle(h),
    m_ownDescriptor(nullptr),
    m_publishResultsDeleter(nullptr)
  {
    // instr::trace<instr::event::coro_dispatcher::constructor>();
  }

  dispatcher(const dispatcher&) = delete;

  // We need this constructor because we need to build a shared ptr from an existing dispatcher right after the dispatcher is created (there is no way to build it in-place, without a move constructor, since the dispatcher object is internally built by the coroutine implementation mechanism)
  dispatcher(dispatcher&& other) :
    state::dispatcher( other.m_handle.promise().get_attr_descriptor_ref(), AppImpl ),
    m_handle(other.m_handle),
    m_ownDescriptor(nullptr),
    m_publishResultsDeleter(nullptr)
  {
    // instr::trace<instr::event::coro_dispatcher::move_constructor>();
  }

  ~dispatcher() {
    // instr::trace<instr::event::coro_dispatcher::destructor>();
    if (m_ownDescriptor) {
      // We use the existence of ownedDescriptor to know if (this) owns a handle.
      // We need this because we need to avoid the destruction of the coroutine when it is first moved to a shared_ptr
      // instr::trace<instr::event::coro_dispatcher::destroying_handle>();
      m_handle.destroy();

      if (state::dispatcher::get_status() == state::dispatcher_status::depleted) {
        // Ie, not alive or error, successfully finished
        m_ownDescriptor.get_deleter() = m_publishResultsDeleter;
      }
    }
  }

  // Resumers will try to extract a task from the coroutine to push it to a set of allowed queues.
  // Resumers could successfully extract a task but fail to push it into a queue due to incompatibility. In that case it is placed in the global queue
  template <typename ResumerTuplePushFnT>
  void
  try_resume_push( greed_t pushGreed, const ResumerTuplePushFnT& resumerPushFns ) noexcept {

    // instr::trace<instr::event::coro_dispatcher::trying_resume>();

    if (not m_handle.done()) {

      // instr::trace<instr::event::coro_dispatcher::handle_alive>();

      auto tryLock = state::dispatcher::try_acquire();

      if (tryLock.owns_lock()) {

        // instr::trace<instr::event::coro_dispatcher::handle_acquired>();

        m_handle.promise().set_push_config( pushGreed, resumerPushFns );

        // Resumed on the current thread
        try {

          m_handle.resume();

          // instr::trace<instr::event::coro_dispatcher::reseting_done>(m_handle.done());

          state::dispatcher::set_status( m_handle.done() ? state::dispatcher_status::depleted : state::dispatcher_status::alive );

          // instr::trace<instr::event::coro_dispatcher::handle_released>();


        } catch (...) {
          // We could rethrow the exception here, if so remove noexcept from here and from the caller

          // instr::trace<instr::event::coro_dispatcher::error>();

          state::dispatcher::set_status( state::dispatcher_status::error );

        }
  

      } else {
        // instr::trace<instr::event::coro_dispatcher::handle_used>();
      }
    } else {
      // instr::trace<instr::event::coro_dispatcher::handle_finalized>();
    }

  }


  // Resumers will try to extract a task from the coroutine to process it right away
  // Resumers could extract an incompatible task. In that case it is placed in the global queue and this returns nullptr
  template <typename ResumerAppGroupImplTupleT>
  own_poly_desc_t
  try_resume_extract( ) noexcept {

    own_poly_desc_t ownPolyDesc = nullptr;

    if (not m_handle.done()) {

      auto tryLock = state::dispatcher::try_acquire();

      if (tryLock.owns_lock()) {

        m_handle.promise().template set_extract_config< ResumerAppGroupImplTupleT >( );

        // Resumed on the current thread
        try {

          m_handle.resume();

          ownPolyDesc = m_handle.promise().extract_descriptor(); // May be nullptr

          state::dispatcher::set_status( m_handle.done() ? state::dispatcher_status::depleted : state::dispatcher_status::alive );

        } catch (...) {
          // We could rethrow the exception here, if so remove noexcept from here and from the caller

          state::dispatcher::set_status( state::dispatcher_status::error );
        }
      }
    }

    return ownPolyDesc;
  }


private:


  // coroutine handle
  handle_type m_handle;


  // No need to have it casted, although we could
  using owned_descriptor_t = workload::wtraits< workload::kind::desc >::own_poly_type; // A unique ptr with a deleter

  using deleter_t = workload::wtraits< workload::kind::desc >::deleter_type;

  using push_poly_desc_t = workload::wtraits< workload::kind::desc >::push_poly_fn_t;

  owned_descriptor_t m_ownDescriptor = nullptr;

  deleter_t m_publishResultsDeleter = nullptr;

public:

  // To be called right after we have an owned dispatcher wrapped in a shared_ptr ()
  void set_owned_descriptor(owned_descriptor_t&& ownDesc, const deleter_t& del) noexcept {

    m_ownDescriptor = std::move(ownDesc);

    // Will be conditionally used as a final deleter of m_ownDescriptor if no error happened
    m_publishResultsDeleter = del;
  }

  void set_push_global( push_poly_desc_t& pushGlobal ) noexcept {
    m_handle.promise().set_push_global( pushGlobal );
  }

};


} // namespace task::coro
