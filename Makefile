test :
		g++-8 -O3 test.cpp -I. -lgraphblas -o test && ./test && rm test
