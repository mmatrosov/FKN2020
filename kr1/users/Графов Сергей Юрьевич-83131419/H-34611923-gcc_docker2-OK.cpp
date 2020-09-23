#include<algorithm>
#include<iostream>
#include<string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    uint64_t ans = 0;
    reverse(s.begin(), s.end());
    for (uint8_t j : s) {
        uint64_t i = j;
        ans = (ans << 7) + (i % (1 << 7));
    }
    std::cout << ans;
}