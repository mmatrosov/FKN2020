#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <set>
#include <vector>

signed main() {
    std::map<std::string, std::vector<std::pair<int, int>>> results;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        for (int e = 0; e < k; ++e) {
            std::string login;
            int result;
            std::cin >> login >> result;
            results[login].emplace_back(i, result);
        }
    }
    for (const auto& [login, result] : results) {
        std::cout << login << "\t";
        int pt = 0;
        for (int i = 0; i < n; i++) {
            if (pt < result.size() && result[pt].first == i) {
                std::cout << result[pt].second << "\t";
                ++pt;
            } else {
                std::cout << "0\t";
            }
        }
        std::cout << "\n";
    }
}