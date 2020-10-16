#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "query.h"

const int RESULTS_TO_PRINT = 3;

bool cmp(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return (a.second < b.second) || (a.second == b.second && a.first < b.first);
}

int main() {
    std::map<std::string, int> login_stats;
    std::string line;
    while (std::getline(std::cin, line)) {
        Query* q = parse_query(line.c_str());

        if (q->action == ACTION_COMMIT) {
            ++login_stats[q->sender_login];
        }
        delete q;
    }

    std::vector<std::pair<std::string, int>> stats_vec(login_stats.begin(), login_stats.end());
    std::sort(stats_vec.begin(), stats_vec.end(), cmp /* не знаю, как сортировать по частоте :( */);
    reverse(stats_vec.begin(), stats_vec.end());
    for (int i = 0; i < std::min(stats_vec.size(), static_cast<size_t>(RESULTS_TO_PRINT)); ++i) {
        std::cout << stats_vec[i].first << " " << stats_vec[i].second << "\n";
    }
}