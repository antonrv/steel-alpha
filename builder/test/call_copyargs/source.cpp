[[steel::task("zeeapp")]]
void zee(int& a, float b, const char c) {
  a = 13;
}


[[steel::task("barapp")]]
void bar(int a, float b, const char c) {

  zee(a, b, c);
}
