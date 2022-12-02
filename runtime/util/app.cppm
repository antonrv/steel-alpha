
export module SteelRT.Util.App;

  export import SteelRT.Util.FwDeclarations.App;

import SteelRT.Util.Basic;

import SteelRT.Util.Meta;




// Metaprogramming functions for apps


////////////////////////////////////////////////////////////
//
// ID <-> IMPL <-> GROUP_IMPL <-> CALL RELATIONS
//
////////////////////////////////////////////////////////////

export
namespace app {


template <impl AppImpl>
struct id_of_impl {
  using type = id;
  static constexpr id value = app::traits< AppImpl >::belonging_id;
};

template <impl AppImpl>
struct arch_of_impl {
  using type = plat::arch;
  static constexpr plat::arch value = app::traits< AppImpl >::arch_value;
};


/////// Sequence / Tuple of all implementation arguments
template <impl AppImpl>
using seq_args_t = util::sequence::make_index_t<app::traits<AppImpl>::arg_tuple_type::size()>;

template <auto AppImplOrCall>
using tuple_args_t = typename app::traits<AppImplOrCall>::arg_tuple_type;

template <auto AppImplOrCall>
using tuple_std_args_t = util::tuple::as_std_t< tuple_args_t<AppImplOrCall> >;


/////// Sequence / Tuple of delegate implementation arguments
template <impl AppImpl>
using seq_delegate_t = typename app::traits<AppImpl>::delegate_arg_indices;

template <impl AppImpl>
using tuple_delegate_t = util::tuple::mask_t< tuple_args_t<AppImpl>, seq_delegate_t<AppImpl> >;

template <impl AppImpl>
using tuple_std_delegate_t = util::tuple::as_std_t< tuple_delegate_t<AppImpl> >;


/////// Sequence / Tuple of resolve (non-delegate) implementation arguments
template <impl AppImpl>
using seq_resolve_t = util::sequence::sub_t< seq_args_t<AppImpl>, seq_delegate_t<AppImpl> >;

template <impl AppImpl>
using tuple_resolve_t = util::tuple::mask_t< tuple_args_t<AppImpl>, seq_resolve_t<AppImpl> >;

template <impl AppImpl>
using tuple_std_resolve_t = util::tuple::as_std_t< tuple_resolve_t<AppImpl> >;


/////// Sequence of arithmetic implementation arguments
template <impl AppImpl>
using seq_arit_t = util::tuple::satisfy_indexes_t< tuple_args_t<AppImpl>, std::is_arithmetic >;


/////// Sequence / feed of feed implementation arguments (intersection of resolve AND arit indices)
template <impl AppImpl>
using seq_feed_t = util::sequence::intersect_t< seq_resolve_t<AppImpl>, seq_arit_t<AppImpl> >;

// This tuple will also be the same across AppImpls belonging to the same AppGroup
template <impl AppImpl>
using tuple_feed_t = util::tuple::mask_t< tuple_args_t<AppImpl>, seq_feed_t<AppImpl> >;





/////// Relations between ID / IMPL / CALL / GROUP

template <call AppCall>
struct id_of {
  using type = id;
  static constexpr id value = app::traits< app::traits< AppCall >::belonging_impl >::belonging_id;
};

template <call AppCall>
inline constexpr id id_of_v = id_of<AppCall>::value;


template <call AppCall>
struct impl_of {
  using type = impl;
  static constexpr impl value = app::traits< AppCall >::belonging_impl;
};

template <call AppCall>
inline constexpr impl impl_of_v = impl_of<AppCall>::value;

template <id AppId, typename ArgTupleT>
struct group_impl {
  static constexpr id id_value = AppId;
  using type = ArgTupleT;
};

template <app::impl AppImpl>
struct group_impl_of {
  using type = group_impl< id_of_impl<AppImpl>::value, tuple_resolve_t<AppImpl> >;
};

template <app::impl AppImpl>
using group_impl_of_t = typename group_impl_of<AppImpl>::type;


template <auto AppImplOrCall>
struct args {
  using type = typename app::traits<AppImplOrCall>::arg_tuple_type;
};

template <app::impl AppImplA, app::impl AppImplB>
struct are_equivalent : std::is_same< group_impl_of_t<AppImplA>, group_impl_of_t<AppImplB> > {};


/////// Sequence / Tuple of feed parameters set in a call that are non-delegate,


template <call AppCall>
using seq_call_feed_t = seq_feed_t<app::impl_of_v<AppCall>>;

template <call AppCall>
using tuple_call_feed_t = util::tuple::mask_t< tuple_args_t<AppCall>, seq_call_feed_t<AppCall> >;

template <call AppCall>
using tuple_std_feed_t = util::tuple::as_std_t< tuple_call_feed_t<AppCall> >;



template <app::impl AppImpl, typename AppGroupT>
using belong_to_app_group = std::is_same< group_impl_of_t<AppImpl>, AppGroupT >;


} // namespace app




