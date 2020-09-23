#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>

int main() {
    size_t word_count, fold_size;
    std::cin >> word_count >> fold_size;
    std::unordered_map<std::string, int> freq;
    std::vector<std::string> words(word_count);
    for (std::string &s : words) {
        std::cin >> s;
    }
    for (size_t i = 0; i + fold_size <= word_count; ++i) {
        std::string data;
        for (size_t j = i; j < i + fold_size; ++j) {
            data += words[j];
            data.push_back(' ');
        }
        ++freq[data];
    }
    std::vector<std::pair<int, std::string>> sorted;
    for (auto const& [substr, count] : freq) {
        sorted.emplace_back(count, substr);
    }
    std::sort(sorted.begin(), sorted.end(), [&](auto const &lhs, auto const &rhs) {
        return std::tie(rhs.first, lhs.second) < std::tie(lhs.first, rhs.second);
    });
    for (auto const& [count, substr] : sorted) {
        std::cout << substr << "- " << count << '\n';
    }
}