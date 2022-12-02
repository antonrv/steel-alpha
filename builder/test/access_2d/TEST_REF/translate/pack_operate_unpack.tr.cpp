//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

#include <vector>
#include <cstdlib> 

[[steel::task("app_allocate_matrix")]]
void allocate_matrix(float *& packMatrix, unsigned nRows, unsigned nCols) {
  packMatrix = static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)));
  // packMatrix = (float*)std::malloc(nRows*nCols*sizeof(float)); HANDLE with pck::undefined TODO
}

[[steel::task("app_deallocate_matrix")]]
void deallocate_matrix(float * packMatrix) {
  std::free(packMatrix);
}


[[steel::task("app_pack_matrix")]]
void pack_copy_matrix(
  float * packMatrix, float const * unpackMatrix,
  unsigned nCols, unsigned nRows, unsigned stride)
{
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      packMatrix[jj*nCols + ii] = unpackMatrix[jj*stride + ii];
    }
  }
}

[[steel::task("app_unpack_matrix")]]
void unpack_copy_matrix(
  float * unpackMatrix, float const * packMatrix,
  unsigned nCols, unsigned nRows, unsigned stride)
{
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      unpackMatrix[jj*stride + ii] = packMatrix[jj*nCols + ii];
    }
  }
}

[[steel::task("app_operate_matrix")]]
void operate_matrix_v1(
  float * editMat,
  unsigned nCols, unsigned nRows)
{
  float init = 42;
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      editMat[jj*nCols + ii] = init;
    }
  }
}

[[steel::task("app_operate_matrix")]] // [[steel::manage("nColBlocks=divisor(nCols)")]] [[steel::manage("nRowBlocks=divisor(nRows)")]]
task::coro::dispatcher<app::impl::operate_matrix_v2> operate_matrix_v2(task::attr::descriptor&  attrDesc, 
  float * editMat,
  unsigned nCols, unsigned nRows,
  unsigned nColBlocks, unsigned nRowBlocks)
{
auto wrap_editMat = dep::wrap_region<2,dep::mesh::direct>(editMat, {/*embeds*/nCols,1}, {/*embeds*/(nRows/nRowBlocks),(nCols/nColBlocks)}, {/*ranges*/range_t({0, nRowBlocks}),range_t({0, nColBlocks})});

  unsigned colBlockSize = nCols / nColBlocks;
  unsigned rowBlockSize = nRows / nRowBlocks;

  unsigned outStride = colBlockSize * nColBlocks;

  std::vector<float*> outCompact;
  outCompact.resize(nRowBlocks*nColBlocks);
  float ** outCompactPtr = outCompact.data();
auto wrap_outCompactPtr = dep::wrap_region<2,dep::mesh::direct>(outCompactPtr, {/*embeds*/nColBlocks,1}, {/*embeds*/1,1}, {/*ranges*/range_t({0, nRowBlocks}),range_t({0, nColBlocks})});

  for (unsigned mb = 0; mb < nRowBlocks; mb++) {
    for (unsigned nb = 0; nb < nColBlocks; nb++) {
      co_await task::make_async<app::call::operate_matrix_v2_app_allocate_matrix_0>(attrDesc.depth + 1,  wrap_outCompactPtr.emit_bnd_writer({/*coord*/mb,nb},{/*ranges*/range_t({mb, (1+mb)}),range_t({nb, (1+nb)})}), rowBlockSize, colBlockSize );
    }
  }

  // Strided -> compact
  for (unsigned jb = 0; jb < nRowBlocks; jb++) {
    for (unsigned ib = 0; ib < nColBlocks; ib++) {
      co_await task::make_async<app::call::operate_matrix_v2_app_pack_matrix_1>(attrDesc.depth + 1,  wrap_outCompactPtr.emit_bnd_writer({/*coord*/jb,ib},{/*ranges*/range_t({jb, (1+jb)}),range_t({ib, (1+ib)})}), wrap_editMat.emit_bnd_reader({/*coord*/(jb*rowBlockSize),(colBlockSize*ib)},{/*ranges*/range_t({(jb*rowBlockSize), (rowBlockSize+(jb*rowBlockSize))}),range_t({(colBlockSize*ib), (colBlockSize+(colBlockSize*ib))})}), colBlockSize, rowBlockSize, outStride);
    }
  }

  // Operate on each contiguous block
  for (unsigned yb = 0; yb < nRowBlocks; yb++) {
    for (unsigned xb = 0; xb < nColBlocks; xb++) {
      co_await task::make_async<app::call::operate_matrix_v2_app_operate_matrix_2>(attrDesc.depth + 1,  wrap_outCompactPtr.emit_bnd_writer({/*coord*/yb,xb},{/*ranges*/range_t({yb, (1+yb)}),range_t({xb, (1+xb)})}), colBlockSize, rowBlockSize );
    }
  }


  // Compact -> strided
  for (unsigned lb = 0; lb < nRowBlocks; lb++) {
    for (unsigned kb = 0; kb < nColBlocks; kb++) {
      co_await task::make_async<app::call::operate_matrix_v2_app_unpack_matrix_3>(attrDesc.depth + 1,  wrap_editMat.emit_bnd_writer({/*coord*/(lb*rowBlockSize),(colBlockSize*kb)},{/*ranges*/range_t({(lb*rowBlockSize), (rowBlockSize+(lb*rowBlockSize))}),range_t({(colBlockSize*kb), (colBlockSize+(colBlockSize*kb))})}), wrap_outCompactPtr.emit_bnd_reader({/*coord*/lb,kb},{/*ranges*/range_t({lb, (1+lb)}),range_t({kb, (1+kb)})}), colBlockSize, rowBlockSize, outStride);
    }
  }

  for (unsigned mb = 0; mb < nRowBlocks; mb++) {
    for (unsigned nb = 0; nb < nColBlocks; nb++) {
      co_await task::make_async<app::call::operate_matrix_v2_app_deallocate_matrix_4>(attrDesc.depth + 1,  wrap_outCompactPtr.emit_bnd_writer({/*coord*/mb,nb},{/*ranges*/range_t({mb, (1+mb)}),range_t({nb, (1+nb)})}) );
    }
  }


while (not dep::all_destroyable(wrap_editMat,wrap_outCompactPtr)) { co_await task::coro::suspend(); }
}
