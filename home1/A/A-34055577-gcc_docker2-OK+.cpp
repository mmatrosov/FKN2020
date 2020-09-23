#include <iostream>
#include <string>

int main() {
    std::string s;
    getline(std::cin, s);
    if (s.length() < 8 || s.length() > 14) {
        std::cout << "NO";
        return 0;
    }
    bool lc = 0, uc = 0, dc = 0, pc = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < 33 || 126 < s[i]) {
            std::cout << "NO";
            return 0;
        }
        if ('a' <= s[i] && s[i] <= 'z')
            lc = 1;
        else if ('A' <= s[i] && s[i] <= 'Z')
            uc = 1;
        else if ('0' <= s[i] && s[i] <= '9')
            dc = 1;
        else
            pc = 1;
    }
    if (lc + uc + dc + pc < 3) {
        std::cout << "NO";
        return 0;
    }
    std::cout << "YES";
    return 0;
}