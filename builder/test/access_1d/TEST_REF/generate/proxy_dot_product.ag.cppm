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
void dot_prod_v1(std::add_pointer_t<float>,std::add_pointer_t<std::add_const_t<float>>,std::add_pointer_t<std::add_const_t<float>>,std::add_const_t<unsigned>);
void reduce(std::add_pointer_t<float>,std::add_pointer_t<std::add_const_t<float>>,std::add_const_t<unsigned>);
task::coro::dispatcher<app::impl::dot_prod_v2> dot_prod_v2(task::attr::descriptor& ,std::add_pointer_t<float>,std::add_pointer_t<std::add_const_t<float>>,std::add_pointer_t<std::add_const_t<float>>,std::add_const_t<unsigned>,std::add_const_t<unsigned>);
export
namespace app{
template <>
class kernel_proxy<impl::dot_prod_v1> {
  static constexpr impl this_impl = impl::dot_prod_v1;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    dot_prod_v1( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class kernel_proxy<impl::reduce> {
  static constexpr impl this_impl = impl::reduce;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    reduce( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::dot_prod_v2> {
public:
  static constexpr impl this_impl = impl::dot_prod_v2;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( dot_prod_v2( std::forward<DispatcherArgs>(args) ... ) );
  }
};
}