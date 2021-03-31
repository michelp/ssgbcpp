#include <GraphBLAS.hpp>
#include <cassert>

#define CCAT2(x, y) x ## y
#define CCAT(x, y) CCAT2(x, y)
#define FN(x) CCAT(x, T)

using namespace ssgbcpp;

#define ANSWER true
#define P GrB_
#define T GrB_BOOL
#define C bool
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"
    
#undef ANSWER
#define ANSWER 42
#define T GrB_INT64
#define C int64_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define T GrB_INT32
#define C int32_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define T GrB_INT16
#define C int16_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define T GrB_INT8
#define C int8_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define T GrB_UINT64
#define C uint64_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define T GrB_UINT32
#define C uint32_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define T GrB_UINT16
#define C uint16_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define T GrB_UINT8
#define C uint8_t
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#undef ANSWER
#define ANSWER 42.0

#define T GrB_FP64
#define C double
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define T GrB_FP32
#define C float
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define T GxB_FC64
#define C std::complex<double>
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

#define T GxB_FC32
#define C std::complex<float>
#include "matrix.cpp"
#include "vector.cpp"
#include "scalar.cpp"

int main () {
    GrB_init (GrB_NONBLOCKING);
    test_GrB_BOOL();
    test_GrB_INT64();
    test_GrB_INT32();
    test_GrB_INT16();
    test_GrB_INT8();
    test_GrB_UINT64();
    test_GrB_UINT32();
    test_GrB_UINT16();
    test_GrB_UINT8();
    test_GrB_FP64();
    test_GrB_FP32();
    test_GxB_FC64();
    test_GxB_FC32();
    GrB_finalize ();
}
