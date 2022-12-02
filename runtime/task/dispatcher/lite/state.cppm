
export module SteelRT.Task.DispatcherState;

import SteelRT.Task.DescriptorState;
import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.App;

// import SteelRT.Instrument;

import <cstdint>;
import <mutex>;
// import <atomic>;

namespace task::state {


/////////////////////////// DISPATCHER ATTRIBUTES
export
enum class dispatcher_status : std::uint8_t {depleted = 0x0, alive = 0x1, error = 0x2}; // 1 bit


// DEPRECATED
// export
// enum class dispatcher_status_trial : std::uint8_t {skipped_depleted = 0x0, skipped_alive = 0x1, acquired_depleted = 0x2, acquired_task = 0x3, acquired_error = 0x4, acquired_finished = 0x5, acquired_guard_destroy = 0x6};

export
class dispatcher : public task::attr::descriptor {
private:



  const enum_uint_t m_appImpl;

  std::mutex m_mutex;

  dispatcher_status m_status = dispatcher_status::alive;


protected:

  dispatcher(const attr::descriptor& d, const app::impl i) : attr::descriptor(d), m_appImpl(static_cast<enum_uint_t>(i)) { }

public:

  std::unique_lock<std::mutex> try_acquire() noexcept {
    return std::unique_lock<std::mutex>( m_mutex, std::try_to_lock );
  }


  app::impl get_implementation() const noexcept {
    return static_cast<app::impl>(m_appImpl);
  }

  void set_status(dispatcher_status s) noexcept {
    m_status = s;
  }

  dispatcher_status get_status() const noexcept {
    return m_status;
  } 

};


} // namespace task::state

///////////// THINGS TO INCLUDE IN THE DESCRIPTOR STATE

  // Following vars are constant (and implicitly set) and packed in a single-word struct (non-atomic)
  // const unsigned rtId; // fixed
  // const unsigned rtCallId; // fixed
  // depth, (fixed)

  // unsigned rtImplId; // variable. May change consistently with m_argsAny, before resolution (non-atomic). may be grouped with previous. Used to identify the call implementation to be matched with the call args

  // Following vars are variable (and set by the runtime) and packed in atomic:
  // awaiters/dependents weight (variable during pre resolution)
  // locality of data (variable during pre resolution, fixed type derived from memspaces).

  // running-on state : (bit for kernel or dispatcher, if dispatcher, bits to encode the active ctxts that are pulling tasks. if kernel, only a single bit will be enabled). May be altered during resolution if it is a dispatcher

  // # of readers
  // bit for whether is being read-writen

// static constexpr std::size_t MaxAwaitersBits = MAX_BITS_WORD - MAX_BITS_ENQUEUED - MAX_BITS_DEPTH - util::log2i(app::NAppIds) - app::NAppIds;

