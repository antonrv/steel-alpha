export module SteelRT.Dep.Guard.Frontend;

import SteelRT.Dep.State;
export import SteelRT.Dep.Guard.Backend;

export
namespace dep::guard::fnd {

///// Objects created at the frontend
template <typename T>
class readable {
private:

  using input_t = T;
  using state_pointee_t = std::remove_reference_t<T>;
  using copy_t = std::decay_t<T>;

  state::readable<state_pointee_t> m_readState;

public:
  readable(input_t& vRef) : 
    m_readState(vRef)
  {}

  explicit readable(const readable& ) = delete;
  readable(readable&& ) = delete;


  // Call to this must be done just after initialization (ie if we know it is ready at compile time)
  copy_t use_copy() const noexcept {
    return m_readState.get_const_ref();
  }

  auto emit_bnd_reader() const noexcept {
    return bnd::readable<state_pointee_t>(m_readState);
  }

  // This is what will be called at coroutine termination when we co_await on objects of this type to TAR protection
  bool is_destroyable() const noexcept {
    return m_readState.is_destroyable();
  }
};


///// Objects created at the frontend
template <typename T>
class writable {
private:

  using input_t = T;
  using state_pointee_t = std::remove_reference_t<T>;
  using copy_t = std::decay_t<T>;

  state::writable<state_pointee_t> m_writeState;

public:

  // Undefined
  writable() :
    m_writeState()
  {}

  // Initialized
  explicit writable(input_t& vRef) : 
    m_writeState(vRef)
  {}

  writable(const writable&) = delete;
  writable(writable&&) = delete;

  // Call to this must be done just after initialization (ie if we know it is ready at compile time)
  copy_t use_copy() const noexcept {
    return m_writeState.get_const_ref();
  }

  auto emit_bnd_reader() const noexcept {
    return bnd::readable<state_pointee_t>(m_writeState);
  }

  auto emit_bnd_writer() noexcept {
    state::readable<state_pointee_t> prevWriteStateAsReadable( m_writeState );
    // m_writeState.~state::writable<state_pointee_t>(); // Destroy object (decrease counter)

    // state::writable<state_pointee_t> newWriteState;
    // m_writeState = std::move(newWriteState); // Create brand new and destroy prev
    m_writeState.reset();

    return bnd::writable<state_pointee_t>(prevWriteStateAsReadable, m_writeState); // Await for previous
  }

    // This is what will be called at coroutine termination when we co_await on objects of this type to TAW protection
  bool is_destroyable() const noexcept {
    return m_writeState.is_destroyable();
  }

};

template <typename T> struct is_readable : std::false_type {};
template <typename T> struct is_readable<readable<T>> : std::true_type {};

template <typename T> struct is_writable : std::false_type {};
template <typename T> struct is_writable<writable<T>> : std::true_type {};

template <typename T> struct is : std::false_type {};
template <typename T> struct is<readable<T>> : std::true_type {};
template <typename T> struct is<writable<T>> : std::true_type {};

} // namespace dep::guard::fnd
