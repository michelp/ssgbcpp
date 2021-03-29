extern "C" {
#include <GraphBLAS.h>
#include <stdint.h>
}
#include <iostream>

#define _SSCPP_MATRIX_TRY(GrB_method)                                   \
    { const char* error; GrB_Info info = GrB_method ;                   \
        if (! (info == GrB_SUCCESS || info == GrB_NO_VALUE)) {          \
            GrB_Matrix_error(&error, A) ;                               \
            std::cout << info << std::flush;                            \
            throw error;                                                \
        }                                                               \
    }


#define _SSCP_BUILDER(TYPE, CTYPE)                                      \
    class Matrix_##TYPE {                                               \
    GrB_Matrix A;                                                       \
public:                                                                 \
 Matrix_##TYPE (GrB_Index nrows, GrB_Index ncols) {                     \
     _SSCPP_MATRIX_TRY(GrB_Matrix_new(&A, GrB_##TYPE,                   \
                                      nrows, ncols));                   \
 }                                                                      \
                                                                        \
 Matrix_##TYPE (){                                                      \
     _SSCPP_MATRIX_TRY(GrB_Matrix_new(&A, GrB_##TYPE,                   \
                                      GxB_INDEX_MAX,                    \
                                      GxB_INDEX_MAX));                  \
}                                                                       \
                                                                        \
 ~Matrix_##TYPE () {                                                    \
     GrB_Matrix_free(&A);                                               \
 }                                                                      \
                                                                        \
 GrB_Index nvals () {                                                   \
     GrB_Index n;                                                       \
     _SSCPP_MATRIX_TRY(GrB_Matrix_nvals(&n, A));                        \
     return n;                                                          \
 }                                                                      \
                                                                        \
 GrB_Index nrows () {                                                   \
     GrB_Index n;                                                       \
     _SSCPP_MATRIX_TRY(GrB_Matrix_nrows(&n, A));                        \
     return n;                                                          \
 }                                                                      \
                                                                        \
 GrB_Index ncols () {                                                   \
     GrB_Index n;                                                       \
     _SSCPP_MATRIX_TRY(GrB_Matrix_ncols(&n, A));                        \
     return n;                                                          \
 }                                                                      \
                                                                        \
 void setElement(CTYPE x, GrB_Index i, GrB_Index j) {                   \
     _SSCPP_MATRIX_TRY(GrB_Matrix_setElement_##TYPE(A, x, i, j));       \
 }                                                                      \
                                                                        \
 void print() {                                                         \
     _SSCPP_MATRIX_TRY(GxB_Matrix_fprint(A, "A", GxB_SHORT, stdout));   \
 }                                                                      \
                                                                        \
 void print(GxB_Print_Level l) {                                        \
     _SSCPP_MATRIX_TRY(GxB_Matrix_fprint(A, "A", l, stdout));           \
 }                                                                      \
                                                                        \
 };                                                                     

_SSCP_BUILDER(FP64,   double)
_SSCP_BUILDER(FP32,   float)
_SSCP_BUILDER(INT64,  int64_t)
_SSCP_BUILDER(INT32,  int32_t)
_SSCP_BUILDER(INT16,  int16_t)
_SSCP_BUILDER(INT8,   int8_t)
_SSCP_BUILDER(UINT64, uint64_t)
_SSCP_BUILDER(UINT32, uint32_t)
_SSCP_BUILDER(UINT16, uint16_t)
_SSCP_BUILDER(UINT8,  uint8_t)
_SSCP_BUILDER(BOOL,   bool)
