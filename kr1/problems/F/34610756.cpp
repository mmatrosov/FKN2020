#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int M, N;
    std::cin >> M >> N;
    std::unordered_map<std::string, int> count;
    std::vector<std::string> words(M);
    for (int i = 0; i < M; i++) {
        std::cin >> words[i];
        if (i >= N - 1) {
            std::string newAnagram = "";
            for (int j = i - N + 1; j < i; j++)
                newAnagram += words[j] + " ";
            newAnagram += words[i];
            ++count[newAnagram];
        }
    }
    std::vector<std::pair<int, std::string> > anagrams;
    for (auto [anagram, cnt] : count)
        anagrams.push_back({-cnt, anagram});
    std::sort(anagrams.begin(), anagrams.end());
    for (const auto& [cnt, ang] : anagrams)
        std::cout << ang << " - " << -cnt << '\n';
    return 0;
}