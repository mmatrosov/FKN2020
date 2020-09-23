#include <iostream>
#include <vector>

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int>>& matrix) {
    int max_elem = matrix[0][0];
    int x = 0, y = 0;
    for (int i = 0; i < matrix.size(); ++i)
        for (int e = 0; e < matrix[i].size(); ++e) {
            if (matrix[i][e] > max_elem) {
                max_elem = matrix[i][e];
                x = i, y = e;
            }
        }
    return {x, y};
}
