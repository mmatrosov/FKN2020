#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<char, bool> letters_in_words;
    std::string s;
    std::cin >> s;
    for (char c : s) {
        letters_in_words[c] = true;
    }
    while (std::cin >> s) {
        for (auto& [key, value] : letters_in_words) {
            if (s.find(key) == s.npos) {
                value = false;
            }
        }
    }
    for (auto& [key, value] : letters_in_words) {
        if (value) {
            std::cout << key;
        }
    }


    return 0;
}
