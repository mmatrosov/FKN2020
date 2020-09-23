#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

std::map<std::string, int> final_standings
        (const std::vector<std::map<std::string, int> >& contests) {
    std::map<std::string, int> final_res;
    for (const auto& contest : contests) {
        for (const auto& [student, res] : contest) {
            if (final_res.find(student) == final_res.end()) {
                final_res.emplace(student, res);
            } else {
                int cur_res = final_res[student];
                if (res > cur_res)
                    final_res[student] = res;
            }
        }
    }
    return final_res;
}