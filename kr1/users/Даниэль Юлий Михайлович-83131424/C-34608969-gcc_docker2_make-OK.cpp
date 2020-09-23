#include <iostream>
#include <string>
#include <vector>

std::string common_prefix(const std::vector<std::string>& words) {
    if (words.empty()) return "";
    size_t mn_len = words[0].size();
    for (const std::string& elem : words)
        mn_len = std::min(mn_len, elem.size());
    std::string ans;
    for (size_t i = 0; i < mn_len; ++i) {
        char same = words[0][i];
        for (size_t str_num = 1; str_num < words.size(); ++str_num) {
            if (words[str_num][i] != same) return ans;
        }
        ans.push_back(same);
    }
    return ans;
}