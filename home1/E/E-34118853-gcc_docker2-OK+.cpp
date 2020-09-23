#include <iostream>
using namespace std;

int ones_count(char c) {
        return __builtin_clz((unsigned char)c ^ 255) - 24;
}

int main() {
        string str;
        getline(cin, str);
        int char_count = 0, sym_rest = 0;
        for (const auto &ch : str) {
                if (!sym_rest) {
                        ++char_count;
                        sym_rest = ones_count(ch);
                }
                if (sym_rest) {
                        --sym_rest;
                }
        }
        cout << char_count << endl;
}
