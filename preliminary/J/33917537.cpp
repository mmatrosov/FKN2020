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


void step(int &curx, int &cury, int n, int m)
{
    if (cury + 1 < m) cury++;
    else
    {
        curx++;
        cury = 0;
    }
}


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


bool ok(int x, int y, int n, int m)
{
    return x > -1 && x < n && y > -1 && y < m;
}


void solve()
{
    int n, m;
    cin >> n >> m;
    int cnt = 1, all = 1;
    while (all + cnt + 1 <= n * m)
    {
        cnt++;
        all += cnt;
    }
    vector<vector<int> > a(n, vector<int> (m, -1));
    int curx = 0, cury = 0;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            a[curx][cury] = i;
            step(curx, cury, n, m);
        }
    }
    while (curx != n)
    {
        a[curx][cury] = cnt - 1;
        step(curx, cury, n, m);
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2) reverse(a[i].begin(), a[i].end());
    }
    vector<vector<int> > g(cnt);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (!ok(i + dx[k], j + dy[k], n, m)) continue;
                int v = a[i][j], u = a[i + dx[k]][j + dy[k]];
                if (v == u) continue;
                g[v].push_back(u);

            }
        }
    }
    vector<char> c(cnt, 'a');
    for (int i = 0; i < cnt; i++)
    {
        for (char cur = 'A'; cur <= 'Z'; cur++)
        {
            bool flag = true;
            for (int j = 0; j < g[i].size(); j++)
            {
                int u = g[i][j];
                if (c[u] == cur) flag = false;
            }
            if (flag)
            {
                c[i] = cur;
                break;
            }
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << c[a[i][j]];
        }
        cout << "\n";
    }
}


signed main()
{
    warp();
    solve();
    return 0;
}
