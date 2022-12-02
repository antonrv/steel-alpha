
////
[[steel::task("foo_lt_add")]]
void foo_lt_add(const float * bbb, int nn) {
  float r;
  for (int ii = 0; ii < nn; ii++) {
    r = bbb[ii];
  }
}

void caller_lt_add(int nCaller) {
  float * ppp;

  int nCall = nCaller;
  foo_lt_add(ppp, nCall);
}

////
[[steel::task("foo_leq_add")]]
void foo_leq_add(const float * bbb, int nn) {
  float r;
  for (int ii = 0; ii <= nn; ii++) {
    r = bbb[ii];
  }
}

void caller_leq_add(int nCaller) {
  float * ppp;

  int nCall = nCaller;
  foo_leq_add(ppp, nCall);
}

////
[[steel::task("foo_gt_sub")]]
void foo_gt_sub(const float * bbb, int nn) {
  float r;
  for (int ii = nn; ii > 0; ii--) {
    r = bbb[ii];
  }
}

void caller_gt_sub(int nCaller) {
  float * ppp;

  int nCall = nCaller;
  foo_gt_sub(ppp, nCall);
}

////
[[steel::task("foo_geq_sub")]]
void foo_geq_sub(const float * bbb, int nn) {
  float r;
  for (int ii = nn; ii >= 0; ii--) {
    r = bbb[ii];
  }
}

void caller_geq_sub(int nCaller) {
  float * ppp;

  int nCall = nCaller;
  foo_geq_sub(ppp, nCall);
}
