#include <iostream>
#include <string>

int main() {
    std::string s;
    std::string ans;
    for (int i = 0; i < 26; ++i) ans += 'a' + i;
    while (std::cin >> s) {
        for (int i = 0; i < ans.size(); ++i) {
            if (s.find(ans[i]) == std::string::npos) {
                ans.erase(ans.begin() + i);
                --i;
            }
        }
    }
    std::cout << ans;
}