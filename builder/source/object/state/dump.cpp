
#include "source/object/function/definition.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/function/call.hpp"
#include "source/object/function/loop.hpp"
#include "source/object/function/context.hpp"
#include "source/object/function/return.hpp"
#include "source/object/data/use.hpp"

#include "source/object/state/def.hpp"

#include "files/name/decl.hpp"


namespace nms_state = bld::state;


namespace bld::src {


template <obj Obj>
void capture_objects( set_csob_t& objSet, const nms_state::filename& fn ) {

  // std::cout << "Capturing " << Obj << " objects in " << fn << '\n';

  auto objs = state<Obj>::get_all_satisfying(
      [fn] (const auto& srcObj) {
        // std::cout << "obj fn : " << srcObj->get_filename() << '\n';
        return srcObj->get_source_filename() == fn;
      }
    );

  std::copy( std::begin(objs), std::end(objs), std::inserter(objSet, std::end(objSet)) );
}


template <obj... Objs>
static
void capture_all_objects( set_csob_t& objSet, const nms_state::filename& fnStr, std::integer_sequence<obj, Objs...> ) {

  ( capture_objects<Objs>( objSet, fnStr ), ... );
}



std::string dump_belonging_to_file( const nms_state::filename& fn ) {

  set_csob_t objectSet;

  capture_all_objects( objectSet, fn, enabled::Sequence_obj{} );

  return std::accumulate( std::begin(objectSet), std::end(objectSet), std::string(),
      [] (const std::string& cum, csob_t srcObj) {
        return cum + "\n" + srcObj->serial();
      }
    );
}


} // namespace bld::src
