#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
    int m, n;
    std::cin >> m >> n;
    if (m < n)
        return 0;
    std::vector<std::string> words(m);
    for (std::string& word : words)
        std::cin >> word;
    std::deque<std::string> ngramm;  //
    for (int i = 0; i < n; i++)
        ngramm.push_back(words[i]);
    std::map<std::deque<std::string>, int> frequency;
    frequency[ngramm]++;
    for (int i = n; i < m; i++) {
        ngramm.push_back(words[i]);
        ngramm.pop_front();
        frequency[ngramm]++;
    }
    std::map<int, std::set<std::deque<std::string>>> reversedFrequency;
    for (const auto& [key, value] : frequency) {
        reversedFrequency[value].insert(key);
    }
    for (auto it = reversedFrequency.rbegin(); it != reversedFrequency.rend(); ++it) {
        const auto& [key, value] = *it;
        for (const auto& deque : value) {
            for (const auto& word : deque) {
                std::cout << word << ' ';
            }
            std::cout << "- " << key << '\n';
        }
    }
}