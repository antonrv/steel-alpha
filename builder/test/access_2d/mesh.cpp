
[[steel::task("fooapp_wo")]]
void foo(float * ptr, const unsigned nRows, const unsigned nCols, const unsigned stride) {
  float init = 13;
  for (unsigned rr = 0; rr < nRows; rr++) {
    for (unsigned cc = 0; cc < nCols; cc++) {
      ptr[rr*stride + cc] = init;
    }
  }
}

void caller1_foo(float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller) {
  unsigned stride = nColBlocks*chunkColsCaller*chunkRowsCaller;
  unsigned localStride = nColBlocks*chunkColsCaller;
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      foo( &ptrCaller[r*stride + c*chunkColsCaller], chunkRowsCaller, chunkColsCaller, localStride );
    }
  }
}

void caller2_foo(float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller) {
  unsigned localStride = nColBlocks*chunkColsCaller;
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      foo( &ptrCaller[r*chunkRowsCaller*localStride + c*chunkColsCaller], chunkRowsCaller, chunkColsCaller, localStride );
    }
  }
}

void caller3_foo(float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller) {
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      foo( &ptrCaller[r*chunkRowsCaller*nColBlocks*chunkColsCaller + c*chunkColsCaller], chunkRowsCaller, chunkColsCaller, nColBlocks*chunkColsCaller );
    }
  }
}

void caller4_foo(float * ptrCaller, const unsigned nRows, const unsigned nCols, const unsigned nRowBlocks, const unsigned nColBlocks) {
  unsigned chunkRowsCaller = nRows / nRowBlocks;
  unsigned chunkColsCaller = nCols / nColBlocks;
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      foo( &ptrCaller[r*chunkRowsCaller*nCols + c*chunkColsCaller], chunkRowsCaller, chunkColsCaller, nCols );
    }
  }
}

void caller5_foo(float * ptrCaller, const unsigned nRows, const unsigned nCols, const unsigned nRowBlocks, const unsigned nColBlocks) {
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      foo( &ptrCaller[r*(nRows/nRowBlocks)*nCols + c*(nCols/nColBlocks)], (nRows/nRowBlocks), (nCols/nColBlocks), nCols );
    }
  }
}
