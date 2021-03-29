#include <GraphBLAS.hpp>
#include <cassert>

using namespace ssgbcpp;

#include "matrix.cpp"

int main () {
    GrB_init (GrB_NONBLOCKING);
    test_FP64();
    GrB_finalize ();
}
