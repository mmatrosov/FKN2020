#include <iostream>
#include <string>
#include <vector>

std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::string result = "";
    for (const std::string& word : tokens) {
        result += word + delimiter;
    }
    result.pop_back();
    return result;
}