////////////////////////////////////////////////////////////
//
// APP::IMPL PREDICATES, IS_KERNEL / IS_DISPATCHER / HAS_DELEGATED
//
////////////////////////////////////////////////////////////

export
namespace app {

// ========== is dispatcher app::impl predicate
template <app::impl AppImpl>
struct is_dispatcher {
  static constexpr bool value = app::traits<AppImpl>::dispatch_sequence::size() > 0;
};

template <app::impl AppImpl>
struct is_kernel {
  static constexpr bool value = not is_dispatcher<AppImpl>::value;
};


//// Useful preds to catch compilation errors

template <typename T> struct is_group_impl : std::false_type {};
template <app::id AppId, typename ArgTupleT> struct is_group_impl < app::group_impl<AppId, ArgTupleT> > : std::true_type {};

template <typename T> struct is_impl_traits : std::false_type {};
template <app::impl Impl> struct is_impl_traits< app::traits<Impl> > : std::true_type {};


// ========== has_delegated predicate


template <app::impl AppImpl>
struct has_delegated : std::negation< util::sequence::empty< seq_delegate_t<AppImpl> > > {};



} // namespace app




////////////////////////////////////////////////////////////
//
// KERNEL-RUNNABLE / DISPATCHER-RUNNABLE PREDICATES GIVEN AN ALLOWED SEQUENCE
//
////////////////////////////////////////////////////////////

namespace app {


// -------------- Concatenate the call sequences of each of the implementations
  template <typename ImplSeqT>
  struct cat_calls_of;

export
template <app::impl... Impls>
struct cat_calls_of< util::sequence::enum_t<app::impl, Impls...> > {
  using type = util::sequence::unique_t< util::sequence::multi_cat_t< typename app::traits<Impls>::call_sequence ... > >;
};

export
template <typename ImplSeqT>
using cat_calls_of_t = typename cat_calls_of<ImplSeqT>::type;


// -------------- Template types to get the compatible sequence of implementation ids.
  template <app::id AppId>
  struct common_id {
    template <app::impl AppImpl>
    using is_sibling = std::conditional_t< app::traits<AppImpl>::belonging_id == AppId ,std::true_type, std::false_type >;
  };
  
  template <app::impl AppImplOrigin>
  struct common_arg {
    template <app::impl AppImplCandidate>
    using same = std::is_same< typename app::traits<AppImplOrigin>::arg_tuple_type, typename app::traits<AppImplCandidate>::arg_tuple_type >;
  
  };

  template <app::impl AppImplOrigin>
  struct is_reimplementable {
    template <app::impl AppImplCandidate>
    using with = std::conjunction<
      typename common_id< app::traits<AppImplOrigin>::belonging_id >::template is_sibling<AppImplCandidate>,
      typename common_arg< AppImplOrigin >::template same<AppImplCandidate>
    >;
  };


// ------------------- Map a call sequence to a tuple of group implementations
// Apparently not needed anymore

// export
// template <typename DispatchCallSeqT>
// using call_seq_to_group_impl_tuple_t = util::tuple::lift_enums_t< util::sequence::transform_t<DispatchCallSeqT, app::impl, app::impl_of>, app::group_impl_of_t >;


export
enum class runnable_as : enum_uint_t { none, kernel, dispatcher, kernel_only, dispatcher_only, kernel_and_dispatcher };

using runnable_as_defined_seq = util::sequence::enum_t< runnable_as, runnable_as::kernel_only, runnable_as::dispatcher_only, runnable_as::kernel_and_dispatcher >;


// --------- 'is' predicate, to know if an AppImpl is runnable as kernel/dispatcher wrt the implementations in AllowedImplSeqT


