

[[steel::task("fooapp_wo")]]
void foo_wo(float * ptr, const unsigned nCols) {
  float init = 13;
  for (unsigned cc = 0; cc < nCols; cc++) {
    ptr[cc] = init;
  }
}

void caller_wo(float * ptrCaller, const unsigned nColBlocks, const unsigned chunkColsCaller) {
  for (unsigned c = 0; c < nColBlocks; c++) {
    foo_wo( &ptrCaller[c*chunkColsCaller], chunkColsCaller );
  }
}
