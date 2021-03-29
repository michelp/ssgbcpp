extern "C" {
#include <GraphBLAS.h>
}
#include <iostream>

#define CCAT2(x, y) x ## y
#define CCAT(x, y) CCAT2(x, y)
#define FN(x) CCAT(x, N)
#define PN(x) CCAT(P, CCAT(x, N))

#define P GrB_
#define N BOOL
#define T bool
#include "matrix.hpp"
    
#define N INT64
#define T int64_t
#include "matrix.hpp"

#define N INT32
#define T int32_t
#include "matrix.hpp"

#define N INT16
#define T int16_t
#include "matrix.hpp"

#define N INT8
#define T int8_t
#include "matrix.hpp"

#define N UINT64
#define T uint64_t
#include "matrix.hpp"

#define N UINT32
#define T uint32_t
#include "matrix.hpp"

#define N UINT16
#define T uint16_t
#include "matrix.hpp"

#define N UINT8
#define T uint8_t
#include "matrix.hpp"

#define N FP64
#define T double
#include "matrix.hpp"

#define N FP32
#define T float
#include "matrix.hpp"

#undef P
#define P GxB_
#define N FC64
#define T std::complex<double>
#include "matrix.hpp"

#define N FC32
#define T std::complex<float>
#include "matrix.hpp"
