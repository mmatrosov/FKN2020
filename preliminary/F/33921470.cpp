#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct tr{
    ll i, j, b;
};

int main() {

    ll n, k;
    cin >> n >> k;
    vector<ll> a;
    ll n1 = n;
    for (ll i = 0; i < n; i++) {
        ll y;
        cin >> y;
        if (y == 0) {
            n1--;
        } else {
            a.push_back(y);
        }
    }
    n = n1;
    sort(a.begin(), a.end());
    vector<ll> ans;
    if (n == 0) {
        for (int i = 1; i <= k; i++) {
            cout << i << " ";
        }
        return 0;
    }
    if (k >= n) {
        if (n != 0) {
            ans.push_back(a[0]);
        }
        ll x = k - n;
        for (ll i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                ll y = a[i - 1] + 1;
                while (x > 0 && y != a[i]) {
                    ans.push_back(y);
                    //cout << y << " ";
                    y++;
                    x--;
                }
                ans.push_back(a[i]);
                //cout << a[i] << " ";
            }
        }
        x = k - ans.size();
        if (x != 0) {
            ll y = a[n - 1] + 1;
            while (x > 0 && y < 1e9) {
                //cout << y << " ";
                ans.push_back(y);
                y++;
                x--;
            }
            y = a[0] - 1;
            while (x > 0 && y > 0) {
                //cout << y << ' ';
                ans.push_back(y);
                y--;
                x--;
            }
        }
        sort(ans.begin(), ans.end());
        for (int i : ans) {
            cout << i << " ";
        }
        return 0;
    }
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k + 1, vector<ll>(2)));
    vector<vector<vector<tr>>> prev(n, vector<vector<tr>>(k + 1, vector<tr>(2, {-1, -1, -1})));
    for (ll i = n - 1; i >= 0; i--) {
        for (ll j = 0; j <= k; j++) {
            if (j != 0) {
                ll s = 1;
                for (ll e = i + 1; e < n; e++) {
                    if (dp[i][j][1] <= dp[e][j - 1][1] + s * a[i]) {
                        prev[i][j][1] = {e, j - 1, 1};
                        dp[i][j][1] = dp[e][j - 1][1] + s * a[i];
                    }
                    s += 1;
                }
                if (dp[i][j][1] <= s * a[i]) {
                    prev[i][j][1] = {n, j, 1};
                    dp[i][j][1] = s * a[i];
                }
            }
            for (ll e = i + 1; e < n; e++) {
                if (dp[i][j][0] <= dp[e][j][0]) {
                    prev[i][j][0] = {e, j, 0};
                    dp[i][j][0] = dp[e][j][0];
                }
                if (dp[i][j][0] <= dp[e][j][1]) {
                    prev[i][j][0] = {e, j, 1};
                    dp[i][j][0] = dp[e][j][1];
                }
            }
        }
    }
    tr last = {0, k, 1};
    tr x = prev[0][k][1];
    if (dp[0][k][1] < dp[0][k][0]) {
        last.b = 0;
        x = prev[0][k][0];
    }
    ll cnt = 0;
    int kol = 0;
    while (cnt <= 100) {
        cnt++;
        if (last.b == 1) {
            if (last.i >= n) {
                break;
            }
            kol++;
            ans.push_back(a[last.i]);
        }
        last = x;
        if(x.i >= n || x.i < 0 || x.j < 0 || x.b > 1 || x.b < 0 || x.j > k) {
            break;
        }
        x = prev[x.i][x.j][x.b];
    }
    if (kol < k) {
        ll x = k - kol;
        if (x != 0) {
            ll y = a[n - 1] + 1;
            while (x > 0 && y < 1e9) {
                //cout << y << " ";
                ans.push_back(y);
                y++;
                x--;
            }
            y = a[0] - 1;
            while (x > 0 && y > 0) {
                //cout << y << ' ';
                ans.push_back(y);
                y--;
                x--;
            }
        }
        sort(ans.begin(), ans.end());
    }
    for (ll i : ans) {
         cout << i << " ";
    }
    //cout << max(dp[0][k][1], dp[0][k][0]);



    return 0;
}
