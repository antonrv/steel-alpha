
[[steel::task("write_mesh_uneven")]]
void foo(float * ptr, const unsigned jSize, const unsigned iSize, const unsigned stride) {
  float init = 13;
  for (unsigned jj = 0; jj < jSize; jj++) {
    for (unsigned ii = 0; ii < iSize; ii++) {
      ptr[jj*stride + ii] = init;
    }
  }
}

[[steel::task("write_mesh_uneven")]] // [[steel::manage("jBlocks={2,3,4,divisors(jSize)}")]] [[steel::manage("iBlocks={2,3,4,divisor(iSize)}")]]
void caller_foo(float * ptrCaller, const unsigned jSize, const unsigned iSize, const unsigned jBlocks, const unsigned iBlocks) {

  unsigned jBlockSize = jSize / jBlocks;
  unsigned iBlockSize = iSize / iBlocks;

  unsigned iBlocksEven = iSize / iBlockSize;
  unsigned jBlocksEven = jSize / jBlockSize;

  for (unsigned j = 0; j < jBlocksEven; j++) {
    for (unsigned i = 0; i < iBlocksEven; i++) {
      foo( &ptrCaller[j*jBlockSize*iSize + i*iBlockSize], jBlockSize, iBlockSize, iSize );
    }
  }

  unsigned iBlockSizeRemain = iSize % iBlockSize;
  if (iBlockSizeRemain != 0) {
    for (unsigned j = 0; j < jBlocksEven; j++) {
      foo( &ptrCaller[j*jBlockSize*iSize + iBlocksEven*iBlockSize], jBlockSize, iBlockSizeRemain, iSize );
    }
  }

  unsigned jBlockSizeRemain = jSize % jBlockSize;
  if (jBlockSizeRemain != 0) {
    for (unsigned i = 0; i < iBlocksEven; i++) {
      foo( &ptrCaller[jBlocksEven*jBlockSize*iSize + i*iBlockSize], jBlockSizeRemain, iBlockSize, iSize );
    }
  }

  if (iBlockSizeRemain != 0 and jBlockSizeRemain != 0) {
    foo( &ptrCaller[jBlocksEven*jBlockSize*iSize + iBlocksEven*iBlockSize], jBlockSizeRemain, iBlockSizeRemain, iSize );
  }
}
