#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5;
vector <pair <int, int> > g[maxn];
int xr[maxn];

void dfs(int v, int pr, int a) {
    xr[v] = pr;
    for (auto el : g[v]) {
        int u = el.first, w = el.second;
        if (u != a) dfs(u, pr ^ w, v);
    }
}

struct node {
    int t0, t1;
    node () {
        t0 = -1;
        t1 = -1;
    }
};

vector <node> bor;

void add(int v, int mask, int bit) {
    if (bit < 0) return;
    if (mask & (1ll << bit)) {
        if (bor[v].t1 != -1ll) {
            add(bor[v].t1, mask, bit - 1);
            return;
        }
        while (bit >= 0) {
            if (mask & (1ll << bit)) bor[v].t1 = bor.size();
            else bor[v].t0 = bor.size();
            v = bor.size();
            bor.push_back(node());
            --bit;
        }
        return;
    }
    if (bor[v].t0 != -1) {
        add(bor[v].t0, mask, bit - 1);
        return;
    }
    while (bit >= 0) {
        if (mask & (1ll << bit)) bor[v].t1 = bor.size();
        else bor[v].t0 = bor.size();
        v = bor.size();
        bor.push_back(node());
        --bit;
    }
}

int get(int v, int mask, int bit) {
    if (bit < 0) return 0;
    if (mask & (1ll << bit)) {
        if (bor[v].t0 != -1) return get(bor[v].t0, mask, bit - 1);
        return (1ll << bit) + get(bor[v].t1, mask, bit - 1);
    }
    if (bor[v].t1 != -1) return (1ll << bit) + get(bor[v].t1, mask, bit - 1);
    return get(bor[v].t0, mask, bit - 1);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        --v;
        --u;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    dfs(0, 0, -1);
    node root = node();
    bor.push_back(root);
    for (int i = 0; i < n; ++i) add(0, xr[i], 31);
    pair <int, int> kek = {0, 0};
    for (int i = 0; i < n; ++i) {
        int res = get(0, xr[i], 31);
        //cout << xr[i] << ' ' << res << endl;
        if ((kek.first ^ kek.second) < (xr[i] ^ res)) {
            kek.first = xr[i];
            kek.second = res;
        }
    }
    int v, u;
    for (int i = 0; i < n; ++i) {
        if (xr[i] == kek.first) v = i;
    }
    for (int i = 0; i < n; ++i) {
        if (xr[i] == kek.second) u = i;
    }
    cout << v + 1 << ' ' << u + 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
