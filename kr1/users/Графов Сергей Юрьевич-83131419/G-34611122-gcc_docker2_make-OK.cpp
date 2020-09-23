#include<algorithm>
#include<string>
#include<vector>
#include<map>


std::map<std::string, int> final_standings(std::vector<std::map<std::string, int>>& results) {
    std::map<std::string, int> ans;
    for (auto i : results) {
        for (auto j : i) {
            if (ans.count(j.first)) {
                ans[j.first] = std::max(ans[j.first], j.second);
            } else {
                ans[j.first] = j.second;
            }
        }
    }
    return ans;
}