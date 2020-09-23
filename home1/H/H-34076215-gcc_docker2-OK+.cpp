#include <iostream>
#include <vector>

char const EMPTY = '.';
char const BOMB = '*';

int main() {
    size_t rows, columns, bomb_count;
    std::cin >> rows >> columns >> bomb_count;
    std::vector<std::vector<char>> field(rows,
                                         std::vector<char>(columns, EMPTY));
    for (size_t _i = 0; _i < bomb_count; ++_i) {
        size_t i, j;
        std::cin >> i >> j;
        --i;
        --j;
        field[i][j] = BOMB;
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if (field[i][j] == BOMB) {
                continue;
            }
            int bombs_around = 0;
            int const di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
            int const dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};
            for (size_t k = 0; k < 8; ++k) {
                size_t const ni = i + di[k];
                size_t const nj = j + dj[k];
                if (ni >= rows || nj >= columns) {
                    continue;
                }
                if (field[ni][nj] == BOMB) {
                    ++bombs_around;
                }
            }
            field[i][j] = '0' + bombs_around;
        }
    }
    for (auto const &line : field) {
        for (char const ch : line) {
            std::cout << ch << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}