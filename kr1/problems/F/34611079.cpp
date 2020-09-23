#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int words, length;
    std::cin >> words >> length;
    std::vector<std::string> word(words);
    std::map<std::string, int> count;
    for (int i = 0; i < words; ++i) {
        std::cin >> word[i];
        if (i + 1 >= length) {
            std::string cur = word[i - length + 1];
            for (int j = i - length + 2; j <= i; ++j) {
                cur = cur + " " + word[j];
            }
            ++count[cur];
        }
    }
    std::map<int, std::vector<std::string>> sorted;
    for (const auto& [text, cnt] : count) {
        sorted[-cnt].emplace_back(text);
    }
    for (const auto& [count, words] : sorted) {
        for (const auto& word : words) {
            std::cout << word << " - " << -count << "\n";
        }
    }
}
