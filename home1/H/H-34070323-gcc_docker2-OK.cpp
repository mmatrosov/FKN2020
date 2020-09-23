#include <iostream>
#include <vector>

int count_mines(int x, int y, std::vector<std::vector<int>> &field) {
    int mines = 0;
    for (int i = -1; i <= 1; i += 1) {
        for (int j = -1; j <= 1; j += 1) {
            if (field[x + i][y + j] == -1) {
                mines += 1;
            }
        }
    }
    return mines;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> field(n + 2, std::vector<int>(m, 0));
    for (int i = 0; i < k; i += 1) {
        int x, y;
        std::cin >> x >> y;
        field[x][y] = -1;
    }
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            if (field[i][j] != -1) {
                std::cout << count_mines(i, j, field);
            } else {
                std::cout << "*";
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
    // for (int i )

    return 0;
}
