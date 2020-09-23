#include <iostream>
#include <vector>

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int>>& matrix) {
    int ans_row = 0, ans_column = 0;
    for (int i = 0; i < matrix.size(); i += 1) {
        for (int j = 0; j < matrix[i].size(); j += 1) {
            if (matrix[i][j] > matrix[ans_row][ans_column]) {
                ans_row = i;
                ans_column = j;
            }
        }
    }
    return {ans_row, ans_column};
}
