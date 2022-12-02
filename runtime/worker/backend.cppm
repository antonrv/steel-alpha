
export module SteelRT.Worker.Backend;

  export import SteelRT.Util.Indexable;
  export import SteelRT.Learn.Agent.Runner.Implementer;

  export import SteelRT.Execute.Load;
  export import SteelRT.Execute.Kernel;
  export import SteelRT.Execute.Dispatcher;

  export import SteelRT.Task.Descriptor.Commit;
  export import SteelRT.Task.Descriptor.Update;

import SteelRT.Learn.Interface.Runner.Send; //Dont export XXX TODO

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
import SteelRT.Util.AppWork;

// exports ?

import SteelRT.Task.Descriptor;

import SteelRT.Task.Dispatcher;

import SteelRT.Instrument;

import SteelRT.Util.Assert;
#include "assert.hpp"


// The worker::backend layer forwards the workload for execution. Possibly selecting an implementation among the possible ones


namespace worker {

export
template < plat::processor ProcId, class NativeT >
class backend {
private:

  // const workload::push_poly_desc_fn_t m_pushNewDescFn; // Not needed as long as we are considering lightweight dispatchers

  const workload::push_poly_disp_fn_t m_pushNewDispFn = nullptr;

  using processable_impl_seq = typename NativeT::template compatible_processable_impls< ProcId >;

  using kernel_impl_seq = typename NativeT::template compatible_kernelable_impls< ProcId >;

  using dispatcher_impl_seq = typename NativeT::template compatible_dispatcher_impls< ProcId >;

  // Among all the processable, get all calls calling to them
  using this_app_calls = app::cat_calls_of_t< processable_impl_seq >;


private: // IMPLEMENTER AGENTS TO PICK THE ADEQUATE IMPLEMENTATION 


  using app_group_tuple_t = typename NativeT::template all_compatible_groups<ProcId>;

  template <typename AppGroupT>
  using implementer_of_t = learn::agent::runner::implementer<ProcId, AppGroupT, NativeT>;

  template <typename AppGroupT>
  using own_implementer_of_t = std::unique_ptr< implementer_of_t<AppGroupT> >;

  using tuple_implementer_t = util::tuple::lift_t< app_group_tuple_t, implementer_of_t >;

  using own_tuple_implementer_t = util::tuple::lift_t< app_group_tuple_t, own_implementer_of_t >;

  using std_own_tuple_implementer_t = util::tuple::as_std_t< own_tuple_implementer_t >; // As many agents as AppGroupTs runnable on this processor
  std_own_tuple_implementer_t m_ownImplementers;


private: // PROCESS DESC LUFT. To process a descriptor based on its call.

  //////////// Table functions to process descriptors
  using process_descriptor_fn_t = std::function<workload::own_poly_desc_t( thread_id_t, workload::own_poly_desc_t&& )>;

  using process_descriptor_table_fn_t = util::indexable_array_t< this_app_calls, process_descriptor_fn_t >;

  process_descriptor_table_fn_t m_procDescTableFn;

  template <app::call AppCall>
  void set_proc_desc_fn() noexcept {
    m_procDescTableFn.template set< AppCall >(
      std::bind( &backend::template process_descriptor<AppCall>, this,
        std::placeholders::_1, // thread_id_t
        std::placeholders::_2 // own_poly_desc_t
      )
    );
  }

  template <app::call... AppCalls>
  void make_proc_desc_table_fn( util::sequence::enum_t<app::call, AppCalls...> ) {
    ( set_proc_desc_fn<AppCalls>(), ... );
  }

private: // PROCESS DISP LUFT. To process a dispatcher based on its impl

  using process_dispatcher_table_fn_t = util::indexable_array_t< dispatcher_impl_seq, std::function<workload::own_poly_desc_t(workload::own_poly_disp_t&)> >;

  process_dispatcher_table_fn_t m_procDispTableFn;

  template <app::impl AppImpl>
  void
  set_proc_disp_fn( ) noexcept {
    m_procDispTableFn.template set< AppImpl >(
      std::bind( &backend::template process_dispatcher<AppImpl>, this,
        std::placeholders::_1 // own poly disp
      ) );
  }

  template <app::impl... AppImpls>
  void make_proc_disp_table_fn( util::sequence::enum_t<app::impl, AppImpls...> ) {
    ( set_proc_disp_fn< AppImpls >( ), ... );
  }



private: // RESOLUTION LUFT. To process a descriptor as a kernel or as a dispatcher. Maybe we can factor out the init to indexable class

  using resolve_fn_t = std::function<void(workload::own_poly_desc_t&&)>;

  using resolve_luft_t = util::indexable_2d_array< processable_impl_seq, this_app_calls, resolve_fn_t >;

  resolve_luft_t m_resolveLUFT;

