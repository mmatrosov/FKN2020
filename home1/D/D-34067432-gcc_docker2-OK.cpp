#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::string keys, in;
    getline(std::cin, keys);
    std::vector <std::string> text;
    while (getline(std::cin, in)) {
        text.push_back(in);
    }
    if (keys.find("-l") != std::string::npos) {
        std::cout << text.size() << ' ';
    }
    if (keys.find("-w") != std::string::npos) {
        int ans = 0;
        for (const auto &s : text) {
            for (int i = 0; i < s.size(); i += 1) {
                if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                    ans += 1;
                }
            }
        }
        std::cout << ans << ' ';
    }
    if ((keys.find("-m") != std::string::npos)) {
        int ans = 0;
        for (const auto &s : text) {
            ans += s.size() + 1;
        }
        std::cout << ans << ' ';
    }
    if ((keys.find("-L") != std::string::npos)) {
        int ans = 0;
        for (const auto &s : text) {
            ans = std::max(ans, static_cast<int> (s.size()));
        }
        std::cout << ans << '\n';
    }
}