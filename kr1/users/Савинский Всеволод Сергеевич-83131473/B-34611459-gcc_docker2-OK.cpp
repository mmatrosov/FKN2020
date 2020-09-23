#include <iostream>
#include <vector>
#include <string>

int main() {
    size_t m;
    std::cin >> m;

    std::vector<std::vector<std::string>> res;
    for (size_t i = 0; i < m; ++i) {
        size_t n;
        std::cin >> n;
        for (size_t j = 0; j < n; ++j) {
            std::string word;
            std::cin >> word;
            if (res.size() == j) {
                res.emplace_back(m);
            }
            res[j][i] += word;
        }
    }
    for (const auto &lin : res) {
        for (const auto &w : lin) {
            std::cout << w << '\t';
        }
        std::cout << std::endl;
    }
}
