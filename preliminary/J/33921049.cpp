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
#define scn(a, n) int a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define scl(a, n) ll a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define sc second
#define ft first
#define int long long
const int inf = 1e18, maxn = 1e5, lg = 32;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool ok(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int n, m;
    cin >> n >> m;
    char ans[n][m];
    f(n) fj(m) ans[i][j] = '#';
    vector<int> xs, ys;
    f(n)
    {
        if(i & 1) for(int j = m - 1; j >= 0; j--) xs.pb(j), ys.pb(i);
        else fj(m) xs.pb(j), ys.pb(i);
    }
    int ls = 0, sz = 1;
    while(ls + sz <= n * m)
    {
        //cout << ls << '\n';
        int am[26] = {0};
        for(int i = ls; (i < ls + sz && ls + sz + sz + 1 <= n * m) || (i < n * m && ls + sz + sz + 1 > n * m); i++)
        {
            fj(4) if(ok(xs[i] + dx[j], ys[i] + dy[j]) && ans[ys[i] + dy[j]][xs[i] + dx[j]] != '#') am[ans[ys[i] + dy[j]][xs[i] + dx[j]] - 'A'] = 1;
        }
        char c;
        f(26)
        {
            if(am[i] == 0)
            {
                c = 'A' + i;
                break;
            }
        }
        //cout << c << '\n';
        for(int i = ls; (i < ls + sz && ls + sz + sz + 1 <= n * m) || (i < n * m && ls + sz + sz + 1 > n * m); i++)
        {
            ans[ys[i]][xs[i]] = c;
        }
        ls += sz;
        sz++;
    }
    cout << sz - 1 << '\n';
    f(n)
    {
        fj(m) cout << ans[i][j];
        cout << '\n';
    }
}
