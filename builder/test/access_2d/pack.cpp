
#include <vector>
#include <cstdlib> 

[[steel::task("matrix_pack")]]
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

[[steel::task("matrix_allocate")]]
void allocate_matrix(float *& packMatrix, unsigned nRows, unsigned nCols) {
  packMatrix = static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)));
  // packMatrix = (float*)std::malloc(nRows*nCols*sizeof(float)); HANDLE with pck::undefined TODO
}

[[steel::task("matrix_deallocate")]]
void deallocate_matrix(float *& packMatrix) {
  std::free(packMatrix);
}


void pack_matrix_caller(
  float const * outMat,
  unsigned mSize, unsigned nSize,
  unsigned mBlocks, unsigned nBlocks)
{

  std::vector<float*> outCompact;
  outCompact.resize(mBlocks*nBlocks);
  float ** outCompactPtr = outCompact.data();

  unsigned mBlockSize = mSize / mBlocks;
  unsigned nBlockSize = nSize / nBlocks;

  unsigned outStride = nBlockSize*nBlocks;

  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      allocate_matrix( outCompactPtr[ mb*nBlocks + nb ], mBlockSize, nBlockSize );
    }
  }

  // Strided -> compact
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      pack_matrix( outCompactPtr[ mb*nBlocks + nb ], &outMat[mb*outStride*mBlockSize + nb*nBlockSize], mBlockSize, nBlockSize, outStride );
    }
  }

  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      deallocate_matrix( outCompactPtr[ mb*nBlocks + nb ] );
    }
  }

}
