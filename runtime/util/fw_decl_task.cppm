export module SteelRT.Util.FwDeclarations.Task;

import SteelRT.Util.FwDeclarations.App;

// import SteelRT.Util.App;

export
namespace task {

template <typename AppGroupImplT>
class group_descriptor;

class poly_descriptor;


template <app::call AppCall, typename CallStdTupleT>
class descriptor;


namespace coro {

template <app::impl AppImpl>
class dispatcher;

} // namespace coro

namespace state {

class dispatcher;

} // namespace state

} // namespace task
