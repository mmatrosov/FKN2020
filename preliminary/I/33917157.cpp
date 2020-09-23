#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
#define all(v) v.begin(), v.end()
using namespace std;
const int maxn = 200010, inf = 1e18;
int distd[maxn];
int dist[maxn];
vector<pair<int, int> > gr[maxn];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int d = 0; d < n; d++) {
        dist[d] = inf;
        distd[d] = inf;
    }
    set<pair<int, int> > stdim;
    for (int d = 0; d < k; d++) {
        int i;
        cin >> i;
        i--;
        distd[i] = 0;
    }
    for (int d = 0; d < n; d++) {
        stdim.insert({distd[d], d});
    }
    for (int d = 0; d < m; d++) {
        int v, u, l;
        cin >> v >> u >> l;
        v--; u--;
        gr[v].pb({u, l});
        gr[u].pb({v, l});
    }
    int s, f;
    cin >> s >> f;
    s--; f--;
    while (!stdim.empty()) {
        int v = (*stdim.begin()).sc;
        stdim.erase(stdim.begin());
        for (pair<int, int> p : gr[v]) {
            if (distd[p.ft] > distd[v] + p.sc) {
                stdim.erase({distd[p.ft], p.ft});
                distd[p.ft] = distd[v] + p.sc;
                stdim.insert({distd[p.ft], p.ft});
            }
        }
    }
    dist[s] = 0;
    set<pair<int, int> > st;
    for (int d = 0; d < n; d++) {
        st.insert({dist[d], d});
    }
    //st.insert({0, s});
    while(!st.empty()) {
        int v = (*st.begin()).sc;
        st.erase(st.begin());
        if (dist[v] >= distd[v]) {
            dist[v] = inf;
            continue;
        }
        for (pair<int, int> p : gr[v]) {
            if (dist[p.ft] > dist[v] + p.sc) {
                st.erase({dist[p.ft], p.ft});
                dist[p.ft] = dist[v] + p.sc;
                st.insert({dist[p.ft], p.ft});
            }
        }
    }
//    for (int d = 0; d < n; d++) {
//        cout << dist[d] << " ";
//    }
//    cout << "\n";
    if (dist[f] == inf) {
        cout << -1;
    } else {
        cout << dist[f];
    }
}
