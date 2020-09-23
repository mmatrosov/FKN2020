#include <iostream>
#include <vector>
#include <string>

std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::string ans = "";
    for (int i = 0; i < tokens.size(); i++) {
        ans += tokens[i];
        if (i + 1 < tokens.size()) {
            ans += delimiter;
        }
    }
    return ans;
}