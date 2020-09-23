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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}


const int alpha = 2;
const int len = 32;


struct node
{
    node* g[alpha];
    vector<int> a;
    node()
    {
        for (int i = 0; i < alpha; i++) g[i] = NULL;
    }
};


typedef node* tree;


tree go(tree v, int id)
{
    if (v->g[id] == NULL)
    {
        v->g[id] = new node();
    }
    return v->g[id];
}


void dfs(int v, int prev, vector<vector<pair<int, int> > > &g, vector<int> &dp)
{
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i].first;
        if (u == prev) continue;
        int w = g[v][i].second;
        dp[u] = (dp[v] ^ w);
        dfs(u, v, g, dp);
    }
}


bool in(int mask, int i)
{
    return (mask & (1 << i)) > 0;
}


tree step(tree v, int id)
{
    if (v->g[id] == NULL) return v->g[id^1];
    return v->g[id];
}


void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 <<  " " << 1 << endl;
        return;
    }
    vector<int> dp(n);
    vector<vector<pair<int, int> > > g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;
        g[v].push_back(make_pair(u, w));
        g[u].push_back(make_pair(v, w));
    }
    dfs(0, -1, g, dp);
    //for (int i = 0; i < n; i++) cout << dp[i] << " ";
    //cout << endl;
    tree root = new node();
    for (int i = 0; i < n; i++)
    {
        tree cur = root;
        //cout << i << dp[i] << endl;
        for (int j = len - 1; j > -1; j--)
        {
            int id = in(dp[i], j);
            //cout << "HEY " << j << " " << id << endl;
            cur = go(cur, id);
        }
        cur->a.push_back(i);
    }
    int top = (dp[0] ^ dp[1]), ft = 0, sc = 1;
    for (int i = 0; i < n; i++)
    {
        tree cur = root, opt = root;
        for (int j = len - 1; j > -1; j--)
        {
            int id = in(dp[i], j);
            int his = (id^1);
            cur = go(cur, id);
            opt = step(opt, his);
        }
        int u = opt->a[0];
        if (u == i) u = opt->a[1];
        int val = (dp[i] ^ dp[u]);
        if (val > top)
        {
            top = val;
            ft = i;
            sc = u;
        }
    }
    /*cout << top << endl;
    cout << dp[2] << " " << dp[5] << endl;*/
    cout << ft + 1 << " " << sc + 1 << endl;
}


signed main()
{
    warp();
    solve();
    return 0;
}
