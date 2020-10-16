#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "query.h"

const size_t RESULTS_TO_PRINT = 3;

bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second > b.second;
}

int main() {
    std::map<std::string, int> login_stats;
    std::string line;
    while (std::getline(std::cin, line)) {
        Query* q = parse_query(line.c_str());
        if (q->action == ACTION_COMMIT) {
            login_stats[q->sender_login] += 1;
            /* „~„u „x„~„p„, „{„p„{ „‚„p„q„€„„„p„„„ „ƒ map :( */
        }
        delete q;
    }

    std::vector<std::pair<std::string, int>> stats_vec(login_stats.begin(), login_stats.end());
    std::sort(stats_vec.begin(), stats_vec.end(), cmp);

    for (size_t i = 0; i < std::min(stats_vec.size(), RESULTS_TO_PRINT); ++i) {
        std::cout << stats_vec[i].first << " " << stats_vec[i].second << "\n";
    }
}
