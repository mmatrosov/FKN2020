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


void kill(vector<int> &a)
{
    vector <int> b;
    sort(a.begin(), a.end());
    if ((int)a.size() == 0) return;
    b.push_back(a[0]);
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] != a[i - 1]) b.push_back(a[i]);
    }
    reverse(b.begin(), b.end());
    while (b.size() && b.back() == 0) b.pop_back();
    reverse(b.begin(), b.end());
    a = b;
}


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    //for (int i = 0; i < n; i++) cout << a[i] << " ";
    //cout << endl;
    vector<vector<int> > dp(n, vector<int> (k + 1));
    vector<vector<int> > len(n, vector<int> (k + 1));
    dp[0] = vector<int> (k + 1, a[0]);
    dp[0][0] = 0;
    len[0] = vector<int> (k + 1, 1);
    len[0][0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = a[i] * (i + 1);
            len[i][j] = i + 1;
            for (int l = 1; l <= i; l++)
            {
                if (dp[i - l][j - 1] + l * a[i] > dp[i][j])
                {
                    len[i][j] = l;
                    dp[i][j] = dp[i - l][j - 1] + l * a[i];
                }
            }
        }
    }
    int top = -1, x = 0, y = k;
    for (int i = 0; i < n; i++)
    {
        if (dp[i][k] > top)
        {
            top = dp[i][k];
            x = i;
        }
    }
    vector<int> ans;
    while (x != -1)
    {
        ans.push_back(a[x]);
        x -= len[x][y];
        y--;
    }
    kill(ans);
    y = 1e9;
    while (ans.size() < k)
    {
        ans.push_back(y);
        y--;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; i++) cout << ans[i] << " ";
    cout << endl;
}


signed main()
{
    warp();
    solve();
    return 0;
}
