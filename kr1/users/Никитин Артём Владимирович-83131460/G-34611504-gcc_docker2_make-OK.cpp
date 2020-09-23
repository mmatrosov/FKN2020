#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> final_standings(const vector<map<string, int>>& results) {
    map<string, int> final_standing;
    for (const auto& contest : results) {
        for (const auto& contestant : contest) {
            auto it = final_standing.find(contestant.first);
            if (it == final_standing.end()) {
                final_standing[contestant.first] = contestant.second;
            } else {
                it->second = max(it->second, contestant.second);
            }
        }
    }
    return final_standing;
}