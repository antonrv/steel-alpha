//// READ ONLY
[[steel::task("foo_ro_multiple_point_app")]]
void foo_ro_multiple_point(const float * bbb, int s, int e) {
  float r;
  for (int i = s; i < e; i++) {
    r = bbb[i];
  }
}

void caller_res_ro_multiple_point() {
  int s1 = 15;
  int e1 = 18;
  int s2 = 23;
  int e2 = 26;
  int s3 = 33;
  int e3 = 39;
  float * ppp;

  foo_ro_multiple_point(ppp, s1, e1);
  foo_ro_multiple_point(ppp, s2, e2);
  foo_ro_multiple_point(ppp, s3, e3);
}

void caller_unres_ro_multiple_point(int s1Caller, int e1Caller, int s2Caller, int e2Caller, int s3Caller, int e3Caller) {
  int s1 = s1Caller;
  int e1 = e1Caller;
  int s2 = s2Caller;
  int e2 = e2Caller;
  int s3 = s3Caller;
  int e3 = e3Caller;
  float * ppp;

  foo_ro_multiple_point(ppp, s1, e1);
  foo_ro_multiple_point(ppp, s2, e2);
  foo_ro_multiple_point(ppp, s3, e3);
}
