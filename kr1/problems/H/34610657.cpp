#include <iostream>
#include <string>

signed main() {
    std::string s;
    getline(std::cin, s);
    uint64_t answer = 0;
    uint64_t len = 1;
    for (unsigned char byte : s) {
        if (byte & (1 << 7))
            byte ^= (1 << 7);
        answer += byte * len;
        len <<= 7;
    }
    std::cout << answer;
}
