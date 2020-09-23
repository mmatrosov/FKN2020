#include <iostream>
#include <vector>

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int>>& matrix) {
    std::pair <size_t, size_t> ans = {0, 0};
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[ans.first][ans.second] < matrix[i][j]) {
                ans = {i, j};
            }
        }
    }
    return ans;
}