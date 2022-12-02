//// READ ONLY
[[steel::task("foo_ro_multiple_point_app")]]
void foo_ro_multiple_point(const float * bbb, int i) {
  float r;
  r = bbb[i];
}

void caller1_ro_multiple_point() {
  int a = 15;
  int b = 23;
  int c = 37;
  float * ppp;

  foo_ro_multiple_point(ppp, a);
  foo_ro_multiple_point(ppp, b);
  foo_ro_multiple_point(ppp, c);
}

void caller2_ro_multiple_point(int i, int j, int k) {
  int a = i;
  int b = j;
  int c = k;
  float * ppp;

  foo_ro_multiple_point(ppp, a);
  foo_ro_multiple_point(ppp, b);
  foo_ro_multiple_point(ppp, c);
}


//// READ WRITE
[[steel::task("foo_rw_multiple_point_app")]]
void foo_rw_multiple_point(float * bbb, int i) {
  float r;
  bbb[i] = r;
}

void caller1_rw_multiple_point() {
  int a = 15;
  int b = 23;
  int c = 37;
  float * ppp;

  foo_rw_multiple_point(ppp, a);
  foo_rw_multiple_point(ppp, b);
  foo_rw_multiple_point(ppp, c);
}

void caller2_rw_multiple_point(int i, int j, int k) {
  int a = i;
  int b = j;
  int c = k;
  float * ppp;

  foo_rw_multiple_point(ppp, a);
  foo_rw_multiple_point(ppp, b);
  foo_rw_multiple_point(ppp, c);
}
