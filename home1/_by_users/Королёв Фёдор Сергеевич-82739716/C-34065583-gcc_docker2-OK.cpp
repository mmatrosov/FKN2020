#include <iostream>

char hexUp(int val) {
    if (val < 10) {
        return '0' + val;
    }
    return 'A' + (val - 10);
}

int main() {
    for (int i = 0; i < 16; i += 1) {
        std::cout << '\t' << hexUp(i);
    }
    std::cout << "\t\n";
    for (int i = 0; i < 6; i += 1) {
        std::cout << i + 2;
        for (int j = 0; j < 16; ++j) {
            std::cout << '\t' << static_cast<char> ((i + 2) * 16 + j);
        }
        std::cout << "\t\n";
    }
}