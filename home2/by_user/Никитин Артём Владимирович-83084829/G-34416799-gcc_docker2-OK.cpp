#include <iostream>
#include <map>
#include <string>
#include <set>

std::map<int, std::set<std::string>> pages;

int main() {
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
