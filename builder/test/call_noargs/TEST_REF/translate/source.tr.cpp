//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;
[[steel::task("fooapp")]]
void foo() {
}

task::coro::dispatcher<app::impl::main_entry> main_entry(task::attr::descriptor&  attrDesc, int& SI_retParam) {

  co_await task::make_async<app::call::main_entry_fooapp_0>(attrDesc.depth + 1);

  SI_retParam = 0;

co_return; // return 0;
}
