


add_library(SteelBuilderOptions SHARED
  options/init.cpp
  options/state/def.cpp
)

target_compile_features(SteelBuilderOptions PRIVATE cxx_std_17)
target_compile_options(SteelBuilderOptions PRIVATE -fexceptions -fno-rtti ${DBG})

target_link_libraries(SteelBuilderOptions
  PUBLIC
  SteelBuilderPaths
)
