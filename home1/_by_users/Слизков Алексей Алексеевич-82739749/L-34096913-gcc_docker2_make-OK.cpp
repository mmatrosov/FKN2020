#include <iostream>
#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    std::vector<std::vector<int>> result(m, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            result[j][i] = matrix[i][j];
    return result;
}
