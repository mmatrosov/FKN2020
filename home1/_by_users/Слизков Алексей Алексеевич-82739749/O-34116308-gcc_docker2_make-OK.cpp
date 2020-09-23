#include <iostream>

inline bool vowel(char c) {
    static std::string vowels = "aeiouyAEIOUY";
    return vowels.find(c) != std::string::npos;
}

std::pair<size_t, size_t> FindVowels(const std::string& text, size_t pos) {
    while (pos < text.length() && !vowel(text[pos]))
        ++pos;
    if (pos == text.length())
        return {std::string::npos, 0};
    int i = pos;
    for (; i < text.length() && vowel(text[i]); ++i)
        continue;
    return {pos, i - pos};
}
