#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

ll INF = (ll) 1e20;
int iINF = (int) 1e20;
ll mod = (ll) 1e9 + 7;
ll p = 137;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

ll hsh(string s) {
    ll h = 0;
    for (auto i : s) {
        h = (h * p + i) % mod;
    }
    return h;
}

bool ok(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_');
}

bool reg, num;

string reformat(string s) {
    if (!reg) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] -= ('A' - 'a');
        }
    }
    return s;
}

signed main() {
    fast
    ll n;
    string a, b;
    cin >> n >> a >> b;
    reg = (a == "yes");
    num = (b == "yes");
    set<ll> restricted;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        restricted.insert(hsh(reformat(s)));
    }
    map<ll, ll> mp;
    map<ll, ll> ff;
    map<ll, string> mm;
    ll global = 0;
    while (!cin.eof()) {
        string s;
        cin >> s;
        s = reformat(s);
        string now;
        bool is = false;
        bool banned = false;
        for (int i = 0; i < s.size(); ++i) {
            if (ok(s[i])) {
                if (banned)
                    continue;
                if (now.empty()) {
                    if (s[i] >= '0' && s[i] <= '9' && !num) {
                        banned = true;
                        continue;
                    }
                }
                if (!(s[i] >= '0' && s[i] <= '9')) {
                    is = true;
                }
                now += s[i];
            } else {
                banned = false;
                if (!is) {
                    now.clear();
                    continue;
                }
                if (now.empty()) {
                    is = false;
                    continue;
                }
                ll h = hsh(now);
                if (restricted.count(h))
                    continue;
                if (ff.find(h) == ff.end()) {
                    ff[h] = global;
                }
                mp[h]++;
                mm[h] = now;
//                cout << now << ' ' << h << '\n';
                now.clear();
                is = false;
            }
            ++global;
        }
        if (!is) {
            now.clear();
            continue;
        }
        if (now.empty()) {
            is = false;
            continue;
        }
        is = false;
        ll h = hsh(now);
        if (restricted.count(h))
            continue;
        if (ff.find(h) == ff.end()) {
            ff[h] = global;
        }
        mp[h]++;
        mm[h] = now;
//        cout << now << ' ' << h << '\n';
        now.clear();
    }
    ll ans = 0, numans = 0;
    for (auto i :mp) {
        if (i.second > numans) {
            ans = i.first, numans = i.second;
        } else if (i.second == numans) {
            if (ff[i.first] < ff[ans]) {
                ans = i.first;
            }
        }
    }
    cout << mm[ans] << '\n';
}