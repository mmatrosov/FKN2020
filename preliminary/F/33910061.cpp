#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using vi = vector<int>;
#define f(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define fk(n) for(int k = 0; k < n; k++)
#define ci(n) cin >> n;
#define ic(n) int n; cin >> n;
#define lc(n) int n; cin >> n;
#define all(a) a.begin(), a.end()
#define pri(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define sc(a, n) int a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define scl(a, n) ll a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define pb push_back
#define eb emplace_back
#define int long long
const int inf = 1e15, maxn = 40;


void solve()
{

}

main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ic(n)
    ic(k)
    sc(a, n)
    sort(a, a + n);
    reverse(a, a + n);
    int tn = n;
    f(tn) if(a[i] > 0) n = i + 1;
    int dp[n][k + 1], p[n][k];
    f(n) fj(k + 1) dp[i][j] = -inf;
    f(n) fj(k) p[i][j] = -1;
    dp[0][1] = a[0];
    for(int i = 1; i < n; i++)
    {
        for(int j = 2; j <= i + 1 && j <= k; j++)
        {
            for(int pr = 0; pr < i; pr++)
            {
                if(dp[pr][j - 1] + a[i] * (i - pr) > dp[i][j])
                {
                    dp[i][j] = dp[pr][j - 1] + a[i] * (i - pr);
                    p[i][j] = pr;
                }
            }
        }
        dp[i][1] = a[i] * (i + 1);
    }
    int si, sj = min(n, k), mx = -inf;
    f(n) if(dp[i][sj] > mx) mx = dp[i][sj], si = i;
    //cout << mx << ' ' << si << ' ' << sj << '\n';
    vector<int> ans;
    while(sj > 0)
    {
        //cout << si << ' ' << a[si] << '\n';
        ans.pb(a[si]);
        si = p[si][sj];
        sj--;
    }
    int t = 1e5 + 1;
    while(ans.size() < k) ans.pb(t++);
    sort(all(ans));
    pri(ans, k)
}
