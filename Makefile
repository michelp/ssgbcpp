test :
		g++-8 -std=c++17 -O3 tests/test.cpp -Iinclude -lgraphblas -o tests/test && ./tests/test && rm tests/test
