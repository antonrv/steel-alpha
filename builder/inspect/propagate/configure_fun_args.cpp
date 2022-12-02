

#include "source/object/data/decl.hpp"
#include "source/object/function/loop.hpp"

#include "source/object/state/def.hpp"


namespace bld {



static
src::set_so_t<src::obj::data_decl>
set_guards( const src::set_so_t<src::obj::data_decl>& dDeclsToGuard) {


  src::set_so_t<src::obj::data_decl> retFunArgSet;

  for (auto dDecl : dDeclsToGuard) {
    // This if probably not needed
    if (not dDecl->has_guard()) {

      // Set the guard
      // std::cout << "Setting the guard of " << dDecl->get_identifier() << '\n';
      dDecl->set_guard();

      // Then locate those data uses whose callee dDecl is dDecl ... 
      auto dUsesCallingThisFunArg = src::state<src::obj::data_use>::edit_all_satisfying(
          [dDecl](const auto& dUseOwn) {
            if (dUseOwn->is_direct_call_argument()) {
              return dUseOwn->get_callee_data_decl()->get_identifier() == dDecl->get_identifier();
            }
            return false;
          }
        );

      // ... and add the corresponding root fun args of these uses to the ret set, so that their guards are set in the next step.
      for (auto dUse : dUsesCallingThisFunArg) {
        auto dDeclRoot = src::state<src::obj::data_decl>::edit_satisfying(
          [dUse] (const auto& dDeclOwn) {
            return dDeclOwn->get_identifier() == dUse->get_root_data_decl()->get_identifier();
          });
        if (dDeclRoot == nullptr) {
          throw std::logic_error("Could not set guard for " + dUse->get_root_data_decl()->get_identifier());
        }
        retFunArgSet.insert( dDeclRoot );

        // We cannot add the copy like this because dUse returns a 'const elem *'
        // state::add_copy( retFunArgSet, dUse->get_root_data_decl() );
      }

    } else {
      // Already has a guard, do nothing
    }
  }

  return retFunArgSet;
}


void configure_data_decls() {

  {
    // 1. First detect loop variables, upgrading the data_decls that qualify as such
    auto funLoops = src::state<src::obj::fun_loop>::get_all();

    auto dDeclsInLoops = src::state<src::obj::data_decl>::edit_all_satisfying(
      [&] (const auto& dDeclOwn) {
        // If any of the fun loops contains this dDeclOwn (dDecl), then that dDecl is returned
        return std::any_of(std::begin(funLoops), std::end(funLoops),
          [&] (src::cso_t<src::obj::fun_loop> fLoop) {
            return fLoop->contains( dDeclOwn.get() );
          });
      }
    );

    // std::cout << "Detecting loop vars in " << dDeclsInLoops.size() <<  "\n";

    std::for_each( std::begin(dDeclsInLoops), std::end(dDeclsInLoops),
      [&] (src::so_t<src::obj::data_decl> dDecl) {
        dDecl->maybe_detect_loop_variable();
      }
    );
  }


  {
    // 2. Second. Build the guards of the dDecls within bottom-most tasks (kernels). ... 

  auto dDeclsToGuard =
        src::state<src::obj::data_decl>::edit_all_satisfying(
          [] (const auto& dDeclOwn) {
            return dDeclOwn->require_guard() and (not dDeclOwn->require_wrap());
          });

    // ... From previous, the guards in upperFunArgs can be built afterwards.
    while (not dDeclsToGuard.empty()) {
      dDeclsToGuard = set_guards( dDeclsToGuard );
    }

    // Build the rest of the guards that have not been already set
    dDeclsToGuard =
        src::state<src::obj::data_decl>::edit_all_satisfying(
          [] (const auto& dDeclOwn) {
            return (not dDeclOwn->has_guard()) and dDeclOwn->require_guard();
          });

    while (not dDeclsToGuard.empty()) {
      dDeclsToGuard = set_guards( dDeclsToGuard );
    }
  }

}

} // namespace bld
