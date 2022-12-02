
export module SteelRT.Dep.State;

import SteelRT.Util.Basic;

export import <atomic>;
import <type_traits>;

import <stdexcept>;
// import <iostream>;


namespace dep::guard::fnd::region {

template <mesh MeshKind, std::size_t D, typename T>
class readable;

template <mesh MeshKind, std::size_t D, typename T>
class writable;

} // namespace dep::guard::fnd::region

export
namespace dep::state {

template <typename T>
class shared {

protected:

  // T is not an reference, so T& , which is the constructor argument, is.
  // Note that T can be const or non const
  static_assert( std::negation_v< std::is_reference<T> > );
  


  struct control {
    T* holdPtr;
    std::atomic<counter_t> usersCount; // We could pack these two in a single word TODO
    std::atomic<counter_t> ownersCount;

    control(T* tp) : holdPtr(tp) {
      usersCount.store(0, std::memory_order::release);
      ownersCount.store(1, std::memory_order::release);
    }

  };

  using control_ptr_t = std::add_pointer_t<control>;

  control_ptr_t controlPtr;

  void reset() noexcept {
    // Only in very specific parts
    
    // std::cout << "Sub 1 to users (RESET)" << this << "\n";
    controlPtr->usersCount.fetch_sub(1, std::memory_order::release);
    controlPtr->ownersCount.fetch_sub(1, std::memory_order::release);
    controlPtr = nullptr;
    controlPtr = new control(nullptr);
    // controlPtr->usersCount.store(0, std::memory_order::release); // NOT NEEDED XXX
    // controlPtr->ownersCount.store(1, std::memory_order::release); // NOT NEEDED XXX
  }

  void initialize(T& ref) noexcept {
    controlPtr = new control(&ref);
  }

  bool is_initialized() const noexcept {
    return controlPtr != nullptr;
  }

  // fnd region container is friend, so it can initialize state vector elements at construction
  template <mesh, template <typename> class StT, typename ProtT, typename MeshT>
  friend class guard::fnd::region::container;

  // fnd region guard is friend, so it can initialize state at construction
  template <mesh, std::size_t , typename >
  friend class dep::guard::fnd::region::readable;

  // fnd region guard is friend, so it can initialize state at construction
  template <mesh, std::size_t , typename >
  friend class dep::guard::fnd::region::writable;

public:
  // Used to prebuild uninitialized states in a container
  explicit shared(std::nullptr_t ) : controlPtr(nullptr) {}

  // Unresolved write dep
  shared() :
    controlPtr(new control(nullptr)) 
  {
    // controlPtr->usersCount.store(0, std::memory_order::release); // NOT NEEDED XXX
    // controlPtr->ownersCount.store(1, std::memory_order::release); // NOT NEEDED XXX
    // std::cout << "shared CONSTR DEFAULT. this " << this << "\n";
  }
  
  // Initialized from given arg
  explicit shared(T& tRef) :
    controlPtr(new control(&tRef))
  {
    // controlPtr->usersCount.store(0, std::memory_order::release); // NOT NEEDED XXX
    // controlPtr->ownersCount.store(1, std::memory_order::release); // NOT NEEDED XXX
    // std::cout << "shared CONSTR INIT. this " << this << "\n";
  }

  // Initialized from another state
  explicit shared(const shared& other) :
    controlPtr(other.controlPtr)
  {
    if (controlPtr) {
      // std::cout << " Add 1 to users (COPY CONSTR)" << this << "\n";
      controlPtr->usersCount.fetch_add(1, std::memory_order::release);
      controlPtr->ownersCount.fetch_add(1, std::memory_order::release);
    }
    // std::cout << "shared CONSTR COPY. this " << this << " from " << &other << "\n";
  }
  // assignment op TODO


  explicit shared(shared&& other) :
    controlPtr(other.controlPtr)
  {
    // Do not increase the pointers.
    other.controlPtr = nullptr; // To skip destructor checking in other XXX
    // std::cout << "shared CONSTR MOVE. this " << this << " from " << &other <<"\n";
  }

