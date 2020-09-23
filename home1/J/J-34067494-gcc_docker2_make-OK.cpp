#include <cstdint>
#include <utility>
#include <vector>

std::pair<size_t, size_t>
max_element(std::vector<std::vector<int>> const &matrix) {
    size_t opt_i = 0;
    size_t opt_j = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] > matrix[opt_i][opt_j]) {
                opt_i = i;
                opt_j = j;
            }
        }
    }
    return {opt_i, opt_j};
}
