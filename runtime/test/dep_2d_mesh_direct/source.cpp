
[[steel::task("fooapp_wo")]]
void foo_wo(float * ptr, const unsigned nRows, const unsigned nCols, const unsigned stride) {
  float init = 13;
  for (unsigned rr = 0; rr < nRows; rr++) {
    for (unsigned cc = 0; cc < nCols; cc++) {
      ptr[rr*stride + cc] = init;
    }
  }
}

[[steel::task("fooapp_rw")]]
void foo_rw(float * ptr, const unsigned nRows, const unsigned nCols, const unsigned stride) {
  float add = 7;
  for (unsigned rr = 0; rr < nRows; rr++) {
    for (unsigned cc = 0; cc < nCols; cc++) {
      ptr[rr*stride + cc] += add;
    }
  }
}

[[steel::task("fooapp_ro")]]
void foo_ro(float const * ptr, const unsigned nRows, const unsigned nCols, const unsigned stride) {
  float res;
  for (unsigned rr = 0; rr < nRows; rr++) {
    for (unsigned cc = 0; cc < nCols; cc++) {
      res = ptr[rr*stride + cc];
    }
  }
}

void caller_wo(float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller) {
  unsigned stride = nColBlocks*chunkColsCaller*chunkRowsCaller;
  unsigned localStride = nColBlocks*chunkColsCaller;
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      foo_wo( &ptrCaller[r*stride + c*chunkColsCaller], chunkRowsCaller, chunkColsCaller, localStride );
    }
  }
}

void caller_rw(float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller) {
  unsigned stride = nColBlocks*chunkColsCaller*chunkRowsCaller;
  unsigned localStride = nColBlocks*chunkColsCaller;
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      foo_rw( &ptrCaller[r*stride + c*chunkColsCaller], chunkRowsCaller, chunkColsCaller, localStride );
    }
  }
}

// We don't use const float * ptrCaller bc we want to test the wrap/execution of foo_ro from a wrapDescriptor that also emits bnds for other rw/wo tasks.
void caller_ro(float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller) {
  unsigned stride = nColBlocks*chunkColsCaller*chunkRowsCaller;
  unsigned localStride = nColBlocks*chunkColsCaller;
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      foo_ro( &ptrCaller[r*stride + c*chunkColsCaller], chunkRowsCaller, chunkColsCaller, localStride );
    }
  }
}
