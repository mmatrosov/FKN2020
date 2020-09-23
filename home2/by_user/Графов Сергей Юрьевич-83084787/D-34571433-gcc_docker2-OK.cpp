#include<iostream>
#include<set>
#include<string>
#include<vector>

int main() {
    std::vector<std::string> files;
    std::string s;
    while (std::cin >> s) {
        files.push_back(s);
    }
    std::set<std::string> directories;
    for (auto i : files) {
        for (int j = 0; j < static_cast<int>(i.size()); ++j) {
            if (i[j] == '/') {
                directories.insert(i.substr(0, j + 1));
            }
        }
    }
    for (auto i : directories) {
        std::cout << i << "\n";
    }
}
