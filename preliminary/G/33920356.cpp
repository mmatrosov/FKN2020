#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ld long double

using namespace std;

const int maxn = 2e5 + 100;
const ll alpha = 29;
const ld eps = 1e-20;
const ll inf = 1e18;

void init() {
#ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef TEST
    freopen("!inp", "r", stdin);
    freopen("!out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vector<vector<pair<int, ll>>> g;

vector<ll> foo;

void dfs(int v, int p = -1) {
    for (auto ev : g[v]) {
        if (ev.ff == p)
            foo[v] = foo[p] ^ ev.ss;
    }

    for (auto ev : g[v]) {
        if (ev.ff == p) {
            continue;
        }

        dfs(ev.ff, v);
    }
}

ll deg[50];

int main() {
    init();

    for (int i = 0; i < 50; i++) {
        deg[i] = (1LL << i);
    }

    int n;
    cin >> n;
    foo.resize(n, 0);
    g.resize(n);

    if (n == 1) {
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].pb({v, c});
        g[v].pb({u, c});
    }

    dfs(0);

    ll ans = 0;
    pair<int, int> res;

    vector<pair<ll, int>> bar;
    for (int i = 0; i < n; i++)
        bar.pb({foo[i], i});

    sort(all(bar));
    reverse(all(bar));

    for (int i = 0; i < n; i++) {
        if (clock() >= 970000)
            break;
        ll cur = 0;
        for (int j = 0; j <= 33; j++) {
            if (((deg[j] & bar[i].ff) == 0) && ((deg[j + 1] & bar[i].ff) != 0))
                cur = j + 1;
        }

        for (int j = n - 1; bar[j].ff < deg[cur]; j--) {
            if ((bar[i].ff ^ bar[j].ff) > ans) {
                ans = (bar[i].ff ^ bar[j].ff);
                res = {bar[i].ss, bar[j].ss};
            }
        }
    }

    cout << res.ff + 1 << " " << res.ss + 1 << endl;

    return 0;
}