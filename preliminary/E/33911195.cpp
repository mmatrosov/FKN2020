#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct ID {
    string s;
    int cnt, idx;

    ID(string s_, int cnt_, int idx_) {
        s = s_;
        cnt = cnt_;
        idx = idx_;
    }

    bool operator< (ID& other) {
        if (cnt != other.cnt) {
            return cnt > other.cnt;
        }
        return idx < other.idx;
    }
};

string reg, numBeg;
set<string> keywords;

bool isUpper(const char& c) {
    return 'A' <= c && c <= 'Z';
}

bool isLower(const char& c) {
    return 'a' <= c && c <= 'z';
}

bool isLetter(const char& c) {
    return isLower(c) || isUpper(c);
}

bool isDigit(const char& c) {
    return '0' <= c && c <= '9';
}

char toLower(const char& c) {
    return char(c - 'A' + 'a');
}

bool isIDsymb(const char & c) {
    return c == '_' || isLetter(c) || isDigit(c);
}

string toLower(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (isUpper(s[i])) {
            s[i] = toLower(s[i]);
        }
    }

    return s;
}

bool isID(string& s) {
    if (s.size() == 0) {
        return false;
    }

    if (keywords.count(s)) {
        return false;
    }

    if (numBeg == "no" && isDigit(s[0])) {
        return false;
    }

    bool flag = false;
    for (int i = 0; i < s.size(); ++i) {
        if (!isIDsymb(s[i])) {
            return false;
        }

        if (!isDigit(s[i])) {
            flag = true;
        }
    }

    return flag;
}

signed main() {
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n >> reg >> numBeg;

    for (int i = 0; i < n; ++i) {
        string id;
        cin >> id;

        if (reg == "no") {
            id = toLower(id);
        }

        keywords.insert(id);
    }

    map<string, pair<int, int>> cnt;

    string s = "";
    int idx = 0;
    char c;
    while (!cin.eof()) {
        ++idx;
        c = cin.get();

        if (!isIDsymb(c)) {
            if (!isID(s)) {
                s = "";
                continue;
            }

            if (cnt.find(s) == cnt.end()) {
                cnt[s] = {1, idx};
            } else {
                ++cnt[s].first;
            }

            s = "";
        } else {
            if (reg == "no" && isUpper(c)) {
                c = toLower(c);
            }

            s += c;
        }

    }

    if (isID(s)) {
        if (reg == "no") {
            s = toLower(s);
        }

        if (cnt.find(s) == cnt.end()) {
            cnt[s] = {1, idx};
        } else {
            ++cnt[s].first;
        }
    }

    vector<ID> ids;
    for (auto& [key, value]: cnt) {
        ids.emplace_back(key, value.first, value.second);
    }

    sort(ids.begin(), ids.end(), [](ID& id1, ID& id2) {
            if (id1.cnt != id2.cnt) {
            return id1.cnt > id2.cnt;
            }
            return id1.idx < id2.idx;
    });

    cout << ids[0].s << '\n';
}
