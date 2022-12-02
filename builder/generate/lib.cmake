

#############################################
#############
############# GENERATOR LIBRARY
#############
#############################################
add_library(SteelBuilderGenerate SHARED
  generate/run.cpp
  generate/run_builder_tests.cpp
  generate/run/aux_enum.cpp
  generate/run/app_enum.cpp
  generate/run/app_graph.cpp
  generate/run/app_proxy.cpp
  generate/run/aux_rt.cpp
  generate/run/aux_template.cpp
  generate/run/runtime_instrument_enum.cpp
  generate/run/runtime_test.cpp
  generate/run/platform_enum.cpp
  generate/run/platform_graph.cpp
)

target_compile_features(SteelBuilderGenerate PRIVATE cxx_std_17)
target_compile_options(SteelBuilderGenerate PRIVATE -fexceptions -fno-rtti ${DBG})

target_link_libraries(SteelBuilderGenerate
  PUBLIC
  SteelBuilderFiles
  SteelBuilderOptions
  SteelBuilderSource
  SteelBuilderInject
  SteelBuilderTest
)
