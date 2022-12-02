

// #include "translate/instruction_clang.hpp"
#include "files/enum.hpp"
#include "files/name/decl.hpp"

#include "translate/translator.hpp"

#include "translate/consumer.clg.hpp"

#include "common/util.hpp"

#include <iostream>

namespace bld {


translator::translator(const std::vector<state::filename>& src) : ast_analyzer(transform_vec(src, [] (const state::filename fn) { return fn.get_full_name(); } )) { }


void translator::run() {

    // Register all function (only aware) and kernels.
  m_toolUptr->run( clang::tooling::newFrontendActionFactory<TranslateFrontendAction>().get() );

}

} // namespace bld

//    // 1. APPLICATION REGISTRATION PASS
//    // Replace source path list in Tool by the ones altered.  
//  
//    // 2.A EXECUTION CONSISTENCY / FUTURIZATION PASS
//    // Once all kernels are registered, match all kernels, and verify the annotations in the arguments.
//    // From callExpr on registered kernels, we can infer whether the arguments are going to be ro, rw, wo, then we can wrap them accordingly.
//    // If several call expressions are in the same block (scope), consistency must be ensured by futurizing the arguments
//    err = Tool.run( clang::tooling::newFrontendActionFactory<steel::translator::ConsistencyFrontendAction>().get() );
//  
//  
//    // Replace source path list in Tool by the ones altered.
//  
//    // 3.A ASYNCHRONY PASS
//    // For every call expression on a registered kernel, do a co_yield and transform that function context into a coroutine.
//    // If several call expressions are in the same block (scope), create a coroutine of that block
//    err = Tool.run( clang::tooling::newFrontendActionFactory<steel::translator::AsynchronyFrontendAction>().get() );
//
//    // Replace source path list in Tool by the ones altered.
//
//    // 3.B PARALLELISM.
//    // Executor recipient is a thread pool on a SMP. (modify AsynchronyFrontendAction)
//
//    // 2.B DATA COHERENCE.
//    // All heap-allocatable kernel arguments are accessed by a data key. (modify ConsistencyFrontendAction)
//
//    // Replace source path list in Tool by the ones altered.
//
//    // 4. RELAXATION PASS.
//    // Design relaxation semantics and inform the runtime codegen accordingly.
//    // Transform relaxation annotations into runtime calls.
//    // Runtime acts randomly on action spaces
//    // Moldable, malleable, hierarchical partitioning is enabled.
//    err = Tool.run( clang::tooling::newFrontendActionFactory<steel::translator::RelaxationFrontendAction>().get() );
//
//    // 5. Heterogeneous computation.
//    // Based on target platform, use LLVM to map to cuda/opencl devices.
//    // Omit opencl runtime. See how can we offload kernels without any opencl queue.
//    // Omit cuda runtime as much as possible, use cuda driver instead.
//    err = Tool.run( clang::tooling::newFrontendActionFactory<steel::translator::KernelOffloadFrontendAction>().get() );


    // Pack all above into libinputtranslator, done in:
    // steel::translator::process_input_syntax( );

    // At this point we have transformed all code with input-syntax into a C++20 compliant code.

    // Gather all codegen runtime code generated from process_input_syntax

    // Gather all runtime code in C++20 modules.

    // Compile everything
