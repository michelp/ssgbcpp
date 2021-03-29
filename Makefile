test :
		g++-8 -O3 test.cpp -Iinclude -lgraphblas -o test && ./test && rm test
