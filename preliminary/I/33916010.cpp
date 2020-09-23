#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

const int N = 2e5 + 47;

vector<pair<int, int>> g[N];

int n, m, k, bad[N], dist[N], bad_dist[N];

void PUNKS_NOT_DEAD() {
    cin >> n >> m >> k;
    set<tuple<int, int, int>> s;

    fill(dist, dist + N, 2e18);
    fill(bad_dist, bad_dist + N, 2e18);
    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
        bad_dist[v] = 0;
        s.insert({0, -1, v});
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int st, ff;
    cin >> st >> ff;
    dist[st] = 0;
    s.insert({0, +1, st});
    while (s.size()) {
        auto [dst, type, u] = *s.begin();
        s.erase(s.begin());
        if (type == -1) {
            bad[u] = +1;
            for (auto [v, c] : g[u]) {
                if (bad_dist[v] > bad_dist[u] + c) {
                    s.erase({bad_dist[v], -1, v});
                    bad_dist[v] = bad_dist[u] + c;
                    s.insert({bad_dist[v], -1, v});
                }
            }
        } else {
            for (auto [v, c] : g[u]) {
                if (dist[v] > dist[u] + c) {
                    s.erase({dist[v], +1, v});
                    dist[v] = dist[u] + c;
                    s.insert({dist[v], +1, v});
                }
            }
        }
    }
    //cout << dist[ff] << ' ' << bad_dist[ff] << endl;
    if (dist[ff] >= bad_dist[ff]) cout << -1;
    else cout << dist[ff];
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    PUNKS_NOT_DEAD();
}