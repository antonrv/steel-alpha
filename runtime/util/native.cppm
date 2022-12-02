
export module SteelRT.Util.Native;

// This module exposes compile-time functions to deduce application- and platform-dependent types.
// export import App.Proxy;
// export import Plat.Graph;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Util.AppWork;



export
namespace util {


template <typename AppIdSeqT, typename ProcIdSeqT>
struct native {

  using all_app_ids = AppIdSeqT;
  using all_proc_ids = ProcIdSeqT;

  static constexpr app::call main_call = static_cast<app::call>(global::EntryAppCall);

  template <plat::processor ProcId>
  struct is_multithread { static constexpr bool value = (plat::ptraits<ProcId>::max_threads > 0); }; // struct is_multithread { static constexpr bool value = (plat::ptraits<ProcId>::max_threads > 1); };

  using all_multithread_proc_ids = util::sequence::filter_t< all_proc_ids, is_multithread>;

  static constexpr std::size_t multithread_proc_count = all_multithread_proc_ids::size();

  using chosen_threads_t = std::array<uint_t, multithread_proc_count>;





  template <workload::kind WorkKind, plat::processor ProcId>
  using compatible_impls = app::compatible_impls_t< WorkKind, AppIdSeqT, ProcId >;

  template <plat::processor ProcId>
  using compatible_processable_impls = compatible_impls< workload::kind::desc, ProcId >;

  template <plat::processor ProcId>
  using compatible_dispatcher_impls = compatible_impls< workload::kind::disp, ProcId >;

  template <plat::processor ProcId>
  using compatible_kernelable_impls = app::compatible_kernel_impls_t< AppIdSeqT, ProcId >;

  // Need to unique to remove possible duplicates (note that processable also include dispatchers)
  template <plat::processor ProcId>
  using all_compatible_impls = util::sequence::unique_t< util::sequence::cat_t< compatible_processable_impls<ProcId>, compatible_dispatcher_impls<ProcId> > >;

  template <plat::processor ProcId>
  using all_compatible_groups = util::tuple::unique_t< util::tuple::lift_enums_t< all_compatible_impls<ProcId>, app::group_impl_of_t > >;

  using all_groups = util::tuple::cat_t< util::tuple::lift_enums_t< all_proc_ids, all_compatible_groups > >;



  using main_app_group = app::group_impl_of_t< app::impl_of_v<main_call> >;

  template <plat::processor ProcId>
  static constexpr std::size_t max_threads = plat::ptraits<ProcId>::max_threads;

  template <plat::processor ProcId>
  using ptraits_of = plat::ptraits<ProcId>;

  static constexpr plat::processor default_processor = util::sequence::head_v< all_proc_ids >;

  template <plat::processor ProcId>
  static std::string get_proc_str() noexcept {
    return "p" + std::to_string( util::sequence::get_index_v<all_proc_ids, ProcId> );
  }

  template <typename AppGroupT>
  static std::string get_appgroup_str() noexcept {
    return "ag" + std::to_string( util::sequence::get_index_v<all_app_ids, AppGroupT::id_value> ) + "_g" + std::to_string( util::tuple::index_v< AppGroupT, all_groups > );
  }

  static std::string get_str_pilot_ready() noexcept {
    return "Pilot awaiting for runner messages";
  }

  static std::string get_str_pilot_exit() noexcept {
    return "Pilot final exit";
  }

  static std::string get_str_msg_queue() noexcept {
    return "msg_queue";
  }





  // template <workload::kind WorkKind, plat::processor ProcId>
  // using work_container_type = workload::container< WorkKind, compatible_impls<WorkKind, ProcId> >;

  // template <workload::kind WorkKind, plat::processor ProcId>
  // using queue_parameters_tuple_type = typename work_container_type<WorkKind, ProcId>::unique_queue_parameters;


  // template <workload::kind WorkKind, plat::processor ProcId>
  // static constexpr std::size_t work_container_count = plat::ptraits<ProcId>::core_count; // For the moment independent from WorkKind


