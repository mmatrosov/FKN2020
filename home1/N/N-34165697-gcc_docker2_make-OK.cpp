
#include <string>
#include <string_view>

bool checkPalindrome(const std::string_view my_view) {
    int n = my_view.size();
    for (int i = 0; i < n; ++i) {
        if (my_view[i] != my_view[n - i - 1]) return false;
    }
    return true;
}

int countPalindromes(const std::string &s) {
    const std::string_view my_view(s);
    int ans = 0, n = s.size();
    int st = -1;
    for (int i = 0; i <= n; ++i) {
        if (i == n || s[i] == ' ') {
            if (st != -1) {
                if (checkPalindrome(my_view.substr(st, i - st))) {
                    ans++;
                }
                st = -1;
            }
        } else {
            if (st == -1) st = i;
        }
    }
    return ans;
}