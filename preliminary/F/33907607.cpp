#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

const int N = 101;

int dp[N][N], n, a[N], k, pr[N][N];

void PUNKS_NOT_DEAD() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        dp[1][i] = a[i] * (n - i + 1);
        pr[1][i] = -1;
    }
    for (int i = 2; i <= k; i++) {
        for (int l = 1; l <= n; l++) {
            for (int c = l; c <= n; c++) {
                if (dp[i][c] <= dp[i - 1][l] + (a[c] - a[l]) * (n - c + 1)) {
                    dp[i][c] = dp[i - 1][l] + (a[c] - a[l]) * (n - c + 1);
                    pr[i][c] = l;
                }
            }
        }
    }
    int last = 0, best = 0;
    for (int c = 1; c <= n; c++) {
        if (dp[k][c] > best) {
            best = dp[k][c];
            last = c;
        }
    }
    vector<int> ans;
    while (k--) {
        ans.push_back(a[last]);
        last = pr[k + 1][last];
    }
    reverse(all(ans));
    for (auto x : ans) cout << x << ' ';
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    PUNKS_NOT_DEAD();
}