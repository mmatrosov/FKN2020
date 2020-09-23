#include <iostream>
#include <vector>

void swap_columns(std::vector<std::vector<int>>& matrix, size_t i, size_t j) {
    int rowCount = matrix.size();
    for (size_t row = 0; row < rowCount; row++) {
        std::swap(matrix[row][i], matrix[row][j]);
    }
}
