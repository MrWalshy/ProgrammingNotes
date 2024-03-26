#ifndef MATRIX_H
#define MATRIX_H
#include "array"
#include <cstdlib>

template<int ROWS, int COLUMNS, typename T = int>
class Matrix
{
    // stored as row_1, row_2, ..., row_COLUMNS
    std::array<T, ROWS * COLUMNS> data;

    public:
        Matrix(): data({}) {}
        Matrix(std::array<T, ROWS*COLUMNS> initialData): data(initialData) {}

        T& get(int row, int column)
        {
            if (row >= ROWS || column >= COLUMNS)
            {
                std::abort(); // causes abnormal program termination, from <cstdlib>
            }
            return data[row * COLUMNS + column];
        }
};
#endif