
#define _TRY(GrB_method)                                        \
    { const char* error; GrB_Info info = GrB_method ;           \
        if (! (info == GrB_SUCCESS || info == GrB_NO_VALUE)) {  \
            GrB_Matrix_error(&error, A) ;                       \
            std::cout << info << std::flush;                    \
            throw error;                                        \
        }                                                       \
    }

namespace ssgbcpp {
    class FN(Matrix_) {
    private:
        GrB_Matrix A;
    public:
        FN(Matrix_) (GrB_Index nrows, GrB_Index ncols) {
            _TRY(GrB_Matrix_new(&A, FN(P),
                                nrows, ncols));
        }
        
        FN(Matrix_) () {
            _TRY(GrB_Matrix_new(&A, FN(P),
                                GxB_INDEX_MAX,
                                GxB_INDEX_MAX));
        }
        
        ~FN(Matrix_) () {
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
        
        void setElement(T x, GrB_Index i, GrB_Index j) {
            _TRY(PN(Matrix_setElement_)(A, x, i, j));
        }
        
        void print() {
            _TRY(GxB_Matrix_fprint(A, "A", GxB_SHORT, stdout));
        }
        
        void print(GxB_Print_Level l) {
            _TRY(GxB_Matrix_fprint(A, "A", l, stdout));
        }
        
    };
}
