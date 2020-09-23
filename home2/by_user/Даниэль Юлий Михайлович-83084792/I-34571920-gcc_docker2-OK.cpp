#include <iostream>
#include <vector>

const int INF = 2000000000;

int main() {
    std::string word;
    int num_words, num_dims;
    std::cin >> num_words >> num_dims;

    std::vector<int> main_vec(num_dims);
    std::cin >> word;
    for (auto &i : main_vec) std::cin >> i;
    int mxscore = -INF;

    std::vector<std::pair<std::string, int>> score;

    for (int i = 0; i < num_words - 1; ++i) {
        std::cin >> word;
        int cur = 0;
        for (int j = 0; j < num_dims; ++j) {
            int dim;
            std::cin >> dim;
            cur += dim * main_vec[j];
        }
        score.emplace_back(word, cur);
        mxscore = std::max(mxscore, cur);
    }

    for (auto [word, sc] : score) {
        if (sc == mxscore) std::cout << word << std::endl;
    }
    return 0;
}