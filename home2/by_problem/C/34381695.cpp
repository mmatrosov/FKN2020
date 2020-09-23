#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    std::map<char, int> countIn;
    std::string word;
    int wordsCount = 0;
    while (std::cin >> word) {
        ++wordsCount;
        std::set<char> letters;
        for (char c : word) {
            if (letters.count(c) == 0) {
                ++countIn[c];
                letters.insert(c);
            }
        }
    }
    for (const auto& [key, value] : countIn) {
        if (value == wordsCount)
            std::cout << key;
    }
}
