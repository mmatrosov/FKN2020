#include <string_view>
#include <string>
#include <cctype>

bool checkPalindrome(std::string_view str) {
        for (size_t i = 0; i < str.size() / 2; ++i) {
                if (str[i] != str[str.size() - i - 1]) {
                        return false;
                }
        }
        return true;
}

int countPalindromes(std::string_view str) {
        int begin, answer = 0;
        for (size_t i = 0; i < str.size(); ++i) {
                if (isalpha(str[i])) {
                        if (i == 0 || !isalpha(str[i - 1])) {
                                begin = i;
                        }
                        if (i + 1 == str.size() || !isalpha(str[i + 1])) {
                                answer += checkPalindrome(str.substr(begin, i - begin + 1));
                        }
                }
        }
        return answer;
}

