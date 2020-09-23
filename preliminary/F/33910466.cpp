#include <bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native") */

//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ss second
#define ff first
#define int long long
//#define double long double
#define pb push_back

const int N = 2e6 + 51, MOD = 1e9 + 7, mod = 998244353,INF = 2e16;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;

int dp[1000][1000], pr[1000][1000], n, k;
vi a, ans;

void rec(int i, int k1) {
    if (i >= n) return;
    ans.pb(a[i]);
    i = pr[i][k1];
    rec(i, k1 - 1);
}

signed main() {
    #ifdef Flash
     freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a.resize(n);
    while (k > n) {
        k--;
        ans.pb(1);
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= k + 1; j++) dp[i][j] = - INF;
    }
    for (int i = 0; i <= k; i++) dp[n][i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans1 = -INF;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            int x = -INF;
            for (int i1 = i; i1 < n; i1++) {
                if (x < (i1 - i + 1) * a[i] + dp[i1 + 1][j]) {
                    pr[i][j + 1] = i1 + 1;
                }
                x = max(x, (i1 - i + 1) * a[i] + dp[i1 + 1][j]);
            }
            dp[i][j + 1] = x;
            ans1 = max(x, ans1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans1 == dp[i][k]) {
            rec(i, k);
            sort(ans.begin(), ans.end());
            for (auto to : ans) cout << to << ' ';
            return 0;
        }
    }
    for (auto to : ans) cout << to << ' ';
}
