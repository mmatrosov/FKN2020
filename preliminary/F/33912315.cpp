#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define int long long

using namespace std;

const int maxn = 101;

int dp[maxn][maxn], p[maxn][maxn];
int a[maxn];
int n, k;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = -1e15;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    a[0] = -1;
    for (int i = 1; i <= n; i++) {
        int cc = 0;
        for (int l = i - 1; l >= 0; l--) {
            if (a[l] == a[l + 1]) continue;
            for (int j = 1; j <= k; j++) {
                int nval = dp[l][j - 1] + a[l + 1] * (i - l);
                dp[i][j] = max(dp[i][j], nval);
                if (dp[i][j] == nval) {
                    p[i][j] = l;
                }
            }
        }
    }
    vector<int> can;
    int x = n, y = k;
    for (int j = 1; j <= k; j++)
        if (dp[n][j] > dp[n][y])
            y = j;
    k -= y;
    while (y) {
        can.pb(a[p[x][y] + 1]);
        x = p[x][y]; --y;
    }
    while (k--)
        can.pb(1e8 + k);
    sort(can.begin(), can.end());
    for (int i = 0; i < can.size(); i++)
        cout << can[i] << ' ';
    return 0;
}
