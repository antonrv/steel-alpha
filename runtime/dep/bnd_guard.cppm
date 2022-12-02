export module SteelRT.Dep.Guard.Backend;

export import SteelRT.Dep.State;

import SteelRT.Util.Basic;


namespace dep::dim {

template <unsigned D, typename T>
class view;

} // namespace dep::dim


export
namespace dep::guard::bnd {

template <typename T>
class readable {
public:
  using protect_type = T;

private:
  // T can be const or non-const

  state::readable<T> m_readState;

public:
  readable() = delete;

  readable(readable&&) = default; // field to field assignment

  explicit readable(const state::shared<T>& rs) :
    m_readState(rs)
  {}




  bool is_ready() const noexcept {
    return m_readState.is_ready();
  }

  T& acquire() {
    return m_readState.acquire(); // XXX static_cast<const T&>( m_readState.acquire() ); // TODO
  }

  void release() noexcept {
    m_readState.release();
  }

  void set_error() noexcept {
    // Do not set error on read state, just release
    m_readState.release();
  }
  
};


template <typename T>
class writable {
public:
  using protect_type = T;
private:

  static_assert( std::negation_v< std::is_const<T> > );

  state::readable<T> m_readState;
  state::writable<T> m_writeState;

public:
  writable() = delete;
  writable(const writable&) = delete;

  writable(writable&&) = default; // field to field assignment

  // Constructible only from a guard fnd
  explicit writable(const state::readable<T>& rs, const state::writable<T>& ws) :
    m_readState(rs),
    m_writeState(ws)
  {}


  bool is_ready() const noexcept {
    return m_readState.is_ready() and m_readState.is_unique();
    // No need to check if the writer state is ready, as this is the only bnd::writable that is able to edit the state.
    // return m_writeState.is_ready();
  }

  T& acquire() {
    return m_readState.acquire();
  }

  void release() noexcept {
    
    m_writeState.release( &(m_readState.get_ref()) );

    m_readState.release();
  }

  void set_error() noexcept {
    m_writeState.release( reinterpret_cast<T*>(global::ErrorPtr) );

    m_readState.release();
  }

  void reset() noexcept { // Needed? TODO
  }

};

template <typename T> struct is_readable : std::false_type {};
template <typename T> struct is_readable<readable<T>> : std::true_type {};

template <typename T> struct is_writable : std::false_type {};
template <typename T> struct is_writable<writable<T>> : std::true_type {};

template <typename T> struct is : std::false_type {};
template <typename T> struct is<readable<T>> : std::true_type {};
template <typename T> struct is<writable<T>> : std::true_type {};

template <typename T> struct is_view : std::false_type {};
template <unsigned D, typename T> struct is_view<readable<dim::view<D, T>>> : std::true_type {};
template <unsigned D, typename T> struct is_view<writable<dim::view<D, T>>> : std::true_type {};


} // namespace dep::guard::bnd
