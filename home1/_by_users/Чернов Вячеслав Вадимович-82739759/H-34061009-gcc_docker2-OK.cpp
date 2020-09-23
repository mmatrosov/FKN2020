#include <iostream>
#include <vector>

int count_mines(int x, int y, const std::vector<std::vector<char>>& field) {
    int rows = field.size(), columns = field[0].size();
    int minesCount = 0;
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            if (i == rows || i == -1 || j == columns || j == -1) {
                continue;
            }
            if (field[i][j] == '*') {
                minesCount++;
            }
        }
    }
    return minesCount;
}

char convert_to_char(int x) {
    return static_cast<char>(x + '0');
}

int main() {
    int rows, columns, mines;
    std::cin >> rows >> columns >> mines;

    std::vector<std::vector<char>> field;
    field.resize(rows, std::vector<char>(columns));

    for (int i = 0; i < mines; ++i) {
        int x, y;
        std::cin >> x >> y;
        field[x - 1][y - 1] = '*';
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (field[i][j] != '*') {
                int minesCount = count_mines(i, j, field);
                field[i][j] = convert_to_char(minesCount);
            }
            std::cout << field[i][j] << ' ';
        }
        std::cout << "\n";
    }
}
