
export module SteelRT.Task.Descriptor;

  export import SteelRT.Task.DescriptorState;
  export import SteelRT.Task.Descriptor.Init;

import SteelRT.Util.Types;
import SteelRT.Util.FwDeclarations.App;
// import SteelRT.Util.Basic;

import SteelRT.Util.App;
import SteelRT.Util.Work;


export import <tuple>;

import <functional>;

namespace task {


///////////////////////////////// POLYMORPHIC DESCRIPTOR
// Polymorphic task descriptor (type-erasure of group_descriptor)
// attr::descriptor is constant by definition
// state::descriptor is variable by definition
export
class poly_descriptor : public attr::descriptor, public state::descriptor {
private:

public:

  poly_descriptor() = default; // Poison pill

  // Constructor from a group_descriptor
  template <app::id AppId, app::impl AppImpl, app::call AppCall>
  poly_descriptor(util::identity<AppId, AppImpl, AppCall>, depth_t depth, solved_mask_t sm) noexcept :
    attr::descriptor(AppId, AppCall, depth),
    state::descriptor(sm)
    // state::descriptor(AppImpl, sm)
  {}

};


///////////////////////////////// APP DESCRIPTOR. What is hold within app-specific queues.
export
// template <app::id AppId>
template <typename AppGroupImplT>
class group_descriptor : public poly_descriptor {

public:

  static constexpr app::id this_app_id = AppGroupImplT::id_value; // AppId;

public:
  // Implicit builds a poison_pill (hack, used by ctxt/entry)
  group_descriptor() noexcept : poly_descriptor() {}

  template <app::impl AppImpl, app::call AppCall>
  group_descriptor(util::identity<AppImpl, AppCall>, depth_t depth, solved_mask_t sm) noexcept : poly_descriptor( util::identity<this_app_id, AppImpl, AppCall>{}, depth, sm ) {}

  group_descriptor(const group_descriptor&&) = delete;
  group_descriptor(group_descriptor&&) = delete;
};

export
template <app::call AppCall, typename TupleT>
class descriptor : public group_descriptor< app::group_impl_of_t<app::impl_of_v<AppCall>> >, public TupleT {
private:

  using tuple_super_type = TupleT;

public:

  static constexpr app::call app_call = AppCall;

  using group_impl_type = app::group_impl_of_t< app::impl_of_v<AppCall> >;

  // This constructor is preferred to avoid movement of tuple objects.
  template <typename... Args>
  descriptor(depth_t depth, Args&&... args) noexcept :
    group_descriptor< group_impl_type >( util::identity<app::impl_of_v<AppCall>, AppCall>{}, depth, task::initialize_solved_mask<tuple_super_type>() ),
    tuple_super_type( std::forward<Args>( args ) ... )
  {}

  descriptor(const descriptor&&) = delete;
  descriptor(descriptor&&) = delete;

};


export
template <app::call AppCall, typename ResolveTupleT, typename DelegateTupleT>
class descriptor_delegate : public DelegateTupleT {

  using own_t = std::unique_ptr< descriptor<AppCall, ResolveTupleT>, workload::desc_deleter_t >;
  own_t m_ownOriginalDesc = nullptr;

public:

  using resolve_tuple_super_type = ResolveTupleT;

  using delegate_tuple_super_type = DelegateTupleT;

public:

  descriptor_delegate( own_t&& ownOriginalDesc, DelegateTupleT&& delArgs ) noexcept :
    delegate_tuple_super_type( std::forward<DelegateTupleT>( delArgs ) ),
    m_ownOriginalDesc( std::forward<own_t>( ownOriginalDesc ) )
  {}

  
  descriptor<AppCall, ResolveTupleT> * get_original_descriptor_ptr() const noexcept {
    return m_ownOriginalDesc.get();
  } 

  own_t& get_original_descriptor_ref() noexcept {
    return m_ownOriginalDesc;
  }

  own_t yield_original_descriptor() noexcept {
    own_t retOwn = std::move(m_ownOriginalDesc);

    m_ownOriginalDesc = nullptr;

    return retOwn;
  }

};


template <app::impl DelegateAppImpl, app::call AppCall>
using descriptor_delegate_type =
  task::descriptor_delegate<
    AppCall,
    app::tuple_std_args_t< AppCall >,
    app::tuple_std_delegate_t<DelegateAppImpl>
  >;


} // namespace task
