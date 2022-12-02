//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

#include <vector>
#include <cstdlib> 

[[steel::task("matrix_pack")]]
void pack_matrix(
  float * packMatrix, float const * unpackMatrix,
  unsigned nRows, unsigned nCols, unsigned stride)
{
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      packMatrix[jj*nCols + ii] = unpackMatrix[jj*stride + ii];
    }
  }
}

[[steel::task("matrix_allocate")]]
void allocate_matrix(float *& packMatrix, unsigned nRows, unsigned nCols) {
  packMatrix = static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)));
  // packMatrix = (float*)std::malloc(nRows*nCols*sizeof(float)); HANDLE with pck::undefined TODO
}

[[steel::task("matrix_deallocate")]]
void deallocate_matrix(float *& packMatrix) {
  std::free(packMatrix);
}


task::coro::dispatcher<app::impl::pack_matrix_caller> pack_matrix_caller(task::attr::descriptor&  attrDesc, 
  float const * outMat,
  unsigned mSize, unsigned nSize,
  unsigned mBlocks, unsigned nBlocks)
{
auto wrap_outMat = dep::wrap_region<2,dep::mesh::direct>(outMat, {/*embeds*/nSize,1}, {/*embeds*/(mSize/mBlocks),(nSize/nBlocks)}, {/*ranges*/range_t({0, mBlocks}),range_t({0, nBlocks})});

  std::vector<float*> outCompact;
  outCompact.resize(mBlocks*nBlocks);
  float ** outCompactPtr = outCompact.data();
auto wrap_outCompactPtr = dep::wrap_region<2,dep::mesh::direct>(outCompactPtr, {/*embeds*/nBlocks,1}, {/*embeds*/1,1}, {/*ranges*/range_t({0, mBlocks}),range_t({0, nBlocks})});

  unsigned mBlockSize = mSize / mBlocks;
  unsigned nBlockSize = nSize / nBlocks;

  unsigned outStride = nBlockSize*nBlocks;

  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      co_await task::make_async<app::call::pack_matrix_caller_matrix_allocate_0>(attrDesc.depth + 1,  wrap_outCompactPtr.emit_bnd_writer({/*coord*/mb,nb},{/*ranges*/range_t({mb, (1+mb)}),range_t({nb, (1+nb)})}), mBlockSize, nBlockSize );
    }
  }

  // Strided -> compact
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      co_await task::make_async<app::call::pack_matrix_caller_matrix_pack_1>(attrDesc.depth + 1,  wrap_outCompactPtr.emit_bnd_writer({/*coord*/mb,nb},{/*ranges*/range_t({mb, (1+mb)}),range_t({nb, (1+nb)})}), wrap_outMat.emit_bnd_reader({/*coord*/(mBlockSize*mb),(nBlockSize*nb)},{/*ranges*/range_t({(mBlockSize*mb), (mBlockSize+(mBlockSize*mb))}),range_t({(nBlockSize*nb), (nBlockSize+(nBlockSize*nb))})}), mBlockSize, nBlockSize, outStride );
    }
  }

  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      co_await task::make_async<app::call::pack_matrix_caller_matrix_deallocate_2>(attrDesc.depth + 1,  wrap_outCompactPtr.emit_bnd_writer({/*coord*/mb,nb},{/*ranges*/range_t({mb, (1+mb)}),range_t({nb, (1+nb)})}) );
    }
  }


while (not dep::all_destroyable(wrap_outMat,wrap_outCompactPtr)) { co_await task::coro::suspend(); }
}
