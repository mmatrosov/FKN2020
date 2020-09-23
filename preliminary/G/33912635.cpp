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
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = 1e9 + 1;
// const ld eps = 1e-8;
// mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
vector<pair<int, int> >g[maxn];
int d[maxn];
void dfs(int v, int p, int x) {
    d[v] = x;
    for (auto [to, w] : g[v]) {
        if (to == p) continue;
        dfs(to, v, x ^ w);
    }
}
struct nd {
    int32_t next[2] = {-1, -1};
    int32_t lf;
};
nd t[maxn * 35];
int sz = 1;
void add(int id) {
    int x = d[id];
    int v = 0;
    for (int i = 31; i >= 0; i--) {
        int dig = (!!((1ll << i) & x));
        if (t[v].next[dig] == -1) {
            t[v].next[dig] = sz++;
        }
        v = t[v].next[dig];
    }
    t[v].lf = id;
}
int go(int v, int x, int d) {
    if (d == 32) return t[v].lf;
    int k = !!((1ll << (32 - d - 1)) & x);
    if (t[v].next[k ^ 1] != -1) {
        return go(t[v].next[k ^ 1], x, d + 1);
    }
    if (t[v].next[k] == -1) while(1);
    return go(t[v].next[k], x, d + 1); 
}
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].push_back({v - 1, w});
        g[v - 1].push_back({u - 1, w});
    }
    dfs(0, -1, 0);
    for (int i = 0; i < n; i++) {
        add(i);
    }
    pair<int, pair<int, int> >ans = {-1, {-1, -1}};
    for (int i = 0; i < n; i++) {
        int fnd = go(0, d[i], 0);
        ans = max(ans, {d[fnd] ^ d[i], {fnd + 1, i + 1}});
    }
    cout << ans.S.F << ' ' << ans.S.S;
    return 0;
}