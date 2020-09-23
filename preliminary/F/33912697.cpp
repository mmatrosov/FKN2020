//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1000000000;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<pair<int, int> > > dp(n + 1, vector<pair<int, int> >(k + 1, {-INF, -1}));
    dp[n][0] = {0, -1};
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) continue;
        for (int c = 1; c <= k; c++) {
            int sum = 0;
            for (int j = i + 1; j <= n; j++) {
                sum += a[i];
                if (j < n && a[i] == a[j]) continue;
                dp[i][c] = max(dp[i][c], make_pair(dp[j][c - 1].first + sum, j));
            }
        }
    }
    int last = n;
    int cnt = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i][j].first < -INF / 2) continue;
            if (last == n || dp[last][cnt].first < dp[i][j].first) {
                last = i, cnt = j;
            }
        }
    }
    vector<int> ans;
    while (last != n) {
        ans.push_back(a[last]);
        int to = dp[last][cnt].second;
        last = to;
        cnt--;
    }
    while ((int)ans.size() < k) {
        if (ans.empty()) ans.push_back(1);
        else ans.push_back(ans.back() + 1);
    }
    for (int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
