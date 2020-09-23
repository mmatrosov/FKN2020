#include <iostream>
#include <string>

int main() {
    std::string pass;
    std::getline(std::cin, pass);

    int smallPresent = 0, bigPresent = 0, numPresent = 0, otherPresent = 0;


    if (pass.size() < 8 || 14 < pass.size()) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    for (char symbol : pass) {
        if (symbol < 33 || 126 < symbol) {
            std::cout << "NO" << std::endl;
            return 0;
        }

        if (std::isalpha(symbol)) {
            if (std::islower(symbol)) {
                smallPresent = 1;
            } else {
                bigPresent = 1;
            }
        } else if (std::isdigit(symbol)) {
            numPresent = 1;
        } else {
            otherPresent = 1;
        }
    }

    if (smallPresent + bigPresent + numPresent + otherPresent >= 3) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}