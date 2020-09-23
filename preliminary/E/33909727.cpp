#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>


using namespace std;


void to_lower(string &s) {
    for (char &c : s) {
        if ('A' <= c && c <= 'Z') {
            c += 'a' - 'A';
        }
    }
}


bool c, d;


bool is_digit(char c) {
    return '0' <= c && c <= '9';
}


bool can_be_used(char c) {
    if (c == '_') {
        return true;
    }

    if ('a' <= c && c <= 'z') {
        return true;
    }

    if ('A' <= c && c <= 'Z') {
        return true;
    }

    return is_digit(c);
}


int main() {
    int n;

    cin >> n;

    string s;
    cin >> s;

    c = (s == "yes");

    cin >> s;

    d = (s == "yes");

    set<string> kws;
    string kw;
    for (int i = 0; i < n; ++i) {
        cin >> kw;

        if (!c) {
            to_lower(kw);
        }

        kws.insert(kw);
    }

    vector<string> pids;

    while (cin >> s) {
        int m = s.length();

        int last = 0;
        for (int i = 0; i < m; ++i) {
            if (can_be_used(s[i])) {
                continue;
            }

            if (last == i) {
                ++last;

                continue;
            }

            pids.push_back(s.substr(last, i - last));

            last = i + 1;
        }

        if (last != m) {
            pids.push_back(s.substr(last, m - last));
        }
    }

    vector<string> ids;
    for (string cs : pids) {
        if (!d && is_digit(cs[0])) {
            continue;
        }

        if (!c) {
            to_lower(cs);
        }

        int len = cs.length();
        int ds = 0;
        for (char c : cs) {
            ds += is_digit(c);
        }

        if (ds == len) {
            continue;
        }

        if (kws.find(cs) == kws.end()) {
            ids.push_back(cs);
        }
    }

    int answ = 0;

    map<string, int> cnt;
    for (string cs : ids) {
        ++cnt[cs];

        if (cnt[cs] > answ) {
            answ = cnt[cs];
        }
    }

    for (string cs : ids) {
        if (cnt[cs] == answ) {
            cout << cs;

            return 0;
        }
    }

    return 0;
}
