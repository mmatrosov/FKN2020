#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, std::vector<int>> results;
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            std::string login;
            std::cin >> login;
            int score;
            std::cin >> score;
            if (results[login].empty()) {
                results[login].resize(n);
            }
            results[login][i] = score;
        }
    }
    for (auto& [name, reses] : results) {
        std::cout << name << '\t';
        for (int i : reses) {
            std::cout << i << "\t";
        }
        std::cout << "\n";
    }



    return 0;
}
