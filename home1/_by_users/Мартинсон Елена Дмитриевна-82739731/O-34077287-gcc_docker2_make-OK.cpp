#include <iostream>
#include <string>

using namespace std;

struct answer{
    int start;
    int length;
};

bool CheckVowel(char a) {
    a = tolower(a);
    return a == 'a' || a == 'i' || a == 'e' || a == 'y' || a == 'u' || a == 'o';
}

answer FindVowels(std::string text, int pos) {
    int end = text.size();
    // bool vowel_begin = false;
    int length = 0;
    while (pos < end) {
        if (CheckVowel(text[pos])) {
           length += 1;
        } else {
            if (length > 0) {
                return {pos - length, length};
            }
        }
        pos += 1;
    }
    if (length == 0) {
        return {-1, -1};
    }
    return {pos - length, length};
}
