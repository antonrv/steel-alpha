
////
[[steel::task("foo_whole_ro_app")]]
void foo_whole_ro(const float * bbb, int nn) {
  float r;
  for (int ii = 0; ii < nn; ii++) {
    r = bbb[ii];
  }
}

void caller_ro(int nCaller) {
  float * ppp;

  int nCall = nCaller;
  foo_whole_ro(ppp, nCall);
}

////
[[steel::task("foo_portion_ro_app")]]
void foo_portion_ro(const float * bbb, int sn, int en) {
  float r;
  for (int ii = sn; ii < en; ii++) {
    r = bbb[ii];
  }
}

void caller_ro(int snCaller, int enCaller) {
  float * ppp;

  int snCall = snCaller;
  int enCall = enCaller;
  foo_portion_ro(ppp, snCall, enCall);
}

////
[[steel::task("foo_whole_rw_app")]]
void foo_whole_rw(float * bbb, int nn) {
  float r;
  for (int ii = 0; ii < nn; ii++) {
    bbb[ii] = r;
  }
}

void caller_rw(int nCaller) {
  float * ppp;

  int nCall = nCaller;
  foo_whole_rw(ppp, nCall);
}

////
[[steel::task("foo_portion_rw_app")]]
void foo_portion_rw(const float * bbb, int sn, int en) {
  float r;
  for (int ii = sn; ii < en; ii++) {
    r = bbb[ii];
  }
}

void caller_rw(int snCaller, int enCaller) {
  float * ppp;

  int snCall = snCaller;
  int enCall = enCaller;
  foo_portion_rw(ppp, snCall, enCall);
}
