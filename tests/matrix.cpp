


void FN(test_init_) () {
    Matrix<C> A(T);
    assert (A.nvals () == 0);
    assert (A.ncols () == GxB_INDEX_MAX);
    assert (A.nrows () == GxB_INDEX_MAX);
    
    Matrix<C> B(T, 10, 11);
    assert (B.nvals () == 0);
    assert (B.nrows () == 10);
    assert (B.ncols () == 11);
}

void FN(test_print_) () {
    Matrix<C> A(T);
    A.print ();
    
    Matrix<C> B(T);
    B.print (GxB_COMPLETE_VERBOSE);
}

void FN(test_Matrix_setElement_) () {
    Matrix<C> A(T);
    A.setElement(ANSWER, 1, 2);
    assert (A.nvals () == 1);
    }

void FN(test_) () {
    FN(test_init_)  ();
    FN(test_print_) ();
    FN(test_Matrix_setElement_) ();
}
