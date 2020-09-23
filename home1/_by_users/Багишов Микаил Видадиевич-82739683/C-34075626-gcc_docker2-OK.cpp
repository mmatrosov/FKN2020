#include <iomanip>
#include <iostream>

int main() {
    std::cout << std::uppercase << std::hex;
    std::cout << '\t';
    for (int i = 0; i < 16; ++i) {
        std::cout << i << '\t';
    }
    std::cout << std::endl;
    std::cout << std::nouppercase;
    for (int row = 2; row < 8; ++row) {
        std::cout << std::uppercase;
        std::cout << row << '\t';
        std::cout << std::nouppercase;
        for (int column = 0; column < 16; ++column) {
            std::cout << static_cast<char>(row * 16 + column) << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}