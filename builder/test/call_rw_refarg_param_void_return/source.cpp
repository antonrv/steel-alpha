[[steel::task("zeeapp")]]
void zee(int& a) {

  int b = 13;
  a = b;
}


[[steel::task("barapp")]]
void bar(int a) {

  zee(a);

  return;
}
