
export module SteelRT.Task.Dispatcher.Promise.Base;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
import SteelRT.Util.AppWork;

import SteelRT.Task.DescriptorState;

import <experimental/coroutine>;


namespace task::coro {

export
using suspend = std::experimental::suspend_always;

export
enum class last_await : enum_uint_t { none, called, guard_destroy, guard_sync };

export
template <app::impl AppImpl>
class dispatcher_promise_base_lite {

private:
  using own_poly_desc_t = workload::wtraits< workload::kind::desc >::own_poly_type;


// General parameters
  attr::descriptor& m_descriptorAttributesRef;

  own_poly_desc_t m_ownDescExtract = nullptr;

protected:


  last_await m_lastAwait = last_await::none;

public:

  last_await get_last_await() const noexcept {
    return m_lastAwait;
  }

  dispatcher_promise_base_lite( attr::descriptor& originalAttrs ) : m_descriptorAttributesRef(originalAttrs) { }


  void set_extract_descriptor( own_poly_desc_t&& ownPolyDesc ) noexcept {
    m_ownDescExtract = std::move(ownPolyDesc);
  }

  own_poly_desc_t extract_descriptor() noexcept {
    auto ret = std::move( m_ownDescExtract );
    m_ownDescExtract = nullptr;
    return ret;
  }

  // Called from dispatcher object
  const attr::descriptor& get_attr_descriptor_ref() const noexcept {
    return m_descriptorAttributesRef;
  }

};

} // namespace task::coro
