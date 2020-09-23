#include <iostream>
#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size(), columns = matrix[0].size();
    std::vector<std::vector<int>> transposeMatrix;
    transposeMatrix.resize(columns, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            transposeMatrix[j][i] = matrix[i][j];
        }
    }
    return transposeMatrix;
}
