#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MAX = (int)(2e5) + 7;
const ll INF_LL = (ll)(1e18) + 7;

int n, m, k;
vector<pair<int, int>> gph[MAX];

signed main() {
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    vector<int> bad(k);
    for (auto& it : bad) {
        cin >> it;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> v >> u >> w;

        gph[v].emplace_back(u, w);
        gph[u].emplace_back(v, w);
    }

    vector<ll> dp(n + 1, INF_LL);
    set<pair<ll, int>> s;
    for (const auto& it : bad) {
        dp[it] = 0;
        s.insert({0, it});
    }

    while (s.size()) {
        int v = s.begin()->second;
        s.erase(s.begin());

        for (const auto& [u, w] : gph[v]) {
            if (dp[u] > dp[v] + w) {
                s.erase({dp[u], u});
                dp[u] = dp[v] + w;
                s.insert({dp[u], u});
            }
        }
    }

    vector<ll> dpp(n + 1, INF_LL);
    int st, f;
    cin >> st >> f;
    dpp[st] = 0;
    s.insert({dpp[st], st});

    while (s.size()) {
        int v = s.begin()->second;
        s.erase(s.begin());

        for (const auto & [u, w] : gph[v]) {
            if (dpp[u] > dpp[v] + w && dpp[v] + w < dp[u]) {
                s.erase({dpp[u], u});
                dpp[u] = dpp[v] + w;
                s.insert({dpp[u], u});
            }
        }
    }

    if (dpp[f] == INF_LL) {
        cout << -1 << '\n';
    } else {
        cout << dpp[f] << '\n';
    }
}
