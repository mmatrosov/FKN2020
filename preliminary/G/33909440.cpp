#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define l first
#define r second
#define pb push_back
#define int long long
#define double long double
#define sqrt sqrtl

using namespace std;

const int maxn = 2e5 + 1, mod = 1e9 + 7;

vector<pi> g[maxn];
int px[maxn];
int n;

void dfs(int x, int pr = -1) {
    for (auto to : g[x]) {
        if (to.l == pr) continue;
        px[to.l] = px[x] ^ to.r;
        dfs(to.l, x);
    }
}

bool check(int cj, int cx) {
    if (!cx) return 1;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int x = (px[i] >> cj) << cj;
        st.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int x = (px[i] >> cj) << cj;
        if (st.find(cx ^ x) != st.end())
            return 1;
    }
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dfs(0, -1);
    int can = 0;
    for (int j = 31; j >= 0; j--) {
        if (check(j, can + (1ll << j)))
            can += (1ll << j);
    }
    if (!can) {
        cout << "1 1";
        return 0;
    }
    map<int, int> cmp;
    for (int i = 0; i < n; i++)
        cmp[px[i]] = i + 1;
    for (int i = 0; i < n; i++) {
        if (cmp[px[i] ^ can]) {
            cout << i + 1 << ' ' << cmp[px[i] ^ can];
            return 0;
        }
    }
    return 0;
}
