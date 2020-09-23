#include <iostream>
#include <unordered_set>
#include <string>

signed main() {
    std::unordered_set<std::string> string_set;
    char type;
    while (std::cin >> type) {
        if (type == '#')
            return 0;
        std::string new_string;
        std::cin >> new_string;
        if (type == '+')
            string_set.insert(new_string);
        else if (type == '-')
            string_set.erase(new_string);
        else if (string_set.find(new_string) == string_set.end())
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
}
