#include <iostream>
#include <string>
#include <string_view>

bool checkPalindrome(const std::string_view& string) {
    bool check = true;
    for (int i = 0; i + i < string.length(); i++)
        check &= (string[i] == string[string.length() - 1 - i]);
    return check;
}

int countPalindromes(const std::string& text) {
    std::string_view view = text;
    int result = 0;
    int begin = 0, end = -1;
    while (begin < text.length()) {
        while (begin < text.length() && text[begin] == ' ')
            begin++;
        if (begin == text.length())
            break;
        end = begin;
        while (end < text.length() && text[end] != ' ')
            end++;
        result += checkPalindrome(view.substr(begin, end - begin));
        begin = end + 1;
    }
    return result;
}
