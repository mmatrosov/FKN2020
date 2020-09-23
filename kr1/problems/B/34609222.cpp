#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int files;
    std::cin >> files;
    std::vector<std::map<int, std::string>> words(files);
    int maxCount = -1;
    for (int i = 0; i < files; ++i) {
        int cntWords;
        std::cin >> cntWords;
        maxCount = std::max(maxCount, cntWords);
        for (int j = 0; j < cntWords; ++j) {
            std::string curWord;
            std::cin >> curWord;
            words[i][j] = curWord;
        }
    }
    for (int i = 0; i < maxCount; ++i) {
        for (int j = 0; j < files; ++j) {
            if (words[j].count(i) == 1) {
                std::cout << words[j][i];
            }
            std::cout << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
