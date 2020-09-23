#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define fi first
#define se second
 
using namespace std;


pii solve(vi &data, int l, int r)
{
	int ans = data[r];
	int h = data[r];
	int counter = 1;
	for (int i = r - 1; i >= l; --i)
	{
		counter++;
		if (data[i] * counter > ans)
		{
			ans = data[i] * counter;
			h = data[i];
		}
	}
	return {ans, h};
}

 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, kek;
    pii cur;
    cin >> n >> k;
    int mem = 0;
    if (k > n)
    {
    	mem = k - n;
    	k = n;
    }
    vi data(n);
    for (int i = 0; i < n; ++i) cin >> data[i];
    sort(all(data));
    vector<vector<pair<int, vi>>> dp(k + 1, vector<pair<int, vi>>(n, {-1, {}}));
    for (int i = 0; i < n; ++i)
    {
    	cur = solve(data, 0, i);
    	dp[1][i].fi = cur.fi;
    	dp[1][i].se = {cur.se};
    }
    for (int i = 2; i < k + 1; ++i)
    {
    	for (int j = i - 1; j < n; ++j)
    	{
    		int ans = -1;
    		vi vec;
    		for (int k = i - 2; k < j; ++k)
    		{
    			kek = dp[i - 1][k].fi + solve(data, k + 1, j).fi;
    			if (kek > ans)
    			{
    				ans = kek;
    				vec = dp[i - 1][k].se;
    				vec.pb(solve(data, k + 1, j).se);
    			}
    		}
    		dp[i][j].fi = ans;
    		dp[i][j].se = vec;
    	}
    }
    /*
    for (int i = 0; i < k + 1; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		cout << dp[i][j] << " ";
    	}
    	cout << endl;
    }
    */
    for (auto vv : dp[k][n - 1].se) cout << vv << " ";
    if (mem != 0)
    {
    	for (int i = 1000000; i < 1000000 + mem; ++i) cout << i << " ";
    }
    cout << endl;
}