#include <iostream>
#include <vector>

void print_field() {
    int rows, columns, cnt_bombs;
    std::cin >> rows >> columns >> cnt_bombs;
    std::vector<std::vector<bool> > bomb(rows);
    for (int i = 0; i < rows; ++i) {
        bomb[i].resize(columns, 0);
    }
    for (int i = 0; i < cnt_bombs; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        bomb[x][y] = 1;
    }
    for (int i = 0; i < rows; ++i) {
        for (int e = 0; e < columns; ++e) {
            if (bomb[i][e]) {
                std::cout << "* ";
                continue;
            }
            int cnt = 0;
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = e - 1; y <= e + 1; ++y) {
                    if ((x >= 0) && (x < rows) && (y >= 0) && (y < columns)) {
                        cnt += bomb[x][y];
                    }
                }
            }
            std::cout << cnt << " ";
        }
        std::cout << "\n";
    }
}

signed main() {
    print_field();
}
