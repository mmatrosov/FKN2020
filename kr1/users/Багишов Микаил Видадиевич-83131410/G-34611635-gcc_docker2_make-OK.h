#include <vector>
#include <map>
#include <string>

std::map<std::string, int> final_standings(
        std::vector<std::map<std::string, int>> const &contests
) {
    std::map<std::string, int> res;
    for (auto const& contest : contests) {
        for (auto const &[name, score] : contest) {
            if (!res.count(name)) {
                res[name] = score;
            } else {
                res[name] = std::max(res[name], score);
            }
        }
    }
    return res;
}