#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

std::string common_prefix(std::vector<std::string>& words) {
    if (words.size() == 0)
        return "";
    if (words.size() == 1)
        return words[0];
    std::sort(words.begin(), words.end());
    size_t ans_ind = 0;
    size_t sz = words.size();
    std::string ans = "";
    while (ans_ind < std::min(words[0].size(), words[sz - 1].size())) {
        if (words[0][ans_ind] != words[sz - 1][ans_ind])
            break;
        else
            ans = ans + words[0][ans_ind];
        ans_ind++;
    }
    return ans;
}
