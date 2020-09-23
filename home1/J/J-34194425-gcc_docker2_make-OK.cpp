#include <iostream>
#include <utility>
#include <vector>

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int>> &matrix) {
        std::pair<size_t, size_t> index = {0, 0};
        long long current_max = -1e10;
        for (size_t i = 0; i < matrix.size(); ++i) {
                for (size_t j = 0; j < matrix[i].size(); ++j) {
                        if (current_max < matrix[i][j]) {
                                current_max = matrix[i][j];
                                index = {i, j};
                        }
                }
        }
        return index;
}
