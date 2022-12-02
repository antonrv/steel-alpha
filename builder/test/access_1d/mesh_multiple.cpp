

[[steel::task("fooapp_callee_x")]]
void foo_callee_x(float * ptr, const unsigned nCols) {
  float init = 13;
  for (unsigned cc = 0; cc < nCols; cc++) {
    ptr[cc] += init;
  }
}

[[steel::task("fooapp_callee_y")]]
void foo_callee_y(const float * ptr, const unsigned nCols) {
  float init = 13;
  for (unsigned cc = 0; cc < nCols; cc++) {
    init = ptr[cc];
  }
}


void caller_same_callee(float * ptrCaller, const unsigned nBlocks, const unsigned blockSize) {

  unsigned nBlocksA = nBlocks;
  unsigned blockSizeA = blockSize;
  for (unsigned a = 0; a < nBlocksA; a++) {
    foo_callee_x( &ptrCaller[a*blockSizeA], blockSizeA );
  }

  unsigned nBlocksB = nBlocks;
  unsigned blockSizeB = blockSize;
  for (unsigned b = 0; b < nBlocksB; b++) {
    foo_callee_x( &ptrCaller[b*blockSizeB], blockSizeB );
  }

  unsigned nBlocksC = nBlocks;
  unsigned blockSizeC = blockSize;
  for (unsigned c = 0; c < nBlocksC; c++) {
    foo_callee_x( &ptrCaller[c*blockSizeC], blockSizeC );
  }
}

void caller_different_callee(float * ptrCaller, const unsigned nBlocks, const unsigned blockSize) {

  unsigned nBlocksA = nBlocks;
  unsigned blockSizeA = blockSize;
  for (unsigned a = 0; a < nBlocksA; a++) {
    foo_callee_x( &ptrCaller[a*blockSizeA], blockSizeA );
  }

  unsigned nBlocksB = nBlocks;
  unsigned blockSizeB = blockSize;
  for (unsigned b = 0; b < nBlocksB; b++) {
    foo_callee_y( &ptrCaller[b*blockSizeB], blockSizeB );
  }
}

void caller_same_n_different_callee(float * ptrCaller, const unsigned nBlocks, const unsigned blockSize) {

  unsigned nBlocksA = nBlocks;
  unsigned blockSizeA = blockSize;
  for (unsigned a = 0; a < nBlocksA; a++) {
    foo_callee_x( &ptrCaller[a*blockSizeA], blockSizeA );
  }

  unsigned nBlocksB = nBlocks;
  unsigned blockSizeB = blockSize;
  for (unsigned b = 0; b < nBlocksB; b++) {
    foo_callee_y( &ptrCaller[b*blockSizeB], blockSizeB );
  }

  unsigned nBlocksC = nBlocks;
  unsigned blockSizeC = blockSize;
  for (unsigned c = 0; c < nBlocksC; c++) {
    foo_callee_y( &ptrCaller[c*blockSizeC], blockSizeC );
  }
}
