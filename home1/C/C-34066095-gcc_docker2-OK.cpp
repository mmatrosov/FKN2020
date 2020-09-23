#include <iostream>

char make_hex(int i) {
    if (i < 10) {
        return static_cast<char>(i + '0');
    }
    return static_cast<char>(i - 10 + 'A');
}

int main() {
    const int rows = 6;
    const int columns = 16;

    std::cout << "\t";
    for (int i = 0; i < columns; ++i) {
        std::cout << make_hex(i) << "\t";
    }
    std::cout << "\n";

    const int minRow = 2;
    const int maxRow = 7;

    for (int i = minRow; i <= maxRow; ++i) {
        std::cout << make_hex(i) << "\t";
        for (int j = 0; j < columns; ++j) {
            std::cout << static_cast<char>(i * columns + j) << "\t";
        }
        std::cout << "\n";
    }
}
