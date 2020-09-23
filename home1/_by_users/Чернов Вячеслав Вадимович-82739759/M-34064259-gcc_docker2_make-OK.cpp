#include <iostream>
#include <vector>

std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::string result = "";
    int length = tokens.size();
    for (int i = 0; i < length; ++i) {
        result += tokens[i];
        if (i < length - 1) {
            result += delimiter;
        }
    }
    return result;
}
