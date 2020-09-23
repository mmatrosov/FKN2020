#include <string>
#include <vector>
std::vector<std::vector<int>>
transpose(std::vector<std::vector<int>> const &matrix) {
    size_t const n = matrix.size();
    size_t const m = matrix[0].size();
    std::vector<std::vector<int>> transposed(m, std::vector<int>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}