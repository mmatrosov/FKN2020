#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define int long long
const int INF = 1e18;
const int N = 2e5 + 1;
vector<pair<int, int>> g[N];
int bad[N];
signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    set<tuple<int, int, int>> st;
    vector<int> d(n + 1, INF);
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        d[x] = 0;
        st.insert({0, 0, x});
    }
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        g[a].emplace_back(b, l);
        g[b].emplace_back(a, l);
    }
    int s, f;
    cin >> s >> f;
    d[s] = 0;
    bad[s] = 1; 
    st.insert({0, 1, s});
    while (!st.empty()) {
        auto [dist, dddd, v] = *st.begin();
        if (v == f) {
            if (!bad[f]) {
                cout << -1;
                return 0;
            } else {
                cout << d[f];
                return 0;
            }
        }
        st.erase(st.begin());
        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to] || (d[v] + len == d[to] && !bad[v])) {
                st.erase({d[to], bad[to], to});
                d[to] = d[v] + len;
                bad[to] = bad[v];
                st.insert({d[to], bad[to], to});
            }
        }
    }
    cout << -1;
}
