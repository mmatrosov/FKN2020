#include <iostream>
#include <set>
#include <string>

int main() {
    std::string path;
    std::set<std::string> nonEmpty;
    while (std::cin >> path) {
        std::string curPath;
        for (char c : path) {
            curPath += c;
            if (c == '/')
                nonEmpty.emplace(curPath);
        }
    }
    for (const auto& elem : nonEmpty)
        std::cout << elem << "\n";
}
