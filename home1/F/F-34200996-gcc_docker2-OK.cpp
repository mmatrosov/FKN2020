#include <iostream>
#include <string>
#include <vector>

std::string get_bytes(std::vector<int>& codes) {
    std::string answer;
    for (int code : codes) {
        if (code < (1 << 7)) {
            char byte1 = code;
            answer += byte1;
        } else if (code < (1 << 11)) {
            char byte1 = (3 << 6) + (code >> 6);
            char byte2 = (1 << 7) + code % (1 << 6);
            answer += byte1;
            answer += byte2;
        } else if (code < (1 << 16)) {
            char byte1 = (7 << 5) + (code >> 12);
            char byte2 = (1 << 7) + (code >> 6) % (1 << 6);
            char byte3 = (1 << 7) + code % (1 << 6);
            answer += byte1;
            answer += byte2;
            answer += byte3;
        } else {
            char byte1 = (15 << 4) + (code >> 18);
            char byte2 = (1 << 7) + (code >> 12) % (1 << 6);
            char byte3 = (1 << 7) + (code >> 6) % (1 << 6);
            char byte4 = (1 << 7) + code % (1 << 6);
            answer += byte1;
            answer += byte2;
            answer += byte3;
            answer += byte4;
        }
    }
    return answer;
}

signed main() {
    std::vector<int> codes;
    int code;
    while (std::cin >> code) {
        codes.push_back(code);
    }
    std::cout << get_bytes(codes);
}
