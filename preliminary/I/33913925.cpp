#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second

using namespace std;

const int maxn = 2e5 + 1;
const long long inf = 1e15;

int n, m, k;
vector<pi> g[maxn];
long long d[maxn], d1[maxn];
bool usd[maxn];
int s, t;

inline void dijkstra(int sp) {
    for (int i = 0; i <= n; i++)
        d[i] = inf;
    d[sp] = 0;
    priority_queue<pair<long long, int> > s1;
    s1.push({0, sp});
    while (!s1.empty()) {
        auto gg = s1.top();
        s1.pop();
        if (usd[gg.r] || gg.l != -d[gg.r]) continue;
        int x = gg.r;
        for (auto to : g[x]) {
            long long nd = d[x] + to.r;
            if (d[to.l] > nd) {
                d[to.l] = nd;
                s1.push({-d[to.l], to.l});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x; --x;
        g[n].pb({x, 0});
        g[x].pb({n, 0});
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    cin >> s >> t; --s; --t;
    dijkstra(n);
    for (int i = 0; i <= n; i++)
        d1[i] = d[i];
    dijkstra(s);
    cout << (d[t] >= d1[t] ? -1 : d[t]);
    return 0;
}
