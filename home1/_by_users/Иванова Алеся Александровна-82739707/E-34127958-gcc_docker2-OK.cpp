#include <iostream>

int count_symbols(const std::string& str) {
    int pos = 0;
    int answer = 0;
    while (pos < str.size()) {
        ++answer;
        int c = str[pos];
        if (c < 0)
            c += 256;
        if (c < (1 << 7)) {
            pos++;
            continue;
        }
        pos += 2;
        if (c & (1 << 5)) {
            ++pos;
            if (c & (1 << 4))
                ++pos;
        }
    }
    return answer;
}

signed main() {
    std::string str = "";
    getline(std::cin, str);
    std::cout << count_symbols(str);
}
