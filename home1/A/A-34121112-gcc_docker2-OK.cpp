#include <iostream>
#include <cctype>
using namespace std;

int main() {
        string password;
        getline(cin, password);

        if (password.size() < 8 || 14 < password.size()) {
               cout << "NO" << endl;
               return 0;
        }

        int cnt[4]{0, 0, 0, 0};
        for (const char &ch : password) {
                if (ch < 33 || 126 < ch) {
                        cout << "NO" << endl;
                        return 0;
                }
                if (isupper(ch)) {
                        ++cnt[0];
                } else if (islower(ch)) {
                        ++cnt[1];
                } else if (isdigit(ch)) {
                        ++cnt[2];
                } else {
                        ++cnt[3];
                }
        }
        int total = 0;
        for (int i = 0; i < 4; ++i) {
                total += !!cnt[i];
        }
        cout << (total >= 3 ? "YES" : "NO") << endl;
}
