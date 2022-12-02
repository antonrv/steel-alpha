#include "files/enum.hpp"

#include "files/paths/enum.hpp"
#include "files/name/decl.hpp"

#include "inspect/inspector.hpp"

#include "inspect/consumer.clg.hpp"

#include "inspect/propagate/interface.hpp"

#include "common/util.hpp"

// To print only
#include "source/object/data/decl.hpp"
#include "source/object/data/use.hpp"
#include "source/object/function/binary.hpp"
#include "source/object/function/call.hpp"
#include "source/object/function/context.hpp"
#include "source/object/function/definition.hpp"
#include "source/object/function/loop.hpp"
#include "source/object/function/return.hpp"

#include "source/object/state/def.hpp"

#include "options/state/decl.hpp"
#include "options/state/log.hpp"


namespace bld {

inspector::inspector(const std::vector<state::filename>& src) : ast_analyzer(transform_vec(src, [] (const state::filename fn) { return fn.get_full_name(); } )) { }

template <src::obj Obj>
void log_recorded() {
  if (state::options::is_set< src::sobject<Obj>::log_record >()) {
    auto allObjs = src::state< Obj >::get_all();
    for (auto srcObj : allObjs) {
      state::log_if< src::sobject<Obj>::log_record >("final", *srcObj);
    }
  }
}

template <src::obj... Objs>
void log_all_recorded( std::integer_sequence<src::obj, Objs...> ) {

  ( log_recorded<Objs>(), ... );
}


void inspector::run() {

  // Do first inspection pass, registering function defs, function calls and task defs
  m_toolUptr->run( clang::tooling::newFrontendActionFactory<FunctionsFrontendAction>().get() );

  propagate_tasks_upstream();

  configure_data_decls();

  m_toolUptr->run( clang::tooling::newFrontendActionFactory<SetTaskInfoFrontendAction>().get() );

  log_all_recorded( enabled::Sequence_obj{} );

  // 1. Classify all source objects wrt files.

  // 2. For each file, dump them to a appFolder/inspect/filename.ins.cpp

  // Dump all the results of this stage

  // auto dUses = src::state<src::obj::data_use>::get_all();

  // for (auto dUse : dUses) {
  //   std::cout << dUse->serial() << '\n';
  // }
}

} // namespace bld
