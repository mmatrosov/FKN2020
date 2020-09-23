#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int main() {
    int word_count = 0;
    std::vector<int> cnt(26);
    std::string word;
    while (std::cin >> word) {
        word_count += 1;
        std::sort(word.begin(), word.end());
        word.erase(std::unique(word.begin(), word.end()), word.end());
        for (char let : word) {
            cnt[static_cast<int>(let - 'a')] += 1;
        }
    }
    for (int let_num = 0; let_num < 26; ++let_num) {
        if (cnt[let_num] == word_count) {
            std::cout << static_cast<char>('a' + let_num);
        }
    }
    std::cout << std::endl;
}
