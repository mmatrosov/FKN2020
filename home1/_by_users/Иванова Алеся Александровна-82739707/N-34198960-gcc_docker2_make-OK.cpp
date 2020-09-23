#include <iostream>
#include <string>
#include <string_view>

bool checkPalindrome(const std::string_view& s) {
    size_t n = s.size();
    for (size_t i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1])
            return 0;
    }
    return 1;
}

int countPalindromes(const std::string& s) {
    std::string_view new_s = s;
    int answer = 0;
    while (!new_s.empty()) {
        int pos = new_s.find(' ');
        auto str = new_s.substr(0, pos);
        if (!str.empty() && checkPalindrome(str))
            ++answer;
        if (pos == std::string::npos)
            break;
        new_s = new_s.substr(pos + 1, new_s.size());
    }
    return answer;
}