#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string common_prefix(const std::vector<std::string>& words) {
    if (words.empty()) {
        return "";
    }
    std::string result = words[0];
    for (const auto& word : words) {
        int commonLen = 0;
        size_t length = std::min(result.size(), word.size());
        for (size_t i = 0; i < length; ++i) {
            if (result[i] != word[i]) {
                commonLen = i;
                break;
            }
            if (i + 1 == length) {
                commonLen = length;
            }
        }
        result.erase(result.begin() + commonLen, result.end());
    }
    return result;
}
