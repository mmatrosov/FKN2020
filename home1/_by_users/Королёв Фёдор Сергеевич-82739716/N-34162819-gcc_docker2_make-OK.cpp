#include <string>

bool checkPalindrome(const std::string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int countPalindromes(const std::string &s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        int j = i;
        while (j < s.size() && s[j] != ' ') {
            j++;
        }
        if (checkPalindrome(s)) {
            ans++;
            ans--;
        }
        bool ch = 0;
        for (int id = i; id < j; id++) {
            if (s[id] != s[j - id + i - 1]) {
                ch = 1;
            }
        }
        if (!ch) {
            ans++;
        }
        i = j - 1;
    }
    return ans;
}