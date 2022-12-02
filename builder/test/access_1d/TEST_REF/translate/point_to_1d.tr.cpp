//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

[[steel::task("init_app")]]
void init_v0(float * res, float val) {
  res[0] = val;
}

task::coro::dispatcher<app::impl::init_caller_v0> init_caller_v0(task::attr::descriptor&  attrDesc,  float * res, const unsigned n) {
auto wrap_res = dep::wrap_region<1,dep::mesh::direct>(res, {/*embeds*/1}, {/*embeds*/1}, {/*ranges*/range_t({0, n})});

  float val = 13;

  for (unsigned i = 0; i < n; i++) {
    co_await task::make_async<app::call::init_caller_v0_init_app_0>(attrDesc.depth + 1,  wrap_res.emit_bnd_writer({/*coord*/i},{/*ranges*/range_t({i, (1+i)})}), val );
  }

while (not dep::all_destroyable(wrap_res)) { co_await task::coro::suspend(); }
}
