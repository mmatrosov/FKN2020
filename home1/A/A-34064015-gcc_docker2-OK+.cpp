#include <iostream>
#include <string>

int main() {
    std::string s;
    getline(std::cin, s);
    bool isBig = 0, isLow = 0, isDig = 0, isOthr = 0, isBad = 0;
    int demands = 0;
    for (int i = 0; i < s.size(); i += 1) {
        if (s[i] < 33 || s[i] > 126) {
            isBad = 1;
            break;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (!isLow) {
                demands += 1;
            }
            isLow = 1;
            continue;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (!isBig) {
                demands += 1;
            }
            isBig = 1;
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            if (!isDig) {
                demands += 1;
            }
            isDig = 1;
            continue;
        }
        if (!isOthr) {
            demands += 1;
        }
        isOthr = 1;
    }
    if (isBad || demands < 3 || s.size() < 8 || s.size() > 14) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
    return 0;
}