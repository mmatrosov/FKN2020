#include <iostream>

char myconv(int i) {
    if (i <= 9) return '0' + i;
    return 'A' + i - 10;
}

int main() {
    std::cout << '\t';
    for (int i = 0; i < 16; ++i) {
        std::cout << myconv(i) << '\t';
    }
    std::cout << '\n';
    for (int first = 2; first < 8; ++first) {
        std::cout << myconv(first) << '\t';
        for (int second = 0; second < 16; ++second) {
            std::cout << static_cast<char>(first * 16 + second) << '\t';
        }
        std::cout << '\n';
    }
    return 0;
}