#include <algorithm>
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
    TicTacToe(size_t n, size_t k): N(n), K(k), CurrentPlayer(1) {
        Table.resize(N);
        for (size_t i = 0; i != N; ++i)
            Table[i].resize(N, 0);
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
        bool wins = CheckRow(i, j)
            || CheckColumn(i, j)
            || CheckDiagonal1(i, j)
            || CheckDiagonal2(i, j);
        return wins;
    }

private:
    bool CheckRow(size_t i, size_t j) const {
        size_t d1 = 0;
        while (d1 <= j && Table[i][j-d1] == Table[i][j])
            ++d1;
        size_t d2 = 0;
        while (j + d2 < N && Table[i][j+d2] == Table[i][j])
            ++d2;
        return d1 + d2 > K;
    }

    bool CheckColumn(size_t i, size_t j) const {
        size_t d1 = 0;
        while (d1 <= i && Table[i-d1][j] == Table[i][j])
            ++d1;
        size_t d2 = 0;
        while (i + d2 < N && Table[i+d2][j] == Table[i][j])
            ++d2;
        return d1 + d2 > K;
    }

    bool CheckDiagonal1(size_t i, size_t j) const {
        size_t d1 = 0;
        size_t dmin = std::min(i, j);
        while (d1 <= dmin && Table[i - d1][j - d1] == Table[i][j])
            ++d1;
        size_t d2 = 0;
        size_t dmax = std::max(i, j);
        while (d2 + dmax < N && Table[i + d2][j + d2] == Table[i][j])
            ++d2;
        return d1 + d2 > K;
    }

    bool CheckDiagonal2(size_t i, size_t j) const {
        size_t d1 = 0;
        while (d1 <= i && j + d1 < N && Table[i - d1][j + d1] == Table[i][j])
            ++d1;
        size_t d2 = 0;
        while (i + d2 < N && d2 <= j && Table[i + d2][j - d2] == Table[i][j])
            ++d2;
        return d1 + d2 > K;
    }
};

std::ostream& operator << (std::ostream& out, TicTacToe& field) {
    for (size_t i = 0; i != field.N; ++i) {
        for (size_t j = 0; j != field.N; ++j) {
            switch (field(i, j)) {
            case 0:
                std::cout << '.';
                break;
            case 1:
                std::cout << 'X';
                break;
            case 2:
                std::cout << 'O';
            }
        }
        std::cout << "\n";
    }
    return out;
}