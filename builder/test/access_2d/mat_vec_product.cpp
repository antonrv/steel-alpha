
[[steel::task("mat_vec_app")]]
void mat_vec_v1(
  float * vecRes, float const * inputMat, float const * inputVec,
  unsigned nCols, unsigned nRows, unsigned stride)
{
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      vecRes[ii] += inputMat[jj*stride + ii] * inputVec[ii];
    }
  }
}


[[steel::task("mat_vec_app")]] // [[steel::manage("nColBlocks=divisor(nCols)")]] [[steel::manage("nRowBlocks=divisor(nRows)")]]
void mat_vec_v2(
  float * vecRes, float const * inputMat, float const * inputVec,
  unsigned nCols, unsigned nRows,
  unsigned nColBlocks, unsigned nRowBlocks)
{

  unsigned colBlockSize = nCols / nColBlocks;
  unsigned rowBlockSize = nRows / nRowBlocks;
  unsigned stride = nColBlocks * colBlockSize * rowBlockSize;
  unsigned localStride = colBlockSize * nColBlocks;

  for (unsigned jj = 0; jj < nRowBlocks; jj++) {
    for (unsigned ii = 0; ii < nColBlocks; ii++) {
      mat_vec_v1( &vecRes[ii*colBlockSize], &inputMat[jj*stride + ii*colBlockSize], &inputVec[ii*colBlockSize], colBlockSize, rowBlockSize, localStride );
    }
  }
}
