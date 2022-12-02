
#include "source/serial/serialize_decl.hpp"

#include "source/serial/locate.hpp"

namespace bld::src {

std::string serialize<std::string>::serial( const std::string& deserialField) {
  return deserialField;
}

// std::string serialize<std::string>::deserial( std::string serialField ) {
//   return serialField;
// }


std::string serialize <u_pair_t>::serial( const u_pair_t& inPair ) {
  return "{r-" + std::to_string(inPair[0]) + ",c-" + std::to_string(inPair[1]) + "}";
}


// u_pair_t serialize <u_pair_t>::deserial( std::string serialField ) {
//   u_pair_t retPair;
// 
//   if (serialField.front() != '{' or serialField.back() != '}') {
//     throw std::runtime_error("Could not deserialize u_pair_t. Brackets not found in : " + serialField);
//   }
// 
//   serialField.erase(0); // erase first bracket
//   serialField.pop_back(); // erase last bracket
//   auto commaPos = serialField.find(",");
// 
//   if (commaPos == std::string::npos) {
//     throw std::runtime_error("Could not deserialize u_pair_t. Comma not found in : " + serialField);
//   }
// 
//   retPair[0] = std::stoul( serialField.substr( 0, commaPos ) );
//   retPair[1] = std::stoul( serialField.substr( commaPos + 1 ) );
// 
//   return retPair;
// }




// sob_t serialize< sobject_base >::deserial( object_id_t objId, const serial_map_t& serialMap ) {
// 
//   if ( exist_any_satisfying( objId, enabled::Sequence_obj{} ) ) {
// 
// 
//       // return edit_any_satisfying( fnFind ); TODO
// 
//   } else {
//     // Throw. Cannot make a sobject_base TODO
//   }
//   throw std::runtime_error("UNIMPLEMENTED");
//     return nullptr;
// }


// sob_t serialize< pc::terminal >::deserial( object_id_t objId, const serial_map_t& serialMap ) {
// 
//   if ( exist_any_satisfying( objId, enabled::Sequence_obj{} ) ) {
// 
// 
//       // return edit_any_satisfying( fnFind ); TODO
// 
//   } else {
//     // Throw. Cannot make a pc::terminal TODO
//   }
//   throw std::runtime_error("UNIMPLEMENTED");
//     return nullptr;
// }


} // namespace bld::src
