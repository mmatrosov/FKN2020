#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <algorithm>
#include <tuple>

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<std::string> text(m);
    for (std::string& word : text)
        std::cin >> word;
    std::map<std::string, int> frequency;
    for (int word_id = 0; word_id + n <= m; ++word_id) {
        ++frequency[std::accumulate(text.begin() + word_id + 1, text.begin() + word_id + n,
            text[word_id], [](const std::string& first, const std::string& second) {
                return first + ' ' + second;
            })];
    }
    std::vector<std::pair<std::string, int>> to_sort(frequency.begin(), frequency.end());
    std::sort(to_sort.begin(), to_sort.end(),
        [](std::pair<std::string, int>& a, std::pair<std::string, int>& b) -> bool {
            return a.second > b.second || a.second == b.second && a.first < b.first;
        });
    for (auto& [key, value] : to_sort)
        std::cout << key << " - " << value << std::endl;
    return 0;
}
