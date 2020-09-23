#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    if (s.size() < 8 || s.size() > 14) {
        cout << "NO" << endl;
        return 0;
    }
    bool upper = false, lower = false, digit = false, other = false;
    for (char c : s) {
        if (!isprint(c) || c == ' ') {
            cout << "NO" << endl;
            return 0;
        }
        if (isupper(c)) upper = true;
        if (islower(c)) lower = true;
        if (isdigit(c)) digit = true;
        if (ispunct(c)) other = true;
    }
    if (upper + lower + digit + other >= 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
