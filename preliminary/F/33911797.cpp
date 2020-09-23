#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define int long long
#define double long double
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define TIME ((clock() - start_time) / CLOCKS_PER_SEC)

using namespace std;
//using namespace __gnu_pbds;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count() + 'd'+'o'+'i'+'n'+'g' + 'g'+'e'+'y');

const int inf = 1e18;
const double eps = 1e-6;
double start_time;

const int maxn = 110;

int dp[maxn][maxn][maxn], best[maxn][maxn];


signed main()
{
    start_time = clock();
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    a.pb(0);
    reverse(all(a));
    if (k >= n) {
        set<int> s;
        for (int i = 1; i <= n; ++i) s.insert(a[i]);
        int mx = a[1];
        for (int x : s) cout << x << " ";
        for (int i = 1; i <= k - sz(s); ++i) cout << mx + i << " ";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int pos = 0; pos < i; ++pos) {
                dp[i][j][pos] = dp[i - 1][j][pos];
                dp[i][j][pos] = max(dp[i][j][pos], best[pos][j - 1] + a[i] * (i - pos));
                best[i][j] = max(best[i][j], dp[i][j][pos]);
            }
        }
    }
    vector<int> ans;
    int i = n, j = k;
    while (i) {
        int pos = 0;
        for (int t = 1; t < n; ++t) {
            if (dp[i][j][t] > dp[i][j][pos]) {
                pos = t;
            }
        }
        if (dp[i][j][pos] == dp[i - 1][j][pos]) {
            --i;
        } else {
            ans.pb(a[i]);
            --j;
            i = pos;
        }
    }
    sort(all(ans));
    while (sz(ans) < k) {
        ans.pb(ans.back() + 1);
    }
    for (int x : ans) cout << x << " ";
    return 0;
}