  // CASE 1: NON-COMPATIBLE AppImpl - AppCall
  template <
    app::impl AppImpl, app::call AppCall,
    util::req_t<
      std::negation< app::are_equivalent<AppImpl, app::impl_of_v<AppCall>> >
    > ...
  >
  void set_resolve_fn( ) {

    m_resolveLUFT.template set<AppImpl, AppCall>( nullptr );
  }

  // CASE 2: COMPATIBLE AppImpl - AppCall, being AppImpl a kernel
  template <
    app::impl AppImpl, app::call AppCall,
    util::req_t<
      std::conjunction<
        app::are_equivalent<AppImpl, app::impl_of_v<AppCall>>,
        app::is_kernel<AppImpl>
      >
    > ...
  >
  void set_resolve_fn( ) {

    m_resolveLUFT.template set<AppImpl, AppCall>(
        std::bind( &backend::resolve_descriptor_as_kernel<AppImpl, AppCall>, this, std::placeholders::_1 )
      );
  }

  // CASE 3: COMPATIBLE AppImpl - AppCall, being AppImpl a dispatcher
  template <
    app::impl AppImpl, app::call AppCall,
    util::req_t<
      std::conjunction<
        app::are_equivalent<AppImpl, app::impl_of_v<AppCall>>,
        app::is_dispatcher<AppImpl>
      >
    > ...
  >
  void set_resolve_fn( ) {

    m_resolveLUFT.template set<AppImpl, AppCall>(
        std::bind( &backend::resolve_descriptor_as_dispatcher<AppImpl, AppCall>, this, std::placeholders::_1 )
      );
  }

  // UNFOLD INITIALIZATION 2nd dim
  template <app::call AppCall, app::impl... AppImpls>
  void initialize_resolve( util::sequence::enum_t<app::impl, AppImpls...> ) {

    ( set_resolve_fn<AppImpls, AppCall>( ), ... );
  }

  // UNFOLD INITIALIZATION 1st dim
  template<app::call... AppCalls>
  void make_resolve_table_fn( util::sequence::enum_t<app::call, AppCalls...> ) {

    ( initialize_resolve<AppCalls>( processable_impl_seq{} ), ... );
  }

private:

  template <std::size_t... ImplementerIds> 
  static
  std_own_tuple_implementer_t make_implementers( const learn::runner::cfg& runnerCfg, util::sequence::index_t<ImplementerIds...> ) {
    return std::make_tuple( std::make_unique< util::tuple::element_t<ImplementerIds, tuple_implementer_t> >( runnerCfg ) ... );
  }


public: // CONSTRUCTOR

  backend( const learn::runner::cfg& runnerCfg, workload::push_poly_disp_fn_t&& pushDispFn ) :
    m_pushNewDispFn( pushDispFn ),
    m_ownImplementers( make_implementers( runnerCfg, util::sequence::make_index_t< tuple_implementer_t::size() >{} ) )
  {
    // Make LUFT structures
    make_proc_desc_table_fn( this_app_calls{} );
    make_proc_disp_table_fn( dispatcher_impl_seq{} );
    make_resolve_table_fn( this_app_calls{} );
  }

  backend(backend&&) = delete;
  backend(const backend&) = delete;


  template <typename AppGroupT>
  static void learn_notify_end( task::poly_descriptor * descPtr ) {

    // learn::intf::runner::send<NativeT, learn::intf::msg::ctg::tasking, learn::intf::msg::kind::end, implementer_of_t<AppGroupT>>( reinterpret_cast<learn::intf::msg::task_id_t>( descPtr ) ); WRONG ptr addresses could be reused
    learn::intf::runner::send<NativeT, learn::intf::msg::ctg::tasking, learn::intf::msg::kind::end, implementer_of_t<AppGroupT>>( descPtr->youth );
  }

private:

  template <typename TrueEncoderT, std::size_t... ImplementerIds>
  void initialize_true_encoder_all( const TrueEncoderT& trueEncoderRef, util::sequence::index_t<ImplementerIds...> ) noexcept {
    ( std::get<ImplementerIds>( m_ownImplementers )->initialize_true_encoder( trueEncoderRef ), ... );
  }

public:

  template <typename TrueEncoderT>
  void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {
    initialize_true_encoder_all( trueEncoderRef, util::sequence::make_index_t< tuple_implementer_t::size() >{} );
  }


public: // OPERATE DESCRIPTOR

  template <
    workload::kind WorkKind,
    util::req_t< util::same<WorkKind, workload::kind::desc> > ...
  >
  workload::own_poly_desc_t operate( thread_id_t thId, workload::own_poly_desc_t&& ownPolyDesc ) const {

    // auto arrImpl = util::sequence::to_array_v< processable_impl_seq >;
    ensure( ownPolyDesc->depth < global::DepthLimit, "Task depth limit surpased" );

    return m_procDescTableFn.get_rt( static_cast<app::call>(ownPolyDesc->appCall) )( thId, std::forward<workload::own_poly_desc_t>(ownPolyDesc) ); 
  }


private:

