// Bippolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef long double ld;

bool get_bool() {
    string s;
    cin >> s;
    if (s == "yes") {
        return true;
    }
    return false;
}

bool check_char(char ch) {
    if (ch >= '0' && ch <= '9') {
        return true;
    }
    if (ch >= 'a' && ch <= 'z') {
        return true;
    }
    if (ch >= 'A' && ch <= 'Z') {
        return true;
    }
    if (ch == '_') {
        return true;
    }
    return false;
}

int main() {
    ll n;
    cin >> n;
    bool flag_1 = get_bool();
    bool flag_2 = get_bool();
    set<string> used;
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (!flag_1) {
            for (auto& i : s) {
                if (i >= 'A' && i <= 'Z') {
                    i = i - 'A' + 'a';
                }
            }
        }
        used.insert(s);
    }
    string s;
    map<string, ll> cnt;
    map<string, ll> position;
    ll count_of_word = 0;
    string result = "";
    while (!cin.eof()) {
        char ch = cin.get();
        if (cin.eof() || !check_char(ch)) {
            if (s.empty()) {
                continue;
            }
            if (!flag_1) {
                for (auto& i : s) {
                    if (i >= 'A' && i <= 'Z') {
                        i = i - 'A' + 'a';
                    }
                }
            }
            bool flag = false;
            for (auto i : s) {
                if (i >= '0' && i <= '9') {
                    continue;
                }
                flag = true;
                break;
            }
            if (used.find(s) != used.end()) {
                flag = false;
            }
            if (s[0] >= '0' && s[0] <= '9' && !flag_2) {
                flag = false;
            }
            if (flag) {
                if (position[s] == 0) {
                    position[s] = ++count_of_word;
                }
                ++cnt[s];
                if (make_pair(cnt[s], -position[s]) > make_pair(cnt[result], -position[result])) {
                    result = s;
                }
            }
            s = "";
            continue;
        }
        s.push_back(ch);
    }
    cout << result << endl;
    return 0;
}
