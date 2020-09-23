#include <iostream>
#include <set>
#include <string>

int main() {
    std::string path;
    std::set<std::string> paths;
    while (std::cin >> path) {
        while (!path.empty()) {
            do {
                path.pop_back();
            } while (!path.empty() && path.back() != '/');
            if (!path.empty())
                paths.insert(path);
        }
    }
    for (const std::string& answer : paths)
        std::cout << answer << '\n';
}