#include <iostream>
#include <string>
#include <string_view>

bool check_palindrome(std::string::const_iterator begin,
                      std::string::const_iterator end) {
    while (begin < end) {
        if (*begin != *end) {
            return false;
        }
        ++begin;
        --end;
    }
    return true;
}

int count_palindrome(std::string const& s) {
    // if SIZE_MAX, we are skipping some whitespace currently.
    // otherwise, contains position of first letter of the word.
    size_t cur_word_begin = SIZE_MAX;
    int count = 0;
    for (size_t pos = 0; pos <= s.size(); ++pos) {
        char const ch = s[pos];
        if (isalpha(ch)) {
            if (cur_word_begin == SIZE_MAX) {
                cur_word_begin = pos;
            } else {
                // do nothing, continue growing word
            }
        } else {
            if (cur_word_begin == SIZE_MAX) {
                // do nothing, continue skipping whitespace
            } else {
                if (check_palindrome(s.begin() + cur_word_begin,
                                     s.begin() + pos - 1)) {
                    ++count;
                }
                cur_word_begin = SIZE_MAX;
            }
        }
    }
    return count;
}

// I think that using camelCase for function names is disgusting
bool checkPalindrome(std::string const& s) {
    return check_palindrome(s.begin(), s.end()-1);
}

int countPalindromes(std::string const& s) { return count_palindrome(s); }
/*
// crop here
using namespace std;
#include <cassert>

int main(int argc, char *argv[]) {
    assert(argc == 2);
    string inp(argv[1]);
    cout << count_palindrome(inp) << endl;
}
*/