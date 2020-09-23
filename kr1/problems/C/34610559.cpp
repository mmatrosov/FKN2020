#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

std::string common_prefix(const std::vector<std::string>& words) {
    if (words.size() == 0) {
        return "";
    }
    int ansl = words[0].size();
    int l;
    for (int i = 1; i < words.size(); ++i) {
        ansl = std::min(ansl, static_cast<int>(words[i].size()));
        l = std::min(ansl, static_cast<int>(std::min(words[i].size(), words[i - 1].size())));
        for (int j = 0; j < l; ++j) {
            if (words[i - 1][j] != words[i][j]) {
                ansl = std::min(ansl, j);
                break;
            }
        }
    }
    return words[0].substr(0, ansl);
}