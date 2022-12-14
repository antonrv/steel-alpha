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
void foo_lt_add(std::add_pointer_t<std::add_const_t<float>>,int);
task::coro::dispatcher<app::impl::caller_lt_add> caller_lt_add(task::attr::descriptor& ,int);
void foo_leq_add(std::add_pointer_t<std::add_const_t<float>>,int);
task::coro::dispatcher<app::impl::caller_leq_add> caller_leq_add(task::attr::descriptor& ,int);
void foo_gt_sub(std::add_pointer_t<std::add_const_t<float>>,int);
task::coro::dispatcher<app::impl::caller_gt_sub> caller_gt_sub(task::attr::descriptor& ,int);
void foo_geq_sub(std::add_pointer_t<std::add_const_t<float>>,int);
task::coro::dispatcher<app::impl::caller_geq_sub> caller_geq_sub(task::attr::descriptor& ,int);
export
namespace app{
template <>
class kernel_proxy<impl::foo_lt_add> {
  static constexpr impl this_impl = impl::foo_lt_add;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    foo_lt_add( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::caller_lt_add> {
public:
  static constexpr impl this_impl = impl::caller_lt_add;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( caller_lt_add( std::forward<DispatcherArgs>(args) ... ) );
  }
};
template <>
class kernel_proxy<impl::foo_leq_add> {
  static constexpr impl this_impl = impl::foo_leq_add;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    foo_leq_add( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::caller_leq_add> {
public:
  static constexpr impl this_impl = impl::caller_leq_add;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( caller_leq_add( std::forward<DispatcherArgs>(args) ... ) );
  }
};
template <>
class kernel_proxy<impl::foo_gt_sub> {
  static constexpr impl this_impl = impl::foo_gt_sub;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    foo_gt_sub( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::caller_gt_sub> {
public:
  static constexpr impl this_impl = impl::caller_gt_sub;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( caller_gt_sub( std::forward<DispatcherArgs>(args) ... ) );
  }
};
template <>
class kernel_proxy<impl::foo_geq_sub> {
  static constexpr impl this_impl = impl::foo_geq_sub;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    foo_geq_sub( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::caller_geq_sub> {
public:
  static constexpr impl this_impl = impl::caller_geq_sub;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( caller_geq_sub( std::forward<DispatcherArgs>(args) ... ) );
  }
};
}