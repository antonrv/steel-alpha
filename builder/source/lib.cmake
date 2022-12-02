

#############################################
#############
############# COMMON SOURCE-ELEMENTS LIBRARY (frontend is ITG)
#############
#############################################

set(ParserSources 
  source/token/tokenize.cpp
  source/token/piece.cpp
  source/token/piece_serial.cpp
  source/token/terminal/terminal.cpp
  source/token/terminal/num.cpp
  source/token/terminal/var.cpp
  source/token/terminal/undef.cpp
  source/token/terminal/loopvar.cpp
  source/token/multiple/multiple.cpp
  source/token/multiple/addends.cpp
  source/token/multiple/factors.cpp
  source/token/multiple/fraction.cpp
  source/token/multiple/cs_list.cpp
  source/token/multiple/call.cpp
  source/token/multiple/address.cpp
  source/token/multiple/offset.cpp
  source/token/multiple/range.cpp
  source/token/multiple/binop.cpp
  source/token/multiple/compare_ops.cpp
  source/token/combine/less.cpp
  source/token/combine/equal.cpp
  source/token/combine/contains.cpp
  source/token/combine/extend_range.cpp
  source/token/combine/extend_arith.cpp
  source/token/combine/extend_piece.cpp
  source/token/make/piece.cpp
  source/token/make/token.cpp
  source/token/make/copy.cpp
  source/token/simplify/aux.cpp
  source/token/simplify/fraction.cpp
  source/token/simplify/addends.cpp
  source/token/simplify/factors.cpp
  source/token/simplify/range.cpp
  source/token/simplify/interface.cpp
  source/token/factorize.cpp
  source/token/transform/multiple.cpp
  source/token/transform/range.cpp
  source/token/transform/loopvar.cpp
  source/token/region/make_access.cpp
  source/token/region/make_guard.cpp
  source/token/region/access.cpp
  source/token/region/guard.cpp
  source/token/region/affine/access.cpp
  source/token/region/affine/digest/functors.cpp
  source/token/region/affine/digest/access.cpp
  source/token/region/affine/digest//ctor/basic.cpp
  source/token/region/affine/digest//ctor/primary.cpp
  source/token/region/affine/digest//ctor/secondary.cpp
  source/token/region/affine/dim/matching.cpp
  source/token/region/affine/dim/permute.cpp
  source/token/region/affine/collection.cpp
  source/token/region/affine/guard.cpp
  source/token/region/affine/to_string.cpp
  source/token/region/point/access.cpp
  source/token/region/point/guard.cpp
)

add_library(SteelBuilderParserTest SHARED
  ${ParserSources}
)

target_compile_features(SteelBuilderParserTest PRIVATE cxx_std_17)
target_compile_options(SteelBuilderParserTest PRIVATE -fexceptions -fno-rtti ${DBG} -DPARSER_TEST)
# target_compile_options(SteelBuilderParserTest PRIVATE -fexceptions -fno-rtti ${DBG} -DPARSER_TEST -ftemplate-backtrace-limit=0)
# target_compile_options(SteelBuilderParserTest PRIVATE -fexceptions -fno-rtti ${DBG} -DPARSER_TEST -ftemplate-backtrace-limit=0 -DREGION_LOG)

target_link_libraries(SteelBuilderParserTest
  SteelBuilderOptions
)



#############################################
#############
############# PARSER LIBRARY TEST
#############
#############################################
add_executable(steelbld-parser-test
  source/token/test/main.cpp
  source/token/test/tokenize.cpp
  source/token/test/make.cpp
  source/token/test/kinds.cpp
  source/token/test/simplify.cpp
  source/token/test/factorize.cpp
  source/token/test/evaluate.cpp
  source/token/test/affine.cpp
  source/token/test/guard/check.cpp
  source/token/test/guard/basic.cpp
  source/token/test/guard/offset.cpp
  source/token/test/guard/range.cpp
)

