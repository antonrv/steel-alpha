
////
[[steel::task("foo_rectangle_app")]]
void foo_rectangle(const float * bbb, int nCols, int nRows) {
  float r = 13.f;
  for (int row = 0; row < nRows; row++) {
    for (int col = 0; col < nCols; col++) {
      r = bbb[col + row*nCols];
    }
  }
}

void caller_rectangle(int nColsCaller, int nRowsCaller) {
  float * ppp;

  foo_rectangle(ppp, nColsCaller, nRowsCaller);
}

////
[[steel::task("foo_1d_blocks_app")]]
void foo_blocks(const float * bbb, int bSize, int nBlocks) {
  float r = 13.f;
  for (int bId = 0; bId < nBlocks; bId++) {
    for (int i = bId*bSize; i < bSize; i++) {
      r = bbb[i + bId*bSize];
    }
  }
}

void caller_blocks(int bSizeCaller, int nBlocksCaller) {
  float * ppp;

  foo_blocks(ppp, bSizeCaller, nBlocksCaller);
}

////
[[steel::task("foo_low_tri_app")]]
void foo_low_triangle(const float * bbb, int nCols, int nRows) {
  float r = 13.f;
  for (int row = 0; row < nRows; row++) {
    for (int col = 0; col < row; col++) {
      r = bbb[col + row*nCols];
    }
  }
}

void caller_low_triangle(int nColsCaller, int nRowsCaller) {
  float * ppp;

  foo_low_triangle(ppp, nColsCaller, nRowsCaller);
}

////
[[steel::task("foo_up_tri_app")]]
void foo_up_triangle(const float * bbb, int nCols, int nRows) {
  float r = 13.f;
  for (int row = 0; row < nRows; row++) {
    for (int col = row; col < nCols; col++) {
      r = bbb[col + row*nCols];
    }
  }
}

void caller_up_triangle(int nColsCaller, int nRowsCaller) {
  float * ppp;

  foo_up_triangle(ppp, nColsCaller, nRowsCaller);
}
