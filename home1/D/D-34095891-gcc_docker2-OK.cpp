#include <iostream>
#include <string>

bool contains(const std::string &s, const std::string &tofind) {
    return s.find(tofind) != std::string::npos;
}

int main() {
    std::string flags;
    std::getline(std::cin, flags);
    bool _m = contains(flags, "-m");
    bool _l = contains(flags, "-l");
    bool _L = contains(flags, "-L");
    bool _w = contains(flags, "-w");

    int ansm = 0, ansl = 0, ansL = 0, answ = 0;
    std::string curLine;
    while (std::getline(std::cin, curLine)) {
        ansl++;
        ansL = std::max(ansL, static_cast<int>(curLine.size()));
        ansm += static_cast<int>(curLine.size()) + 1;
        bool word = false;
        for (char c : curLine) {
            if (std::isspace(c)) {
                if (word) answ++;
                word = false;
            } else {
                word = true;
            }
        }
        if (word) ++answ;
    }
    if (_l) std::cout << ansl << ' ';
    if (_w) std::cout << answ << ' ';
    if (_m) std::cout << ansm << ' ';
    if (_L) std::cout << ansL << ' ';
    std::cout << std::endl;
    return 0;
}