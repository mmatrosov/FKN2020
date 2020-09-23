#include <iostream>
#include <string>

int const CHAR_CLASS_NONE = 0;

int classify_char(char const target) {
    std::string const TABLE[] = {"bfpv", "cgjkqsxz", "dt", "l", "mn", "r"};
    size_t const TABLE_SIZE = sizeof(TABLE) / sizeof(TABLE[0]);
    for (int cls = 1; cls <= TABLE_SIZE; ++cls) {
        for (char const ch : TABLE[cls - 1]) {
            if (ch == target) {
                return cls;
            }
        }
    }
    return CHAR_CLASS_NONE;
}

int main() {
    std::string word;
    std::cin >> word;
    std::string repr;
    repr.push_back(word[0]);
    word = word.substr(1);
    for (char const ch : word) {
        int cls = classify_char(ch);
        if (cls == CHAR_CLASS_NONE) {
            continue;
        }
        if (repr.back() == cls + '0') {
            continue;
        }
        repr.push_back(cls + '0');
        if (repr.size() == 4) {
            break;
        }
    }
    while (repr.size() < 4) {
        repr.push_back('0');
    }
    std::cout << repr << std::endl;
}