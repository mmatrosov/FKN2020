#include <bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native") */

//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ss second
#define ff first
#define int long long
#define double long double
#define pb push_back

const int N = 2e6 + 51, MOD = 1e9 + 7, mod = 998244353,INF = 2e16;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;

int d[N], a[N];
vp g[N];

void dey(int v) {
    set <pair <int, int>> s;
    d[v] = 0;
    s.insert({0, v});
    while (!s.empty()) {
        int u = s.begin() -> second;
        s.erase(*s.begin());
        for (auto to : g[u]) {
            if (d[to.ff] > to.ss + d[u]) {
                s.erase({d[to.ff], to.ff});
                d[to.ff] = to.ss + d[u];
                s.insert({d[to.ff], to.ff});
            }
        }
    }
}

signed main() {
    #ifdef Flash
     freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int l, r, cost;
        cin >> l >> r >> cost;
        g[l].pb({r, cost});
        g[r].pb({l, cost});
    }
    int s, f;
    for (int i = 0; i <= n; i++) d[i] = INF;
    cin >> s >> f;
    dey(f);
    int mn = INF;
    for (int i = 0; i < k; i++) mn = min(mn, d[a[i]]);
    if (mn <= d[s]) {
        cout << -1;
        return 0;
    }
    cout << d[s];
}
