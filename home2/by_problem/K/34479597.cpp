#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <map>

int main() {
    size_t n;
    std::cin >> n;
    std::vector<std::pair<int, int>> rqs(n);
    std::map<int, std::list<int>> lines;
    for (auto &[num, aft] : rqs) {
        std::cin >> num >> aft;
        if (lines.find(aft) == lines.end()) {
            aft = -1;
        }
        lines[num] = {num};
    }
    std::reverse(rqs.begin(), rqs.end());
    for (const auto &[num, aft] : rqs) {
        lines[aft].splice(lines[aft].end(), lines[num]);
    }
    for (int i : lines[-1]) {
        std::cout << i << std::endl;
    }
}
