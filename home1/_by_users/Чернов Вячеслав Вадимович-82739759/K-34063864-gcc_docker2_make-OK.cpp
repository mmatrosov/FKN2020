#include <iostream>
#include <vector>

void swap_columns(std::vector<std::vector<int>>& matrix, size_t i, size_t j) {
    int rows = matrix.size();
    for (int k = 0; k < rows; ++k) {
        std::swap(matrix[k][i], matrix[k][j]);
    }
}