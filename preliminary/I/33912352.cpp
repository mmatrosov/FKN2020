#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>


using namespace std;


#define int long long


const int INF = (int)1e16;


signed main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];

        --a[i];
    }

    vector<vector<pair<int, int>>> graph(n);

    int x, y, l;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> l;
        
        --x;
        --y;

        graph[x].emplace_back(y, l);
        graph[y].emplace_back(x, l);
    }

    int s, f;
    cin >> s >> f;

    --s;
    --f;

    vector<int> fired(n, INF);
    priority_queue<pair<int, int>> djk;

    for (int x : a) {
        fired[x] = 0;

        djk.emplace(0, x);
    }

    while (!djk.empty()) {
        int v = djk.top().second;
        int d = -djk.top().first;

        djk.pop();

        if (fired[v] < d) {
            continue;
        }

        for (auto p : graph[v]) {
            int u = p.first;
            int w = p.second;

            if (fired[u] > d + w) {
                fired[u] = d + w;

                djk.emplace(-fired[u], u);
            }
        }
    }

    vector<int> dist(n, INF);
    dist[s] = 0;
    djk.emplace(0, s);

    while (!djk.empty()) {
        int v = djk.top().second;
        int d = -djk.top().first;

        djk.pop();

        if (dist[v] < d) {
            continue;
        }

        if (dist[v] >= fired[v]) {
            continue;
        }

        for (auto p : graph[v]) {
            int u = p.first;
            int w = p.second;

            if (dist[u] > d + w) {
                dist[u] = d + w;

                djk.emplace(-dist[u], u);
            }
        }
    }

    if (dist[f] == INF || dist[f] >= fired[f]) {
        cout << -1;

        return 0;
    }

    cout << dist[f];

    return 0;
}
