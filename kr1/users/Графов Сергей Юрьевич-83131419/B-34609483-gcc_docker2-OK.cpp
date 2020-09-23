#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

int main() {
    int n;
    std::cin >> n;
    int maxl = 0;
    std::vector<std::vector<std::string>> files(n);
    int m;
    std::string word;
    for (int i = 0; i < n; i++) {
        std::cin >> m;
        maxl = std::max(maxl, m);
        for (int j = 0; j < m; j++) {
            std::cin >> word;
            files[i].push_back(word);
        }
    }
    for (int i = 0; i < maxl; i++) {
        for (int j = 0; j < n; j++) {
            if (files[j].size() <= i) {
                std::cout << "\t";
            } else {
                std::cout << files[j][i] << "\t";
            }
        }
        std::cout << "\n";
    }
}
