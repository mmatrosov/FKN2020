#include <vector>

void swap_columns(std::vector<std::vector<int>>& matrix, size_t i, size_t j) {
    for (int k = 0; k < matrix.size(); ++k)
        std::swap(matrix[k][i], matrix[k][j]);
}
