#include <iostream>
#include <string>
#include <map>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector <int> v(m), u(m);
    std::string s;
    std::cin >> s;
    std::map <int64_t, std::vector <std::string> > words;
    int64_t maxv = -1e18;
    for (int i = 0; i < m; ++i) {
        std::cin >> v[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> s;
        for (int j = 0; j < m; ++j) {
            std::cin >> u[j];
        }
        int64_t product = 0;
        for (int j = 0; j < m; ++j) {
            product += v[j] * u[j];
        }
        words[product].push_back(s);
        maxv = std::max(maxv, product);
    }
    for (auto word : words[maxv]) {
        std::cout << word << '\n';
    }
    return 0;
}