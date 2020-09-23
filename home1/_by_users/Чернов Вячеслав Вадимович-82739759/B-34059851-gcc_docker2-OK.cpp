#include <iostream>
#include <map>
#include <string>

const int vowelsCount = 8;
const char vowels[vowelsCount] = {'a', 'e', 'h', 'i', 'o', 'u', 'w', 'y'};

bool is_vowel(const char& letter) {
    for (int i = 0; i < vowelsCount; ++i) {
        if (letter == vowels[i]) {
            return true;
        }
    }
    return false;
}

void remove_vowels(std::string& word) {
    std::string newWord = {word[0]};
    int length = word.size();
    for (int i = 1; i < length; ++i) {
        if (is_vowel(word[i])) {
            continue;
        }
        newWord += word[i];
    }
    word = newWord;
}

void assign_codes(std::map<char, char>& codes) {
    codes['b'] = codes['f'] = codes['p'] = codes['v'] = '1';
    codes['c'] = codes['g'] = codes['j'] = codes['k'] =
        codes['q'] = codes['s'] = codes['x'] = codes['z'] = '2';
    codes['d'] = codes['t'] = '3';
    codes['l'] = '4';
    codes['m'] = codes['n'] = '5';
    codes['r'] = '6';
}

void change_consonants(std::string& word) {
    std::map<char, char> codes;
    assign_codes(codes);

    int length = word.size();
    for (int i = 1; i < length; ++i) {
        word[i] = codes[word[i]];
    }
}

void compress(std::string& word) {
    std::string newWord = {word[0]};
    int length = word.size();
    for (int i = 1; i < length; ++i) {
        if (word[i - 1] != word[i]) {
            newWord += word[i];
        }
    }
    word = newWord;
}

void print_result(std::string& word) {
    if (word.size() >= 4) {
        for (int i = 0; i < 4; ++i) {
            std::cout << word[i];
        }
    } else {
        while (word.size() < 4) {
            word += '0';
        }
        std::cout << word;
    }
}

int main() {
    std::string word;
    std::cin >> word;

    remove_vowels(word);
    change_consonants(word);
    compress(word);
    print_result(word);
}