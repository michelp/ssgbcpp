#include <GraphBLAS.hpp>
#include <cassert>

#define CCAT2(x, y) x ## y
#define CCAT(x, y) CCAT2(x, y)
#define FN(x) CCAT(x, N)
#define PN(x) CCAT(P, CCAT(x, N))

using namespace ssgbcpp;

#define ANSWER true
#define P GrB_
#define N BOOL
#define T bool
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"
    
#undef ANSWER
#define ANSWER 42
#define N INT64
#define T int64_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define N INT32
#define T int32_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define N INT16
#define T int16_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define N INT8
#define T int8_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define N UINT64
#define T uint64_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define N UINT32
#define T uint32_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define N UINT16
#define T uint16_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define N UINT8
#define T uint8_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#undef ANSWER
#define ANSWER 42.0

#define N FP64
#define T double
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define N FP32
#define T float
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#undef P
#define P GxB_
#define N FC64
#define T std::complex<double>
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define N FC32
#define T std::complex<float>
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

int main () {
    GrB_init (GrB_NONBLOCKING);
    test_BOOL();
    test_INT64();
    test_INT32();
    test_INT16();
    test_INT8();
    test_UINT64();
    test_UINT32();
    test_UINT16();
    test_UINT8();
    test_FP64();
    test_FP32();
    test_FC64();
    test_FC32();
    GrB_finalize ();
}
