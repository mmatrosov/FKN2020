#include <iostream>
#include <vector>

class TicTacToe {
public:
    const size_t N;  // размер игрового поля
    const size_t K;  // сколько фишек нужно поставить в ряд, чтобы выиграть

private:
    // 0 - пусто, 1 - фишка первого игрока (крестик), 2 - фишка второго игрока (нолик)
    std::vector<std::vector<int>> Table;

    // номер текущего игрока (1 или 2)
    int CurrentPlayer;

public:
    TicTacToe(size_t n, size_t k) : N(n), K(k), CurrentPlayer(1) {
        Table.resize(N);
        for (size_t i = 0; i != N; ++i)
            Table[i].resize(N);
    }

    int operator()(size_t i, size_t j) const {
        return Table[i][j];
    }

    int GetCurrentPlayer() const {
        return CurrentPlayer;
    }

    bool Set(size_t i, size_t j) {  // возвращает true, если ход завершился выигрышем
        Table[i][j] = CurrentPlayer;
        CurrentPlayer = CurrentPlayer % 2 + 1;
        bool wins = CheckDirection(i, j, 0) || CheckDirection(i, j, 1) || CheckDirection(i, j, 2) ||
                    CheckDirection(i, j, 3);
        return wins;
    }

private:
    bool CheckDirection(size_t i, size_t j, size_t direction) const {
        static const int kRowOffset[4] = {0, -1, -1, -1};
        static const int kColumnOffset[4] = {1, 1, 0, -1};

        int row_offset = kRowOffset[direction];
        int col_offset = kColumnOffset[direction];

        size_t same_to_the_left = 0;
        {
            int cur_i = i;
            int cur_j = j;
            while (true) {
                cur_i -= row_offset;
                cur_j -= col_offset;
                if (cur_i < 0 || cur_j < 0 || cur_i >= N || cur_j >= N ||
                    Table[cur_i][cur_j] != Table[i][j]) {
                    break;
                }
                ++same_to_the_left;
            }
        }
        size_t same_to_the_right = 0;
        {
            int cur_i = i;
            int cur_j = j;
            while (true) {
                cur_i += row_offset;
                cur_j += col_offset;
                if (cur_i >= N || cur_j >= N || cur_i >= N || cur_j >= N ||
                    Table[cur_i][cur_j] != Table[i][j]) {
                    break;
                }
                ++same_to_the_right;
            }
        }
        size_t total_same = same_to_the_left + same_to_the_right + 1;
        return total_same >= K;
    }
};

std::ostream& operator<<(std::ostream& out, TicTacToe const& field) {
    for (size_t i = 0; i != field.N; ++i) {
        for (size_t j = 0; j != field.N; ++j) {
            switch (field(i, j)) {
                case 0:
                    out << '.';
                    break;
                case 1:
                    out << 'X';
                    break;
                case 2:
                    out << 'O';
            }
        }
        out << '\n';
    }
    return out;
}