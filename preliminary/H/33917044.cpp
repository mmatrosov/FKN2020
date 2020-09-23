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
    cout << "30 65\n"
            "5 10 2 4 2 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4";
}