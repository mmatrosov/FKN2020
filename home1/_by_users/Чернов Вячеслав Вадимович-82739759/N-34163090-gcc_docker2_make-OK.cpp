#include <iostream>
#include <string>
#include <string_view>

bool checkPalindrome(const std::string_view& word) {
    int length = word.size();
    for (int i = 0; i < length / 2; ++i) {
        if (word[i] != word[length - i - 1]) {
            return false;
        }
    }
    return true;
}

int countPalindromes(const std::string& text) {
    int palindromes = 0;
    int curPos = 0, length = text.size();
    while (curPos < length) {
        while (curPos < length && text[curPos] == ' ') {
            curPos++;
        }
        if (curPos == length) {
            break;
        }
        int startPos = curPos, wordLength = 0;
        while (curPos < length && text[curPos] != ' ') {
            wordLength++;
            curPos++;
        }
        std::string_view curWord{text.c_str() + startPos, wordLength};
        palindromes += static_cast<int>(checkPalindrome(curWord));
    }
    return palindromes;
}
