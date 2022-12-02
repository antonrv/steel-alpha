//////////////////////////////////////
// 
// Autogenerated file. Do not modify. 
// 
//////////////////////////////////////

export module App.Proxy;
export import App.Graph;
export import SteelRT.Util.Types;
export import SteelRT.Util.Sequence;
export import SteelRT.Util.FwDeclarations.App;
export import SteelRT.Util.Predicates.App;
export import SteelRT.Task.Descriptor;
export import SteelRT.Task.Dispatcher;
export import SteelRT.Work.Descriptor.Global;
export import SteelRT.Dep.MakeAsync;
export import SteelRT.Dep.Guard.Backend;
export import SteelRT.Dep.Guard.Frontend;
export import SteelRT.Dep.Wrap;
export import <type_traits>;
export import <stdexcept>;
void init_v0(std::add_pointer_t<float>,float);
task::coro::dispatcher<app::impl::init_caller_v0> init_caller_v0(task::attr::descriptor& ,std::add_pointer_t<float>,std::add_const_t<unsigned>);
export
namespace app{
template <>
class kernel_proxy<impl::init_v0> {
  static constexpr impl this_impl = impl::init_v0;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    init_v0( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::init_caller_v0> {
public:
  static constexpr impl this_impl = impl::init_caller_v0;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( init_caller_v0( std::forward<DispatcherArgs>(args) ... ) );
  }
};
}