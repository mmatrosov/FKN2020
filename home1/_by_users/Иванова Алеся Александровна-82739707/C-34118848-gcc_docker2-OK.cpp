#include <iostream>

void print_symbols() {
    std::cout << "\t";
    for (int e = 0; e < 10; e++) {
        std::cout << e << "\t";
    }
    for (char e = 'A'; e <= 'F'; e++) {
        std::cout << e << "\t";
    }
    std::cout << "\n";
    for (int i = 2; i < 8; i++) {
        std::cout << i << "\t";
        for (int e = 0; e < 16; e++) {
            char symbol = i * 16 + e;
            std::cout << symbol << "\t";
        }
        std::cout << "\n";
    }
}

signed main() {
    print_symbols();
}
