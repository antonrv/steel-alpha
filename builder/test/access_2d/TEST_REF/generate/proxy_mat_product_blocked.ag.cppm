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
void allocate_matrix(std::add_pointer_t<float>,unsigned,unsigned);
void deallocate_matrix(std::add_pointer_t<float>);
void mat_product_v0_kernel_compact(std::add_pointer_t<float>,std::add_pointer_t<std::add_const_t<float>>,std::add_pointer_t<std::add_const_t<float>>,unsigned,unsigned,unsigned);
void pack_matrix(std::add_pointer_t<float>,std::add_pointer_t<std::add_const_t<float>>,unsigned,unsigned,unsigned);
void unpack_matrix(std::add_pointer_t<float>,std::add_pointer_t<std::add_const_t<float>>,unsigned,unsigned,unsigned);
task::coro::dispatcher<app::impl::mat_product_v3_block_compact> mat_product_v3_block_compact(task::attr::descriptor& ,std::add_pointer_t<float>,std::add_pointer_t<std::add_const_t<float>>,std::add_pointer_t<std::add_const_t<float>>,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
export
namespace app{
template <>
class kernel_proxy<impl::allocate_matrix> {
  static constexpr impl this_impl = impl::allocate_matrix;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    allocate_matrix( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class kernel_proxy<impl::deallocate_matrix> {
  static constexpr impl this_impl = impl::deallocate_matrix;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    deallocate_matrix( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class kernel_proxy<impl::mat_product_v0_kernel_compact> {
  static constexpr impl this_impl = impl::mat_product_v0_kernel_compact;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    mat_product_v0_kernel_compact( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class kernel_proxy<impl::pack_matrix> {
  static constexpr impl this_impl = impl::pack_matrix;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    pack_matrix( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class kernel_proxy<impl::unpack_matrix> {
  static constexpr impl this_impl = impl::unpack_matrix;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
public:
  template <typename... KernelArgs>
  static void run(KernelArgs&&... args) {
    unpack_matrix( std::forward<KernelArgs>(args) ... );
  }
};
template <>
class dispatcher_proxy<impl::mat_product_v3_block_compact> {
public:
  static constexpr impl this_impl = impl::mat_product_v3_block_compact;
  using arg_tuple_type = typename app::traits<this_impl>::arg_tuple_type;
  template <typename... DispatcherArgs>
  static
  std::shared_ptr<task::coro::dispatcher<this_impl>>
  create(DispatcherArgs&&... args) noexcept {
    return std::make_shared< task::coro::dispatcher<this_impl> >( mat_product_v3_block_compact( std::forward<DispatcherArgs>(args) ... ) );
  }
};
}