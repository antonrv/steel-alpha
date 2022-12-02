
export module SteelRT.Task.Descriptor.Commit;


import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
import SteelRT.Util.App;

import SteelRT.Dep.Guard.Backend;

import SteelRT.Task.Descriptor;

// import SteelRT.Instrument;


namespace task {


  ////////////////////////////////////////// RELEASE DEPENDENCIES. This is actually the deleter of the workload::desc::own_poly_t


  template <typename StdCallTupleT, std::size_t... BndIds>
  void set_result_detail(StdCallTupleT& callTupleRef, util::sequence::index_t<BndIds...>) {
    ( std::get<BndIds>( callTupleRef ).release(), ... );
  }

export
template <
  app::call AppCall
>
void set_result( task::poly_descriptor * descPtr, const std::function<void(task::poly_descriptor*)>& successCallback ) {


  using StdCallTupleT = app::tuple_std_args_t<AppCall>;

  StdCallTupleT& callTupleRef = *static_cast<StdCallTupleT*>( static_cast<task::descriptor<AppCall, StdCallTupleT>*>( descPtr ) );

  using OnlyBndIds = util::tuple::filter_ids_t< app::tuple_args_t<AppCall>, dep::guard::bnd::is >;

  // instr::trace<instr::event::dep_commit::start>();

  set_result_detail( callTupleRef, OnlyBndIds{} );

  // instr::trace<instr::event::dep_commit::end>();
  successCallback(descPtr);

  // We need to delete on the static_cast so that the bnd guards are destroyed (ie if we destroy the base ->  memory leak)
  delete static_cast<task::descriptor<AppCall, StdCallTupleT>*>( descPtr );

}



  template <typename StdCallTupleT, std::size_t... Ids>
  void set_error_detail(StdCallTupleT& callTupleRef, util::sequence::index_t<Ids...>) {
    ( std::get<Ids>( callTupleRef ).set_error(), ... );
  }


export
template <
  app::call AppCall
>
void set_error( task::poly_descriptor * descPtr ) {

  using StdCallTupleT = app::tuple_std_args_t<AppCall>;

  StdCallTupleT& callTupleRef = *static_cast<StdCallTupleT*>( static_cast<task::descriptor<AppCall, StdCallTupleT>*>( descPtr ) );

  using OnlyBndIds = util::tuple::filter_ids_t< app::tuple_args_t<AppCall>, dep::guard::bnd::is >;

  // instr::trace<instr::event::dep_commit::error_start>();

  set_error_detail( callTupleRef, OnlyBndIds{} );

  // instr::trace<instr::event::dep_commit::error_end>();

  // We need to delete on the static_cast so that the bnd guards are destroyed (ie if we destroy the base ->  memory leak)
  delete static_cast<task::descriptor<AppCall, StdCallTupleT>*>( descPtr );
}

} // namespace task
