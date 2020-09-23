// Bippolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;
typedef long double ld;

const ll INF = (ll)1e17 + 666;

vector<vector<pair<ll, ll>>> graph;

vector<ll> bfs(ll s) {
    vector<ll> dist(graph.size(), INF);
    dist[s] = 0;
    set<pair<ll, ll>> q;
    q.insert(make_pair(dist[s], s));
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());
        for (auto e : graph[v]) {
            ll u = e.first;
            if (dist[u] > dist[v] + e.second) {
                q.erase(make_pair(dist[u], u));
                dist[u] = dist[v] + e.second;
                q.insert(make_pair(dist[u], u));
            }
        }
    }
    return dist;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(k);
    for (ll i = 0; i < k; ++i) {
        cin >> a[i];
        --a[i];
    }
    graph.resize(n);
    for (ll i = 0; i < m; ++i) {
        ll v, u, w;
        cin >> v >> u >> w;
        graph[v - 1].emplace_back(u - 1, w);
        graph[u - 1].emplace_back(v - 1, w);
    }
    ll s, f;
    cin >> s >> f;
    --s;
    --f;
    vector<ll> dist = bfs(f);
    ll mn = INF;
    for (ll i : a) {
        mn = min(mn, dist[i]);
    }
    if (mn <= dist[s]) {
        cout << -1 << endl;
    } else {
        cout << dist[s] << endl;
    }
    return 0;
}
