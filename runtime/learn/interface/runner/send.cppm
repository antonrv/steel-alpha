
export module SteelRT.Learn.Interface.Runner.Send;

import SteelRT.Util.Types;

import SteelRT.Learn.Types;

import SteelRT.Learn.Interface.Runner.Master; // DONT EXPORT





export
namespace learn::intf::runner {

template <typename NativeT, msg::ctg MsgCtg, msg::kind MsgKind, typename ContextT, typename... Args>
void send( Args&&... args ) {

  master<NativeT>::template send<MsgCtg, MsgKind, ContextT>( std::forward<Args>(args) ... );
}


} // namespace learn::intf::runner
