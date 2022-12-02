//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

[[steel::task("callee_offset_app")]]
void callee_offset(float * bbb, int i) {
  float r;
  bbb[i] = r;
}

task::coro::dispatcher<app::impl::caller_offset> caller_offset(task::attr::descriptor&  attrDesc, float * ptr) {
auto wrap_ptr = dep::wrap_region<0>(ptr);

  int a = 15;

  co_await task::make_async<app::call::caller_offset_callee_offset_app_0>(attrDesc.depth + 1,  wrap_ptr.emit_bnd_writer(0, /*ds-off*/a), a );

while (not dep::all_destroyable(wrap_ptr)) { co_await task::coro::suspend(); }
}

[[steel::task("callee_no_offset_app")]]
void callee_no_offset(float * bbb) {
  float r;
  bbb[0] = r;
}

task::coro::dispatcher<app::impl::caller_no_offset> caller_no_offset(task::attr::descriptor&  attrDesc, float * ptr) {
auto wrap_ptr = dep::wrap_region<0>(ptr);

  int a = 15;

  co_await task::make_async<app::call::caller_no_offset_callee_no_offset_app_0>(attrDesc.depth + 1,  wrap_ptr.emit_bnd_writer(0) );

while (not dep::all_destroyable(wrap_ptr)) { co_await task::coro::suspend(); }
}
