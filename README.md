# ssgbcpp

C++ Classes around SuiteSparse::GraphBLAS.

This is a header-only library that you include in your C++ that will
generate C++ wrapper classes around the SuiteSparse GraphBLAS C API.

```
#include <GraphBLAS.hpp>
#include <cassert>

Matrix<uint64_t> A(GrB_UINT64);
A.setElement (42, 1, 2);
assert (A.nvals () == 1);
A.print ();

Matrix<uint64_t> B(GrB_UINT64, 10, 20);
B.setElement (42, 4, 2);
assert (B.nrows () == 10);
assert (B.ncols () == 20);
assert (B.nvals () == 1);
B.print ();

```
