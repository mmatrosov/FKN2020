#include <string>
#include <vector>

std::string common_prefix(const std::vector<std::string>& words) {
    std::string res;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i == 0) {
            res = words[i];
            continue;
        }
        for (int j = 0; j < res.size(); ++j) {
            if (j == words[i].size() || words[i][j] != res[j]) {
                res.erase(res.begin() + j, res.end());
                break;
            }
        }
    }
    return res;
}
