#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<std::string, int> final_standings(const std::vector<std::map<std::string, int>> results) {
    std::map<std::string, int> best;
    for (const auto& contest : results) {
        for (const auto& [login, score] : contest) {
            if (best.count(login) == 0) {
                best[login] = score;
            } else {
                best[login] = std::max(best[login], score);
            }
        }
    }
    return best;
}
