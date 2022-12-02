#ifndef SOURCE_OBJECT_STATE_SERIAL_LOCATE_HPP
#define SOURCE_OBJECT_STATE_SERIAL_LOCATE_HPP

#include "source/object/state/def.hpp"

#include "source/object/function/call.hpp"
#include "source/object/function/definition.hpp"
#include "source/object/function/loop.hpp"
#include "source/object/function/return.hpp"
#include "source/object/function/context.hpp"
#include "source/object/function/binary.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/data/use.hpp"


namespace bld::src {

template < typename OwnSrcObjT >
static
bool find_object(const OwnSrcObjT& ownObj, std::string targetId) {
  return ownObj->get_identifier() == targetId;
};

template <obj... Objs>
static
bool exist_any_satisfying( const std::string& targetId, std::integer_sequence<obj, Objs...> ) {

  // Returns true if an object with targetId is found in the state
  return ( state<Objs>::exist_satisfying( std::bind( &find_object< own_so_t<Objs> >, std::placeholders::_1, targetId ) ) || ... );
}


template <obj... Objs>
sob_t get_satisfying( const std::string& targetId, std::integer_sequence<obj, Objs...> );


template <obj Obj, obj... Objs>
sob_t get_satisfying( const std::string& targetId, std::integer_sequence<obj, Obj, Objs...> ) {

  auto fnFind = std::bind( &find_object< own_so_t<Obj> >, std::placeholders::_1, targetId );

  if (state<Obj>::exist_satisfying( fnFind )) {
    return state<Obj>::get_satisfying( fnFind );
  } else {
    return get_satisfying( targetId, std::integer_sequence<obj, Objs...>{} );
  }
}

} // namespace bld::src

#endif // SOURCE_OBJECT_STATE_SERIAL_LOCATE_HPP
