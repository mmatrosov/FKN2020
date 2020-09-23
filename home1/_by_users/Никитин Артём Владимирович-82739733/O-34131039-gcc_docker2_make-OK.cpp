#include <iostream>
#include <string>

std::pair <int, int> FindVowels(const std::string& text, int pos) {
    std::string vowels = "AaEeIiOoUuYy";
    int start = pos;
    int len = 0;
    while (start < text.length() && vowels.find(text[start]) == -1)
        start++;
    for (int i = start; i < text.length() && vowels.find(text[i]) != -1; i++)
        len++;
    if (len == 0)
        start = std::string::npos;
    return { start, len };
}
