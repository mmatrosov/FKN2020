#include <iostream>
#include <string>
#include <vector>

int main() {
    int m;
    std::cin >> m;
    int maxFile = 0;
    std::vector<std::vector<std::string>> files(m);
    for (auto& file : files) {
        int n;
        std::cin >> n;
        file.resize(n);
        maxFile = std::max(maxFile, n);
        for (auto& string : file) {
            std::cin >> string;
        }
    }
    for (int i = 0; i < maxFile; i++) {
        for (auto& file : files) {
            if (file.size() <= i) {
                std::cout << '\t';
            } else {
                std::cout << file[i] << '\t';
            }
        }
        std::cout << '\n';
    }
}
