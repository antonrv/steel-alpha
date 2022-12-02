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
void foo(std::add_pointer_t<float>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>);
task::coro::dispatcher<app::impl::caller_foo> caller_foo(task::attr::descriptor& ,std::add_pointer_t<float>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>);
export
namespace app{
template <>
class kernel_proxy<impl::foo> {
  static constexpr impl this_impl = impl::foo;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    foo( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::caller_foo> {
public:
  static constexpr impl this_impl = impl::caller_foo;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( caller_foo( std::forward<DispatcherArgs>(args) ... ) );
  }
};
}