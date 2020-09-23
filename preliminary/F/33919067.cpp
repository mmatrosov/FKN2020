#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[a[i]]++;
    }
    vector<pair<int, int>> b;
    for (auto i : m) {
        b.emplace_back(i);
    }
    n = b.size();
    for (int i = n - 2; i >= 0; i--) {
        b[i].second += b[i + 1].second;
    }
    if (k >= n) {
        if (b[0].first == 0) {
            for (int i = 1; i < n; i++) {
                cout << b[i].first << " ";
            }
            for (int i = 0; i < k - n + 1; i++) {
                cout << b[n - 1].first + i + 1 << " ";
            }
        } else {
            for (int i = 0; i < n; i++) {
                cout << b[i].first << " ";
            }
            for (int i = 0; i < k - n; i++) {
                cout << b[n - 1].first + i + 1 << " ";
            }
        }
    } else {
        vector<vector<int>> dp(k, vector<int>(n, 0));
        vector<vector<int>> pr(k, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            dp[0][i] = b[i].first * b[i].second;
        }
        for (int i = 1; i < k; i++) {
            for (int j = i - 1; j < n; j++) {
                for (int p = j + 1; p < n; p++) {
                    if (dp[i][p] < dp[i - 1][j] + (b[p].first - b[j].first) * b[p].second) {
                        dp[i][p] = dp[i - 1][j] + (b[p].first - b[j].first) * b[p].second;
                        pr[i][p] = j;
                    }
                }
            }
        }
        vector<int> ans(k);
        int mx = 0;
        int t = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, dp[k - 1][i]);
        }
        for (int i = 0; i < n; i++) {
            if (dp[k - 1][i] == mx) {
                t = i;
                break;
            }
        }
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = b[t].first;
            t = pr[i][t];
        }
        sort(ans.begin(), ans.end());
        if (ans[0] == 0) {
            for (int i = 1; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout << ans[ans.size() - 1] + 1;
        } else {
            for (int i : ans) {
                cout << i << " ";
            }
        }
    }
}

int main() {
#ifdef OLYMP
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
