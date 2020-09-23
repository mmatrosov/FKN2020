#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <tuple>


int main() {
    int n, m;
    std::cin >> m >> n;
    std::vector<std::string> text(m);
    for (auto &word : text) {
        std::cin >> word;
    }

    std::unordered_map<std::string, int> cnt;
    for (size_t i = 0; i + n - 1 < text.size(); ++i) {
        std::string str;
        for (size_t j = i; j < i + n; ++j) {
            if (j != i) {
                str += " ";
            }
            str += text[j];
        }
        cnt[str] += 1;
    }

    std::vector<std::pair<std::string, int>> vec;
    for (const auto &p : cnt) {
        vec.emplace_back(p);
    }

    std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
        return std::tie(b.second, a.first) < std::tie(a.second, b.first);
    });

    for (const auto &[str, val] : vec) {
        std::cout << str << " - " << val << std::endl;
    }
}
