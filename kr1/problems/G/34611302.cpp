#include <algorithm>
#include <map>
#include <string>
#include <vector>

std::map<std::string, int> final_standings(std::vector<std::map<std::string, int>> &results) {
    std::map<std::string, int> final_res;
    for (const auto& contest : results)
        for (const auto& [student, score] : contest)
            if (final_res.find(student) == final_res.end())
                final_res[student] = score;
            else
                final_res[student] = std::max(final_res[student], score);
    return final_res;
}