#include <iostream>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> field(n, std::vector<int>(m, 0));
    std::vector<std::vector<bool>> mines(n, std::vector<bool>(m, 0));

    for (int i = 0; i < k; ++i) {
        int r, c;
        std::cin >> r >> c;
        r--, c--;
        mines[r][c] = true;
        for (int dc = -1; dc <= 1; ++dc) {
            for (int dr = -1; dr <= 1; ++dr) {
                if ((0 <= c + dc && c + dc < m) &&
                    (0 <= r + dr && r + dr < n)) {
                    field[r + dr][c + dc]++;
                }
            }
        }
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (mines[r][c]) {
                std::cout << "* ";
            } else {
                std::cout << field[r][c] << ' ';
            }
        }
        std::cout << '\n';
    }
    return 0;
}