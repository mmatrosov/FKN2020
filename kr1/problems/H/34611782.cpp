#include <iostream>
#include <string>

int main() {
    std::string s;
    getline(std::cin, s);
    uint64_t result = 0;
    int shift = 0;
    for (uint8_t c : s) {
        if ((c & (1 << 7)) > 0) {
            c ^= 1 << 7;
        }
        result += static_cast<uint64_t>(c) << shift;
        shift += 7;
    }
    std::cout << result;
}
