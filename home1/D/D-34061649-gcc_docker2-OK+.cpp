#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    bool m = 0, l = 0, L = 0, w = 0;
    std::string keys;
    getline(std::cin, keys);
    for (int i = 0; i < keys.length(); i++) {
        switch (keys[i]) {
            case 'm':
                m = 1;
                break;
            case 'l':
                l = 1;
                break;
            case 'L':
                L = 1;
                break;
            case 'w':
                w = 1;
                break;
            default:
                break;
        }
    }
    std::string temp;
    int symbCount = 0, lineCount = 0, maxLen = 0, wordCount = 0;
    while (getline(std::cin, temp)) {
        ++lineCount;
        int tl = temp.length();
        symbCount += tl;
        maxLen = std::max(maxLen, tl);
        if (temp.empty())
            continue;
        bool lastSpace = (temp[0] == ' ');
        for (int i = 1; i < temp.length(); i++) {
            if (temp[i] == ' ') {
                if (!lastSpace)
                    ++wordCount;
                lastSpace = 1;
            } else {
                lastSpace = 0;
            }
        }
        if (!lastSpace)
            ++wordCount;
    }
    symbCount += lineCount;
    if (l)
        std::cout << lineCount << ' ';
    if (w)
        std::cout << wordCount << ' ';
    if (m)
        std::cout << symbCount << ' ';
    if (L)
        std::cout << maxLen;
    return 0;
}