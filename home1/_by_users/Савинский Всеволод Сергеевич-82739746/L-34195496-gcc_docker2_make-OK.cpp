#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix) {
        std::vector<std::vector<int>> trans(matrix[0].size(), std::vector<int>(matrix.size()));
        for (size_t i = 0; i < matrix.size(); ++i) {
                for (size_t j = 0; j < matrix[i].size(); ++j) {
                        trans[j][i] = matrix[i][j];
                }
        }
        return trans;
}
