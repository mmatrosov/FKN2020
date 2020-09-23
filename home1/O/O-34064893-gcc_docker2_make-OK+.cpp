#include <iostream>
#include <string>

const int vowelsCount = 6;
const char vowels[vowelsCount] = {'a', 'e', 'i', 'o', 'u', 'y'};

bool is_vowel(char c) {
    for (int i = 0; i < vowelsCount; ++i) {
        if (tolower(c) == vowels[i]) {
            return true;
        }
    }
    return false;
}

std::pair<size_t, size_t> FindVowels(const std::string& text, int pos) {
    size_t firstVowelPosition = std::string::npos;
    for (size_t i = pos; i < text.size(); ++i) {
        if (is_vowel(text[i])) {
            firstVowelPosition = i;
            break;
        }
    }

    if (firstVowelPosition == std::string::npos) {
        return std::make_pair(std::string::npos, std::string::npos);
    }

    size_t ind = firstVowelPosition, length = 0;
    while (ind < text.size() && is_vowel(text[ind])) {
        ++ind;
        ++length;
    }
    return std::make_pair(firstVowelPosition, length);
}
