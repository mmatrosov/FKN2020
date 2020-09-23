#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int op[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> op[i][j];
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            for (int c = 0; c < n; ++c) {
                if (op[op[a][b]][c] != op[a][op[b][c]]) {
                    std::cout << "NO";
                    return 0;
                }
            }
        }
    }
    std::cout << "YES";
    return 0;
}
