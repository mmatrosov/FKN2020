#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int MAXN = 105;
int n, k;
ll a[MAXN];
ll dp[MAXN][MAXN];
int p[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if (n > 100 || k > 100) {
        while (true) {}
    }
    rep(i, n) {
        cin >> a[i];
    }
    sort(a, a + n);

    rep(i, MAXN) {
        rep(j, MAXN) {
            dp[i][j] = 0;
            p[i][j] = -1;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j <= k; ++j) {
            for (int t = i + 1; t <= n; ++t) {
                ll nw = a[i] * (t - i) + dp[t][j - 1];
                if (nw > dp[i][j]) {
                    dp[i][j] = nw;
                    p[i][j] = t;
                }
            }
        }
    }

    int x = 0, y = min(n, k);
    ll mx = -1;
    rep(i, n) {
        if (dp[i][y] > mx) {
            mx = dp[i][y];
            x = i;
        }
    }

    vector<int> res;
    while (y >= 0 && x < n && x != -1) {
        if (a[x] != 0) res.push_back(a[x]);
        // cout << a[x] << ' ';
        x = p[x][y];
        y--;
    }

    while (res.size() < k) {
        res.push_back(res.size() ? res.back() + 1 : 1);
    }

    for (auto it : res) {
        cout << it << ' ';
    }
    cout << endl;
}
