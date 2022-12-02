

[[steel::task("mat_product_app")]]
void mat_product_v1_kernel_strided(
  float * outMat, float const * inMatA, float const * inMatB,
  unsigned mSize, unsigned nSize, unsigned kSize,
  unsigned outStride, unsigned inAStride, unsigned inBStride)
{
  for (unsigned mm = 0; mm < mSize; mm++) {
    for (unsigned nn = 0; nn < nSize; nn++) {
      for (unsigned kk = 0; kk < kSize; kk++) {
        outMat[mm * outStride + nn] += inMatA[mm * inAStride + kk] * inMatB[kk * inBStride + nn];
      }
    }
  }
}


[[steel::task("mat_product_app")]] // [[steel::manage("mBlocks=divisor(mSize)")]] [[steel::manage("nBlocks=divisor(nSize)")]] [[steel::manage("kBlocks=divisor(kSize)")]]
void mat_product_v2_block_strided(
  float * outMat, float const * inMatA, float const * inMatB,
  unsigned mSize, unsigned nSize, unsigned kSize,
  unsigned mBlocks, unsigned nBlocks, unsigned kBlocks)
{
  unsigned mBlockSize = mSize / mBlocks;
  unsigned nBlockSize = nSize / nBlocks;
  unsigned kBlockSize = kSize / kBlocks;

  ////////////
  //
  // MATRIX STRIDED BLOCK PRODUCT
  //
  ////////////
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      for (unsigned kb = 0; kb < kBlocks; kb++) {
        mat_product_v1_kernel_strided( &outMat[mb * nSize * mBlockSize + nb * nBlockSize], &inMatA[mb * kSize * mBlockSize + kb * kBlockSize], &inMatB[kb * nSize * kBlockSize + nb * nBlockSize], mBlockSize, nBlockSize, kBlockSize, nSize, kSize, nSize);
      }
    }
  }
}
