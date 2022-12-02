#include "compile/base.hpp"

#include "files/interface.hpp"

#include "options/state/log.hpp"


namespace bld {

compile::compile() {
  initialize_system_includes();
  initialize_primary_flags();
  initialize_secondary_flags();

  initialize();
}

template <code InterfaceOrImpl>
compilation_flags_t
compile::run_dependencies(const dependent_file * fElemPtr) {

  compilation_flags_t inEff;

  // bool stdModDone = false;
  for (auto modPtr : fElemPtr->get_imported_modules()) {
    if (modPtr->is_cpp_std() /*and not stdModDone*/) {

      // if constexpr (InterfaceOrImpl == code::interface) {
      //   inEff.push_back("-stdlib=libc++"); // "-Wno-attributes" to prevent warning of UDER attrs
      //   inEff.push_back("-fmodules");
      //   inEff.push_back("-fmodules-cache-path=" + state::paths<key_path::build_std>::get_path());
      //   stdModDone = true;
      // }

    } else if (not modPtr->is_cpp_std()) {
      if (modPtr->get_interface() == nullptr) {
        throw std::runtime_error("Undefined interface file for module " + modPtr->get_identifier());
      }
      auto flags = this->run_if_needed<code::interface>( modPtr->get_interface() );
      inEff.insert(std::end(inEff), std::begin(flags), std::end(flags));

    }
  }
  if constexpr (InterfaceOrImpl == code::interface) {
    inEff.push_back("-stdlib=libc++"); // "-Wno-attributes" to prevent warning of UDER attrs
    inEff.push_back("-fmodules");
    inEff.push_back("-fmodules-cache-path=" + state::paths<key_path::build_std>::get_path());
  }

  for (auto incDir : fElemPtr->get_include_routes()) {
    inEff.push_back("-I" + incDir);
  }

  return inEff;
}

template compilation_flags_t compile::run_dependencies<code::interface>(const dependent_file * fElemPtr);
template compilation_flags_t compile::run_dependencies<code::implementation>(const dependent_file * fElemPtr);


void compile::gather_link_dependencies(std::set<std::string>& modulesLinkEff, set_cmodule_t& depModules, cmodule_t inputMod) {

  auto [insertIt, wasInserted] = depModules.emplace( inputMod );

  if (wasInserted) {
    // Not already registered
    // std::cout << "Recording dep module " << inputMod->get_identifier() << '\n';

    if (inputMod->is_cpp_std()) {

      modulesLinkEff.insert("-lstdc++");

      if (inputMod->get_identifier() == "<thread>") {
        modulesLinkEff.insert("-lpthread");
      }

      // state::add_copy(depModules, inputMod);

    } else {
      // A steel runtime module:

      // state::add_copy(depModules, inputMod);

      // Loop over implementations, gathering the compiled objects.
      for (auto implModPtr : inputMod->get_implementations()) {
        auto implFlags = this->run_if_needed<code::implementation>( implModPtr );
        // for (auto f : implFlags) { std::cout << "  Including its implementation " << f << '\n'; }
        for (const auto& lEff : implFlags) {
          modulesLinkEff.insert(lEff);
        }

        for (auto childModPtr : implModPtr->get_imported_modules()) {
          gather_link_dependencies(modulesLinkEff, depModules, childModPtr);
        }
      }

      // Recurse
      for (auto childModPtr : inputMod->get_interface()->get_imported_modules()) {
        gather_link_dependencies(modulesLinkEff, depModules, childModPtr);
      }
    }

  } else {
    // std::cout << "Already registered " << inputMod->get_identifier() << '\n';
    // Do nothing
  }
}

template <>
compilation_flags_t
compile::run_dependencies<code::entry>(const dependent_file * depfElemPtr) {

  auto retFlags = this->run_dependencies<code::implementation>(depfElemPtr);

  auto fElemPtr = static_cast<cfile_t<file_kind::compilable, code::entry>>(depfElemPtr);

  // Gather unique module elements
  set_cmodule_t depModules;
  std::set<std::string> modulesLinkEff;

  for (auto modPtr : fElemPtr->get_imported_modules()) {
    gather_link_dependencies(modulesLinkEff, depModules, modPtr);
  }

  for (auto& inEff : modulesLinkEff) {
    fElemPtr->get_yield()->add_in_effect_link(inEff);
  }

  return retFlags;
}

// DEPRECATED (too shallow, need recursion to gather the link deps)
// template <>
// compilation_flags_t
// compile::run_dependencies<code::entry>(dependent_file * depfElemPtr) {
// 
//   auto retFlags = this->run_dependencies<code::implementation>(depfElemPtr);
// 
//   auto fElemPtr = static_cast<felement<file_kind::compilable, code::entry>*>(depfElemPtr);
// 
//   // fElem yield element (bitcode file) is already defined, although the file is not created
//   for (auto modPtr : fElemPtr->get_imported_modules()) {
//     if (modPtr->is_cpp_std()) {
//       fElemPtr->get_yield()->add_in_effect_link("-lstdc++");
//     } else if (not modPtr->is_cpp_std()) {
//       // This fElemPtr depends on a module whose implementations must be linked.
//       for (auto implModPtr : modPtr->get_implementations()) {
//         auto implFlags = this->run_if_needed<code::implementation>( implModPtr );
//         for (const auto& lEff : implFlags) {
//           // The yield of fElemPtr is a felement<file_kind::compiled, code::entry>, which is a target_file
//           fElemPtr->get_yield()->add_in_effect_link(lEff);
//         }
//       }
//     }
//   }
// 
//   return retFlags;
// }

} // namespace bld
