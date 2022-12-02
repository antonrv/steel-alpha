
export module SteelRT.Task.Dispatcher;

  export import SteelRT.Task.Dispatcher.Promise;
  export import SteelRT.Task.DescriptorState;
  export import SteelRT.Task.DispatcherState;

import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.Meta;
import SteelRT.Util.AppWork;

import SteelRT.Task.Descriptor;


import SteelRT.Instrument;

export import <experimental/coroutine>;


namespace task::coro {

export
template <app::impl AppImpl>
class dispatcher : public state::dispatcher {


public:

  using promise_type = dispatcher_promise_lite<AppImpl>;

  using handle_type = typename promise_type::handle_type;// std::experimental::coroutine_handle< promise_type >;


  dispatcher(handle_type h) :
    state::dispatcher( h.promise().get_attr_descriptor_ref(), AppImpl ),
    m_handle(h),
    m_ownDescriptor(nullptr),
    m_publishResultsDeleter(nullptr)
  {
    // instr::trace<instr::event::task_dispatcher::constructor>("main");
  }

  dispatcher(const dispatcher&) = delete;

  // We need this constructor because we need to build a shared ptr from an existing dispatcher right after the dispatcher is created (there is no way to build it in-place, without a move constructor, since the dispatcher object is internally built by the coroutine implementation mechanism)
  dispatcher(dispatcher&& other) :
    state::dispatcher( other.m_handle.promise().get_attr_descriptor_ref(), AppImpl ),
    m_handle(other.m_handle),
    m_ownDescriptor(nullptr),
    m_publishResultsDeleter(nullptr)
  {
    // instr::trace<instr::event::task_dispatcher::constructor>("move");
  }


  ~dispatcher() {
    // instr::trace<instr::event::coro_dispatcher::destructor>();
    if (m_ownDescriptor) {
      // We use the existence of ownedDescriptor to know if (this) owns a handle.
      // We need this because we need to avoid the destruction of the coroutine when it is first moved to a shared_ptr
      // instr::trace<instr::event::coro_dispatcher::destroying_handle>();
      // instr::trace<instr::event::task_dispatcher::handle_status>("in destructor, handle ", m_handle.done() ? "done" : "not done");
      m_handle.destroy();

      if (state::dispatcher::get_status() == state::dispatcher_status::depleted) {
        // Ie, not alive or error, successfully finished
        // instr::trace<instr::event::task_dispatcher::destructor>("depleted");
        m_ownDescriptor.get_deleter() = m_publishResultsDeleter;
      } else {
        // instr::trace<instr::event::task_dispatcher::destructor>("not depleted");
      }
    }
  }


  workload::own_poly_desc_t try_resume( ) noexcept {

    workload::own_poly_desc_t ownPolyDesc = nullptr;

    // instr::trace<instr::event::task_dispatcher::trying_resume>();

    if (not m_handle.done()) {

      // instr::trace<instr::event::task_dispatcher::handle_status>(m_handle.done() ? "done" : "not done");

      auto tryLock = state::dispatcher::try_acquire();

      if (tryLock.owns_lock()) {

        // m_handle.promise().template set_extract_config< ResumerAppGroupImplTupleT >( );

        // Resumed on the current thread
        try {

          // instr::trace<instr::event::task_dispatcher::acquired>();

          m_handle.resume();

          // instr::trace<instr::event::task_dispatcher::released>();

          ownPolyDesc = m_handle.promise().extract_descriptor(); // May be nullptr

          state::dispatcher::set_status( m_handle.done() ? state::dispatcher_status::depleted : state::dispatcher_status::alive );

          // instr::trace<instr::event::task_dispatcher::handle_status>(m_handle.done() ? "done" : "not done");

        } catch (...) {
          // We could rethrow the exception here, if so remove noexcept from here and from the caller

          state::dispatcher::set_status( state::dispatcher_status::error );
        }
      }
    }
    // instr::trace<instr::event::task_dispatcher::returning>(ownPolyDesc.get());

    return ownPolyDesc;
  }


private:


  // coroutine handle
  handle_type m_handle;


  // No need to have it casted, although we could
  using owned_descriptor_t = workload::wtraits< workload::kind::desc >::own_poly_type; // A unique ptr with a deleter

  using deleter_t = workload::wtraits< workload::kind::desc >::deleter_type;

  owned_descriptor_t m_ownDescriptor = nullptr;

  deleter_t m_publishResultsDeleter = nullptr;

public:

  // To be called right after we have an owned dispatcher wrapped in a shared_ptr ()
  void set_owned_descriptor(owned_descriptor_t&& ownDesc, const deleter_t& del) noexcept {

    m_ownDescriptor = std::move(ownDesc);

    // Will be conditionally used as a final deleter of m_ownDescriptor if no error happened
    m_publishResultsDeleter = del;
  }

};


};
