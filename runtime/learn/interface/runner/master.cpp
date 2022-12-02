

module SteelRT.Learn.Interface.Runner.Master;


import SteelRT.Util.Types;

namespace learn::intf::runner {

std::unique_ptr<runner::queue> core::s_ownQueue = nullptr;
std::unique_ptr<runner::core::pipes> core::s_ownPipes = nullptr;



raii_master initialize( const str_t& strId, const str_t& vArgs, const str_t& queueIdStr, const str_t& cueOkStr, const str_t& exitStr ) {
  return core::initialize( strId, vArgs, queueIdStr, cueOkStr, exitStr );
}

} // namespace learn::intf::runner
