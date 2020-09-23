#include <bits/stdc++.h>
#define int long long
#define to first
#define wt second
using namespace std;

const int N = 2.1e5;
int deatht[N], d[N];
vector<pair<int, int>> g[N];
set<pair<int, int>> S;
int used[N];

void dijkstra1() {
    while (!S.empty()) {
        int w, cur;
        tie(w, cur) = *S.begin();
        S.erase(S.begin());
        used[cur] = 1;
        for (auto i : g[cur]) {
            if (deatht[i.to] > deatht[cur] + i.wt && !used[i.to]) S.insert({w + i.wt, i.to}), deatht[i.to] = deatht[cur] + i.wt;
        }
    }
}

void dijkstra2() {
    while (!S.empty()) {
        int w, cur;
        tie(w, cur) = *S.begin();
        S.erase(S.begin());
        used[cur] = 1;
        for (auto i : g[cur]) {
            if (d[i.to] > d[cur] + i.wt && !used[i.to] && deatht[i.to] > d[cur] + i.wt) S.insert({w + i.wt, i.to}), d[i.to] = d[cur] + i.wt;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> fire(k);
    for (int i = 1; i <= n; i++) deatht[i] = d[i] = LLONG_MAX / 5;
    for (int i = 0; i < k; i++) cin >> fire[i], S.insert({0, fire[i]}), deatht[fire[i]] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int f, s;
    cin >> s >> f;
    dijkstra1();
    S.clear();
    S.insert({0, s});
    d[s] = 0;
    memset(used, 0, sizeof used);
    dijkstra2();
    // for (int i = 1; i <= n; i++) cout << d[i] << " ";
    cout << (d[f] > 1e15 ? -1 : d[f]);
}
