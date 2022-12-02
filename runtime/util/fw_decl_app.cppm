
export module SteelRT.Util.FwDeclarations.App;

import SteelRT.Util.Types;


export
namespace app {

enum class id : enum_uint_t;
enum class impl : enum_uint_t;
enum class call : enum_uint_t;

template <auto EnumV> class traits;
template <impl AppImpl> class kernel_proxy;
template <impl AppImpl> class dispatcher_proxy;

template <app::id AppId, typename GroupImplT, typename EnableT = util::enabler_t> class load_proxy;

} // namespace app
