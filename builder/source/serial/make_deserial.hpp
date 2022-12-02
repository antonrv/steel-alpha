
#include "source/object/typedef.hpp"

namespace bld::src {

// Called from objects constructors
template <typename TargetT>
TargetT make_deserial( const std::string& serialStr, std::string keyField, const serial_map_t& serialMap ) {

//   auto foundKeyStartPos = serialStr.find( keyField );
//   if (foundKeyStartPos == std::string::npos) {
//     throw std::runtime_error("Could not find key field : " + keyField + " in serialized object V:"\n + serialStr);
//   }
// 
//   auto foundKeyEndPos = serialStr.rfind(";", foundKeyStartPos);
// 
//   if (foundKeyEndPos == std::string::npos) {
//     throw std::runtime_error("Could not capture field : " + keyField + ", no end field character found  ';', in serialized object V:"\n + serialStr);
//   }
// 
//   auto captureStartPos = foundKeyStartPos + keyField.size();
// 
//   return deserial_field< TargetT >( serialStr.substr(captureStartPos, foundKeyEndPos - captureStartPos ) );
  return TargetT();
}

} // namespace bld::src
