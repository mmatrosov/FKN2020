#include <iostream>
#include <deque>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::deque <std::string> works;
    for (int i = 0; i < n; ++i) {
        std::string surn, type;
        std::cin >> surn >> type;
        if (type == "top") {
            works.push_front(surn);
        } else {
            works.push_back(surn);
        }
    }
    std::string ans[n];
    int id = 0;
    while (!works.empty()) {
        ans[id] = works.front();
        works.pop_front();
        ++id;
    }
    int q;
    std::cin >> q;
    while (q) {
        --q;
        int work;
        std::cin >> work;
        std::cout << ans[work - 1] << '\n';
    }
    return 0;
}