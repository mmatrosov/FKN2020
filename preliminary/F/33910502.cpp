#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    vector <vector <pair <int, int> > > dp(n, vector <pair <int, int> > (k + 1, {0ll, -1ll}));
    int smaler[n];
    int val = 0;
    for (int i = 0; i < n; ++i) {
        smaler[i] = val;
        if (i + 1 < n && a[i] < a[i + 1]) val = i + 1;
    }
    dp[0][1].first = a[0] * n;
    for (int i = 1; i < n; ++i) {
        for (int j = 2; j <= k; ++j) {
            for (int id = 0; id < i; ++id) {
                if (a[id] == a[i] || dp[id][j - 1].first == 0) continue;
                dp[i][j] = max(dp[i][j], {dp[id][j - 1].first + (n - smaler[i]) * (a[i] - a[id]), id});
            }
        }
        dp[i][1].first = a[i] * (n - smaler[i]);
    }
    //for (int i = 0; i < n; ++i) for (int j = 0; j <= k; ++j) cout << i << ' ' << j << ' ' << dp[i][j].first << ' ' << dp[i][j].second << endl;
    pair <int, int> bst = {0, 0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (dp[bst.first][bst.second].first < dp[i][j].first) {
                bst = {i, j};
            }
        }
    }
    vector <int> ans;
    ans.push_back(a[bst.first]);
    while (dp[bst.first][bst.second].second != -1) {
        //cout << bst.first << ' ' << bst.second << endl;
        bst = {dp[bst.first][bst.second].second, bst.second - 1};
        ans.push_back(a[bst.first]);
    }
    reverse(ans.begin(), ans.end());
    int bigval = 1e6;
    while (ans.size() < k) {
        ans.push_back(bigval);
        ++bigval;
    }
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
