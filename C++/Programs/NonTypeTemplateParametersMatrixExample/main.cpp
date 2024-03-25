#include "Matrix.h"
#include <iostream>
#include <array>

int main()
{
    Matrix<int, 2, 5> matrix({
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10
    });
    std::cout << "matrix 0,0: " << matrix.get(0, 0) << std::endl;
    std::cout << "matrix 1,4: " << matrix.get(1, 4) << std::endl;

    return EXIT_SUCCESS;
}
// g++ -I include/ -o main main.cpp