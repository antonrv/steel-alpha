
export module SteelRT.Task.MakeAsync;

  export import SteelRT.Task.Descriptor;
  export import SteelRT.Task.Descriptor.Commit;

import SteelRT.Dep.Guard.Backend;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
import SteelRT.Util.AppWork;

import <type_traits>;
export import <memory>;

namespace task {


///////////////// READ ONLY COPY
template <
  typename AppCallArgT,
  typename ArgT,
  util::req_t<
    std::conjunction<
      std::negation<std::is_lvalue_reference<AppCallArgT>>,
      std::negation<std::is_rvalue_reference<AppCallArgT>>,
      std::negation<dep::guard::bnd::is<std::decay_t<ArgT>>> // Argument is not a guard
    >
  >...
>
AppCallArgT make_call_arg(ArgT arg) {
  return static_cast<AppCallArgT>(arg);
}

///////////////// PASSING VARIABLE AS COPY
template <
  typename AppCallArgT,
  typename ArgT,
  util::req_t<
    std::conjunction<
      std::negation<std::is_lvalue_reference<AppCallArgT>>,
      std::negation<std::is_rvalue_reference<AppCallArgT>>,
      // std::is_rvalue_reference<ArgT>,
      dep::guard::bnd::is_readable<std::decay_t<ArgT>>,
      std::is_same<std::decay_t<ArgT>, AppCallArgT>
    >
  >...
>
AppCallArgT make_call_arg(ArgT arg) {
  return arg;
}

template <
  typename AppCallArgT,
  typename ArgT,
  util::req_t<
    std::conjunction<
      std::negation<std::is_lvalue_reference<AppCallArgT>>,
      std::negation<std::is_rvalue_reference<AppCallArgT>>,
      // std::is_rvalue_reference<ArgT>,
      dep::guard::bnd::is_writable<std::decay_t<ArgT>>,
      std::is_same<std::decay_t<ArgT>, AppCallArgT>
    >
  >...
>
AppCallArgT make_call_arg(ArgT arg) {
  return arg;
}



template <
  app::call AppCall,
  std::size_t...Ids,
  typename... ArgTs>
inline
std::unique_ptr< task::descriptor<AppCall, util::tuple::as_std_t< typename app::traits<AppCall>::arg_tuple_type>>, workload::desc_deleter_t >
make_async_detail(util::sequence::index_t<Ids...>, depth_t d, ArgTs&&... args) {

  using AppCallArgTupleT = typename app::traits<AppCall>::arg_tuple_type;

  using desc_t = task::descriptor<AppCall, util::tuple::as_std_t<AppCallArgTupleT> >;
  
  return std::unique_ptr< desc_t, workload::desc_deleter_t >( new desc_t( d, make_call_arg< util::tuple::element_t<Ids, AppCallArgTupleT> >( std::forward<ArgTs>(args) ) ...),  &task::set_error<AppCall> );

}

//////////////////// INTERFACE ENTRY POINT


export
template <
  app::call AppCall,
  typename... ArgTs>
std::unique_ptr< task::descriptor<AppCall, util::tuple::as_std_t< typename app::traits<AppCall>::arg_tuple_type>>, workload::desc_deleter_t >
make_async(depth_t d, ArgTs&&... args) {


  // using IdxSeq = util::sequence::make_index_t< util::tuple::size_v<typename app::traits<AppCall>::arg_tuple_type> >;
  using IdxSeq = util::sequence::make_index_t< app::traits<AppCall>::arg_tuple_type::size() >;
  // std::make_index_sequence< util::tuple::size_v<typename app::traits<AppCall>::arg_tuple_type> >;

  return make_async_detail<AppCall>(IdxSeq{}, d, std::forward<ArgTs>(args) ... );
}

} // namespace task
