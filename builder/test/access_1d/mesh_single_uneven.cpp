

[[steel::task("fooapp_wo")]]
void foo_wo(float * ptr, const unsigned nCols) {
  float init = 13;
  for (unsigned cc = 0; cc < nCols; cc++) {
    ptr[cc] = init;
  }
}

void caller_wo(float * ptrCaller, const unsigned nElems, const unsigned bSize) {

  unsigned nBlocksEven = nElems / bSize;

  for (unsigned c = 0; c < nBlocksEven; c++) {
    foo_wo( &ptrCaller[c*bSize], bSize );
  }

  unsigned bSizeRemain = nElems % bSize;

  if (bSizeRemain != 0) {
    foo_wo( &ptrCaller[nBlocksEven*bSize], bSizeRemain );
  }
}