  template <
    app::call AppCall
  >
  workload::own_poly_desc_t process_descriptor( thread_id_t thId, workload::own_poly_desc_t&& ownPolyDesc ) {

    // Update state information synchronizing wrapped dependencies
    task::update<AppCall>( ownPolyDesc.get() );

    if (ownPolyDesc->get_solved_mask() == global::AllSolvedMask) {

      using app_group_t = app::group_impl_of_t< app::impl_of_v<AppCall> >;

      auto computeLoad = exe::estimate_load< AppCall >( ownPolyDesc.get() );

      app::impl appImpl = std::get< own_implementer_of_t<app_group_t> >( m_ownImplementers )->template choose<AppCall>( thId, ownPolyDesc.get(), computeLoad );

      if (ownPolyDesc->depth == global::DepthLimit - 1) {

        uint_t dbgTrials = 0; // TMP DBG XXX
        while (util::sequence::get_index_rt<dispatcher_impl_seq>::exists_in(appImpl) and dbgTrials < 100) {  // TMP DBG XXX

          // Max depth reached and dispatcher chosen, loop until a non-dispatcher appImpl is chosen.
          instr::trace<instr::event::worker_backend::retry>("Retrying impl", (uint_t)appImpl, "trial", dbgTrials);

          appImpl = std::get< own_implementer_of_t<app_group_t> >( m_ownImplementers )->template retry_choose<AppCall>( thId, ownPolyDesc.get() );
          dbgTrials++; // TMP DBG XXX
        }
        if (dbgTrials >=100) { // TMP DBG XXX
          throw std::logic_error("Number of max trials in retry_choose exceeded");
        }

        // Avoid this. Possibly a cause of divergence XXX
        // app::impl appImpl = std::get< own_implementer_of_t<app_group_t> >( m_ownImplementers )->template choose_restricted<kernel_impl_seq, AppCall>( thId, ownPolyDesc.get() );
      }

      m_resolveLUFT.get_rt( appImpl, AppCall )( std::forward<workload::own_poly_desc_t>(ownPolyDesc) );

      return nullptr;

    } else {

      return std::move(ownPolyDesc);
    }
  }



  template < app::impl AppImpl, app::call AppCall,
    util::req_t<
      std::conjunction<
        app::is_kernel<AppImpl>,
        std::negation< app::has_delegated<AppImpl> >
      >
    > ...
  >
  void resolve_descriptor_as_kernel( workload::own_poly_desc_t&& ownPolyDesc ) const {

    using this_app_group_t = app::group_impl_of_t< AppImpl >;


    exe::run_kernel<AppImpl, AppCall>( ownPolyDesc.get() );

    // Execution succeeded. Set deleter that resolves all writes
    ownPolyDesc.get_deleter() = std::bind( &task::set_result<AppCall>, std::placeholders::_1, &backend::learn_notify_end<this_app_group_t> );
  }


  template < app::impl AppImpl, app::call AppCall,
    util::req_t<
      std::conjunction<
        app::is_dispatcher<AppImpl>,
        std::negation< app::has_delegated<AppImpl> >
      >
    > ...
  >
  void resolve_descriptor_as_dispatcher( workload::own_poly_desc_t&& ownPolyDesc ) const {

    using this_app_group_t = app::group_impl_of_t< AppImpl >;

    auto newDisp = exe::create_dispatcher<AppImpl, AppCall>( ownPolyDesc.get() );

    newDisp->set_owned_descriptor( std::move(ownPolyDesc), std::bind( &task::set_result<AppCall>, std::placeholders::_1, &backend::learn_notify_end<this_app_group_t> ) );

    m_pushNewDispFn( std::move(newDisp) ); // Lightweight dispatchers
  }




public: // OPERATE DISPATCHER

  template <
    workload::kind WorkKind,
    util::req_t< util::same<WorkKind, workload::kind::disp> > ...
  >
  workload::own_poly_desc_t operate( thread_id_t thId, workload::own_poly_disp_t& ownPolyDisp ) const {

    // thId for the moment not used
    return m_procDispTableFn.get_rt( ownPolyDisp->get_implementation() )( ownPolyDisp );
  }


private:

  template <app::impl AppImpl>
  workload::own_poly_desc_t process_dispatcher( workload::own_poly_disp_t& ownPolyDisp ) const {

    using disp_t = task::coro::dispatcher<AppImpl>;

    return static_cast<disp_t*>(ownPolyDisp.get())->try_resume( );
  }

};


} // namespace worker