  template <runnable_as RA, app::impl AppImpl, typename AllowedImplSeqT>
  struct is;


// ---------- Runnable both as kernel and dispatcher
export
template <app::impl AppImpl, typename AllowedImplSeqT>
struct is <runnable_as::kernel_and_dispatcher, AppImpl, AllowedImplSeqT> {

  using seq_kernel_t = typename is<runnable_as::kernel, AppImpl, AllowedImplSeqT>::seq_t;
  using seq_dispatcher_t = typename is<runnable_as::dispatcher, AppImpl, AllowedImplSeqT>::seq_t;

  using seq_t = util::sequence::filter_t< AllowedImplSeqT, is_reimplementable<AppImpl>::template with >;

  static constexpr bool value = std::conjunction_v<std::negation< util::sequence::empty< seq_kernel_t > >, std::negation< util::sequence::empty< seq_dispatcher_t > > >;
};

// ---------- Runnable as kernel
export
template <app::impl AppImpl, typename AllowedImplSeqT>
struct is <runnable_as::kernel, AppImpl, AllowedImplSeqT> {

  using seq_t = 
        util::sequence::filter_t<
          util::sequence::filter_t<
            AllowedImplSeqT,
            is_reimplementable<AppImpl>::template with
          >, // Sequence of implementations that are compatible with AppImpl
          app::is_kernel
        >; // Sequence of implementations compatible with AppImpl that are kernels

  static constexpr bool value = std::negation_v< util::sequence::empty< seq_t > >;
};

// ---------- Runnable as dispatcher
export
template <app::impl AppImpl, typename AllowedImplSeqT>
struct is <runnable_as::dispatcher, AppImpl, AllowedImplSeqT> {

  using seq_t = 
        util::sequence::filter_t<
          util::sequence::filter_t<
            AllowedImplSeqT,
            is_reimplementable<AppImpl>::template with
          >, // Sequence of implementations that are compatible with AppImpl
          app::is_dispatcher
        >; // Sequence of implementations compatible with AppImpl that are dispatchers

  static constexpr bool value = std::negation_v< util::sequence::empty< seq_t > >;
};

// ---------- Runnable as kernel, not dispatcher
export
template <app::impl AppImpl, typename AllowedImplSeqT>
struct is <runnable_as::kernel_only, AppImpl, AllowedImplSeqT> {

  using seq_kernel_t = typename is<runnable_as::kernel, AppImpl, AllowedImplSeqT>::seq_t;
  using seq_dispatcher_t = typename is<runnable_as::dispatcher, AppImpl, AllowedImplSeqT>::seq_t;

  // using seq_t = seq_kernel_t; not needed

  static constexpr bool value = std::conjunction_v< std::negation<util::sequence::empty< seq_kernel_t >>, util::sequence::empty< seq_dispatcher_t > >;
};


// ---------- Runnable as dispatcher, not kernel
export
template <app::impl AppImpl, typename AllowedImplSeqT>
struct is <runnable_as::dispatcher_only, AppImpl, AllowedImplSeqT> {

  using seq_kernel_t = typename is<runnable_as::kernel, AppImpl, AllowedImplSeqT>::seq_t;
  using seq_dispatcher_t = typename is<runnable_as::dispatcher, AppImpl, AllowedImplSeqT>::seq_t;

  // using seq_t = seq_dispatcher_t; not needed

  static constexpr bool value = std::conjunction_v< util::sequence::empty< seq_kernel_t >, std::negation< util::sequence::empty< seq_dispatcher_t > > >;
};

// ---------- Runnable as nothing
export
template <app::impl AppImpl, typename AllowedImplSeqT>
struct is <runnable_as::none, AppImpl, AllowedImplSeqT> {

  using seq_kernel_t = typename is<runnable_as::kernel, AppImpl, AllowedImplSeqT>::seq_t;
  using seq_dispatcher_t = typename is<runnable_as::dispatcher, AppImpl, AllowedImplSeqT>::seq_t;

  static constexpr bool value = std::conjunction_v< util::sequence::empty< seq_kernel_t >, util::sequence::empty< seq_dispatcher_t > >;
};


} // namespace app




////////////////////////////////////////////////////////////
//
// IMPL / CALL PREDICATES EXECUTABLE / DISPATCHABLE ON ARCHITECTURE / PROCESSOR 
//
////////////////////////////////////////////////////////////



