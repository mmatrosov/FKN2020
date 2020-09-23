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
vector<vector<pair<int, int>>> g;
vector<int> xr;



pair<int, int> max_xor(vector<int> arr) {
    int n = len(arr);
    int maxx = 0, mask = 0;
    set<int> se;
    for (int i = 33; i >= 0; i--) {
        mask |= (1ll << i);
        for (int i = 0; i < n; ++i) {
            se.insert(arr[i] & mask);
        }
        int newMaxx = maxx | (1ll << i);

        for (int prefix : se) {

            if (se.count(newMaxx ^ prefix)) {
                maxx = newMaxx;
                break;
            }
        }

        se.clear();
    }
    map<int, int> was;
    forn (i, len(arr)){
        if (was.count(arr[i] ^ maxx))
            return {was[arr[i] ^ maxx], i};
        was[arr[i]] = i;
    }
    return {0, 0};


}

void dfs(int v, int p = -1){
    for (auto u : g[v]){
        if (u.first != p){
            xr[u.first] = xr[v] ^ u.second;
            dfs(u.first, v);
        }
    }
}

void solve() {
    int n; cin >> n;
    g.resize(n); xr.resize(n);
    forn (qwe, n - 1){
        int v, u, w; cin >> v >> u >> w; v--; u--;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    dfs(0);
    auto ans = max_xor(xr);
    cout << ans.first + 1 << ' ' << ans.second + 1 << endl;
}
