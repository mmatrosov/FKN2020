#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include "query.h"

const int RESULTS_TO_PRINT = 3;

int main() {
    std::map<std::string, int> login_stats;
    std::string line;
    while (std::getline(std::cin, line)) {
        Query *q = parse_query(line.c_str());

        if (q->action == ACTION_COMMIT) {
            login_stats[q->sender_login] += 1;
        }
        delete q;
    }

    std::vector<std::pair<std::string, int>> stats_vec(login_stats.begin(), login_stats.end());
    std::sort(stats_vec.begin(), stats_vec.end(), [](const auto &a, const auto &b) {
        return std::tie(b.second, a.first) < std::tie(a.second, b.first);
    });

    for (int i = 0; i < std::min<int>(RESULTS_TO_PRINT, stats_vec.size()); ++i) {
        std::cout << stats_vec[i].first << " " << stats_vec[i].second << "\n";
    }
}