  ~shared() {
    if (controlPtr) {
      if (controlPtr->ownersCount.load(std::memory_order::seq_cst) == 1) {
        controlPtr->ownersCount.fetch_sub(1, std::memory_order::release);
        delete controlPtr;
        // std::cout << "shared DESTR CLEAN. this " << this << "\n";
      } else {
        controlPtr->ownersCount.fetch_sub(1, std::memory_order::release);
        // std::cout << "shared DESTR NOTLAST. this " << this << "\n";
      }
    } else {
      // std::cout << "shared DESTR NOptr. this " << this << "\n";
    }
  }


  shared& operator=(shared&& other) {
    this->controlPtr = other.controlPtr;
    other.controlPtr = nullptr;
    return *this;
  }
  
  bool is_destroyable() const noexcept {
    return controlPtr->ownersCount.load(std::memory_order::acquire) == 1;
  }

};

template <typename T>
class writable;

template <typename T>
class readable : public shared<T> {
  using super_type = shared<T>;

public:
  // static constexpr bool is_readable = true;
  // static constexpr bool is_writable = false;

public:

  explicit readable(std::nullptr_t ) : super_type(nullptr) {}

  explicit readable(T& tRef) : super_type(tRef) {}

  explicit readable(const shared<T>& other) : super_type(other) {}

  explicit readable(const readable& r) : super_type(r) {}
  explicit readable(readable&& r) : super_type(std::forward<super_type>(r)) {}

  explicit readable(writable<std::remove_const_t<T>>&& w) : super_type(std::forward<super_type>(w)) {}

  // Callable from dep::acquire
  bool is_ready() const noexcept {
    super_type::controlPtr->usersCount.load( std::memory_order::acquire );
    return super_type::controlPtr->holdPtr != nullptr;
  }

  bool is_unique() const noexcept {
    return super_type::controlPtr->usersCount.load( std::memory_order::acquire ) < 2;
  }

  // Callable from exe
  T& acquire() {
    super_type::controlPtr->usersCount.load( std::memory_order::acquire );
    if (reinterpret_cast<std::uintptr_t>(super_type::controlPtr->holdPtr) == global::ErrorPtr) {
      throw std::runtime_error("Could not acquire corrupt dependency");
    }
    return static_cast<T&>(*(super_type::controlPtr->holdPtr));
  }

  // Callable from dep::release
  void release() noexcept {
    // std::cout << "Sub 1 to users (REL R)" << this << "\n";
    super_type::controlPtr->usersCount.fetch_sub(1, std::memory_order::release );
  }

  // Used to set a write state from a read state (no const cast)
  T& get_ref() noexcept {
    return static_cast<T&>(*(super_type::controlPtr->holdPtr));
  }

  // Used to set a write state from a read state (const cast)
  const T& get_const_ref() const noexcept {
    return static_cast<const T&>(*(super_type::controlPtr->holdPtr));
  }

};

template <typename T>
class writable : public shared<T> {

  using super_type = shared<T>;

  static_assert( std::negation_v<std::is_const<T>> );
public:
  // static constexpr bool is_readable = false;
  // static constexpr bool is_writable = true;

public:

  explicit writable(std::nullptr_t ) : super_type(nullptr) {}

  writable() : super_type() {}

  explicit writable(T& tRef) : super_type(tRef) {}

  explicit writable(const shared<T>& other) : super_type(other) {}
  explicit writable(const writable<T>& other) : super_type(other) {}

  explicit writable(writable&& w) : super_type(std::forward<super_type>(w)) {}

  writable& operator=(shared<T>&& w) {
    super_type::operator=(std::forward<shared<T>>(w));
    return *this;
  }

  void reset() noexcept {
    super_type::reset();
  }

  // Callable from dep::release
  void release(T * tPtr) noexcept {
    // std::cout << " Sub 1 to users (REL W)\n";
    super_type::controlPtr->holdPtr = tPtr;
    super_type::controlPtr->usersCount.fetch_sub(1, std::memory_order::release );
  }

  const T& get_const_ref() const noexcept {
    return static_cast<const T&>(*(super_type::controlPtr->holdPtr));
  }

};

// template <template <typename > class TemplT> struct is_readable : std::false_type {};
// template <template <typename T> class > struct is_readable<readable<T>> : std::true_type {};
// 
// template <template <typename > class TemplT> struct is_writable : std::false_type {};
// template <template <typename T> class > struct is_writable<writable<T>> : std::true_type {};

} // namespace dep::state
