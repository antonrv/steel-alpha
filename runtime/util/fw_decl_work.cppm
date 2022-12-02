
export module SteelRT.Util.FwDeclarations.Work;

import SteelRT.Util.Types;

export
namespace workload {

  enum class kind : enum_uint_t;


  template <kind WorkKind>
  struct wtraits;

  // template < workload::kind WorkKind, typename ImplSeqT >
  // class container;

  // template < workload::kind WorkKind >
  // class container;

} // namespace workload
