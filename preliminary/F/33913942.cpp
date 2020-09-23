#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
const int N = 200;
int dp[N][N];
int pr[N][N];
signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(all(v));
    vector<int> ans;
    dp[1][1] = v[0];
    pr[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int k_ = 1; k_ <= k; ++k_) {
            dp[i][k_] = dp[i - 1][k_];
            for (int j = i; j >= 1; --j) {
                int x = dp[i][k_];
                dp[i][k_] = max(dp[i][k_], dp[j - 1][k_ - 1] + v[j - 1] * (i - j + 1));
                if (dp[i][k_] != x) {
                    pr[i][k_] = j;
                }
            }
        }
    }
    int j = 1;
    for (int i = 1; i <= k; ++i) {
        if (dp[n][i] > dp[n][j]) {
            j = i;
        }
    }
    int i = n;
    while (j > 0) {
        int x = pr[i][j];
        ans.emplace_back(v[x - 1]);
        i = x - 1;
        --j;
    }
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    while (!ans.empty() && ans[0] == 0) {
        ans.erase(ans.begin());
    }
    if (ans.empty() && k > 0) {
        ans.emplace_back(0);
    }
    while (ans.size() < k) {
        ans.emplace_back(ans.back());
    }
    for (auto i : ans) {
        cout << i << " ";
    }
}
