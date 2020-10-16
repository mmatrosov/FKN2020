#include <iostream>
#include <string>
#include "address.h"

int main() {
    std::string line;
    Address* address = new Address();
    while (getline(std::cin, line)) {
        try {
            Parse(line, address);
        } catch (...) {
            std::cout << "exception\n";
            continue;
        }
        try {
            Unify(address);
        } catch (...) {
            std::cout << "exception\n";
            continue;
        }
        std::cout << Format(*address) << "\n";
    }

    delete address;
}
