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
//#define double long double
#define pb push_back

const int N = 4e6 + 51, MOD = 1e9 + 7, mod = 998244353,INF = 2e16;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;

vp g[N], G[N];
int d[N], nw = 1, who[N];

void build(int v, int del, int deep, int num) {
    if (deep == -1) {
        who[v] = num;
        return;
    }
    int bit = (del >> deep) & 1ll;
    bool ok = false;
    for (auto to : G[v]) {
        if (to.ss == bit) {
            build(to.ff, del, deep - 1, num);
            ok = true;
        }
    }
    if (!ok) {
        G[v].pb({nw, bit});
        nw++;
        build(nw - 1, del, deep - 1, num);
    }
}

pair <int, int> ask(int v, int del, int deep, int tek) {
    if (deep == -1) {
        return {who[v], tek};
    }
    int bit = (del >> deep) & 1ll;
    for (auto to : G[v]) {
        if (to.ss != bit) {
            tek += (1ll << deep);
            return ask(to.ff, del, deep - 1, tek);
        }
    }
    for (auto to : G[v]) {
        return ask(to.ff, del, deep - 1, tek);
    }
}

void dfs (int v, int p, int tek) {
    d[v] = tek;
    for (auto to : g[v]) {
        if (to.ff == p) continue;
        dfs(to.ff, v, (to.ss ^ tek));
    }
}


signed main() {
    #ifdef Flash
     freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int l, r, cost;
        cin >> l >> r >> cost;
        g[l].pb({r, cost});
        g[r].pb({l, cost});
    }
    dfs(1, 1, 0);
    pair <int, int> chel = {1, 1};
    int ans = -INF;
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            auto to = ask(0, d[i], 32, 0);
            if (ans < to.ss) {
                ans = to.ss;
                chel = {i, to.ff};
            }
        }
        build(0, d[i], 32, i);
    }
    if (chel.ff > chel.ss) swap(chel.ff, chel.ss);
    cout << chel.ff << ' ' << chel.ss;

}
