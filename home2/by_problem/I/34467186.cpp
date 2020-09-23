#include <iostream>
#include <string>
#include <vector>

int main() {
    int m, n;
    std::cin >> m >> n;

    std::vector<int> first_word;
    int max_val = -2e9;
    std::vector<std::string> maxes;
    for (size_t i = 0; i < m; ++i) {
        std::string word;
        std::cin >> word;
        std::vector<int> arr(n);
        for (int &x : arr) {
            std::cin >> x;
        }
        if (i == 0) {
            first_word = move(arr);
        } else {
            int sum = 0;
            for (size_t j = 0; j < n; ++j) {
                sum += first_word[j] * arr[j];
            }
            if (max_val < sum) {
                max_val = sum;
                maxes.clear();
                maxes.emplace_back(word);
            } else if (max_val == sum) {
                maxes.emplace_back(word);
            }
        }
    }
    for (const auto &word : maxes) {
        std::cout << word << std::endl;
    }
}
