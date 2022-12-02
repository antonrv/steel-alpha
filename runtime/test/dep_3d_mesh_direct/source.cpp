
[[steel::task("fooapp_wo")]]
void foo_wo(float * ptr, const unsigned nRows, const unsigned nCols, const unsigned nSlices, const unsigned localStrideRows, const unsigned localStrideSlices) {
  float init = 13;
  for (unsigned ss = 0; ss < nSlices; ss++) {
    for (unsigned rr = 0; rr < nRows; rr++) {
      for (unsigned cc = 0; cc < nCols; cc++) {
        ptr[ss*localStrideSlices*localStrideRows + rr*localStrideRows + cc] = init;
      }
    }
  }
}


[[steel::task("fooapp_rw")]]
void foo_rw(float * ptr, const unsigned nRows, const unsigned nCols, const unsigned nSlices, const unsigned localStrideRows, const unsigned localStrideSlices) {
  float add = 7;
  for (unsigned ss = 0; ss < nSlices; ss++) {
    for (unsigned rr = 0; rr < nRows; rr++) {
      for (unsigned cc = 0; cc < nCols; cc++) {
        ptr[ss*localStrideSlices*localStrideRows + rr*localStrideRows + cc] += add;
      }
    }
  }
}

[[steel::task("fooapp_ro")]]
void foo_ro(float const * ptr, const unsigned nRows, const unsigned nCols, const unsigned nSlices, const unsigned localStrideRows, const unsigned localStrideSlices) {
  float res;
  for (unsigned ss = 0; ss < nSlices; ss++) {
    for (unsigned rr = 0; rr < nRows; rr++) {
      for (unsigned cc = 0; cc < nCols; cc++) {
        res = ptr[ss*localStrideSlices*localStrideRows + rr*localStrideRows + cc];
      }
    }
  }
}

void caller_wo(float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned nSliceBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller, const unsigned chunkSlicesCaller) {

  unsigned localStrideRows = nColBlocks*chunkColsCaller;
  unsigned strideRows = localStrideRows*chunkRowsCaller;

  unsigned localStrideSlices = nRowBlocks*chunkRowsCaller;
  unsigned strideSlices = chunkSlicesCaller*localStrideSlices*localStrideRows;

  for (unsigned s = 0; s < nSliceBlocks; s++) {
    for (unsigned r = 0; r < nRowBlocks; r++) {
      for (unsigned c = 0; c < nColBlocks; c++) {
        foo_wo( &ptrCaller[s*strideSlices + r*strideRows + c*chunkColsCaller], chunkRowsCaller, chunkColsCaller, chunkSlicesCaller, localStrideRows, localStrideSlices );
      }
    }
  }
}

void caller_rw(float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned nSliceBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller, const unsigned chunkSlicesCaller) {

  unsigned localStrideRows = nColBlocks*chunkColsCaller;
  unsigned strideRows = localStrideRows*chunkRowsCaller;

  unsigned localStrideSlices = nRowBlocks*chunkRowsCaller;
  unsigned strideSlices = chunkSlicesCaller*localStrideSlices*localStrideRows;

  for (unsigned s = 0; s < nSliceBlocks; s++) {
    for (unsigned r = 0; r < nRowBlocks; r++) {
      for (unsigned c = 0; c < nColBlocks; c++) {
        foo_rw( &ptrCaller[s*strideSlices + r*strideRows + c*chunkColsCaller], chunkRowsCaller, chunkColsCaller, chunkSlicesCaller, localStrideRows, localStrideSlices );
      }
    }
  }
}

// We don't use const float * ptrCaller bc we want to test the wrap/execution of foo_ro from a wrapDescriptor that also emits bnds for other rw/wo tasks.
void caller_ro(float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned nSliceBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller, const unsigned chunkSlicesCaller) {

  unsigned localStrideRows = nColBlocks*chunkColsCaller;
  unsigned strideRows = localStrideRows*chunkRowsCaller;

  unsigned localStrideSlices = nRowBlocks*chunkRowsCaller;
  unsigned strideSlices = chunkSlicesCaller*localStrideSlices*localStrideRows;

  for (unsigned s = 0; s < nSliceBlocks; s++) {
    for (unsigned r = 0; r < nRowBlocks; r++) {
      for (unsigned c = 0; c < nColBlocks; c++) {
        foo_ro( &ptrCaller[s*strideSlices + r*strideRows + c*chunkColsCaller], chunkRowsCaller, chunkColsCaller, chunkSlicesCaller, localStrideRows, localStrideSlices );
      }
    }
  }
}
