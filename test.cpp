#include <GraphBLAS.hpp>
#include <cassert>

void test_init () {
    Matrix_FP64 A;
    assert (A.nvals () == 0);
    assert (A.ncols () == GxB_INDEX_MAX);
    assert (A.nrows () == GxB_INDEX_MAX);
    
    Matrix_FP64 B(10, 11);
    assert (B.nvals () == 0);
    assert (B.nrows () == 10);
    assert (B.ncols () == 11);
}

void test_print () {
    Matrix_FP64 A;
    A.print ();
    
    Matrix_FP64 B;
    A.print (GxB_COMPLETE_VERBOSE);
}

void test_Matrix_setElement () {
    Matrix_FP64 A;
    A.setElement(2.0, 1, 2);
    A.print ();
        
    Matrix_INT64 B;
    B.setElement(2, 1, 2);
    B.print ();
    }

int main () {
    GrB_init (GrB_NONBLOCKING);
    
    test_init  ();
    test_print ();
    test_Matrix_setElement ();
    
    GrB_finalize ();
}
