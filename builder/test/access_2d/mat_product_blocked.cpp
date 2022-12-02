
#include <vector>
#include <cstdlib> 

[[steel::task("matrix_allocate")]]
void allocate_matrix(float *& packMatrix, unsigned nRows, unsigned nCols) {
  packMatrix = static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)));
  // packMatrix = (float*)std::malloc(nRows*nCols*sizeof(float)); HANDLE with pck::undefined TODO
}

[[steel::task("matrix_deallocate")]]
void deallocate_matrix(float * packMatrix) {
  std::free(packMatrix);
}

[[steel::task("mat_product_app")]]
void mat_product_v0_kernel_compact(
  float * outMat, float const * inMatA, float const * inMatB,
  unsigned mSize, unsigned nSize, unsigned kSize)
{
  for (unsigned mm = 0; mm < mSize; mm++) {
    for (unsigned nn = 0; nn < nSize; nn++) {
      for (unsigned kk = 0; kk < kSize; kk++) {
        outMat[mm * nSize + nn] += inMatA[mm * kSize + kk] * inMatB[kk * nSize + nn];
      }
    }
  }
}


[[steel::task("app_pack")]]
void pack_matrix(
  float * packMatrix, float const * unpackMatrix,
  unsigned nRows, unsigned nCols, unsigned stride)
{
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      packMatrix[jj*nCols + ii] = unpackMatrix[jj*stride + ii];
    }
  }
}

[[steel::task("app_unpack")]]
void unpack_matrix(
  float * unpackMatrix, float const * packMatrix,
  unsigned nRows, unsigned nCols, unsigned stride)
{
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      unpackMatrix[jj*stride + ii] = packMatrix[jj*nCols + ii];
    }
  }
}


[[steel::task("mat_product_app")]] // [[steel::manage("mBlocks=divisors(mSize)")]] [[steel::manage("nBlocks=divisors(nSize)")]] [[steel::manage("kBlocks=divisors(kSize)")]]
void mat_product_v3_block_compact(
  float * outMat, float const * inMatA, float const * inMatB,
  unsigned mSize, unsigned nSize, unsigned kSize,
  unsigned mBlocks, unsigned nBlocks, unsigned kBlocks)
{

  std::vector<float*> outCompact;
  outCompact.resize(mBlocks*nBlocks);
  float ** outCompactPtr = outCompact.data();

  std::vector<float*> inACompact;
  inACompact.resize(mBlocks*kBlocks);
  float ** inACompactPtr = inACompact.data();

  std::vector<float*> inBCompact;
  inBCompact.resize(kBlocks*nBlocks);
  float ** inBCompactPtr = inBCompact.data();

  unsigned mBlockSize = mSize / mBlocks;
  unsigned nBlockSize = nSize / nBlocks;
  unsigned kBlockSize = kSize / kBlocks;

  unsigned outStride = nBlockSize*nBlocks;
  unsigned inAStride = kBlockSize*kBlocks;
  unsigned inBStride = nBlockSize*nBlocks;

  ////////////
  //
  // MATRIX ALLOCATION
  //
  ////////////
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      allocate_matrix( outCompactPtr[ mb*nBlocks + nb ], mBlockSize, nBlockSize );
    }
  }

  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned kb = 0; kb < kBlocks; kb++) {
      allocate_matrix( inACompactPtr[ mb*kBlocks + kb ], mBlockSize, kBlockSize );
    }
  }

  for (unsigned kb = 0; kb < kBlocks; kb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      allocate_matrix( inBCompactPtr[ kb*nBlocks + nb ], kBlockSize, nBlockSize );
    }
  }

  ////////////
  //
  // MATRIX PACKING
  //
  ////////////

  // OUT : Strided -> compact
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      pack_matrix( outCompactPtr[ mb*nBlocks + nb ], &outMat[mb*outStride*mBlockSize + nb*nBlockSize], mBlockSize, nBlockSize, outStride );
    }
  }

  // INA : Strided -> compact
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned kb = 0; kb < kBlocks; kb++) {
      pack_matrix( inACompactPtr[ mb*kBlocks + kb ], &inMatA[mb*inAStride*mBlockSize + kb*kBlockSize], mBlockSize, kBlockSize, inAStride );
    }
  }

  // INB : Strided -> compact
  for (unsigned nb = 0; nb < nBlocks; nb++) {
    for (unsigned kb = 0; kb < kBlocks; kb++) {
      pack_matrix( inBCompactPtr[ kb*nBlocks + nb ], &inMatB[kb*inBStride*kBlockSize + nb*nBlockSize], kBlockSize, nBlockSize, inBStride );
    }
  }

  ////////////
  //
  // MATRIX COMPACT BLOCK PRODUCT
  //
  ////////////
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      for (unsigned kb = 0; kb < kBlocks; kb++) {
        mat_product_v0_kernel_compact( outCompactPtr[mb*nBlocks + nb], inACompactPtr[mb*kBlocks + kb], inBCompactPtr[kb*nBlocks + nb], mBlockSize, nBlockSize, kBlockSize );
      }
    }
  }


  ////////////
  //
  // MATRIX UNPACKING
  //
  ////////////

  // OUT : Compact -> strided
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      unpack_matrix( &outMat[mb*outStride*mBlockSize + nb*nBlockSize], outCompactPtr[ mb*nBlocks + nb ], mBlockSize, nBlockSize, outStride );
    }
  }

  ////////////
  //
  // MATRIX DEALLOCATION
  //
  ////////////
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      deallocate_matrix( outCompactPtr[ mb*nBlocks + nb ] );
    }
  }

  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned kb = 0; kb < kBlocks; kb++) {
      deallocate_matrix( inACompactPtr[ mb*kBlocks + kb ] );
    }
  }

  for (unsigned kb = 0; kb < kBlocks; kb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      deallocate_matrix( inBCompactPtr[ kb*nBlocks + nb ] );
    }
  }
}

