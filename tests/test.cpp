#include <GraphBLAS.hpp>
#include <cassert>

using namespace ssgbcpp;

#include "matrix.cpp"

int main () {
    GrB_init (GrB_NONBLOCKING);
    
    test_init  ();
    test_print ();
    test_Matrix_setElement ();
    
    GrB_finalize ();
}
