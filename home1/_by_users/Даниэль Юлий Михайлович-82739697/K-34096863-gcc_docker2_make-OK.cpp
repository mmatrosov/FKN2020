#include <vector>

void swap_columns(std::vector<std::vector<int>>& matrix, size_t i, size_t j) {
    for (int r = 0; r < matrix.size(); ++r) {
        std::swap(matrix[r][i], matrix[r][j]);
    }
}