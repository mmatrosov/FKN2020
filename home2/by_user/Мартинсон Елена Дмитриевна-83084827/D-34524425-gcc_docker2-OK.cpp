#include <iostream>
#include <set>
#include <string>



int main() {
    std::string s;
    std::set<std::string> paths;
    while (std::cin >> s) {
        std::string now;
        for (char c : s) {
            now += c;
            if (c == '/') {
                paths.insert(now);
            }
        }
    }
    for (auto& el : paths) {
        std::cout << el << "\n";
    }


    return 0;
}
