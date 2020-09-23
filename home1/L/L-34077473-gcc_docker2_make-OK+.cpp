#include <iostream>
#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector <int> > ans;
    if (matrix.empty()) {
        return ans;
    }
    ans.resize(matrix[0].size());
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            ans[i].push_back(matrix[j][i]);
        }
    }
    return ans;
}