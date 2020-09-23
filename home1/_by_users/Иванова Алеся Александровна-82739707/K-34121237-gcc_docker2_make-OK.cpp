#include <iostream>
#include <vector>

void swap_columns(std::vector<std::vector<int>>& matrix, size_t i, size_t j) {
    for (int row = 0; row < matrix.size(); ++row) {
        int cur = matrix[row][i];
        matrix[row][i] = matrix[row][j];
        matrix[row][j] = cur;
    }
}
