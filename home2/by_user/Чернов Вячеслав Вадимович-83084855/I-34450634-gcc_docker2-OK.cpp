#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int operator * (const std::vector<int>& a, const std::vector<int>& b) {
    size_t size = a.size();
    int result = 0;
    for (size_t i = 0; i < size; ++i)
        result += a[i] * b[i];
    return result;
}

int main() {
    int words, dimension;
    std::cin >> words >> dimension;
    std::string firstWord;
    std::vector<int> firstVector;
    std::map<std::string, int> index;
    std::map<std::string, std::vector<int>> vector;
    for (int i = 0; i < words; ++i) {
        std::string word;
        std::cin >> word;
        if (i == 0)
            firstWord = word;
        index[word] = i;
        std::vector<int> coords(dimension);
        for (int j = 0; j < dimension; ++j)
            std::cin >> coords[j];
        vector[word] = coords;
        if (i == 0) {
            firstWord = word;
            firstVector = coords;
        }
    }
    std::vector<std::string> best;
    int maxResult = static_cast<int>(-2e9);
    for (const auto& [word, coords] : vector) {
        if (word == firstWord)
            continue;
        int curResult = firstVector * coords;
        if (curResult > maxResult) {
            maxResult = curResult;
            best.clear();
            best.emplace_back(word);
        } else {
            if (curResult == maxResult)
                best.emplace_back(word);
        }
    }
    sort(best.begin(), best.end(), [&index](const std::string& a, const std::string& b) {
        return index[a] < index[b];
    });
    for (const auto& word : best)
        std::cout << word << "\n";
}
