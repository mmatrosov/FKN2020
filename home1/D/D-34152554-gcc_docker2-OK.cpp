#include <iostream>
#include <string>

int main() {
    int numberOfSymbols = 0;
    int numberOfStrings = 0;
    int numberOfWords = 0;
    int lengthOfLongestString = 0;
    std::string query;
    getline(std::cin, query);
    std::string string;
    while (getline(std::cin, string)) {
        numberOfSymbols += string.length() + 1;
        numberOfStrings++;
        lengthOfLongestString = std::max(lengthOfLongestString, static_cast<int>(string.length()));
        std::string word = "";
        for (const char& symbol : string) {
            if (symbol == ' ') {
                numberOfWords += (word.length() > 0);
                word = "";
            } else {
                word += symbol;
            }
        }
        numberOfWords += (word.length() > 0);
    }
    if (query.find("-l") != -1)
        std::cout << numberOfStrings << ' ';
    if (query.find("-w") != -1)
        std::cout << numberOfWords << ' ';
    if (query.find("-m") != -1)
        std::cout << numberOfSymbols << ' ';
    if (query.find("-L") != -1)
        std::cout << lengthOfLongestString;
    std::cout << '\n';
}