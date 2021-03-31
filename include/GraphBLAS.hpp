#pragma once

extern "C" {
#include <GraphBLAS.h>
}
#include <iostream>

#define CCAT2(x, y) x ## y
#define CCAT(x, y) CCAT2(x, y)
#define FN(x) CCAT(x, N)
#define PN(x) CCAT(P, CCAT(x, N))


#define _TRY(GrB_method)                                        \
    { const char* error; GrB_Info info = GrB_method ;           \
        if (! (info == GrB_SUCCESS || info == GrB_NO_VALUE)) {  \
            GrB_Matrix_error(&error, A) ;                       \
            std::cout << info << std::flush;                    \
            throw error;                                        \
        }                                                       \
    }

#define SET_ELEMENT(P, CT, T)                                     \
    if constexpr (std::is_same<C, CT>::value) {                  \
        _TRY(P ## _Matrix_setElement_ ## T(A, x, i, j));           \
        return;                                                  \
        }                                                        \
    
namespace ssgbcpp {
    template <typename C>
    class Matrix {
    protected:
        GrB_Matrix A;
    public:
        Matrix (GrB_Type type, GrB_Index nrows, GrB_Index ncols) {
            _TRY(GrB_Matrix_new(&A, type, nrows, ncols));
        }

        Matrix (GrB_Type type) {
            _TRY(GrB_Matrix_new(&A, type, GxB_INDEX_MAX, GxB_INDEX_MAX));
        }

        ~Matrix () {
            GrB_Matrix_free(&A);
        }

        GrB_Index nvals () {
            GrB_Index n;
            _TRY(GrB_Matrix_nvals(&n, A));
            return n;
        }

        GrB_Index nrows () {
            GrB_Index n;
            _TRY(GrB_Matrix_nrows(&n, A));
            return n;
        }

        GrB_Index ncols () {
            GrB_Index n;
            _TRY(GrB_Matrix_ncols(&n, A));
            return n;
        }

        void print() {
            _TRY(GxB_Matrix_fprint(A, "A", GxB_SHORT, stdout));
        }

        void print(GxB_Print_Level l) {
            _TRY(GxB_Matrix_fprint(A, "A", l, stdout));
        }
        void setElement(C x, GrB_Index i, GrB_Index j) {
            SET_ELEMENT(GrB, bool,     BOOL);
            SET_ELEMENT(GrB, int64_t,  INT64);
            SET_ELEMENT(GrB, int32_t,  INT32);
            SET_ELEMENT(GrB, int16_t,  INT16);
            SET_ELEMENT(GrB, int8_t,   INT8);
            SET_ELEMENT(GrB, uint64_t, UINT64);
            SET_ELEMENT(GrB, uint32_t, UINT32);
            SET_ELEMENT(GrB, uint16_t, UINT16);
            SET_ELEMENT(GrB, uint8_t,  UINT8);
            SET_ELEMENT(GrB, float,    FP32);
            SET_ELEMENT(GrB, double,   FP64);
            SET_ELEMENT(GxB, std::complex<float>,    FC32);
            SET_ELEMENT(GxB, std::complex<double>,   FC64);
        }
    };
}

#undef _TRY
#undef CCAT2
#undef CCAT
#undef FN
#undef PN
