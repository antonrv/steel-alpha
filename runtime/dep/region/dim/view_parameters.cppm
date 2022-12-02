
export module SteelRT.Dep.Dim.View.Parameters;

import SteelRT.Dep.Dim.Types;


namespace dep::dim {

export
template <unsigned Dim>
struct view_parameters {

  array_t<Dim> embeddings;
  array_t<Dim> sizes;
  array_t<Dim> offsets;
  array_t<Dim> spacing;
};

// template <unsigned Dim, typename T>
// void mem_copy(view<Dim, T> outView, view<Dim, T> inView) {
//   TODO
//   // Ptr in outView has been already allocated as a fold_product of its sizes. all its parameters already been set.
// }

} // namespace dep::dim
