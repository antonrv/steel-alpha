

[[steel::task("fooapp")]]
void foo(float * ptr, const unsigned bSize) {
  float r = 13;
  for (unsigned i = 0; i < bSize; i++) {
    ptr[i] = r;
  }
}

void caller(float * ptrCaller, const unsigned nCalls, const unsigned bSizeCaller) {

  for (unsigned i = 0; i < nCalls; i++) {
    foo( &ptrCaller[i*bSizeCaller], bSizeCaller );
  }
}
