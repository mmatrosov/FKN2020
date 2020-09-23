#include <string>
#include <string_view>
// reminder that PascalCase for function is disgusting

struct Match {
    size_t start;
    size_t length;
};

static bool is_vowel(char const ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'y';
}

Match find_vowels(std::string_view s) {
    Match match;
    match.start = std::string::npos;
    match.length = 0;
    for (size_t i = 0; i <= s.size(); ++i) {
        if (i < s.size() && is_vowel(tolower(s[i]))) {
            if (match.start == std::string::npos) {
                match.start = i;
            }
        } else if (match.start != std::string::npos) {
            match.length = i - match.start;
            break;
        }
    }
    return match;
}

Match FindVowels(std::string_view raw_view, size_t additional_offset) {
    raw_view.remove_prefix(additional_offset);
    Match match = find_vowels(raw_view);
    if (match.start != std::string::npos) {
        match.start += additional_offset;
    }
    return match;
}