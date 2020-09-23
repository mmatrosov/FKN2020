// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma warning(disable : 4996)

// by ivan esipov

#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()
// #define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
const int maxn = 1e3 + 2;
const int mod = 1e9 + 7;
const int INF = 1e9 + 1;
// const ld eps = 1e-8;
// mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
bool fl1, fl2;
bool valid(char x) {
    if (x == '_' || x <= '9' && x >= '0' || x <= 'Z' && x >= 'A' || x <= 'z' && x >= 'a') return 1;
    return 0;
}
bool isdig(char x) {
    return (x >= '0' && x <= '9');
}
bool issmall(char x) {
    return (x <= 'z' && x >= 'a');
}
bool isbig(char x) {
    return (x <= 'Z' && x >= 'A');
}
bool validstr(string x) {
    if (!fl2) if (isdig(x[0])) return 0;
    for (int i = 0; i < x.size(); i++) {
        if (!isdig(x[i])) return 1;
    }
    return 0;
}
string low(string x) {
    string xx = x;
    for (int i = 0; i < xx.size(); i++) {
        if (isbig(xx[i])) xx[i] = (char)((xx[i] - 'A') + 'a');
    }
    return xx;
}
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    // ifstream in("input.txt");
    int n;
    cin >> n;
    // in >> n;
    string ss, tt;
    cin >> ss >> tt;
    // in >> ss >> tt;
    map<string, int>mp;
    if (ss == "yes") {
        fl1 = 1;
    } else fl1 = 0;
    if (tt == "yes") {
        fl2 = 1;
    } else fl2 = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // in >> s;
        if (!fl1) s = low(s);
        mp[s] = 1;
    }
    string s;
    map<string, int>key;
    int cnt = 0;
    map<string, int>fst;
    while (getline(cin, s)) {
        vector<string>shit;
        string cur;
        for (int i = 0; i < s.size(); i++) {
            if (valid(s[i])) cur += s[i];
            else if (!cur.empty()) {
                // cout << cur << ' ';
                if (validstr(cur)) shit.pb(cur);
                cur.clear();
            }
        }
        if (!cur.empty()) {
            if (validstr(cur)) shit.pb(cur);
            cur.clear();
        }
        // for (auto &x : shit) cout << x << ' '; cout << endl;
        for (auto &x : shit) {
            if (!fl1) {
                x = low(x);
            }
            if (mp.count(x)) continue;
            if (!fst.count(x)) fst[x] = cnt;
            cnt++;
            key[x]++;
        }
    }
    pair<int, pair<int, string>>ans = {-1, {-1, "!!!!!!"}};
    for (auto [a, b] : key) {
        // cout << a << ' ' << fst[a] << endl;
        ans = max(ans, {b, {-fst[a], a}});
    }
    cout << ans.S.S;
    return 0;
}