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
void foo_shift_literal(std::add_pointer_t<std::add_const_t<float>>);
task::coro::dispatcher<app::impl::caller_shift_literal> caller_shift_literal(task::attr::descriptor& ,int,std::add_pointer_t<std::add_const_t<float>>);
void foo_shift_start(std::add_pointer_t<std::add_const_t<float>>,int);
task::coro::dispatcher<app::impl::caller_shift_start> caller_shift_start(task::attr::descriptor& ,int,std::add_pointer_t<std::add_const_t<float>>,int);
void foo_shift_end(std::add_pointer_t<std::add_const_t<float>>,int);
task::coro::dispatcher<app::impl::caller_shift_end> caller_shift_end(task::attr::descriptor& ,int,std::add_pointer_t<std::add_const_t<float>>,int);
void foo_shift_start_end(std::add_pointer_t<std::add_const_t<float>>,int,int);
task::coro::dispatcher<app::impl::caller_shift_start_end> caller_shift_start_end(task::attr::descriptor& ,int,int,int);
export
namespace app{
template <>
class kernel_proxy<impl::foo_shift_literal> {
  static constexpr impl this_impl = impl::foo_shift_literal;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    foo_shift_literal( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::caller_shift_literal> {
public:
  static constexpr impl this_impl = impl::caller_shift_literal;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( caller_shift_literal( std::forward<DispatcherArgs>(args) ... ) );
  }
};
template <>
class kernel_proxy<impl::foo_shift_start> {
  static constexpr impl this_impl = impl::foo_shift_start;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    foo_shift_start( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::caller_shift_start> {
public:
  static constexpr impl this_impl = impl::caller_shift_start;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( caller_shift_start( std::forward<DispatcherArgs>(args) ... ) );
  }
};
template <>
class kernel_proxy<impl::foo_shift_end> {
  static constexpr impl this_impl = impl::foo_shift_end;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    foo_shift_end( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::caller_shift_end> {
public:
  static constexpr impl this_impl = impl::caller_shift_end;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( caller_shift_end( std::forward<DispatcherArgs>(args) ... ) );
  }
};
template <>
class kernel_proxy<impl::foo_shift_start_end> {
  static constexpr impl this_impl = impl::foo_shift_start_end;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    foo_shift_start_end( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::caller_shift_start_end> {
public:
  static constexpr impl this_impl = impl::caller_shift_start_end;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( caller_shift_start_end( std::forward<DispatcherArgs>(args) ... ) );
  }
};
}