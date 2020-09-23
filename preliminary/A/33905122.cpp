#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ld long double
#define ull unsigned long long
#define mp make_pair

using namespace std;

void init() {
#ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef TEST
    freopen("!inp", "r", stdin);
    freopen("!out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int maxn = 2e5;

ll tree[maxn];

ll f(ll x) {
    return x & (x + 1);
}

void add(ll pos, ll val) {
    while (pos < maxn) {
        tree[pos] += val;
        pos |= (pos + 1);
    }
}

ll prefsum(ll pos) {
    ll ans = 0;
    while (pos >= 0) {
        ans += tree[pos];
        pos = f(pos) - 1;
    }
    return ans;
}

int main() {
    init();

    ll k;
    cin >> k;
    if (k == 1) {
        cout << "YES\n";
        return 0;
    }
    for (ll i = 1; i <= 1000000; i++) {
        if (2 * i + 2 * (i - 2) == k) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}