#include <iostream>
#include <vector>

void swap_columns(std::vector<std::vector<int>>& matrix, size_t i, size_t j) {
    size_t n = matrix.size();
    for (size_t k = 0; k < n; k++) {
        std::swap(matrix[k][i], matrix[k][j]);
    }
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
//     size_t x, y;
//     std::cin >> x >> y;
//     swap_columns(matrix, x, y);
//     for (size_t i = 0; i < n; i++) {
//         for (size_t j = 0; j < m; j++) {
//             std::cout << matrix[i][j] << ' ';
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }
