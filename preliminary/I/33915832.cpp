#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
mt19937 rnd;

struct Edge {
    int to, w;
};

const int N = 2e5 + 10;
const ll inf = 1e18;
vector<Edge> g[N];
bool fire[N];
ll dist[2][N];
priority_queue<pair<ll, int>> pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int cur;
        cin >> cur;
        fire[cur] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    int s, t;
    cin >> s >> t;
    for (int i = 1; i <= n; i++) {
        if (fire[i]) {
            dist[0][i] = 0;
            pq.push({0, i});
        }
        else {
            dist[0][i] = inf;
        }
    }
    while (!pq.empty()) {
        int v = pq.top().S;
        pq.pop();
        for (Edge e : g[v]) {
            if (dist[0][e.to] > dist[0][v] + e.w) {
                dist[0][e.to] = dist[0][v] + e.w;
                pq.push({-dist[0][e.to], e.to});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        dist[1][i] = inf;
    }
    dist[1][s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int v = pq.top().S;
        pq.pop();
        for (Edge e : g[v]) {
            if (dist[1][e.to] > dist[1][v] + e.w && dist[0][e.to] > dist[1][v] + e.w) {
                dist[1][e.to] = dist[1][v] + e.w;
                pq.push({-dist[1][e.to], e.to});
            }
        }
    }
    if (dist[1][t] == inf) {
        cout << "-1\n";
    }
    else {
        cout << dist[1][t] << "\n";
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