namespace app {


  // InputAppImpl is anyhow runnable on ArchId if it
 template <app::impl InputAppImpl, plat::arch InputArchId>
 using is_kernel_runnable_on =
   std::conjunction<
     app::is_kernel< InputAppImpl >,
     util::same< app::traits<InputAppImpl>::arch_value, InputArchId >
   >;


  template <app::call AppCall, plat::arch ArchId>
  struct is_call_runnable_on {

    // The group impl associated to this call
    using this_group_impl_type = typename app::group_impl_of< app::impl_of<AppCall>::value >::type;

    // Get the AppId
    static constexpr app::id AppId = id_of_v<AppCall>;

    // To get all the implementations associated
    using app_impl_sequence = typename app::traits<AppId>::impl_sequence;

    // Only those implementations pure-kernel AND whose group impl matches this_group_impl_type will be runnable on ArchId

    template <app::impl InputAppImpl>
    using is_runnable_on_here = std::conjunction<
        is_kernel_runnable_on<InputAppImpl, ArchId>,
        std::is_same< app::group_impl_of_t< InputAppImpl >, this_group_impl_type > // Has same group impl as this call
      >;
    
    // AppCall may trigger an execution on ArchId if at least one impl is compatible with call and is a runnable kernel on archid
    static constexpr bool value = util::sequence::filter_t< app_impl_sequence, is_runnable_on_here >::size() > 0;
  };

  template <typename AppCallSeqT, plat::arch ArchId>
  struct is_any_call_runnable_on;

  template <app::call... AppCalls, plat::arch ArchId>
  struct is_any_call_runnable_on < util::sequence::enum_t<app::call, AppCalls...>, ArchId > : std::disjunction< is_call_runnable_on<AppCalls, ArchId> ... > {};

  template <app::impl InputAppImpl, plat::arch InputArchId>
  using is_dispatcher_runnable_on = 
    std::conjunction<
      app::is_dispatcher< InputAppImpl >,
      is_any_call_runnable_on< typename app::traits<InputAppImpl>::dispatch_sequence, InputArchId >
    >;

////////// Return all the implementations dispatchable in ArchId

  template <typename AppImplSeqT, plat::arch ArchId>
  struct filter_impl_dispatchable_on {
  
    template <app::impl AppImpl>
    using is_dispatchable_here = is_dispatcher_runnable_on< AppImpl, ArchId >;
  
    using type = util::sequence::filter_t< AppImplSeqT, is_dispatchable_here >;
  };

export
template <typename AppImplSeqT, plat::arch ArchId>
using filter_impl_dispatchable_on_t = typename filter_impl_dispatchable_on<AppImplSeqT, ArchId>::type;

////////// Return all the implementations compatible (via kernel execute)

  template <typename AppImplSeqT, plat::arch ArchId>
  struct filter_impl_kernelable_on {
  
    template <impl AppImpl>
    using kernelable_here = is_kernel_runnable_on< AppImpl, ArchId >;

    // Only those impl that ar ArchId-compatible kernels or ArchId-compatible dispatchers are allowed
    using type = util::sequence::filter_t< AppImplSeqT, kernelable_here >;
  };

export
template <typename AppImplSeqT, plat::arch ArchId>
using filter_impl_kernelable_on_t = typename filter_impl_kernelable_on<AppImplSeqT, ArchId>::type;


////////// Return all the implementations compatible (via kernel execute or dispatcher execute) with ArchId

  template <typename AppImplSeqT, plat::arch ArchId>
  struct filter_impl_processable_on {
  
    template <impl AppImpl>
    using processable_here =
        std::disjunction<
          is_kernel_runnable_on< AppImpl, ArchId >,
          is_dispatcher_runnable_on< AppImpl, ArchId >
        >;

    // Only those impl that ar ArchId-compatible kernels or ArchId-compatible dispatchers are allowed
    using type = util::sequence::filter_t< AppImplSeqT, processable_here >;
  };

export
template <typename AppImplSeqT, plat::arch ArchId>
using filter_impl_processable_on_t = typename filter_impl_processable_on<AppImplSeqT, ArchId>::type;



////////// Extract and aggregate all implementations of the input app::id sequence

  template <typename AppIdSeqT>
  struct cat_impls_of;
  
