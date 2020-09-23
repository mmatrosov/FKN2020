#include <iostream>

int main() {
    std::cout << "\t";
    for (int i = 0; i < 10; ++i) {
        std::cout << i << "\t";
    }
    for (int i = 10; i < 16; ++i) {
        std::cout << char(i - 10 + 'A') << "\t";
    }
    std::cout << "\n";
    int cnt = 32;
    for (int i = 2; i < 8; ++i) {
        std::cout << i << "\t";
        for (int j = 0; j < 16; ++j) {
            std::cout << char(cnt) << "\t";
            cnt += 1;
        }
        std::cout << "\n";
    }


    return 0;
}
