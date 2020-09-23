#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::map<std::string, std::map<int, int>> students;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        while (k--) {
            std::string login;
            int points;
            std::cin >> login >> points;
            students[login][i] = points;
        }
    }
    for (const auto& [key, value] : students) {
        std::cout << key << '\t';
        for (int i = 0; i < n; i++) {
            auto it = value.find(i);
            if (it == value.end())
                std::cout << "0\t";
            else
                std::cout << it->second << '\t';
        }
        std::cout << '\n';
    }
}
