#include <vector>
#include <climits>

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int>>& matrix) {
    int max = INT_MIN;
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j < matrix[i].size(); ++j)
            max = std::max(max, matrix[i][j]);
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j < matrix[i].size(); ++j)
            if (matrix[i][j] == max)
                return {i, j};
}
