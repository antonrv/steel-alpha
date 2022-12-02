//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;
[[steel::task("zeeapp")]]
void zee(int& a, float b, const char c) {
  a = 13;
}


[[steel::task("barapp")]]
task::coro::dispatcher<app::impl::bar> bar(task::attr::descriptor&  attrDesc, int a, float b, const char c) {
auto wrap_a = dep::wrap(a);

  co_await task::make_async<app::call::bar_zeeapp_0>(attrDesc.depth + 1, wrap_a.emit_bnd_writer(), b, c);

while (not dep::all_destroyable(wrap_a)) { co_await task::coro::suspend(); }
}
