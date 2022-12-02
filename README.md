# STEEL alpha

This repository contains code for an alpha C++ implementation of STEEL-PM *Single-Task Expanded-Execution-Leveraged-* Programming model,
belonging to a research project continuation of this [PhD thesis](https://eprints.ucm.es/id/eprint/62846/).

This project is composed of two main components: **Builder** and **Runtime**. The builder ingests user application code and 
compiles it against the Runtime, resulting in a automatically parallelized application driven by internal Runtime logic.

## Builder

Builder component extends Clang 11 with user-defined execution relaxations from C++11-compliant function annotations.

Application code featured with STEEL task annotations is transformed into several stages

* **Inspect**: User-annotated functions are inspected and to build a graph-like application representation.
* **Translate**: Information from the Inspect stage is used to translate user-annotated translated into STEEL-RT-compliant code.
* **Generate**: Additional C++ modules are generated from inspected info with a representation of the user application.
* **Scan**: Translated, generated and runtime sources are scanned to perform module matching.
* **Compile**: Translated, generated and runtime sources are compiled from scanned information.
* **Link**: Compiled code is finally linked into an executable.

Check `builder/test/` API examples to see how user code is transformed into translated and generated code.

### Translation example: dot product

#### User application

```c++
#include <vector>

[[steel::task("dot_prod_app")]]
void dot_prod_v1(float * res, float const * aVec, float const * bVec, const unsigned n) {
  for (unsigned i = 0; i < n; i++) {
    res[0] += aVec[i] * bVec[i];
  }
}

[[steel::task("reduce_app")]]
void reduce(float * res, float const * vec, const unsigned n) {
  for(unsigned i = 0; i < n; i++) {
    res[0] += vec[i];
  }
}

[[steel::task("dot_prod_app")]]
void dot_prod_v2( float * res, float const * aPtr, float const * bPtr, const unsigned n, const unsigned blockSize) {

  const unsigned nBlocks = n / blockSize;

  // Create vector of partial results
  std::vector<float> resVec;
  resVec.resize(nBlocks);
  float * resPtr = resVec.data();

  // Compute smaller 'nBlocks' dot products
  for (unsigned b = 0; b < nBlocks; b++) {
    dot_prod_v1( &resPtr[b], &aPtr[b*blockSize], &bPtr[b*blockSize], blockSize );
  }

  float resReduce = 0;
  reduce(&resReduce, resPtr, nBlocks);
}
```

#### Automatically translated code dependent on Runtime

```c++
//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

#include <vector>

[[steel::task("dot_prod_app")]]
void dot_prod_v1(float * res, float const * aVec, float const * bVec, const unsigned n) {
  for (unsigned i = 0; i < n; i++) {
    res[0] += aVec[i] * bVec[i];
  }
}

[[steel::task("reduce_app")]]
void reduce(float * res, float const * vec, const unsigned n) {
  for(unsigned i = 0; i < n; i++) {
    res[0] += vec[i];
  }
}

[[steel::task("dot_prod_app")]]
task::coro::dispatcher<app::impl::dot_prod_v2> dot_prod_v2(task::attr::descriptor&  attrDesc,  float * res, float const * aPtr, float const * bPtr, const unsigned n, const unsigned blockSize) {
  auto wrap_aPtr = dep::wrap_region<1,dep::mesh::direct>(aPtr, {/*embeds*/1}, {/*embeds*/blockSize}, {/*ranges*/range_t({0, (n/blockSize)})});
  auto wrap_bPtr = dep::wrap_region<1,dep::mesh::direct>(bPtr, {/*embeds*/1}, {/*embeds*/blockSize}, {/*ranges*/range_t({0, (n/blockSize)})});

  const unsigned nBlocks = n / blockSize;

  // Create vector of partial results
  std::vector<float> resVec;// (nBlocks, 0); TODO
  resVec.resize(nBlocks);
  float * resPtr = resVec.data();
  auto wrap_resPtr = dep::wrap_region<1,dep::mesh::tree>(resPtr, {/*embeds*/1});

  // Compute smaller 'nBlocks' dot products
  for (unsigned b = 0; b < nBlocks; b++) {
    co_await task::make_async<app::call::dot_prod_v2_dot_prod_app_0>(attrDesc.depth + 1,  wrap_resPtr.emit_bnd_writer({/*coord*/b},{/*ranges*/range_t({b, (1+b)})}), wrap_aPtr.emit_bnd_reader({/*coord*/(b*blockSize)},{/*ranges*/range_t({(b*blockSize), (blockSize+(b*blockSize))})}), wrap_bPtr.emit_bnd_reader({/*coord*/(b*blockSize)},{/*ranges*/range_t({(b*blockSize), (blockSize+(b*blockSize))})}), blockSize );
  }

  float resReduce = 0;
  auto wrap_resReduce = dep::wrap_region<0>(resReduce);
  co_await task::make_async<app::call::dot_prod_v2_reduce_app_1>(attrDesc.depth + 1, wrap_resReduce.emit_bnd_writer(0, /*ds-off*/0), wrap_resPtr.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({0, nBlocks})}), nBlocks);

  while (not dep::all_destroyable(wrap_aPtr,wrap_bPtr,wrap_resPtr,wrap_resReduce)) { co_await task::coro::suspend(); }
}
```

## Runtime

Runtime codebase is a C++20-module only component used by the builder to leverage STEEL Runtime to drive the relaxed user application.

The code in `runtime/` encompass the code run by two processes:

* **Runner process**:
  * Executes the user-relaxed application, distributing user-defined tasks (kernels and coroutines) into a thread pool.
  * Feeds the pilot with application-dependent information.
  * Is driven by the pilot.
  * *Pending work*: fix integration with the builder pipeline.
* **Pilot process**:
  * Drives the execution of the runner.
  * *Pending work*: uses Reinforcement learning to drive the user-application.
  * *Pending work*: fix integration with the builder pipeline.


## Install and test

This project still has several installation portability problems. Installation and testing can be tried with the following steps.

* Ensure a C++17-compliant compiler (used `clang-9`)

* Checkout [LLVM-11](https://github.com/llvm/llvm-project/releases/tag/llvmorg-11.1.0) from sources -> `llvm-project/`.

  * See `builder/llvm_build.txt` to see example build commands
  * Ensure `make` succeeds before proceeding

* Apply git patch in `build/llvm11.patch` in source `llvm-project` repository.

* Move or create symlink of `steel-posdoc`, containing `builder/` and `runtime/` in `llvm-project/clang-tools-extra/steel/`

* Integrating `clang-tools-extra/steel` into the `llvm-project/` cmake hierarchy by `add_subdirectiory`.

* Replace `[LLVM-PROJECT-DIR]` occurrences by full path `llvm-project/`.

* Recompile llvm project with following targets. **NOTE** If this step fails, search for `clang-9` in builder and replace it by a C++17-compliant compiler.
  * steelbld-i
  * steelbld-it
  * steelbld-itg
  * steelbld-itgs
  * steelbld-itgsc
  * steelbld-itgscl

* From `builder/`, run builder tests: `. test/builder.sh [BUILD_DIR] [STEEL_PATH]`
  * *`[BUILD_DIR]`* is the target output dir in which the test results are written
  * *`[STEEL_PATH]`* is the full path of `llvm-project/clang-tools-extra/steel/`

* From `builder/`, run runtime tests: `. test/runtime.sh [BUILD_DIR] [STEEL_PATH]`

## Acknowledgements
This work has been developed during the period [2020-01-01 - 2021-04-21] and has been supported by the EU (FEDER) and the Spanish MINECO and CM under grants S2018/TCS-4423 and RTI2018-093684-B-I00.
