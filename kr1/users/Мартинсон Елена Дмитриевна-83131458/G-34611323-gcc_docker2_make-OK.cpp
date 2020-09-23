#include <iostream>
#include <vector>
#include <map>
#include <string>

std::map<std::string, int> final_standings(std::vector<std::map<std::string, int>> res) {
    std::map<std::string, int> ans;
    std::map<std::string, bool> have_mark;
    for (const auto& el : res) {
        for (const auto& [key, val] : el) {
            if (have_mark[key] == false) {
                have_mark[key] = true;
                ans[key] = val;
            } else {
                if (val > ans[key]) {
                    ans[key] = val;
                }
            }
        }
    }
    return ans;
}


