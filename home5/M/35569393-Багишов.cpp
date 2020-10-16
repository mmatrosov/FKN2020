#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "query.h"

const int qResultsToPrint = 3;

int main() {
    std::map<std::string, int> login_stats;
    std::string line;
    while (std::getline(std::cin, line)) {
        Query* q = parse_query(line.c_str());

        if (q->action == ACTION_COMMIT) {
            login_stats[q->sender_login]++;
        }

        delete q;
    }

    std::vector<std::pair<std::string, int>> stats_vec(login_stats.begin(), login_stats.end());
    std::sort(stats_vec.begin(), stats_vec.end(), [&](auto const& lhs, auto const& rhs) {
        return std::tie(rhs.second, lhs.first) < std::tie(lhs.second, rhs.first);
    });

    for (int i = 0; i < std::min(qResultsToPrint, static_cast<int>(stats_vec.size())); ++i) {
        std::cout << stats_vec[i].first << " " << stats_vec[i].second << "\n";
    }
}
