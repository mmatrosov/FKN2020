#include <iostream>
#include <string>

char hex(int x) {
    if (x < 10)
        return '0' + x;
    return 'A' + (x - 10);
}

int main() {
    for (int i = 0; i < 16; i++) {
        std::cout << '\t' << hex(i);
    }
    std::cout << '\n';
    for (int i = 1; i <= 6; i++) {
        std::cout << hex(i + 1) << '\t';
        for (int j = 0; j < 16; j++) {
            std::cout << char(16 * (i + 1) + j);
            if (j < 15)
                std::cout << '\t';
            else
                std::cout << '\n';
        }
    }
    return 0;
}