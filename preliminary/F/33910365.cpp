#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
mt19937 rnd;

const int N = 100 + 10;
int a[N];
int dp[N][N];
int par[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (a[n] == 0) {
        for (int i = 1; i <= k; i++) {
            cout << i << " ";
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][1] = a[i] * (n - i + 1);
        par[i][1] = n + 1;
    }
    for (int j = 2; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            for (int k = i + 1; k <= n + 1; k++) {
                if (dp[i][j] < a[i] * (k - i) + dp[k][j - 1]) {
                    dp[i][j] = a[i] * (k - i) + dp[k][j - 1];
                    par[i][j] = k;
                }
            }
        }
    }
    int ans = 0, ptr = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            continue;
        }
        if (ans < dp[i][k]) {
            ans = dp[i][k];
            ptr = i;
        }
    }
    a[n + 1] = a[n] + 1;
    for (int j = k; j >= 1; j--) {
        cout << a[ptr] << " ";
        ptr = par[ptr][j];
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
