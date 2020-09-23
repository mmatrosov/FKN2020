#include <iostream>
#include <string>
#include <vector>

int main() {
    int num;
    std::string ans;
    while (std::cin >> num) {
        if (num < 128) {
            ans += static_cast<char> (num);
            continue;
        }
        std::vector <int> bytes;
        int baf = 0, st = 64;
        while (num >= st) {
            bytes.push_back(-128 + (num % 64));
            num /= 64;
            baf += st;
            st /= 2;
        }
        bytes.push_back(-128 + baf + num);
        while (!bytes.empty()) {
            ans += static_cast<char> (bytes.back());
            bytes.pop_back();
        }
    }
    std::cout << ans << '\n';
}