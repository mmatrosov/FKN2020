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

const int N = 113, mod = 1e9 + 7;

int dp[N][N], pr[N][N];

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> in(n);
    for (int i = 0; i < n; i++)
        cin >> in[i];
    sort(in.rbegin(), in.rend());
    in.insert(in.begin(), 0);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int l = 0; l < j; l++)
            {
                if (dp[i - 1][l] + (j - l) * in[j] > dp[i][j])
                {
                    pr[i][j] = l;
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][l] + (j - l) * in[j]);
            }
        }
    }
    int ans = -1, uki, ukj;
    for (int i = 1; i <= n; i++)
    {
        if (dp[k][i] > ans)
        {
            ans = dp[k][i];
            uki = k;
            ukj = i;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        if (dp[i][n] > ans)
        {
            ans = dp[i][n];
            uki = i;
            ukj = n;
        }
    }
    vector<int> vans;
    while (uki)
    {
        vans.push_back(in[ukj]);
        ukj = pr[uki][ukj];
        uki--;
    }
    sort(vans.begin(), vans.end());
    for (int i : vans)
        cout << i << ' ';
}