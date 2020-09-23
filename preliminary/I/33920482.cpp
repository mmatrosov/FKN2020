#include <bits/stdc++.h>
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define len(a) (int) (a).size()
#define forn(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define int long long
using namespace std;
void solve();
mt19937 rnd(2007);
signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    swap(rng, rnd);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

struct edge{
    int to;
    int w;
};

vector<vector<edge>> gp, g;
const int inf = 1e16;

vector<int> dist(vector<vector<edge>> g, vector<int> tminf, int s){
    int n = len(g);
    vector<int> d (n, inf);
    d[s] = 0;
    set <pair<int,int>> q;
    q.insert (make_pair (d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase (q.begin());
        if (d[v] >= tminf[v]){
            d[v] = inf;
            continue;
        }

        for (auto u : g[v]) {
            if (d[v] + u.w < d[u.to]) {
                q.erase (make_pair (d[u.to], u.to));
                d[u.to] = d[v] + u.w;
                q.insert (make_pair (d[u.to], u.to));
            }
        }
    }

    return d;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    gp.resize(n + 1); g.resize(n);
    forn (i, k){
        int val; cin >> val;
        gp[0].push_back({val, 0});
        gp[val].push_back({0, 0});
    }
    forn (qwe, m){
        int v, u, w; cin >> v >> u >> w;
        gp[v].push_back({u, w});
        gp[u].push_back({v, w});
        v--;
        u--;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    int s, f; cin >> s >> f; s--; f--;
    vector<int> tminf0(n + 1, inf);
    auto tminf = dist(gp, tminf0, 0);
    reverse(all(tminf)); tminf.pop_back(); reverse(all(tminf));

    auto dst = dist(g, tminf, s);
    int ans = dst[f];
    if (ans == inf)
        ans = -1;
    cout << ans << endl;
}