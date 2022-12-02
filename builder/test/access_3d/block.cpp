
////
[[steel::task("foo_block_app")]]
void foo_block(const float * bbb, int nCols, int nRows, int nDepth) {
  float r;
  for (int slice = 0; slice < nDepth; slice++) {
    for (int row = 0; row < nRows; row++) {
      for (int col = 0; col < nCols; col++) {
        r = bbb[col + row*nCols + slice*nCols*nRows];
      }
    }
  }
}

void caller_block(int nColsCaller, int nRowsCaller, int nDepthCaller) {
  float * ppp;

  foo_block(ppp, nColsCaller, nRowsCaller, nDepthCaller);
}
