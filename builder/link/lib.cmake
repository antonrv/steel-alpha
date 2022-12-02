

#############################################
#############
############# LINK LIBRARY
#############
#############################################
add_library(SteelBuilderLink SHARED
  link/base.cpp
  link/run.cpp
  link/run_builder_tests.cpp
  link/entry.cpp
  # link/options.cpp
)

target_compile_features(SteelBuilderLink PRIVATE cxx_std_17)
target_compile_options(SteelBuilderLink PRIVATE -fexceptions -fno-rtti ${DBG})
target_include_directories(SteelBuilderLink PRIVATE ${PROJECT_SOURCE_DIR}/../lld/include)

target_link_libraries(SteelBuilderLink
  PUBLIC
  SteelBuilderFiles
  SteelBuilderOptions
  LLVMSupport
  lldELF
)
