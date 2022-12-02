//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

[[steel::task("write_mesh_uneven")]]
void foo(float * ptr, const unsigned jSize, const unsigned iSize, const unsigned stride) {
  float init = 13;
  for (unsigned jj = 0; jj < jSize; jj++) {
    for (unsigned ii = 0; ii < iSize; ii++) {
      ptr[jj*stride + ii] = init;
    }
  }
}

[[steel::task("write_mesh_uneven")]] // [[steel::manage("jBlocks={2,3,4,divisors(jSize)}")]] [[steel::manage("iBlocks={2,3,4,divisor(iSize)}")]]
task::coro::dispatcher<app::impl::caller_foo> caller_foo(task::attr::descriptor&  attrDesc, float * ptrCaller, const unsigned jSize, const unsigned iSize, const unsigned jBlocks, const unsigned iBlocks) {
auto wrap_ptrCaller = dep::wrap_region<2,dep::mesh::direct>(ptrCaller, {/*embeds*/iSize,1}, {/*embeds*/(jSize/jBlocks),(iSize/iBlocks)}, {/*ranges*/range_t({0, rt::max(jBlocks,(1+jBlocks))}),range_t({0, rt::max(iBlocks,(1+iBlocks))})});

  unsigned jBlockSize = jSize / jBlocks;
  unsigned iBlockSize = iSize / iBlocks;

  unsigned iBlocksEven = iSize / iBlockSize;
  unsigned jBlocksEven = jSize / jBlockSize;

  for (unsigned j = 0; j < jBlocksEven; j++) {
    for (unsigned i = 0; i < iBlocksEven; i++) {
      co_await task::make_async<app::call::caller_foo_write_mesh_uneven_0>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(j*jBlockSize),(i*iBlockSize)},{/*ranges*/range_t({(j*jBlockSize), (jBlockSize+(j*jBlockSize))}),range_t({(i*iBlockSize), (iBlockSize+(i*iBlockSize))})}), jBlockSize, iBlockSize, iSize );
    }
  }

  unsigned iBlockSizeRemain = iSize % iBlockSize;
  if (iBlockSizeRemain != 0) {
    for (unsigned j = 0; j < jBlocksEven; j++) {
      co_await task::make_async<app::call::caller_foo_write_mesh_uneven_1>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(j*jBlockSize),(iBlockSize*iBlocksEven)},{/*ranges*/range_t({(j*jBlockSize), (jBlockSize+(j*jBlockSize))}),range_t({(iBlockSize*iBlocksEven), (iBlockSizeRemain+(iBlockSize*iBlocksEven))})}), jBlockSize, iBlockSizeRemain, iSize );
    }
  }

  unsigned jBlockSizeRemain = jSize % jBlockSize;
  if (jBlockSizeRemain != 0) {
    for (unsigned i = 0; i < iBlocksEven; i++) {
      co_await task::make_async<app::call::caller_foo_write_mesh_uneven_2>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(jBlockSize*jBlocksEven),(i*iBlockSize)},{/*ranges*/range_t({(jBlockSize*jBlocksEven), (jBlockSizeRemain+(jBlockSize*jBlocksEven))}),range_t({(i*iBlockSize), (iBlockSize+(i*iBlockSize))})}), jBlockSizeRemain, iBlockSize, iSize );
    }
  }

  if (iBlockSizeRemain != 0 and jBlockSizeRemain != 0) {
    co_await task::make_async<app::call::caller_foo_write_mesh_uneven_3>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(jBlockSize*jBlocksEven),(iBlockSize*iBlocksEven)},{/*ranges*/range_t({(jBlockSize*jBlocksEven), (jBlockSizeRemain+(jBlockSize*jBlocksEven))}),range_t({(iBlockSize*iBlocksEven), (iBlockSizeRemain+(iBlockSize*iBlocksEven))})}), jBlockSizeRemain, iBlockSizeRemain, iSize );
  }

while (not dep::all_destroyable(wrap_ptrCaller)) { co_await task::coro::suspend(); }
}
