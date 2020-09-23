#include <utility>
#include <string>

bool is_vowel(char ch) {
        const std::string vowels = "aeiouy";
        return vowels.find(tolower(ch)) != std::string::npos;
}


std::pair<size_t, size_t> FindVowels(std::string &text, size_t pos) {
        while (pos < text.size() && !is_vowel(text[pos])) {
                pos++;
        }
        size_t len = 0;
        while (pos + len < text.size() && is_vowel(text[pos + len])) {
                len++;
        }
        return {pos < text.size() ? pos : std::string::npos, len};
}
