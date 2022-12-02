

#############################################
#############
############# TRANSLATOR LIBRARY
#############
#############################################
add_library(SteelBuilderTranslate SHARED

  translate/consumer.clg.cpp
  translate/translator.cpp
  translate/run.cpp
  translate/run_builder_tests.cpp

  translate/cb/task_call.clg.cpp
  translate/cb/call_argument.clg.cpp
  translate/cb/return_in_task.clg.cpp
  translate/cb/ctxt_of_function.clg.cpp
  translate/cb/vardecl.clg.cpp
  translate/cb/ctxt_nested.clg.cpp
  translate/cb/task_def.clg.cpp

  translate/cb/aux/coro_raii/create.cpp
  translate/cb/aux/coro_raii/destroy.cpp
  translate/cb/aux/coro_raii/emit_bnd.cpp
)

target_compile_features(SteelBuilderTranslate PRIVATE cxx_std_17)
target_compile_options(SteelBuilderTranslate PRIVATE -fexceptions -fno-rtti ${DBG})

target_link_libraries(SteelBuilderTranslate
  PUBLIC
  SteelBuilderSourceCl
  SteelBuilderInject
  SteelBuilderTest
  clangFrontend # inspector lib
  clangASTMatchers # inspector lib
  clangRewrite
)
