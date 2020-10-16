#include <iostream>
#include <string>

#include "address.h"

int main() {
    std::string line;
    while (getline(std::cin, line)) {
        Address* address = new Address();
        try {
            Parse(line, address);
            Unify(address);
            std::cout << Format(*address) << "\n";
        } catch (...) {
            std::cout << "exception" << "\n";
        }
        delete address;
    }
}