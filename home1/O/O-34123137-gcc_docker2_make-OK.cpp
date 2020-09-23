#include <iostream>
#include <vector>

bool IsTowel(const char& letter) {
    char c = tolower(letter);
    return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'y'));
}

std::pair<int, int> FindVowels(const std::string& str, const int& pos) {
    int lenth = str.size();
    for (int i = pos; i < lenth; ++i) {
        if (IsTowel(str[i])) {
            int cnt = 1;
            while (i + cnt < lenth && IsTowel(str[i + cnt]))
                cnt++;
            return {i, cnt};
        }
    }
    return {std::string::npos, 0};
}
