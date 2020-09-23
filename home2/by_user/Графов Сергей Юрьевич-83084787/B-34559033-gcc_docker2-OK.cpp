#include<iostream>
#include<string>
#include<unordered_set>

int main() {
    std::unordered_set<std::string> set;
    char c;
    std::string s;
    std::cin >> c;
    while (c != '#') {
        std::cin >> s;
        if (c == '+') {
            set.insert(s);
            std::cin >> c;
            continue;
        }
        if (c == '-') {
            set.erase(s);
            std::cin >> c;
            continue;
        }
        std::cin >> c;
        if (set.find(s) == set.end()) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
}
