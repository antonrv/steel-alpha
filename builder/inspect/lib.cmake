

#############################################
#############
############# INSPECTOR LIBRARY
#############
#############################################
add_library(SteelBuilderInspect SHARED

  inspect/inspector.cpp
  inspect/consumer.clg.cpp
  inspect/propagate/tasks_upstream.cpp
  inspect/propagate/configure_fun_args.cpp
  inspect/cb/defs.clg.cpp
  inspect/cb/ops.clg.cpp
  inspect/cb/calls.clg.cpp
  inspect/cb/loops.clg.cpp
  inspect/cb/tasks.clg.cpp
  inspect/cb/ctxts.clg.cpp
  inspect/cb/returns.clg.cpp
  inspect/cb/tasks_prop.clg.cpp


  inspect/run.cpp
  inspect/run_builder_tests.cpp
  # inspect/options.cpp
  # inspect/test.cpp
)

target_compile_features(SteelBuilderInspect PRIVATE cxx_std_17)
target_compile_options(SteelBuilderInspect PRIVATE -fexceptions -fno-rtti ${DBG})

target_link_libraries(SteelBuilderInspect 
  PUBLIC 
  SteelBuilderSourceCl
  SteelBuilderInject
  SteelBuilderFiles
  SteelBuilderTest
  SteelBuilderOptions
  clangASTMatchers # inspector lib
  clangFrontend # inspector lib
)
