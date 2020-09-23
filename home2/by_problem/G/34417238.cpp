#include <iostream>
#include <map>
#include <string>
#include <set>

int main() {
    std::map<int, std::set<std::string>> pages;
    int n;
    std::cin >> n;
    while (n--) {
        std::string word;
        int page;
        std::cin >> word >> page;
        pages[page].insert(word);
    }
    for (const auto& [key, value] : pages) {
        std::cout << key << ' ';
        for (const auto& word : value)
            std::cout << word << ' ';
        std::cout << '\n';
    }
}
