#include <iostream>

const int MAXPOW = 8;
const int SUFLEN = 6;

void print_bin(int cur) {
    for (int i = 3 * MAXPOW - 1; i >= 0; --i) {
        std::cout << ((cur & (1 << i)) != 0);
    }
    std::cout << std::endl;
}

int my_cast(char symbol) {
    return static_cast<int>(symbol) & ((1 << MAXPOW) - 1);
}

int main() {
    int byte;
    char symbol;
    std::string res, line;
    std::getline(std::cin, line);
    for (int i = 0; i < line.size(); ++i) {
        symbol = line[i];
        int cur = 0, num_ones = 0;
        byte = my_cast(symbol);

        for (int pow = MAXPOW - 1; pow >= 0; --pow) {
            if ((byte | (1 << pow)) != byte) break;
            num_ones++;
            byte -= 1 << pow;
        }
        cur += byte;

        for (int j = 0; j < num_ones - 1; ++j) {
            ++i;
            symbol = line[i];
            byte = my_cast(symbol);

            cur = (cur << SUFLEN) + byte - (1 << (MAXPOW - 1));
        }
        std::cout << cur << ' ';
    }
    std::cout << std::endl;
    return 0;
}