#include <set>
#include <iostream>
#include <string>

int main() {
    std::set<std::string> paths;
    std::string path;
    while (std::cin >> path) {
        std::string current;
        for (char c : path) {
            current += c;
            if (c == '/') {
                paths.insert(current);
            }
        }
    }
    for (const auto &p : paths) {
        std::cout << p << std::endl;
    }
}
