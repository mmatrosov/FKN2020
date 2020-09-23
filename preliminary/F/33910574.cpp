// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma warning(disable : 4996)

// by ivan esipov

#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
const int maxn = 101;
const int mod = 1e9 + 7;
const int INF = 1e18 + 1;
// const ld eps = 1e-8;
// mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
int dp[maxn][maxn];
int p[maxn][maxn];
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int>a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i + 1];
    sort(all(a));
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            dp[i][j] = -INF;
        }
    }
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int lf = 1; lf <= i; lf++) {
                int val = dp[lf - 1][j - 1] + (i - lf + 1) * a[lf];
                if (dp[i][j] < val) {
                    dp[i][j] = val;
                    p[i][j] = lf;
                }
            }
        }
    }
    pair<int, int>mx = {-INF, -1};
    for (int i = 0; i <= k; i++) {
        mx = max(mx, {dp[n][i], i});
    }
    vector<int>ans;
    int mi = 1e9;
    for (int i = mx.S; i < k; i++) {
        ans.pb(mi);
        mi--;
    }
    int now = n;
    for (int i = mx.S; i >= 1; i--) {
        int z = p[now][i];
        ans.push_back(a[z]);
        z--;
        now = z;
    }
    for (auto &x : ans) if (x == 0) x = mi--;
    sort(all(ans));
    for (auto x : ans) cout << x << ' ';
    return 0;
}