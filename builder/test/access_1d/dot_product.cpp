
#include <vector>

[[steel::task("dot_prod_app")]]
void dot_prod_v1(float * res, float const * aVec, float const * bVec, const unsigned n) {
  for (unsigned i = 0; i < n; i++) {
    res[0] += aVec[i] * bVec[i];
  }
}

[[steel::task("reduce_app")]]
void reduce(float * res, float const * vec, const unsigned n) {
  for(unsigned i = 0; i < n; i++) {
    res[0] += vec[i];
  }
}

[[steel::task("dot_prod_app")]] // [[steel::manage("blockSize=divisor(n)")]]
void dot_prod_v2( float * res, float const * aPtr, float const * bPtr, const unsigned n, const unsigned blockSize) {

  const unsigned nBlocks = n / blockSize;

  // Create vector of partial results
  std::vector<float> resVec;// (nBlocks, 0); TODO
  resVec.resize(nBlocks);
  float * resPtr = resVec.data();

  // Compute smaller 'nBlocks' dot products
  for (unsigned b = 0; b < nBlocks; b++) {
    dot_prod_v1( &resPtr[b], &aPtr[b*blockSize], &bPtr[b*blockSize], blockSize );
  }

  float resReduce = 0;
  reduce(&resReduce, resPtr, nBlocks);
}
