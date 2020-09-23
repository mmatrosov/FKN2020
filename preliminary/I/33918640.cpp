#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

ll INF = (ll) 1e20;
int iINF = (int) 1e20;
ll mod = (ll) 1e9 + 7;
ll p = 137;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<vector<pair<ll, ll>>> nodes(n);
    for (int i = 0; i < m; ++i) {
        ll u, v, l;
        cin >> u >> v >> l;
        nodes[u - 1].push_back({v - 1, l});
        nodes[v - 1].push_back({u - 1, l});
    }
    set<pair<ll, ll>> st;
    vector<ll> dist(n, INF);
    for (auto i : a) {
        dist[i] = 0;
        st.insert({0, i});
    }
    while (!st.empty()) {
        pair<ll, ll> p = (*st.begin());
        st.erase(st.begin());
        ll v = p.second, l = p.first;
        dist[v] = l;
        for (auto i : nodes[v]) {
            if (dist[i.first] > dist[v] + i.second) {
                st.erase({dist[i.first], i.first});
                dist[i.first] = dist[v] + i.second;
                st.insert({dist[i.first], i.first});
            }
        }
    }
    vector <ll> dist1(n, INF);
    ll s, f;
    cin >> s >> f;
    --s, --f;
    dist1[s] = 0;
    st.insert({0, s});
    while (!st.empty()) {
        pair<ll, ll> p = (*st.begin());
        st.erase(st.begin());
        ll v = p.second, l = p.first;
        dist1[v] = l;
        for (auto i : nodes[v]) {
            if (dist1[i.first] > dist1[v] + i.second) {
                st.erase({dist1[i.first], i.first});
                dist1[i.first] = dist1[v] + i.second;
                st.insert({dist1[i.first], i.first});
            }
        }
    }
    if(dist1[f] < dist[f]) {
        cout << dist1[f];
        return 0;
    }
    cout << -1;
}