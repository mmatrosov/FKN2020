#include <iostream>
using namespace std;

int how_many_bytes(char first_byte) {
        int ones = __builtin_clz((unsigned char)first_byte ^ 255) - 24;
        return (ones == 0 ? 1 : ones);
}

int main() {
        string str;
        getline(cin, str);
        int rest = 0, cur_code = 0;
        for (const char &ch : str) {
                if (rest == 0) {
                        rest = how_many_bytes(ch);
                        cur_code = static_cast<int>(ch) & ((1 << (8 - rest)) - 1);
                } else {
                        cur_code = (cur_code << 6) + (ch & ((1 << 6) - 1));
                }
                if (--rest == 0) {
                        cout << cur_code << ' ';
                }
        }
        cout << endl;
}

