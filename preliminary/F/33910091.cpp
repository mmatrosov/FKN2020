#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> num;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (a != 0)
            num.push_back(a);
    }

    n = num.size();
    int add = max(0, k - n);
    k = min(k, n);

    sort(num.begin(), num.end());

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -INF));
    vector<vector<int>> from(n + 1, vector<int>(k + 1, -1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int p = 0; p < i; p++)
            {
                ll val = dp[p][j - 1] + num[p] * (ll)(i - p);
                if (val > dp[i][j])
                {
                    dp[i][j] = val;
                    from[i][j] = p;
                }
            }
        }
    }

    vector<ll> ans;
    int cur = n;
    for (int j = k; j > 0; j--)
    {
        ans.push_back(num[from[cur][j]]);
        cur = from[cur][j];
    }

    sort(ans.begin(), ans.end());
    for (ll x : ans)
        cout << x << " ";
    for (int i = 0; i < add; i++)
        cout << (int)1e8 + i << " ";

    return 0;
}
