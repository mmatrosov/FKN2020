#include <iostream>
#include <vector>

std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::string ans = "";
    for (const auto& s : tokens) {
        ans += s;
        ans += delimiter;
    }
    ans.pop_back();
    return ans;
}
