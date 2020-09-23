#include <iostream>
#include <utility>
#include <map>
#include <string>

signed main() {
    std::map<std::string, std::pair<long long, int>> marks;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string name;
        int mark;
        std::cin >> name >> mark;
        marks[name].first += mark;
        ++marks[name].second;
        std::cout << marks[name].first / marks[name].second << "\n";
    }
}
