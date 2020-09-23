#include <iostream>
#include <map>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::map<int, std::set<std::string>> dict;
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;
        int page;
        std::cin >> page;
        dict[page].insert(word);
    }
    for (const auto& [page, words] : dict) {
        std::cout << page << " ";
        for (const auto& el : words) {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
