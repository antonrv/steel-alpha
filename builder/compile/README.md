The cc1_call and cc1_main are adapted from clang frontend files. We should use a much more shorter versions,
possibly having a single CompilerInstance for all sources, and making a compiler invocation for every source
to lower.
