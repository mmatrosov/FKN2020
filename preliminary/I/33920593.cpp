#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long

using namespace std;
const int INF = 2e15;
const int MB = 20;
const int MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        g[x].push_back({ y, w });
        g[y].push_back({ x, w });
    }

    int s, f;
    cin >> s >> f;
    s--; f--;

    priority_queue<pair<int, int>> q;
    vector<int> d(n, INF), nd(n, INF);

    for (int v : a) {
        nd[v] = 0;
        q.push({ 0, v });
    }


    while (!q.empty()) {
        auto p = q.top();
        q.pop();

        int len = -p.first;
        int v = p.second;
        if (len != nd[v]) continue;
        for (auto& pp : g[v]) {
            int u = pp.first;
            int w = pp.second;
            if (nd[u] > nd[v] + w) {
                nd[u] = nd[v] + w;
                q.push({ -nd[u], u });
            }
        }
    }

    d[s] = 0;
    q.push({ 0, s });
    while (!q.empty()) {
        auto p = q.top();
        q.pop();

        int len = -p.first;
        int v = p.second;
        if (len != d[v]) continue;
        for (auto& pp : g[v]) {
            int u = pp.first;
            int w = pp.second;
            if (d[u] > d[v] + w && d[v] + w < nd[u]) {
                d[u] = d[v] + w;
                q.push({ -d[u], u });
            }
        }
    }

    cout << (d[f] == INF ? -1 : d[f]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(12);
    //srand(time(0));
    int t = 1;
    //int t;
    //cin >> t;
    while (t--) solve();
}