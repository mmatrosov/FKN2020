#include <iostream>
#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<std::vector<int>> trans(m, std::vector<int>(n));
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            trans[j][i] = matrix[i][j];
        }
    }
    return trans;
}
