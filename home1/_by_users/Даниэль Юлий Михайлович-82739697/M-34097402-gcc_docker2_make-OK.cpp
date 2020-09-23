#include <string>
#include <vector>

std::string join(const std::vector<std::string>& tokens, char delimiter) {
    if (tokens.empty()) return "";
    std::string ans = tokens[0];
    for (int i = 1; i < tokens.size(); ++i) {
        ans += delimiter + tokens[i];
    }
    return ans;
}