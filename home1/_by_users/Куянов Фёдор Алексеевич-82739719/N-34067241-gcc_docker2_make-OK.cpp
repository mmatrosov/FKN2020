#include <iostream>
#include <string>

bool checkPalindrome(const std::string_view& s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int countPalindromes(const std::string_view& s) {
    int cnt = 0;
    size_t pr = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (i != pr) {
                cnt += checkPalindrome(s.substr(pr, i - pr));
            }
            pr = i + 1;
        }
    }
    if (pr != s.size()) {
        cnt += checkPalindrome(s.substr(pr));
    }
    return cnt;
}
