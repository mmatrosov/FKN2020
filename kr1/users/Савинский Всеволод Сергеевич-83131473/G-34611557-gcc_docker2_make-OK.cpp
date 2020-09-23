#include <iostream>
#include <vector>
#include <string>
#include <map>

std::map<std::string, int> final_standings(
        const std::vector<std::map<std::string, int>> &contests) {
    std::map<std::string, int> res;
    for (const auto &contest : contests) {
        for (const auto &[name, val] : contest) {
            if (res.find(name) == res.end()) {
                res[name] = std::numeric_limits<int>::min();
            }
            res[name] = std::max(res[name], val);
        }
    }
    return res;
}