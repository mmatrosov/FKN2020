//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<pair<int, int> > > g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int s, f;
    cin >> s >> f;
    s--, f--;
    vector<ll> fire(n, INF);
    for (int i: a) fire[i] = 0;
    set<pair<ll, int> > all;
    for (int i: a) all.insert({0, i});
    while (!all.empty()) {
        int u = (*all.begin()).second;
        all.erase(all.begin());
        for (auto elem: g[u]) {
            int v = elem.first, w = elem.second;
            if (fire[v] > fire[u] + w) {
                all.erase({fire[v], v});
                fire[v] = fire[u] + w;
                all.insert({fire[v], v});
            }
        }
    }
    // for (int i = 0; i < n; i++) cout << fire[i] << ' ';
    // cout << endl;
    vector<ll> dist(n, INF);
    dist[s] = 0;
    set<pair<ll, int> > st;
    st.insert({0, s});
    while (!st.empty()) {
        int u = (*st.begin()).second;
        st.erase(st.begin());
        for (auto elem: g[u]) {
            int v = elem.first, w = elem.second;
            if (dist[v] > dist[u] + w && dist[u] + w < fire[v]) {
                st.erase({dist[v], v});
                dist[v] = dist[u] + w;
                st.insert({dist[v], v});
            }
        }
    }
    if (dist[f] == INF) {
        cout << -1 << endl;
    }
    else {
        cout << dist[f] << endl;
    }
    return 0;
}
