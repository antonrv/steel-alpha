
[[steel::task("foo_ro_multiple_call_app")]]
void foo_ro_multiple(const float * bbb, int i) {
  float r;
  r = bbb[i];
}
[[steel::task("bar_ro_multiple_call_app")]]
void bar_ro_multiple(const float * bbb, int i) {
  float r;
  r = bbb[i];
}

void caller1_ro_multiple_call() {
  int j = 4;
  float * ppp;

  foo_ro_multiple(ppp, j);
  bar_ro_multiple(ppp, j);
  foo_ro_multiple(ppp, j);
}

void caller2_ro_multiple_call(int k) {
  int j = k;
  float * ppp;

  foo_ro_multiple(ppp, j);
  bar_ro_multiple(ppp, j);
  foo_ro_multiple(ppp, j);
}

[[steel::task("foo_rw_multiple_call_app")]]
void foo_rw_multiple_call(float * bbb, int i) {
  float r;
  bbb[i] = r;
}
[[steel::task("bar_rw_multiple_call_app")]]
void bar_rw_multiple_call(float * bbb, int i) {
  float r;
  bbb[i] = r;
}

void caller1_rw_multiple_call() {
  int j = 4;
  float * ppp;

  foo_rw_multiple_call(ppp, j);
  bar_rw_multiple_call(ppp, j);
  foo_rw_multiple_call(ppp, j);
}

void caller2_rw_multiple_call(int k) {
  int j = k;
  float * ppp;

  foo_rw_multiple_call(ppp, j);
  bar_rw_multiple_call(ppp, j);
  foo_rw_multiple_call(ppp, j);
}
