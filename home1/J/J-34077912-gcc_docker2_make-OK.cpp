#include <iostream>
#include <vector>

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int>>& matrix) {
    size_t mx_x = -1, mx_y = -1;
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if (mx_x == -1 || matrix[mx_x][mx_y] < matrix[i][j]) {
                mx_x = i, mx_y = j;
            }
        }
    }
    return {mx_x, mx_y};
}

// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int> > a(n, vector<int>(m));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> a[i][j];
//         }
//     }
//     auto [x, y] = max_element(a);
//     cout << x << ' ' << y << endl;
//     return 0;
// }
