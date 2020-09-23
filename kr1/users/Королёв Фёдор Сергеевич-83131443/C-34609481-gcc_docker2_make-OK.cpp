#include <string>
#include <vector>

std::string common_prefix(const std::vector<std::string>& words) {
    if (words.empty()) {
        return "";
    }
    int ans = words[0].size();
    for (int i = 1; i < words.size(); ++i) {
        int wasans = ans;
        ans = 0;
        while (ans < words[0].size() && ans < words[i].size() && words[0][ans] == words[i][ans]) {
            ++ans;
        }
        if (ans > wasans) {
            ans = wasans;
        }
    }
    return words[0].substr(0, ans);
}