#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include "query.h"

const int RESULTS_TO_PRINT = 3;

bool cmp(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return std::tie(b.second, a.first) < std::tie(a.second, b.first);
}

int main() {
    std::map<std::string, int> login_stats;
    std::string line;
    while (std::getline(std::cin, line)) {
        Query* q = parse_query(line.c_str());

        if (q->action == ACTION_COMMIT) {
            std::string cur_login = (*q).sender_login;
            login_stats[cur_login]++;
        }
        delete q;
    }

    std::vector<std::pair<std::string, int>> stats_vec(
        login_stats.begin(), login_stats.end());
    std::sort(stats_vec.begin(), stats_vec.end(), cmp);

    for (int i = 0; i < RESULTS_TO_PRINT && i < stats_vec.size(); ++i) {
        std::cout << stats_vec[i].first << " " << stats_vec[i].second << "\n";
    }
}
