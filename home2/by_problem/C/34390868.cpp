#include <iostream>
#include <bitset>
#include <string>

signed main() {
    const int cnt_letters = 26;
    std::bitset<cnt_letters>letter;
    for (int i = 0; i < cnt_letters; ++i)
        letter[i] = 1;
    std::string word;
    while (std::cin >> word) {
        std::bitset<cnt_letters> word_letter;
        for (char c : word)
            word_letter[c - 'a'] = 1;
        letter &= word_letter;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (letter[c - 'a'])
            std::cout << c;
    }
}
