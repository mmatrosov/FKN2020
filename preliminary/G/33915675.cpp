#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
#define all(v) v.begin(), v.end()
using namespace std;
const int maxn = 200000, inf = 1e18;
vector<pair<int, int> > gr[maxn];
int mas[maxn];
void dfs(int v, int pr, int tek) {
    mas[v] = tek;
    for (pair<int, int> p : gr[v]) {
        if (p.ft != pr) {
            dfs(p.ft, v, tek ^ p.sc);
        }
    }
}
struct var {
    int v, s0, s1;
    var(int _v, int _s0, int _s1) {
        v = _v; s0 = _s0; s1 = _s1;
    }
    var() {
        v = -1; s0 = -1; s1 = -1;
    }
};
var vars[4000000];
int uk = 1;
void add_v(int ch, int nm) {
    int tek = 0;
    for (int i = 31; i >= 0; i--) {
        if ((ch & (1ll << i)) != 0) {
            if (vars[tek].s1 != -1) {
                tek = vars[tek].s1;
            } else {
                vars[uk].v = -1; vars[uk].s0 = -1; vars[uk].s1 = -1;
                vars[tek].s1 = uk;
                tek = uk;
                uk++;
            }
        } else {
            if (vars[tek].s0 != -1) {
                tek = vars[tek].s0;
            } else {
                vars[uk].v = -1; vars[uk].s0 = -1; vars[uk].s1 = -1;
                vars[tek].s0 = uk;
                tek = uk;
                uk++;
            }
        }
    }
    vars[tek].v = nm;
}
int best(int ch) {
    int tek = 0;
    for (int i = 31; i >= 0; i--) {
        if ((ch & (1ll << i)) == 0) {
            if (vars[tek].s1 != -1) {
                tek = vars[tek].s1;
            } else if (vars[tek].s0 != -1) {
                tek = vars[tek].s0;
            } else {
                break;
            }
        } else {
            if (vars[tek].s0 != -1) {
                tek = vars[tek].s0;
            } else if (vars[tek].s1 != -1) {
                tek = vars[tek].s1;
            } else {
                break;
            }
        }
    }
    return vars[tek].v;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int d = 0; d < n - 1; d++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        int w;
        cin >> w;
        gr[v].pb({u, w});
        gr[u].pb({v, w});
    }
    dfs(0, -1, 0);
    vars[0].v = -1;
    vars[0].s0 = -1;
    vars[0].s0 = -1;
    for (int d = 0; d < n; d++) {
        add_v(mas[d], d);
    }
    int max1 = 0, rem1 = 0, rem2 = 0;
    for (int d = 0; d < n; d++) {
        int u = best(mas[d]);
        if ((mas[u] ^ mas[d]) > max1) {
            max1 = (mas[u] ^ mas[d]);
            rem1 = u;
            rem2 = d;
        }
    }
    cout << rem1 + 1 << " " << rem2 + 1;
}
