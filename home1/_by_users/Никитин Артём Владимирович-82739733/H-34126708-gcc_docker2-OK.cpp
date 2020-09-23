#include <iostream>

int main() {
    int rowCount, columnCount;
    std::cin >> rowCount >> columnCount;
    int mines;
    std::cin >> mines;
    bool minefield[rowCount][columnCount];
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < columnCount; col++) {
            minefield[row][col] = false;
        }
    }
    while (mines--) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        minefield[x][y] = true;
    }
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < columnCount; col++) {
            if (minefield[row][col]) {
                std::cout << "* ";
            } else {
                int minesCount = 0;
                for (int i = std::max(0, row - 1); i < std::min(rowCount, row + 2); i++) {
                    for (int j = std::max(0, col - 1); j < std::min(columnCount, col + 2); j++) {
                        if (i != row || j != col) {
                            minesCount += minefield[i][j];
                        }
                    }
                }
                std::cout << minesCount << ' ';
            }
        }
        std::cout << '\n';
    }
}
