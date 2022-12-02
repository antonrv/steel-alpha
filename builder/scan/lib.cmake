

#############################################
#############
############# SCAN LIBRARY
#############
#############################################


add_library(SteelBuilderScan SHARED
  scan/run.cpp
  scan/run_builder_tests.cpp
  scan/capture.cpp
  scan/lexer.cpp
  # scan/options.cpp
  #../../clang/lib/Lex/Lexer.cpp
)

target_compile_features(SteelBuilderScan PRIVATE cxx_std_17)
target_compile_options(SteelBuilderScan PRIVATE -fexceptions -fno-rtti ${DBG})


target_link_libraries(SteelBuilderScan
  PUBLIC
  SteelBuilderOptions
  # SteelBuilderPaths
  SteelBuilderFiles
  SteelBuilderModules
  # SteelBuilderMiddlend
  LLVMSupport
  clangBasic
  clangLex
)

