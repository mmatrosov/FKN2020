#include <iostream>

int main() {
    std::cout << '\t';
    for (int i = 0; i < 16; i++) {
        if (i < 10) {
            std::cout << static_cast<char>('0' + i) << '\t';
        } else {
            std::cout << static_cast<char>('A' + i - 10) << '\t';
        }
    }
    std::cout << '\n';
    for (int i = 32; i <= 112; i += 16) {
        std::cout << (i >> 4) << '\t';
        for (int j = i; j < i + 16; j++) {
            std::cout << static_cast<char>(j) << '\t';
        }
        std::cout << '\n';
    }
}