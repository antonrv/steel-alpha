[[steel::task("zeeapp")]]
void zee(int& a, float b, const char c) {
  a += b + c;
}

[[steel::task("fooapp")]]
void foo(int& a) {
  a += 13;
}

[[steel::task("kuuapp")]]
void kuu(const int& a) {
  int b = a;
}


[[steel::task("barapp")]]
void bar(int a, float b, const char c) {

  zee(a, b, c);

  foo(a);

  kuu(a);
  kuu(a);
  kuu(a);
}
