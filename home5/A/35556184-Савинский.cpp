#include <iostream>
#include <string>

#include "address.h"

int main() {
    std::string line;
    Address* address = new Address;
    while (getline(std::cin, line)) {
        try {
            Parse(line, address);
            Unify(address);
            std::cout << Format(*address) << "\n";
        } catch (...) {
            std::cout << "exception\n";
        }
    }
    delete address;
}
