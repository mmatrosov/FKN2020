/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
*/


#include <bits/stdc++.h>


using namespace std;


#define int long long


void warp()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}


const int INF = 1e18;


void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<pair<int, int> > > g(n);
    for (int i = 0; i < m; i++)
    {
        int v, u, l;
        cin >> v >> u >> l;
        v--;
        u--;
        g[v].push_back(make_pair(u, l));
        g[u].push_back(make_pair(v, l));
    }
    int s, f;
    cin >> s >> f;
    s--;
    f--;
    vector<int> smoke(n, INF);
    vector<int> dist(n, INF);
    dist[s] = 0;
    set<pair<int, int> > q;
    //q.insert(make_pair(0, s + n));
    for (int i = 0; i < k; i++)
    {
        smoke[a[i]] = 0;
        //q.insert(make_pair(0, a[i]));
    }
    for (int i = 0; i < n; i++)
    {
        q.insert(make_pair(smoke[i], i));
        q.insert(make_pair(dist[i], i + n));
    }
    while (q.size())
    {
        pair<int, int> cur = *(q.begin());
        q.erase(cur);
        int t = cur.first, v = cur.second;
        if (v < n)
        {
            for (int i = 0; i < g[v].size(); i++)
            {
                int u = g[v][i].first, l = g[v][i].second;
                if (smoke[v] + l < smoke[u])
                {
                    q.erase(make_pair(smoke[u], u));
                    smoke[u] = smoke[v] + l;
                    q.insert(make_pair(smoke[u], u));
                }
            }
        }
        else
        {
            v -= n;
            if (smoke[v] <= t)
            {
                dist[v] = INF;
                continue;
            }
            for (int i = 0; i < g[v].size(); i++)
            {
                int u = g[v][i].first, l = g[v][i].second;
                if (dist[v] + l < dist[u])
                {
                    q.erase(make_pair(dist[u], u + n));
                    dist[u] = dist[v] + l;
                    q.insert(make_pair(dist[u], u + n));
                }
            }
        }
    }
    if (dist[f] == INF)
    {
        cout << -1 << endl;
        return;
    }
    cout << dist[f] << endl;
}


signed main()
{
    warp();
    solve();
    return 0;
}
