#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> get_words(const std::string& text) {
    std::vector<std::string> result;
    int currentPos = 0, length = text.size();
    while (currentPos < length) {
        while (currentPos < length && text[currentPos] == ' ') {
            ++currentPos;
        }
        std::string currentWord = "";
        while (currentPos < length && text[currentPos] != ' ') {
            currentWord += text[currentPos];
            ++currentPos;
        }
        if (!currentWord.empty()) {
            result.emplace_back(currentWord);
        }
    }
    return result;
}

int main() {
    std::string keys;
    getline(std::cin, keys);

    bool isCountSymbols = false, isCountLines = false;
    bool isCountMaxLength = false, isCountWords = false;

    auto keyWords = get_words(keys);
    for (const auto& key : keyWords) {
        if (key == "-m") {
            isCountSymbols = true;
        }
        if (key == "-l") {
            isCountLines = true;
        }
        if (key == "-L") {
            isCountMaxLength = true;
        }
        if (key == "-w") {
            isCountWords = true;
        }
    }

    int symbolsCount = 0, linesCount = 0;
    int maxLength = 0, wordsCount = 0;

    std::string text;
    while (getline(std::cin, text)) {
        symbolsCount += text.size();
        auto words = get_words(text);
        maxLength = std::max(maxLength, static_cast<int>(text.size()));
        linesCount++;
        wordsCount += words.size();
    }
    symbolsCount += linesCount;
    if (isCountLines) {
        std::cout << linesCount << ' ';
    }
    if (isCountWords) {
        std::cout << wordsCount << ' ';
    }
    if (isCountSymbols) {
        std::cout << symbolsCount << ' ';
    }
    if (isCountMaxLength) {
        std::cout << maxLength << ' ';
    }
}
