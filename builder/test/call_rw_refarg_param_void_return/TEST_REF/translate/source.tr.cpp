//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;
[[steel::task("zeeapp")]]
void zee(int& a) {

  int b = 13;
  a = b;
}


[[steel::task("barapp")]]
task::coro::dispatcher<app::impl::bar> bar(task::attr::descriptor&  attrDesc, int a) {
auto wrap_a = dep::wrap(a);

  co_await task::make_async<app::call::bar_zeeapp_0>(attrDesc.depth + 1, wrap_a.emit_bnd_writer());

  
while (not dep::all_destroyable(wrap_a)) { co_await task::coro::suspend(); }

co_return; // return;
}
