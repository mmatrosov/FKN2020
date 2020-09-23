#include <string>
#include <utility>
#include <set>

std::pair<int, int> FindVowels(const std::string &s, int start) {
    std::set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
    int curVowels = 0;
    for (; start < s.size(); ++start) {
        if (vowels.find(std::tolower(s[start])) == vowels.end()) {
            if (curVowels != 0) {
                return {start - curVowels, curVowels};
            }
        } else {
            curVowels++;
        }
    }
    if (curVowels == 0) return {std::string::npos, curVowels};
    return {s.size() - curVowels, curVowels};
}