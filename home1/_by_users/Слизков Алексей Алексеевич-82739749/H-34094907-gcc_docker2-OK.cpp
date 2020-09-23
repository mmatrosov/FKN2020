#include <iostream>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    bool a[n][m];
    for (int i = 0; i < n; ++i)
        std::fill(a[i], a[i] + m, false);
    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;
        a[--x][--y] = true;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j]) {
                std::cout << "* ";
                continue;
            }
            int cnt = 0;
            for (int k = -1; k <= 1; ++k)
                for (int l = -1; l <= 1; ++l)
                    cnt += i + k >= 0 && i + k < n && j + l >= 0 && j + l < m && a[i+k][j+l];
            std::cout << cnt << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
