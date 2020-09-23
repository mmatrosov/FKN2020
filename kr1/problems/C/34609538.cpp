#include <iostream>
#include <string>
#include <vector>

std::string common_prefix(const std::vector<std::string>& words) {
    std::string pref;
    if (words.size() == 0) {
        return pref;
    }
    pref = words[0];
    for (int i = 1; i < words.size(); ++i) {
        int n = words[i].size();
        std::string cur;
        int j = 0;
        while (j < n && j < pref.size()) {
            if (words[i][j] != pref[j]) {
                break;
            }
            cur += pref[j];
            j += 1;
        }
        pref = cur;
    }
    return pref;
}
