#include <iostream>
#include <string>
#include <vector>

std::string common_prefix(const std::vector<std::string>& words) {
    if (words.empty())
        return "";
    int answer = 0;
    while (answer < words[0].size()) {
        char c = words[0][answer];
        bool is_equal = true;
        for (const auto& word : words) {
            if (answer >= word.size() || word[answer] != c) {
                is_equal = false;
                break;
            }
        }
        if (is_equal)
            answer++;
        else
            break;
    }
    return words[0].substr(0, answer);
}