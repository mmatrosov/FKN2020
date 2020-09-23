#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    getline(std::cin, s);
    uint64_t ans = 0;
    int cnt = 0;
    for (uint8_t byte0 : s) {
        uint64_t byte = byte0;
        if (byte >> 7) {
            byte -= (1 << 7);
        }
        ans += (byte << (7 * cnt));
        cnt++;
    }
    std::cout << ans << std::endl;
    return 0;
}