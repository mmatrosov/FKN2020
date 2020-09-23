#include <map>
#include <vector>
#include <string>

std::map<std::string, int> final_standings(const std::vector<std::map<std::string, int>>& stands) {
    std::map<std::string, int> res;
    for (const auto& m : stands) {
        for (const auto& [name, point] : m) {
            if (res.find(name) == res.end()) {
                res[name] = point;
            }
            res[name] = std::max(res[name], point);
        }
    }
    return res;
}