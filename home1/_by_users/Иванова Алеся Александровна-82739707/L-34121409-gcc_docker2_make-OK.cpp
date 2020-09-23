#include <iostream>
#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<std::vector<int>> new_matrix(m);
    for (int i = 0; i < m; ++i) {
        new_matrix[i].resize(n);
        for (int e = 0; e < n; ++e) {
            new_matrix[i][e] = matrix[e][i];
        }
    }
    return new_matrix;
}
