//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;
[[steel::task("zeeapp")]]
void zee(int& a) {

  int c = 13;
  a = c;
}


[[steel::task("barapp")]]
task::coro::dispatcher<app::impl::bar> bar(task::attr::descriptor&  attrDesc, int a) {

  int b = a;
auto wrap_b = dep::wrap(b);

  co_await task::make_async<app::call::bar_zeeapp_0>(attrDesc.depth + 1, wrap_b.emit_bnd_writer());

while (not dep::all_destroyable(wrap_b)) { co_await task::coro::suspend(); }
}
