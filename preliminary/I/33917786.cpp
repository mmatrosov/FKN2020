#include <bits/stdc++.h>

using namespace std;

#define int long long

const int big = 1e18;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[k];
    vector <pair <int, int> > g[n];
    for (int i = 0; i < k; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        --v;
        --u;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    vector <int> d(n, big);
    for (int i = 0; i < k; ++i) d[a[i] - 1] = 0;
    set <pair <int, int> > q;
    for (int i = 0; i < k; ++i) q.insert({0, a[i] - 1});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto el : g[v]) {
            int u = el.first, w = el.second;
            if (d[u] > d[v] + w) {
                q.erase({d[u], u});
                d[u] = d[v] + w;
                q.insert({d[u], u});
            }
        }
    }
    int s, f;
    cin >> s >> f;
    --s;
    --f;
    vector <int> dist(n, big);
    dist[s] = 0;
    if (d[s] == 0) {
        cout << -1;
        return;
    }
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto el : g[v]) {
            int u = el.first, w = el.second;
            if (dist[u] > dist[v] + w && dist[v] + w < d[u]) {
                q.erase({dist[u], u});
                dist[u] = dist[v] + w;
                q.insert({dist[u], u});
            }
        }
    }
    if (dist[f] == big) cout << -1;
    else cout << dist[f];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
