

cc20 -fmodules --precompile ../../util/types.cppm \
  -o build/types.pcm

cc20 -fmodules --precompile ../../util/values.cppm \
  -fmodule-file=build/types.pcm \
  -o build/values.pcm

cc20 -g -fmodules -c ../../util/values.cpp \
  -fmodule-file=build/values.pcm \
  -fmodule-file=build/types.pcm \
  -o build/values.o

cc20 -fmodules --precompile ../../util/sequence.cppm \
  -fmodule-file=build/types.pcm \
  -o build/sequence.pcm

cc20 -fmodules --precompile ../../util/tuple.cppm \
  -fmodule-file=build/types.pcm \
  -fmodule-file=build/sequence.pcm \
  -o build/tuple.pcm

cc20 -fmodules --precompile ../../util/pred_require.cppm \
  -o build/pred_require.pcm


cc20 -fmodules --precompile ../../safe/assert.cppm \
  -o build/safe_assert.pcm

cc20 -g -fmodules -c ../../safe/assert.cpp \
  -fmodule-file=build/safe_assert.pcm \
  -fmodule-file=build/values.pcm \
  -o build/safe_assert.o

cc20 -fmodules --precompile ../../learn/feat/manip.cppm \
  -fmodule-file=build/types.pcm \
  -fmodule-file=build/safe_assert.pcm \
  -I../../include \
  -o build/learn_feat_manip.pcm

cc20 -fmodules --precompile ../../learn/feat/tile_coder.cppm \
  -fmodule-file=build/types.pcm \
  -fmodule-file=build/values.pcm \
  -fmodule-file=build/tuple.pcm \
  -fmodule-file=build/pred_require.pcm \
  -fmodule-file=build/sequence.pcm \
  -fmodule-file=build/learn_feat_manip.pcm \
  -o build/learn_feat_tile_coder.pcm

cc20 -g -fmodules -c test_tile_coder.cpp \
  -fmodule-file=build/types.pcm \
  -fmodule-file=build/values.pcm \
  -fmodule-file=build/sequence.pcm \
  -fmodule-file=build/tuple.pcm \
  -fmodule-file=build/pred_require.pcm \
  -fmodule-file=build/learn_feat_tile_coder.pcm \
  -o build/test_tile_coder.o

cc20 -g \
  build/safe_assert.o \
  build/test_tile_coder.o \
  -o build/test_tile_coder


