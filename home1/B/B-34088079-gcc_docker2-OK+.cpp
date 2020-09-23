#include <iostream>

using namespace std;

bool vowel(char c) {
    static std::string vowels = "aehiouwy";
    return vowels.find(c) != std::string::npos;
}

char code(char c) {
    switch (c) {
    case 'b':
    case 'f':
    case 'p':
    case 'v':
        return '1';
    case 'c':
    case 'g':
    case 'j':
    case 'k':
    case 'q':
    case 's':
    case 'x':
    case 'z':
        return '2';
    case 'd':
    case 't':
        return '3';
    case 'l':
        return '4';
    case 'm':
    case 'n':
        return '5';
    case 'r':
        return '6';
    }
}

int main() {
    std::string input;
    std::cin >> input;
    std::string replaced(1, input[0]);
    char lastcode = '7';  // impossible code
    for (char c : input.substr(1))
        if (!vowel(c) && code(c) != lastcode)
            replaced += lastcode = code(c);
    while (replaced.length() < 4)
        replaced += '0';
    std::cout << replaced.substr(0, 4);
    return 0;
}
