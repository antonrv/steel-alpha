#ifndef SOURCE_OBJECT_STATE_SERIAL_SERIALIZE_OBJ_DEF_HPP
#define SOURCE_OBJECT_STATE_SERIAL_SERIALIZE_OBJ_DEF_HPP


#include "source/object/typedef.hpp"

#include "source/serial/serialize_decl.hpp"

#include "source/serial/locate.hpp"

namespace bld::src {


// template <obj Obj>
// so_t<Obj> serialize < sobject<Obj> >::deserial( object_id_t objId, const serial_map_t& serialMap ) {
// 
//   auto fnFind = std::bind( &find_object< own_so_t<Obj> >, std::placeholders::_1, objId );
// 
//   if ( state< Obj>::exist_satisfying( fnFind )) {
// 
//     return state< Obj >::edit_satisfying( fnFind );
// 
//   } else {
//     // Find in serialMap...
//     auto objContent = serialMap.at( objId );
//     
//     // ...and build new.
//     return state< Obj >::make_serial( objContent, serialMap );
//   }
// }


} // namespace bld::src

#endif // SOURCE_OBJECT_STATE_SERIAL_SERIALIZE_OBJ_DEF_HPP
