
export module SteelRT.Util.FwDeclarations.Plat;

import SteelRT.Util.Types;

export
namespace plat {

enum class processor : enum_uint_t;
enum class arch : enum_uint_t;
enum class freq : enum_uint_t;
enum class memspace : enum_uint_t;
enum class memkind : enum_uint_t;
enum class host : enum_uint_t;

  template <processor PId>
  struct ptraits;

  template <memspace MSId>
  struct mtraits;

} // namespace plat
