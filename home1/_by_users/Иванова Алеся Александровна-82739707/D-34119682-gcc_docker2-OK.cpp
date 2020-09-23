#include <iostream>

void wc() {
    bool key_m = 0;
    bool key_l = 0;
    bool key_L = 0;
    bool key_w = 0;
    std::string s;
    getline(std::cin, s);
    for (const char& c : s) {
        if (c == 'm') {
            key_m = 1;
        } else if (c == 'l') {
            key_l = 1;
        } else if (c == 'L') {
            key_L = 1;
        } else if (c == 'w') {
            key_w = 1;
        }
    }
    int cnt_symbols = 0;
    int cnt_lines = 0;
    int max_line = 0;
    int cnt_words = 0;
    while (getline(std::cin, s)) {
        cnt_symbols += s.size() + 1;
        ++cnt_lines;
        if (s.size() > max_line) {
            max_line = s.size();
        }
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i]) && (!i || !isalnum(s[i - 1])))
                ++cnt_words;
        }
    }
    if (key_l) {
        std::cout << cnt_lines << " ";
    }
    if (key_w) {
        std::cout << cnt_words << " ";
    }
    if (key_m) {
        std::cout << cnt_symbols << " ";
    }
    if (key_L) {
        std::cout << max_line << " ";
    }
}

signed main() {
    wc();
}
