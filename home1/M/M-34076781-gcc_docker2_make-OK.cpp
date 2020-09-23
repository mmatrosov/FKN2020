#include <iostream>
#include <vector>

std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::string result;
    for (const auto &i : tokens) {
        result += i;
        result += delimiter;
    }
    result.pop_back();
    return result;
}
