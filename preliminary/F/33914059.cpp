#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
#define all(v) v.begin(), v.end()
using namespace std;
const int maxn = 101, inf = 1e15;
int dp[maxn][maxn];
int rem[maxn][maxn];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> vec(n, 0);
    for (int d = 0; d < n; d++) {
        cin >> vec[d];
    }
    sort(all(vec));
    if (k > n) {
        for (int d = 0; d < n; d++) {
            cout << vec[d] << " ";
        }
        for (int d = 0; d < k - n; d++) {
            cout << vec.back() + 1 + d << " ";
        }
        return 0;
    }
    for (int d = 0; d < n; d++) {
        for (int i = 0; i <= k; i++) {
            dp[d][i] = -inf;
        }
    }
    dp[0][1] = vec[0];
    for (int d = 0; d < n; d++) {
        dp[d][0] = 0;
        rem[d][0] = 0;
        for (int i = 1; i <= k; i++) {
            int cnt = 0;
            for (int j = d - 1; j >= 0; j--) {
                cnt++;
                if (dp[j][i - 1] + cnt * vec[j + 1] > dp[d][i]) {
                    dp[d][i] = dp[j][i - 1] + cnt * vec[j + 1];
                    rem[d][i] = j + 1;
                }
            }
        }
    }
    //cout << dp[n - 1][k];
    vector<int> ans;
    int tek = n - 1, kol = k;
    while (kol > 0) {
        ans.pb(vec[rem[tek][kol]]);
        tek = rem[tek][kol] - 1;
        kol--;
    }
    sort(all(ans));
    for (int d = 0; d < ans.size(); d++) {
        cout << ans[d] << " ";
    }
}
