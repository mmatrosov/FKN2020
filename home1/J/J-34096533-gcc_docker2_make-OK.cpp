#include <utility>
#include <vector>

std::pair<std::size_t, std::size_t> max_element(const std::vector<std::vector<int>>& matrix) {
    std::size_t mr = 0, mc = 0;
    for (std::size_t r = 0; r < matrix.size(); ++r) {
        for (std::size_t c = 0; c < matrix[0].size(); ++c) {
            if (matrix[r][c] > matrix[mr][mc]) {
                mr = r, mc = c;
            }
        }
    }
    return {mr, mc};
}