#include <iostream>
#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix) {
    size_t matrixRowCount = matrix.size();
    size_t matrixColumnCount = matrix[0].size();
    std::vector<std::vector<int>> transposision(matrixColumnCount);
    for (std::vector<int>& row : transposision)
        row.resize(matrixRowCount);
    for (size_t i = 0; i < matrixRowCount; i++)
        for (size_t j = 0; j < matrixColumnCount; j++)
            transposision[j][i] = matrix[i][j];
    return transposision;
}