  // template <plat::processor ProcId>
  // using resumer_push_fn_tuple_type =
  //     util::tuple::lift_t<
  //       workload::wtraits<workload::kind::desc>::push_fn_type_from_queue_parameter,
  //       util::tuple::lift_enums_t< compatible_processable_impls<ProcId>, app::group_impl_of_t >
  //     >;


  // template <plat::processor ProcId>
  // using resumer_push_fn_std_tuple_type = util::tuple::as_std_t< resumer_push_fn_tuple_type<ProcId> >;


  // template <plat::processor ProcIdA, plat::processor ProcIdB>
  // using shared_compatible_processable_impls = util::sequence::intersect_t< compatible_processable_impls<ProcIdA>, compatible_processable_impls<ProcIdB> >;

  // template <plat::processor ProcIdA, plat::processor ProcIdB>
  // struct can_cooperate : std::negation< sequence::empty< shared_compatible_processable_impls<ProcIdA, ProcIdB> > > {};


  // template <plat::processor ProcId>
  // struct compatible_procs {

  //   template <plat::processor OtherProcId>
  //   using compatible_with_this = can_cooperate<OtherProcId, ProcId>;

  //   using type = util::sequence::filter_t< ProcIdSeqT, compatible_with_this >;
  // };

  // template <plat::processor ProcId>
  // using compatible_procs_t = typename compatible_procs< ProcId >::type;

  // template <plat::processor ProcId>
  // using compatible_remote_procs_t = util::sequence::remove_t< typename compatible_procs< ProcId >::type, ProcId >;

  ////////////////////// INFER APP-PLAT PROPERTIES TO DEFINE RUNTIME COMPILE-TIME CONFIGURATION

  /////////////////// INFER WHETHER APP IS ACYCLIC OR CYCLIC
  // Returns true if at least one descendant of AppImpl is runnable as AppImplTarget
  // template <app::impl AppImpl, app::impl AppImplTarget>
  // struct is_cyclic {

  //   // Automatically true if AppImpl == AppImplTarget

  //   children_disps = children_dispatchers_of<AppImpl>;

  //   // If empty -> acyclic
  //   // Else for each children: OR is_cyclic<AppImplChildren, AppImplTarget>

  // };

  // template <app::impl AppImpl>
  // struct children_dispatchers_of {
  // 
  //   // using calls_t = app::traits<AppImpl>::call_sequence;
  //   // expand calls_t into impls,
  //   // expand impls into compat impls (using all impls)
  //   // type = filter dispatchers only 
  // };

  /////////////////// INFER WHETHER DEPENDENCIES BETWEEN SIBLING TASK EXISTS
  // Directly inferred by the builder, that injects this info into app::traits<AppImpl>
  // Overall app does not have deps if all dispatchers don't have deps

  
  /////////////////// ARCH HETEROG trivial


  /////////////////// APP-PLAT COMPAT 
  // To know how many container types must be defined.
  // Full compat = When all processors have the same appgroup tuple => Single work container
  // Partial compat / Incompat: As many containers as needed:
  //  For each procA in procs
  //    Get compat AppGroupTs_A
  //    For each procB > procA in procs
  //      Get compat AppGroupTs_B
  //        Inters = intersection(AppGroupsTs_A, AppGroupTs_B)
  //        A_not_B = AppGroupTs_A - Inters
  //        B_not_A = AppGroupTs_B - Inters
  //        Add_to_result( Inters, A_not_B, B_not_A )
  //  result <- unique( result )
  // result is a tuple of tuples of app groups. We have to create as many containers as elements of this tuple


};

// // Syntatic suger ?? eg:
// template <typename AppIdSeqT, typename ProcIdSeqT, workload::kind WorkKind, plat::processor ProcId>
// using native_compatible_impls_t = typename native<AppIdSeqT, ProcIdSeqT>::compatible_impls<WorkKind, ProcId>;


} // namespace util
