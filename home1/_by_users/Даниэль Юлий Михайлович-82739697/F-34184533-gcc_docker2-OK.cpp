#include <iostream>
#include <string>

const int MXONE = (1 << 7) - 1;
const int MXTWO = (1 << 11) - 1;
const int MXTHREE = (1 << 16) - 1;

const int SUFLEN = 6;
const int PREF = 128;
const int PREF_ONE = 192;
const int PREF_TWO = 224;
const int PREF_THREE = 240;

std::string convert(int code) {
    std::string ans;
    if (code <= MXONE) {
        ans.push_back(static_cast<char>(code));
    } else if (code <= MXTWO) {
        ans.push_back(static_cast<char>(PREF_ONE + (code >> SUFLEN)));
        ans.push_back(static_cast<char>(PREF + code % (1 << SUFLEN)));
    } else if (code <= MXTHREE) {
        ans.push_back(static_cast<char>(PREF_TWO + (code >> (2 * SUFLEN))));
        ans.push_back(static_cast<char>(PREF + (code >> SUFLEN) % (1 << SUFLEN)));
        ans.push_back(static_cast<char>(PREF + code % (1 << SUFLEN)));
    } else {
        ans.push_back(static_cast<char>(PREF_THREE + (code >> (3 * SUFLEN))));
        ans.push_back(static_cast<char>(PREF + (code >> 2 * SUFLEN) % (1 << SUFLEN)));
        ans.push_back(static_cast<char>(PREF + (code >> SUFLEN) % (1 << SUFLEN)));
        ans.push_back(static_cast<char>(PREF + code % (1 << SUFLEN)));
    }
    return ans;
}

int main() {
    int symbol;
    while (std::cin >> symbol) {
        std::cout << convert(symbol);
    }
    std::cout << std::endl;
    return 0;
}