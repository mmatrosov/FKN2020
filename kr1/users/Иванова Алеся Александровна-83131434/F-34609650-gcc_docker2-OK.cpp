#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <algorithm>

signed main() {
    int cnt_words, len;
    std::cin >> cnt_words >> len;
    std::vector<std::string> words(cnt_words);
    for (int i = 0; i < cnt_words; ++i)
        std::cin >> words[i];
    std::unordered_map<std::string, int> cnt_strings;
    for (int i = 0; i + len <= cnt_words; ++i) {
        std::string cur = words[i];
        for (int e = 1; e < len; e++)
            cur += " " + words[i + e];
        cnt_strings[cur]++;
    }
    std::vector<std::pair<int, std::string> > strings_for_printing;
    for (auto it = cnt_strings.begin(); it != cnt_strings.end(); ++it) {
        strings_for_printing.emplace_back(-(*it).second, (*it).first);
    }
    std::sort(strings_for_printing.begin(), strings_for_printing.end());
    for (const auto str : strings_for_printing) {
        std::cout << str.second << " - " << -str.first << "\n";
    }
}
