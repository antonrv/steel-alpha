//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;
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
task::coro::dispatcher<app::impl::bar> bar(task::attr::descriptor&  attrDesc, int a, float b, const char c) {
auto wrap_a = dep::wrap(a);

  co_await task::make_async<app::call::bar_zeeapp_0>(attrDesc.depth + 1, wrap_a.emit_bnd_writer(), b, c);

  co_await task::make_async<app::call::bar_fooapp_1>(attrDesc.depth + 1, wrap_a.emit_bnd_writer());

  co_await task::make_async<app::call::bar_kuuapp_2>(attrDesc.depth + 1, wrap_a.emit_bnd_reader());
  co_await task::make_async<app::call::bar_kuuapp_3>(attrDesc.depth + 1, wrap_a.emit_bnd_reader());
  co_await task::make_async<app::call::bar_kuuapp_4>(attrDesc.depth + 1, wrap_a.emit_bnd_reader());

while (not dep::all_destroyable(wrap_a)) { co_await task::coro::suspend(); }
}
