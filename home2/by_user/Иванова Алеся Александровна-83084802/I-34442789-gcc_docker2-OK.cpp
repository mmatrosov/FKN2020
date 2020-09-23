#include <iostream>
#include <string>
#include <vector>

int get_dist(const std::vector<int>& v1, const std::vector<int>& v2) {
    int dist = 0;
    int n = v1.size();
    for (int i = 0; i < n; ++i)
        dist += v1[i] * v2[i];
    return dist;
}

signed main() {
    int n, m;
    std::cin >> m >> n;
    std::string first_word;
    std::vector<int> first_word_vec(n);
    std::cin >> first_word;
    for (int i = 0; i < n; ++i)
        std::cin >> first_word_vec[i];
    int max_dist = -1;
    std::vector<std::string> answer;
    for (int i = 0; i < m - 1; ++i) {
        std::string word;
        std::cin >> word;
        std::vector<int> word_vec(n);
        for (int e = 0; e < n; ++e)
            std::cin >> word_vec[e];
        int dist = get_dist(first_word_vec, word_vec);
        if (dist > max_dist) {
            max_dist = dist;
            answer.resize(0);
        }
        if (dist == max_dist)
            answer.push_back(word);
    }
    for (const auto& word : answer)
        std::cout << word << "\n";
}
