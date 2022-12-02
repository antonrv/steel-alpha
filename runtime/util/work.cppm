

export module SteelRT.Util.Work;

  export import SteelRT.Util.Work.Enum;
  export import SteelRT.Util.FwDeclarations.Work;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
import SteelRT.Util.App;


export import <functional>;
export import <memory>;


export
namespace workload {


///////////////// DESCRIPTOR TRAITS

template <>
struct wtraits <kind::desc> {


  using poly_type = std::add_pointer_t<task::poly_descriptor>;

  using deleter_type = std::function<void(poly_type)>;


  using own_poly_type = std::unique_ptr< task::poly_descriptor, deleter_type >;

  template <app::impl AppImpl>
  using queue_parameter_type = app::group_impl_of_t<AppImpl>;

  template <app::impl AppImpl>
  using element_type = task::group_descriptor< queue_parameter_type<AppImpl> >;

  template <typename AppGroupImplT>
  using element_type_from_queue_parameter = task::group_descriptor< AppGroupImplT >;

  template <app::impl AppImpl>
  using own_type = std::unique_ptr< element_type<AppImpl>, deleter_type >;

  template <typename AppGroupImplT>
  using own_type_from_queue_parameter = std::unique_ptr< task::group_descriptor< AppGroupImplT > >;


  template <app::impl AppImpl>
  using push_fn_type = std::function<void(own_type<AppImpl>&&)>;

  template <typename AppGroupImplT>
  using push_fn_type_from_queue_parameter = std::function<void(own_type_from_queue_parameter<AppGroupImplT>&&)>;

  using push_poly_fn_t = std::function<void(own_poly_type&&)>;

  using try_pull_poly_fn_t = std::function<own_poly_type()>;

  // Call it just 'type' TODO
  template <app::call AppCall>
  using descriptor_type = task::descriptor<AppCall, util::tuple::as_std_t< typename app::traits<AppCall>::arg_tuple_type>>;

};


///////////////// DISPATCHER TRAITS

template <>
struct wtraits <kind::disp> {

  using poly_type = std::add_pointer_t< task::state::dispatcher >;

  using own_poly_type = std::shared_ptr< task::state::dispatcher >;

  template <app::impl AppImpl>
  using queue_parameter_type = app::traits<AppImpl>;

  template <app::impl AppImpl>
  using element_type = task::coro::dispatcher< AppImpl >;

  template <typename AppImplTraitsT>
  using element_type_from_queue_parameter = task::coro::dispatcher< AppImplTraitsT::this_impl >;

  template <app::impl AppImpl>
  using own_type = std::shared_ptr< element_type<AppImpl> >;

  template <typename AppImplTraitsT>
  using own_type_from_queue_parameter = own_type< AppImplTraitsT::this_impl >;

  template <typename QueueParamT>
  using push_fn_type = std::function<void(own_type_from_queue_parameter<QueueParamT>&&)>;

  using push_poly_fn_t = std::function<void(own_poly_type&&)>;

  using try_pull_poly_fn_t = std::function<own_poly_type()>;
};



////////////// Easy aliases
using poly_desc_t = wtraits<workload::kind::desc>::poly_type;
using own_poly_desc_t = wtraits<workload::kind::desc>::own_poly_type;
using desc_deleter_t = wtraits<workload::kind::desc>::deleter_type;

template <app::call AppCall>
using desc_t = wtraits<workload::kind::desc>::descriptor_type<AppCall>;

template <app::impl AppImpl>
using own_desc_t = wtraits<workload::kind::desc>::own_type<AppImpl>;

using push_poly_desc_fn_t = wtraits<workload::kind::desc>::push_poly_fn_t;

using poly_disp_t = wtraits<workload::kind::disp>::poly_type;
using own_poly_disp_t = wtraits<workload::kind::disp>::own_poly_type;
using push_poly_disp_fn_t = wtraits<workload::kind::disp>::push_poly_fn_t;

template <app::impl AppImpl>
using own_disp_t = wtraits<workload::kind::disp>::own_type<AppImpl>;



///////////////// WORK CASTING FUNCTIONS


template <
  typename AppGroupImplT,
  typename OwnPolyT,
  util::req_t< std::conjunction< app::is_group_impl<AppGroupImplT>, std::is_same<OwnPolyT, wtraits<kind::desc>::own_poly_type> > > ...
>
wtraits<kind::desc>::own_type_from_queue_parameter<AppGroupImplT> cast_poly( OwnPolyT&& ownPoly ) {

  return wtraits<kind::desc>::own_type_from_queue_parameter<AppGroupImplT>( static_cast< wtraits<kind::desc>::element_type_from_queue_parameter<AppGroupImplT>* >(ownPoly.release()), ownPoly.get_deleter() );
}


template <
  typename AppImplTraitsT,
  typename OwnPolyT,
  util::req_t< std::conjunction< app::is_impl_traits<AppImplTraitsT>, std::is_same<OwnPolyT, wtraits<kind::disp>::own_poly_type> > > ...
>
wtraits<kind::disp>::own_type_from_queue_parameter<AppImplTraitsT> cast_poly( OwnPolyT&& ownPoly ) {
  return std::static_pointer_cast< wtraits< kind::disp >::element_type_from_queue_parameter<AppImplTraitsT> >( ownPoly );
}

} // namespace workload
   

///////////////// WORK FUNCTION TYPES

namespace workload {

  template <worker::fun WorkFun, workload::kind WorkKind>
  struct callback;

  template <workload::kind WorkKind>
  struct callback <worker::fun::try_pull, WorkKind> {
    using type = typename wtraits<WorkKind>::try_pull_poly_fn_t;
  };

  template <workload::kind WorkKind>
  struct callback <worker::fun::push, WorkKind> {
    using type = typename wtraits<WorkKind>::push_poly_fn_t;
  };

  // template <workload::kind WorkKind>
  // struct callback <worker::fun::has_work, WorkKind> {
  //   using type = std::function<bool()>;
  // };

  export
  template <>
  struct callback <worker::fun::operate, workload::kind::desc> {

    using own_poly_t = wtraits<kind::desc>::own_poly_type;

    using push_poly_desc_fn_t = wtraits<kind::desc>::push_poly_fn_t;

    using push_poly_disp_fn_t = wtraits<kind::disp>::push_poly_fn_t;

    using type = std::function<void(own_poly_t&&, const push_poly_desc_fn_t&, const push_poly_disp_fn_t&)>;
  };

  template <>
  struct callback <worker::fun::operate_push, workload::kind::disp> {

    using desc_own_poly_t = wtraits<kind::desc>::own_poly_type;
    using disp_own_poly_t = wtraits<kind::disp>::own_poly_type;

    template <typename ResumerPushFnTupleT>
    using type = std::function<void(disp_own_poly_t&, greed_t, const ResumerPushFnTupleT&)>;

  };

  template <>
  struct callback <worker::fun::operate_extract, workload::kind::disp> {

    using desc_own_poly_t = wtraits<kind::desc>::own_poly_type;
    using disp_own_poly_t = wtraits<kind::disp>::own_poly_type;

    using type = std::function<desc_own_poly_t(disp_own_poly_t&)>;
  };


export
template <worker::fun WorkFun, workload::kind WorkKind>
using callback_t = typename callback<WorkFun, WorkKind>::type;

} // namespace workload
