#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second

using namespace std;

bool is_digit(char c) {
    return ('0' <= c && c <= '9');
}

bool is_letter(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

bool is_cor_symbol(char c) {
    if (is_digit(c)) return 1;
    if (c == '_') return 1;
    if (is_letter(c)) return 1;
    return 0;
}

void tlc(char &c) {
    if (!is_letter(c)) return;
    if ('a' <= c) return;
    c += ('a' - 'A');
}

bool C, D;
set<string> keywords;
map<string, int> mp;
map<string, int> lv;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; string Cs, Ds;
    cin >> n >> Cs >> Ds;
    C = (Cs == "yes");
    D = (Ds == "yes");
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (!C) {
            for (int j = 0; j < s.size(); j++)
                tlc(s[j]);
        }
        keywords.insert(s);
    }
    string s;
    int cj = 0;
    while (cin >> s) {
        string cs = "";
        for (int i = 0; i < s.size(); i++, cj++) {
            if (!is_cor_symbol(s[i])) {
                if (!cs.empty()) {
                    bool hnd = 0;
                    for (int j = 0; j < cs.size(); j++) {
                        if (!is_digit(cs[j])) hnd = 1;
                        if (!C) tlc(cs[j]);
                    }
                    if ((D || !is_digit(cs[0])) && hnd && keywords.find(cs) == keywords.end()) {
                        mp[cs]++;
                        if (lv.find(cs) == lv.end())
                            lv[cs] = cj - cs.size() + 1;
                    }
                }
                cs = ""; continue;
            }
            cs += s[i];
        }
        if (!cs.empty()) {
            bool hnd = 0;
            for (int j = 0; j < cs.size(); j++) {
                if (!is_digit(cs[j])) hnd = 1;
                if (!C) tlc(cs[j]);
            }
            if ((D || !is_digit(cs[0])) && hnd && keywords.find(cs) == keywords.end()) {
                mp[cs]++;
                if (lv.find(cs) == lv.end())
                    lv[cs] = cj - cs.size() + 1;
            }
        }
    }
    string ans = (*mp.begin()).l;
    int cnt = (*mp.begin()).r;
    int lc = lv[ans];
    for (auto gg : mp) {
        if (gg.r > cnt || gg.r == cnt && lv[gg.l] < lc) {
            ans = gg.l;
            cnt = gg.r;
            lc = lv[gg.l];
        }
    }
    cout << ans;
    return 0;
}
