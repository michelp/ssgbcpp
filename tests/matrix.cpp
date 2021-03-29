
void FN(test_init_) () {
    FN(Matrix_) A;
    assert (A.nvals () == 0);
    assert (A.ncols () == GxB_INDEX_MAX);
    assert (A.nrows () == GxB_INDEX_MAX);
    
    FN(Matrix_) B(10, 11);
    assert (B.nvals () == 0);
    assert (B.nrows () == 10);
    assert (B.ncols () == 11);
}

void FN(test_print_) () {
    FN(Matrix_) A;
    A.print ();
    
    FN(Matrix_) B;
    A.print (GxB_COMPLETE_VERBOSE);
}

void FN(test_Matrix_setElement_) () {
    FN(Matrix_) A;
    A.setElement(ANSWER, 1, 2);
    A.print ();
    }

void FN(test_) () {
    FN(test_init_)  ();
    FN(test_print_) ();
    FN(test_Matrix_setElement_) ();
}
