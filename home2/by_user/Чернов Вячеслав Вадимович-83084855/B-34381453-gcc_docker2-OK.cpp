#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> dict;
    char type;
    while (std::cin >> type) {
        if (type == '#')
            break;
        std::string word;
        std::cin >> word;
        if (type == '+')
            dict.emplace(word);
        else if (type == '-')
            dict.erase(word);
        else
            std::cout << (dict.count(word) == 1 ? "YES" : "NO") << "\n";
    }
}
