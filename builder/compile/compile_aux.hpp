#ifndef STEEL_COMPILER_BACKEND_AUX_HPP
#define STEEL_COMPILER_BACKEND_AUX_HPP


#include "files/interface.hpp"
#include "compile/base.hpp"



namespace bld {

template <code CodK>
void add_out_effect(dependent_file * yieldPtr);

template <code CodK>
compilation_flags_t
compile::run_if_needed(const felement<file_kind::compilable, CodK> * fElemPtr) {

  // std::cout << "Running_if_needed " << fElemPtr->get_identifier() << "\n";

  auto yieldPtr = fElemPtr->get_yield();

  if (yieldPtr == nullptr) {

    yieldPtr = state::register_yield<file_kind::compilable, CodK>( fElemPtr->get_filename() );
    // std::cout << "  Got yield: " << yieldPtr->get_identifier() << "\n";

    compilation_flags_t inEff;

    this->set_initial_flags<CodK>(inEff, fElemPtr);

    auto flags = this->run_dependencies<CodK>(fElemPtr);

    inEff.insert(std::end(inEff), std::begin(flags), std::end(flags));

    this->set_final_flags<CodK>(inEff, fElemPtr); 

    // Set unique
    inEff.resize( std::distance(std::begin(inEff), std::unique(std::begin(inEff), std::end(inEff))) );

    if (not yieldPtr->same_in_effects(inEff)) {

      // Trigger the actual compilation
      this->run<CodK>( fElemPtr->get_filename(), inEff );

      yieldPtr->reset_out_effects();
      yieldPtr->reset_in_effects(inEff);
      yieldPtr->template add_out_effect<CodK>();
    }

  } else { // Else assumed to be valid, otherwise it would not have been registered in cache
    // std::cout << "  Yield already initialized: " << yieldPtr->get_identifier() << "\n";
  }

  return yieldPtr->get_out_effects();
}


} // namespace bld

#endif // STEEL_COMPILER_BACKEND_AUX_HPP
