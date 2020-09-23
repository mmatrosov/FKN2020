#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
        string answer;

        int sym_num;
        while (cin >> sym_num) {
                if (sym_num < (1 << 7)) {
                        answer += static_cast<char>(sym_num);
                } else if (sym_num < (1 << 11)) {
                        answer += static_cast<char>((1 << 7) + (1 << 6) + (sym_num >> 6));
                        answer += static_cast<char>((1 << 7) + (((1 << 6) - 1) & sym_num));
                } else if (sym_num < (1 << 16)) {
                        answer += static_cast<char>((1 << 7) + (1 << 6) + (1 << 5)
                                        + (sym_num >> 12));
                        answer += static_cast<char>((1 << 7) + (((1 << 6) - 1) & (sym_num >> 6)));
                        answer += static_cast<char>((1 << 7) + (((1 << 6) - 1) & sym_num));
                } else {
                        answer += static_cast<char>((1 << 7) + (1 << 6) + (1 << 5) + (1 << 4)
                                        + (sym_num >> 18));
                        answer += static_cast<char>((1 << 7) + (((1 << 6) - 1) & (sym_num >> 12)));
                        answer += static_cast<char>((1 << 7) + (((1 << 6) - 1) & (sym_num >> 6)));
                        answer += static_cast<char>((1 << 7) + (((1 << 6) - 1) & sym_num));
                }
        }
        cout << answer << endl;
}
