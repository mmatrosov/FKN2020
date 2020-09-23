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

    ll k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;

    if (k1 == k2 && b1 == b2) {
        cout << "coincide" << endl;
        return 0;
    }
    if (k1 == k2) {
        cout << "parallel" << endl;
        return 0;
    }

    ld x = ((ld)b2 - (ld)b1) / ((ld)k1 - (ld)k2);
    ld y = (ld)k1 * x + (ld)b1;

    cout << "intersect" << endl;
    cout << fixed << setprecision(10) << x << " " << y << endl;

    return 0;
}