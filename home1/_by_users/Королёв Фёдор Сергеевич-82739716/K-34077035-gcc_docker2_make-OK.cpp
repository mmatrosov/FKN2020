#include <iostream>
#include <vector>

void swap_columns(std::vector<std::vector<int>>& matrix, size_t i, size_t j) {
    for (int id = 0; id < matrix.size(); id++) {
        std::swap(matrix[id][j], matrix[id][i]);
    }
}