  template <app::id... AppIds>
  struct cat_impls_of < util::sequence::enum_t<app::id, AppIds...> > {
  
    using type = util::sequence::unique_t< util::sequence::multi_cat_t< typename app::traits<AppIds>::impl_sequence ... > >;
  };

export
template <typename AppIdSeqT>
using cat_impls_of_t = typename cat_impls_of<AppIdSeqT>::type;




////////// Extract and all implementations of the input app::id

  template <app::id AppId>
  struct impls_of {
    using type = typename app::traits<AppId>::impl_sequence;
  };

export
template <app::id AppId>
using impls_of_t = typename impls_of<AppId>::type;



////////// From a sequence of AppIds, Return all the implementations compatible (via processable/dispatchable) with a processor

  template <typename AppIdSeqT, plat::processor ProcId>
  struct compatible_processable_impls {
    using type = filter_impl_processable_on_t< cat_impls_of_t< AppIdSeqT >, plat::ptraits<ProcId>::arch_value >; 
  };

export
template <typename AppIdSeqT, plat::processor ProcId>
using compatible_processable_impls_t = typename compatible_processable_impls<AppIdSeqT, ProcId>::type;


  template <typename AppIdSeqT, plat::processor ProcId>
  struct compatible_kernel_impls {
    using type = filter_impl_kernelable_on_t< cat_impls_of_t< AppIdSeqT >, plat::ptraits<ProcId>::arch_value >; 
  };

export
template <typename AppIdSeqT, plat::processor ProcId>
using compatible_kernel_impls_t = typename compatible_kernel_impls<AppIdSeqT, ProcId>::type;



  template <typename AppIdSeqT, plat::processor ProcId>
  struct compatible_dispatcher_impls {
    using type = filter_impl_dispatchable_on_t< cat_impls_of_t< AppIdSeqT >, plat::ptraits<ProcId>::arch_value >; 
  };

export
template <typename AppIdSeqT, plat::processor ProcId>
using compatible_dispatcher_impls_t = typename compatible_dispatcher_impls<AppIdSeqT, ProcId>::type;




  template <workload::kind WorkKind, typename AppIdSeqT, plat::processor ProcId>
  struct compatible_impls;

  template < typename AppIdSeqT, plat::processor ProcId>
  struct compatible_impls <workload::kind::desc, AppIdSeqT, ProcId> : compatible_processable_impls< AppIdSeqT, ProcId > {};

  template < typename AppIdSeqT, plat::processor ProcId>
  struct compatible_impls <workload::kind::disp, AppIdSeqT, ProcId> : compatible_dispatcher_impls< AppIdSeqT, ProcId > {};

export
template <workload::kind WorkKind, typename AppIdSeqT, plat::processor ProcId>
using compatible_impls_t = typename compatible_impls< WorkKind, AppIdSeqT, ProcId >::type;


} // namespace app

// DEPRECATED XXX
// // To extract the impl of a queue parameter, which can be a app::group_impl or a app::traits
// template < typename QueueParamT, typename AppImplSeqT >
// struct queue_param_impl;
// 
// // If queue parameter is just app::traits (queue of dispatchers)
// template < app::impl AppImpl, typename AppImplSeqT >
// struct queue_param_impl< app::traits<AppImpl>, AppImplSeqT > {
//   static constexpr app::impl value = AppImpl;
// };
// 
// // If queue parameter is a group impl (queue of descriptors)
// template < app::id AppId, typename ArgTupleT, typename AppImplSeqT >
// struct queue_param_impl< app::group_impl<AppId, ArgTupleT>, AppImplSeqT > {
//   // In AppImplSeqT, pick the impl whose group impl is this
// 
//   using this_group_impl_type = app::group::impl<AppId, ArgTupleT>;
// 
//   template <app::impl InputAppImpl>
//   using same_to_this_group_impl = std::is_same< app::group_impl_of_t<InputAppImpl>, this_group_impl_type > >;
// 
//   using filter_seq_t = util::sequence::filter_t< AppImplSeqT, same_to_this_group_impl >;
// 
//   using value_type = app::impl;
// 
//   static constexpr app::impl value = util::sequence::head_v< filter_seq_t >;
// };
// 
// 
// template < typename QueueParamT, typename AppImplSeqT >
// inline constexpr impl queue_param_impl_v = typename queue_param_impl<QueueParamT, AppImplSeqT>::value;

