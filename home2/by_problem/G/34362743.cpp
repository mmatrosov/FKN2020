#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::map <int, std::set <std::string> > book;
    for (int i = 0; i < n; ++i) {
        int page;
        std::string word;
        std::cin >> word >> page;
        book[page].insert(word);
    }
    for (auto page : book) {
        std::cout << page.first << ' ';
        for (auto word : page.second) {
            std::cout << word << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}