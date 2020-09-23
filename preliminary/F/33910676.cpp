#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define ld long double

const int maxn = 109;
int dp[maxn][maxn];
int pr[maxn][maxn];
int n, k;
int a[maxn];
int inf = 1e9;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (!a[i])
        {
            n--;
            i--;
        }
    }
    sort(a, a + n);
    vector<int> b;
    for (int i = 0; i < n; i++)
        b.pb(a[i]);
    uniq(b);
    if (k >= (int)b.size())
    {
        int pt = 0;
        int cur = 1;
        while (k)
        {
            if (pt < (int)b.size() && cur == b[pt])
            {
                pt++;
                cout << cur << " ";
                cur++;
                k--;
            }
            else if ((int)b.size() - pt < k)
            {
                cout << cur << " ";
                cur++;
                k--;
            }
            else
                cur = b[pt];
        }
        return 0;
    }
    for (int i = 0; i < maxn; i++)
        for (int e = 0; e < maxn; e++)
            dp[i][e] = -inf;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            continue;
        dp[i][0] = 0;
        for (int cnt = 1; cnt <= i && cnt <= k; cnt++)
        {
            for (int e = i - 1; e >= cnt - 1; e--)
            {
                int cur = dp[e][cnt - 1] + a[e] * (i - e);
                if (cur > dp[i][cnt])
                {
                    dp[i][cnt] = cur;
                    pr[i][cnt] = e;
                }
            }
        }
    }
    vector<int> ans;
    int j = n;
    k++;
    while (k)
    {
        if (j != n)
            ans.pb(a[j]);
        k--;
        j = pr[j][k];
    }
    reverse(all(ans));
    for (int e : ans)
        cout << e << " ";
}
