#include <algorithm>
#include <string>
#include <vector>

std::string common_prefix(std::vector<std::string>& words) {
    if (words.empty())
        return "";
    std::string lcp = "";
    size_t maxLen = words[0].length();
    for (const auto& word : words)
        maxLen = std::min(maxLen, word.length());
    for (int prefLen = 0; prefLen < maxLen; prefLen++) {
        lcp += words[0][prefLen];
        for (const auto& word : words)
            if (word[prefLen] != lcp[prefLen]) {
                lcp.pop_back();
                return lcp;
            }
    }
    return lcp;
}