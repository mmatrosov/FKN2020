#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

//
bool cmp(const std::pair<int, std::string> &a, const std::pair<int, std::string> &b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a < b;
}

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<std::string> words(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> words[i];
    }
    std::map<std::string, int> cnt;
    for (int i = 0; i + n <= m; ++i) {
        std::string tmp = words[i];
        for (int j = 1; j < n; ++j) {
            tmp += ' ' + words[i + j];
        }
        ++cnt[tmp];
    }
    std::vector<std::pair<int, std::string> > ans;
    for (auto el : cnt) {
        ans.push_back({el.second, el.first});
    }
    std::sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i].second << " - " << ans[i].first << '\n';
    }
    return 0;
}