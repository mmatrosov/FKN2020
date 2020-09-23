#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1e15));
    vector<vector<int>> prev(n + 1, vector<int>(k + 1, -1));
    for (int i = 0; i < n + 1; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            dp[i + 1][j + 1] = dp[i][j] + v[i];
            prev[i + 1][j + 1] = i;
            for (int l = 0; l < i; ++l) {
                ll cur = dp[l][j] + v[l] * (i - l + 1);
                if (dp[i + 1][j + 1] < cur) {
                    dp[i + 1][j + 1] = cur;
                    prev[i + 1][j + 1] = l;
                }
            }
        }
    }
    vector<int> ans;
    int ci = n, cj = k;
    while (dp[ci][cj] < 0) {
        cj--;
    }
    while (ci > 0 && cj > 0) {
        ci = prev[ci][cj];
        ans.push_back(v[ci]);
        cj--;
    }
    sort(ans.begin(), ans.end());
    for (int i : ans) {
        if (i > 0) {
            cout << i << " ";
            k--;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << 1e5 + i + 1 << " ";
    }
    cout << endl;
}
