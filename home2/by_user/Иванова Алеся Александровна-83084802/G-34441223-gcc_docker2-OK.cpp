#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <set>

signed main() {
    std::map<int, std::set<std::string>> words;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string word;
        int page;
        std::cin >> word >> page;
        words[page].insert(word);
    }
    for (const auto& page : words) {
        std::cout << page.first;
        for (const auto& word : page.second) {
            std::cout << " " << word;
        }
        std::cout << "\n";
    }
}
