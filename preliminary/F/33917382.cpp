#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const int N = 105;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    a[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }
    a.push_back(1e7);
    ++n;
    sort(a.begin(), a.end());
    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(N, 0)));
    vector<vector<ll>> all(N, vector<ll>(N, 0)), rem = all;
    ll ans = 0;
    int p = 0, t = 0, r = 0;
    for (int z = 1; z <= k; ++z) {
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                dp[z][i][j] = all[z - 1][i] + a[i] * (j - i);
                if (all[z][j] < dp[z][i][j]) {
                    all[z][j] = dp[z][i][j];
                    rem[z][j] = i;
                }
                if (ans < dp[z][i][j]) r = z, p = i, t = j, ans = dp[z][i][j];
            }
        }
    }
    set<int> res;
    if (a[t] == 1e7) t = rem[r][t], --r;
    while (t > 0) {
        res.insert(a[t]);
        //cout << a[t] << " ";
        t = rem[r][t];
        --r;
    }
    vector<int> q;
    for (auto e : res)
        q.push_back(e);
    int tmp = 1e6 + 1;
    while (q.size() < k) {
        q.push_back(++tmp);
    }
    for (auto e : q)
        cout << e << " ";
    //cout << ans;
    return 0;
}