target_link_libraries(steelbld-parser-test PRIVATE SteelBuilderParserTest)
target_compile_options(steelbld-parser-test PRIVATE -fexceptions -fno-rtti ${DBG} -DPARSER_TEST)
# target_link_libraries(steelbld-parser-test PRIVATE SteelBuilderSource)
# target_include_directories(steelbld-parser-test PRIVATE ./)

add_executable(steelbld-parser-cli
  source/token/test/cli.cpp
)

target_link_libraries(steelbld-parser-cli PRIVATE SteelBuilderParserTest)
target_compile_options(steelbld-parser-cli PRIVATE -fexceptions -fno-rtti ${DBG} -DPARSER_TEST)


#############################################
#############
############# COMMON SOURCE-ELEMENTS LIBRARY (frontend is ITG)
#############
#############################################
add_library(SteelBuilderSource SHARED
  source/object/base.cpp
  source/object/base_serial.cpp
  source/object/function/definition.cpp
  source/object/function/definition_serial.cpp
  source/object/function/call.cpp
  source/object/function/call_serial.cpp
  source/object/function/return.cpp
  source/object/function/return_serial.cpp
  source/object/function/context.cpp
  source/object/function/context_serial.cpp
  source/object/function/loop.cpp
  source/object/function/loop_serial.cpp
  source/object/function/binary.cpp
  source/object/function/binary_serial.cpp
  source/object/function/task.cpp
  source/object/function/task_serial.cpp
  source/object/data/decl.cpp
  source/object/data/decl_aux.cpp
  source/object/data/decl_serial.cpp
  source/object/data/use.cpp
  source/object/data/use_aux.cpp
  source/object/data/use_serial.cpp
  source/object/data/transform/collect_local.cpp
  source/object/data/transform/to_local.cpp
  source/object/data/transform/to_global.cpp
  source/object/data/transform/align/aux.cpp
  source/object/data/transform/align/uniform.cpp
  source/object/data/transform/align/target.cpp
  source/object/state/init.cpp 
  source/object/state/dump.cpp 
  source/serial/serialize_def.cpp 
  source/serial/indent.cpp 

  ${ParserSources}
)


target_compile_features(SteelBuilderSource PRIVATE cxx_std_17)
target_compile_options(SteelBuilderSource PRIVATE -fexceptions -fno-rtti ${DBG})

# target_compile_options(SteelBuilderSource PRIVATE -fexceptions -fno-rtti ${DBG} -DTRANSFORM_LOG)
# target_compile_options(SteelBuilderSource PRIVATE -fexceptions -fno-rtti ${DBG} -DREGION_LOG=1)

target_link_libraries(SteelBuilderSource
  PUBLIC
  SteelBuilderCommon
  SteelBuilderOptions
  SteelBuilderFiles
  # SteelBuilderPaths ## Needed???  XXX
)

#############################################
#############
############# COMMON IT LIBRARY
#############
#############################################
add_library(SteelBuilderSourceCl SHARED
  common/it/ast_analyzer.cpp
  common/it/base_callback.cpp
  source/object/base.clg.cpp
  source/object/fix_data.clg.cpp
  source/object/function/definition.clg.cpp
  source/object/function/call.clg.cpp
  source/object/function/return.clg.cpp
  source/object/function/context.clg.cpp
  source/object/function/loop.clg.cpp
  source/object/function/binary.clg.cpp

  source/object/data/decl.clg.cpp
  source/object/data/use.clg.cpp
  source/object/data/factory.clg.cpp

  # files/state/sgraph.cpp # dup ?? TODO
  # files/state/inspected.cpp # dup ?? TODO
)

target_compile_features(SteelBuilderSourceCl PRIVATE cxx_std_17)
target_compile_options(SteelBuilderSourceCl PRIVATE -fexceptions -fno-rtti ${DBG})

target_link_libraries(SteelBuilderSourceCl
  PUBLIC
  # SteelBuilderPaths
  SteelBuilderSource
  LLVMSupport
  clang
  clangBasic
  clangTooling
  clangSerialization
  clangAST
)
