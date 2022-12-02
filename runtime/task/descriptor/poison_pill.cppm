
export module SteelRT.Task.DescriptorPoisonPill;

import SteelRT.Task.Descriptor;
import SteelRT.Task.DescriptorState;
import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.App;

export
namespace task::poison_pill {

using group_impl_t = app::group_impl< static_cast<app::id>(global::PoisonPillAppIndex), util::tuple_t<> >;

// using group_descriptor_t = group_descriptor<  poison_pill::group_impl_t  >;

class descriptor : public task::group_descriptor< poison_pill::group_impl_t > {

  using super_type = task::group_descriptor< poison_pill::group_impl_t >;
public:
  descriptor() : super_type() {}
};

} // namespace task::poison_pill
