#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    char operation;
    std::unordered_set<std::string> words;
    std::string word;
    while (std::cin >> operation) {
        if (operation == '#')
            break;
        std::cin >> word;
        if (operation == '+')
            words.insert(word);
        else if (operation == '-')
            words.erase(word);
        else if (words.find(word) != words.end())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}