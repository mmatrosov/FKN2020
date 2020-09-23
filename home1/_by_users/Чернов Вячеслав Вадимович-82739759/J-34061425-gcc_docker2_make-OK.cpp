#include <iostream>
#include <vector>

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int>>& matrix) {
    int max_value = matrix[0][0];
    size_t rowNum = 0, colNum = 0;

    int rows = matrix.size(), columns = matrix[0].size();
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if (max_value < matrix[i][j]) {
                max_value = matrix[i][j];
                rowNum = i;
                colNum = j;
            }
        }
    }
    return std::make_pair(rowNum, colNum);
}