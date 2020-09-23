#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve();

signed main()
{
#ifdef _______
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#else
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int _ = _ = _ = 1;
    for (_; _; --_)
        solve();
}

const int N = 2e5 + 77, mod = 1e9 + 7;

int tfr[N], t[N];

vector<pair<int, int>> g[N];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        tfr[i] = 1e18;
    for (int i = 0; i < k; i++)
    {
        int v;
        cin >> v;
        tfr[v] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        g[u].push_back({v, l});
        g[v].push_back({u, l});
    }
    int s, f;
    cin >> s >> f;
    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++)
    {
        st.insert({tfr[i], i});
    }
    while (st.size())
    {
        auto kek = *st.begin();
        st.erase(st.begin());
        for (auto to : g[kek.second])
        {
            if (tfr[to.first] > kek.first + to.second)
            {
                st.erase({tfr[to.first], to.first});
                tfr[to.first] = kek.first + to.second;
                st.insert({tfr[to.first], to.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != s)
        {
            t[i] = 1e18;
            st.insert({t[i], i});
        }
        else
        {
            t[i] = 0;
            st.insert({t[i], i});
        }
    }
    while (st.size())
    {
        auto kek = *st.begin();
        if (kek.first >= tfr[kek.second])
        {
            t[kek.second] = 1e18;
            kek.first = 1e18;
        }
        st.erase(st.begin());
        for (auto to : g[kek.second])
        {
            if (t[to.first] > kek.first + to.second)
            {
                st.erase({t[to.first], to.first});
                t[to.first] = kek.first + to.second;
                st.insert({t[to.first], to.first});
            }
        }
    }
    if (t[f] > 1e10)
    {
        cout << -1;
    }
    else
    {
        cout << t[f];
    }
}