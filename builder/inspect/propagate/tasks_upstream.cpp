
#include "source/object/function/definition.hpp"
#include "source/object/function/call.hpp"

#include "options/state/log.hpp"
#include "source/object/state/def.hpp"


namespace bld {

// The goal of this function is to propagate kernel calls upstream so that functions that call tasks become tasks.
void propagate_tasks_upstream() {

  // Loop until no more changes wrt function -> task upgrades are made
  bool doneFunctionToTaskUpgrade = true;
  // while (not removeList.empty())
  while (doneFunctionToTaskUpgrade) {

    doneFunctionToTaskUpgrade = false;
    // removeList.clear();

    auto funDefs = src::state<src::obj::fun_def>::edit_all();

    for (auto fDef : funDefs) {
      for (auto fBodyCall : fDef->get_body_calls()) {
        if (fBodyCall->get_callee()->is_task()) {
          // This fundef calls a task, so it becomes a task. Prepare everything:

          // then build a singleton task app (ie a impl belonging to a id without any more impl) task def from that fun def
          if (not fDef->is_task()) {
            fDef->set_task();

            doneFunctionToTaskUpgrade = true;
          }
          // state::add_copy(removeList, fDef);

          // break bc no need to keep looping over the calls of the fundecl, since we already know that it has been upgraded to a task
          break;

        } else {
          // Called function is not a task, so keep looping over calls
        }
      }
    }
    
  }

}

} // namespace bld
