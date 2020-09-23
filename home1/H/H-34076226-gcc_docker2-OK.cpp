#include <iostream>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector <std::vector <bool> > isBomb(n, std::vector <bool> (m));
    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        isBomb[x - 1][y - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isBomb[i][j]) {
                std::cout << "* ";
                continue;
            }
            int cnt = 0;
            if (i && j && isBomb[i - 1][j - 1]) {
                cnt++;
            }
            if (i && isBomb[i - 1][j]) {
                cnt++;
            }
            if (i && j + 1 < m && isBomb[i - 1][j + 1]) {
                cnt++;
            }
            if (j && isBomb[i][j - 1]) {
                cnt++;
            }
            if (j + 1 < m && isBomb[i][j + 1]) {
                cnt++;
            }
            if (i + 1 < n && j && isBomb[i + 1][j - 1]) {
                cnt++;
            }
            if (i + 1 < n && isBomb[i + 1][j]) {
                cnt++;
            }
            if (i + 1 < n && j + 1 < m && isBomb[i + 1][j + 1]) {
                cnt++;
            }
            std::cout << cnt << ' ';
        }
        std::cout << '\n';
    }
}