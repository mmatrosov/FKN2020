#include <iostream>
#include <string>

using namespace std;

bool get_bit(char c, int num) {
    return (c >> num) & 1;
}

int main() {
    string s;
    getline(cin, s);
    int cnt = 0;
    for (size_t i = 0; i < s.size(); i++) {
        cnt++;
        if (get_bit(s[i], 7) && get_bit(s[i], 6) && get_bit(s[i], 5) && get_bit(s[i], 4)) {
            i += 3;
        } else if (get_bit(s[i], 7) && get_bit(s[i], 6) && get_bit(s[i], 5)) {
            i += 2;
        } else if (get_bit(s[i], 7) && get_bit(s[i], 6)) {
            i += 1;
        }
    }
    cout << cnt << endl;
    return 0;
}
