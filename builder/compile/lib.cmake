

#############################################
#############
############# COMPILE LIBRARY
#############
#############################################
add_library(SteelBuilderCompile SHARED
  compile/run.cpp
  compile/run_builder_tests.cpp
  compile/base.cpp
  compile/compile_pcm.cpp
  compile/interface_clang.cpp
  compile/compile_obj.cpp
  compile/call_cc1.cpp
  compile/cc1_main.cpp
  compile/execute_invocation.cpp
  # compile/options.cpp
)

target_compile_features(SteelBuilderCompile PRIVATE cxx_std_17)
target_compile_options(SteelBuilderCompile PRIVATE -fexceptions -fno-rtti ${DBG})
 

target_link_libraries(SteelBuilderCompile
  PUBLIC
  SteelBuilderFiles
  SteelBuilderModules
  SteelBuilderOptions
  LLVMSupport
  clangCodeGen
  clangSerialization
#  clangSerialization
#  LLVMX86AsmParser
#  LLVMX86CodeGen
#  LLVMX86Desc
#  LLVMX86Disassembler
#  LLVMX86Info
#  LLVMX86Utils
  clangFrontend
  clangTooling
  clangBasic
)
