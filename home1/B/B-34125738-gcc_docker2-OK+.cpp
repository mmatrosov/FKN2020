#include <iostream>
#include <string>

int main() {
    std::string vowels = "aehiouwy";
    std::string consonants_type_1 = "bfpv";
    std::string consonants_type_2 = "cgjkqsxz";
    std::string consonants_type_3 = "dt";
    std::string consonants_type_4 = "l";
    std::string consonants_type_5 = "mn";
    std::string consonants_type_6 = "r";
    std::string word;
    std::cin >> word;
    std::string code;
    code += word[0];
    word.erase(0, 1);
    for (const char& letter : word) {
        if (vowels.find(letter) != -1) {
            continue;
        }
        char consonant;
        if (consonants_type_1.find(letter) != -1) {
            consonant = 1;
        }
        if (consonants_type_2.find(letter) != -1) {
            consonant = 2;
        }
        if (consonants_type_3.find(letter) != -1) {
            consonant = 3;
        }
        if (consonants_type_4.find(letter) != -1) {
            consonant = 4;
        }
        if (consonants_type_5.find(letter) != -1) {
            consonant = 5;
        }
        if (consonants_type_6.find(letter) != -1) {
            consonant = 6;
        }
        consonant += '0';
        if (consonant != code.back())
            code += consonant;
    }
    while (code.length() > 4)
        code.pop_back();
    while (code.length() < 4)
        code += '0';
    std::cout << code << '\n';
}
