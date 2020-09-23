#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200;
int dp[N][N], a[N], f[N][N];
vector<int> ans;

signed main() {
    memset(dp, 0x80, sizeof dp);
    dp[0][0] = 0;
    int n, k;
    cin >> n >> k;
    if (k > n) {
        for (int i = 0; i < k - n; i++) ans.push_back(1e8 + i);
        k = n;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int d = 0; d < i; d++) {
                if (dp[d][j - 1] + a[i] * (i - d) > dp[i][j]) f[i][j] = d;
                dp[i][j] = max(dp[i][j], dp[d][j - 1] + a[i] * (i - d));
            }
        }
    }
    int mx = 0, st = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i][k] > mx) mx = dp[i][k], st = i;
    }
    int ptr = k, pos = st;
    while(ptr) {
        ans.push_back(a[pos]);
        pos = f[pos][ptr];
        ptr--;
    };
    for (int i = 0; i < ans.size(); i++) {
        if (!ans[i]) ans[i] = 1e7 + i;
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " ";
}
