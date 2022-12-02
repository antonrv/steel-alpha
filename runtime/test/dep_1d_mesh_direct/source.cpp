

[[steel::task("fooapp_wo")]]
void foo_wo(float * ptr, const unsigned bSize) {
  float r = 13;
  for (unsigned i = 0; i < bSize; i++) {
    ptr[i] = r;
  }
}

[[steel::task("fooapp_rw")]]
void foo_rw(float * ptr, const unsigned bSize) {
  float r = 7;
  for (unsigned i = 0; i < bSize; i++) {
    ptr[i] += r;
  }
}

// We don't use const float * ptrCaller bc we want to test the wrap/execution of foo_ro from a wrapDescriptor that also emits bnds for other rw/wo tasks.
[[steel::task("fooapp_ro")]]
void foo_ro(float const * ptr, const unsigned bSize) {
  float r;
  for (unsigned i = 0; i < bSize; i++) {
    r = ptr[i];
  }
}


void caller_wo(float * ptrCaller, const unsigned nCalls, const unsigned bSizeCaller) {
  for (unsigned i = 0; i < nCalls; i++) {
    foo_wo( &ptrCaller[i*bSizeCaller], bSizeCaller );
  }
}

void caller_rw(float * ptrCaller, const unsigned nCalls, const unsigned bSizeCaller) {
  for (unsigned i = 0; i < nCalls; i++) {
    foo_rw( &ptrCaller[i*bSizeCaller], bSizeCaller );
  }
}

// We don't use const float * ptrCaller bc we want to test the wrap/execution of foo_ro from a wrapDescriptor that also emits bnds for other rw/wo tasks.
void caller_ro(float * ptrCaller, const unsigned nCalls, const unsigned bSizeCaller) {
  for (unsigned i = 0; i < nCalls; i++) {
    foo_ro( &ptrCaller[i*bSizeCaller], bSizeCaller );
  }
}
