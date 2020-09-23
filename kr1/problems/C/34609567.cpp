#include <iostream>
#include <string>
#include <vector>

std::string common_prefix(const std::vector<std::string>& words) {
    int minLen = (words.empty() ? 0 : words[0].length());
    for (const std::string& word : words)
        minLen = std::min(minLen, static_cast<int>(word.length()));
    std::string answer = "";
    for (int i = 0; i < minLen; i++) {
        bool areTheSame = true;
        char curChar = words[0][i];
        for (const std::string& word : words) {
            areTheSame &= (word[i] == curChar);
        }
        if (!areTheSame) {
            break;
        } else {
            answer += curChar;
        }
    }
    return answer;
}