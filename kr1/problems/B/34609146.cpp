#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::string>> all(n);

    int max_k = 0;

    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        if (max_k < k) {
            max_k = k;
        }
        all[i].resize(k);
        for (int j = 0; j < k; ++j) {
            std::string cur;
            std::cin >> cur;
            all[i][j] = cur;
        }
    }
    for (int i = 0; i < max_k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (all[j].size() > i) {
                std::cout << all[j][i];
            }
            std::cout << "\t";
        }
        std::cout << "\n";
    }


    return 0;
}
