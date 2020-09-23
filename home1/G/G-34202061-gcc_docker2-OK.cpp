#include <iostream>
#include <string>
#include <vector>

int get_byte(char& c) {
    int answer = c;
    if (answer < 0)
        return answer + 256;
    return answer;
}

std::vector<int> get_codes(std::string& bytes) {
    std::vector<int> codes;
    for (size_t i = 0; i < bytes.size(); ++i) {
        int byte1 = get_byte(bytes[i]);
        if (byte1 < (1 << 7)) {
            codes.push_back(byte1);
        } else if (!(byte1 & (1 << 5))) {
            int code = byte1 % (1 << 5);
            int byte2 = get_byte(bytes[i + 1]);
            code = (code << 6) + byte2 % (1 << 6);
            codes.push_back(code);
            ++i;
        } else if (!(byte1 & (1 << 4))) {
            int code = byte1 % (1 << 4);
            int byte2 = get_byte(bytes[i + 1]);
            code = (code << 6) + byte2 % (1 << 6);
            int byte3 = get_byte(bytes[i + 2]);
            code = (code << 6) + byte3 % (1 << 6);
            codes.push_back(code);
            i += 2;
        } else {
            int code = byte1 % (1 << 3);
            int byte2 = get_byte(bytes[i + 1]);
            code = (code << 6) + byte2 % (1 << 6);
            int byte3 = get_byte(bytes[i + 2]);
            code = (code << 6) + byte3 % (1 << 6);
            int byte4 = get_byte(bytes[i + 3]);
            code = (code << 6) + byte4 % (1 << 6);
            codes.push_back(code);
            i += 3;
        }
    }
    return codes;
}

signed main() {
    std::string bytes;
    getline(std::cin, bytes);
    auto codes = get_codes(bytes);
    for (int code : codes)
        std::cout << code << " ";
}
