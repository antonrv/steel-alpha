//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;
[[steel::task("barapp")]]
void bar(int a) {
}

task::coro::dispatcher<app::impl::main_entry> main_entry(task::attr::descriptor&  attrDesc, int& SI_retParam) {

  int a = 4;

  co_await task::make_async<app::call::main_entry_barapp_0>(attrDesc.depth + 1, a);

  SI_retParam = 0;

co_return; // return 0;
}
