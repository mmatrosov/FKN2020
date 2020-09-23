#include <iostream>
#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix) {
    size_t n = matrix.size(), m = matrix[0].size();
    std::vector<std::vector<int>> ans(m, std::vector<int>(n));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            ans[j][i] = matrix[i][j];
        }
    }
    return ans;
}

// int main() {
//     size_t n, m;
//     std::cin >> n >> m;
//     std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
//     for (size_t i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             std::cin >> matrix[i][j];
//         }
//     }
//     auto ans = transpose(matrix);
//     for (size_t i = 0; i < m; i++) {
//         for (size_t j = 0; j < n; j++) {
//             std::cout << ans[i][j] << ' ';
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }
