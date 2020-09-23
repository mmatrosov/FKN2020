#include <iostream>

bool is_vowel(const char& c) {
    return ((c == 'a') || (c == 'e') || (c == 'h') || (c == 'i') ||
            (c == 'o') || (c == 'u') || (c == 'w') || (c == 'y'));
}

char get_digit(const char& c) {
    if ((c == 'b') || (c == 'f') || (c == 'p') || (c == 'v')) {
        return '1';
    } else if ((c == 'd') || (c == 't')) {
        return '3';
    } else if (c == 'l') {
        return '4';
    } else if ((c == 'm') || (c == 'n')) {
        return '5';
    } else if (c == 'r') {
        return '6';
    }
    return '2';
}

std::string get_code(const std::string& word) {
    std::string code = "";
    for (const char& c : word) {
        if (code.empty()) {
            code += c;
        } else if (code.size() == 4) {
            break;
        } else if (!is_vowel(c)) {
            char new_digit = get_digit(c);
            if (new_digit != code.back()) {
                code += new_digit;
            }
        }
    }
    while (code.size() < 4) {
        code += '0';
    }
    return code;
}

signed main() {
    std::string word;
    getline(std::cin, word);
    std::cout << get_code(word);
}
