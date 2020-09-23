// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma warning(disable : 4996)

// by ivan esipov

#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
const int maxn = 3e5 + 500;
const int mod = 1e9 + 7;
const int INF = 1e18 + 1;
// const ld eps = 1e-8;
// mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
vector<pair<int, int> >g[maxn];
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>a(k), d(n, INF);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < m; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        x--, y--;
        g[x].pb({y, l});
        g[y].pb({x, l});
    }
    int s, f;
    cin >> s >> f;
    s--, f--;
    set<pair<int, int> >st;
    for (int i = 0; i < k; i++) {
        st.insert({0, a[i]});
        d[a[i]] = 0;
    }
    while (!st.empty()) {
        int v = st.begin()->S;
        st.erase(st.begin());
        for (auto [to, w] : g[v]) {
            if (d[v] + w < d[to]) {
                st.erase({d[to], to});
                d[to] = d[v] + w;
                st.insert({d[to], to});
            }
        }
    }
    // for (int i = 0; i < n; i++) cout << d[i] << ' ';cout << endl;
    vector<int>d1(n, INF);
    d1[s] = 0;
    st.insert({0, s});
    while (!st.empty()) {
        int v = st.begin()->S;
        st.erase(st.begin());
        for (auto [to, w] : g[v]) {
            if (d1[v] + w < d1[to] && d1[v] + w < d[to]) {
                st.erase({d1[to], to});
                d1[to] = d1[v] + w;
                st.insert({d1[to], to});
            }
        }
    }
    // for (int i = 0; i < n; i++) cout << d1[i] << ' ';cout << endl;
    if (d1[f] == INF) cout << -1;
    else cout << d1[f];
    return 0;
}