#include <string_view>
#include <string>
#include <vector>

std::string common_prefix(std::vector<std::string> const &words) {
    // special case
    if (words.empty()) {
        return "";
    }
    std::string_view cur = words[0];
    for (std::string const &word : words) {
        size_t cnt = 0;
        while (cur[cnt] == word[cnt] && cnt < cur.size()) {
            ++cnt;
        }
        cur = cur.substr(0, cnt);
    }
    return std::string(cur);
}