export module SteelRT.Dep.Dim.View;

export import SteelRT.Dep.Dim.View.Parameters;

import SteelRT.Util.Basic;


export
namespace dep::dim {

template <typename T>
class view_base {
private:

  static_assert( not std::is_pointer_v<T> );
  static_assert( not std::is_reference_v<T> );

  using ptr_t = std::add_pointer_t<T>;

  ptr_t m_ptr = nullptr;

public:

  view_base() = default;
  view_base(view_base&&) = default;

  view_base(ptr_t p) : m_ptr(p) {}

  ptr_t get_ptr() const noexcept { return m_ptr; }

  void set_ptr(ptr_t p) noexcept { m_ptr = p; }
};



template <unsigned Dim, typename T>
class view;

//////////////// A view of a N-D range in memory
template <unsigned Dim, typename T>
class view : public view_base<T> {

private:

  using super_type = view_base<T>;

  using ptr_t = std::add_pointer_t<T>;

  using array_t = std::array<ulong_t, Dim>;

  // View parameters are solely used perform n-Dim data copies. Not used for data region overlap detection for synchronization.
  // TODO. for mesh::direct we don't need to store parameters in each data view, since they are mostly common and can be stored in dim_mapper
  view_parameters<Dim> m_parameters;
  
public:

  view() = default;
  view(view&&) = default;

  // view(T& ref, const array_t& s) : super_type(&ref), m_sizes(s) {}

  // const array_t& get_sizes() const noexcept { return m_sizes; }

  void set_parameters(view_parameters<Dim> vp) noexcept { m_parameters = vp; }
};


} // namespace dep::dim
