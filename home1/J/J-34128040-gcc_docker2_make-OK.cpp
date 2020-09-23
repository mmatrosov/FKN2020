#include <iostream>
#include <vector>

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int>>& matrix) {
    int maximum = matrix[0][0];
    size_t row = 0, col = 0;
    size_t rowCount = matrix.size();
    size_t columnCount = matrix[0].size();
    for (size_t i = 0; i < rowCount; i++) {
        for (size_t j = 0; j < columnCount; j++) {
            if (matrix[i][j] > maximum) {
                maximum = matrix[i][j];
                row = i;
                col = j;
            }
        }
    }
    return { row, col };
}
