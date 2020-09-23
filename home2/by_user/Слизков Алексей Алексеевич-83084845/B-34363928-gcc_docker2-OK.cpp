#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> theSet;
    char command_type;
    std::string word;
    while (std::cin >> command_type && command_type != '#') {
        std::string word;
        std::cin >> word;
        if (command_type == '+')
            theSet.insert(word);
        if (command_type == '-')
            theSet.erase(word);
        if (command_type == '?')
            std::cout << (theSet.find(word) == theSet.end() ? "NO" : "YES") << '\n';
    }
    return 0;
}
