
#include <vector>
#include <cstdlib> 

[[steel::task("app_allocate_matrix")]]
void allocate_matrix(float *& packMatrix, unsigned nRows, unsigned nCols) {
  packMatrix = static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)));
  // packMatrix = (float*)std::malloc(nRows*nCols*sizeof(float)); HANDLE with pck::undefined TODO
}

[[steel::task("app_deallocate_matrix")]]
void deallocate_matrix(float * packMatrix) {
  std::free(packMatrix);
}


[[steel::task("app_pack_matrix")]]
void pack_copy_matrix(
  float * packMatrix, float const * unpackMatrix,
  unsigned nCols, unsigned nRows, unsigned stride)
{
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      packMatrix[jj*nCols + ii] = unpackMatrix[jj*stride + ii];
    }
  }
}

[[steel::task("app_unpack_matrix")]]
void unpack_copy_matrix(
  float * unpackMatrix, float const * packMatrix,
  unsigned nCols, unsigned nRows, unsigned stride)
{
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      unpackMatrix[jj*stride + ii] = packMatrix[jj*nCols + ii];
    }
  }
}

[[steel::task("app_operate_matrix")]]
void operate_matrix_v1(
  float * editMat,
  unsigned nCols, unsigned nRows)
{
  float init = 42;
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      editMat[jj*nCols + ii] = init;
    }
  }
}

[[steel::task("app_operate_matrix")]] // [[steel::manage("nColBlocks=divisor(nCols)")]] [[steel::manage("nRowBlocks=divisor(nRows)")]]
void operate_matrix_v2(
  float * editMat,
  unsigned nCols, unsigned nRows,
  unsigned nColBlocks, unsigned nRowBlocks)
{

  unsigned colBlockSize = nCols / nColBlocks;
  unsigned rowBlockSize = nRows / nRowBlocks;

  unsigned outStride = colBlockSize * nColBlocks;

  std::vector<float*> outCompact;
  outCompact.resize(nRowBlocks*nColBlocks);
  float ** outCompactPtr = outCompact.data();

  for (unsigned mb = 0; mb < nRowBlocks; mb++) {
    for (unsigned nb = 0; nb < nColBlocks; nb++) {
      allocate_matrix( outCompactPtr[ mb*nColBlocks + nb ], rowBlockSize, colBlockSize );
    }
  }

  // Strided -> compact
  for (unsigned jb = 0; jb < nRowBlocks; jb++) {
    for (unsigned ib = 0; ib < nColBlocks; ib++) {
      pack_copy_matrix( outCompactPtr[ ib + jb*nColBlocks ], &editMat[ jb*rowBlockSize*outStride + ib*colBlockSize ], colBlockSize, rowBlockSize, outStride);
    }
  }

  // Operate on each contiguous block
  for (unsigned yb = 0; yb < nRowBlocks; yb++) {
    for (unsigned xb = 0; xb < nColBlocks; xb++) {
      operate_matrix_v1( outCompactPtr[ yb*nColBlocks + xb ], colBlockSize, rowBlockSize );
    }
  }


  // Compact -> strided
  for (unsigned lb = 0; lb < nRowBlocks; lb++) {
    for (unsigned kb = 0; kb < nColBlocks; kb++) {
      unpack_copy_matrix( &editMat[ lb*rowBlockSize*outStride + kb*colBlockSize ], outCompactPtr[ kb + lb*nColBlocks ], colBlockSize, rowBlockSize, outStride);
    }
  }

  for (unsigned mb = 0; mb < nRowBlocks; mb++) {
    for (unsigned nb = 0; nb < nColBlocks; nb++) {
      deallocate_matrix( outCompactPtr[ mb*nColBlocks + nb ] );
    }
  }

}
