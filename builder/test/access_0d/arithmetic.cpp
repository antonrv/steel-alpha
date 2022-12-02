
[[steel::task("foo_ro_arit_app")]]
void foo_ro_arit(const float * bbb, int i) {
  int ii = i + 3;
  float r;
  r = bbb[ii + 99 + 7*ii + 425];
}

void caller_foo_ro_arit_1() {
  int j = 11;
  float * ppp;

  foo_ro_arit(ppp, j);
}

void caller_foo_ro_arit_2(int k) {
  int j = k;
  float * ppp;

  foo_ro_arit(ppp, j);
}

[[steel::task("foo_rw_arit_app")]]
void foo_rw_arit(float * bbb, int i) {
  int ii = i + 3;
  float r;
  bbb[ii + 99 + 7*ii + 425] = r;
}

void caller_foo_rw_arit_1() {
  int j = 11;
  float * ppp;

  foo_rw_arit(ppp, j);
}

void caller_foo_rw_arit_2(int k) {
  int j = k;
  float * ppp;

  foo_rw_arit(ppp, j);
}
