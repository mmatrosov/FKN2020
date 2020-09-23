// Bippolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;
typedef long double ld;

const ll INF = (ll)(1e17) + 666;

int main() {
    ll n, k;
    cin >> n >> k;
    ll kek = max(k - n, (ll)0);
    k = min(n, k);
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.emplace_back(0);
    a.emplace_back(0);
    ++n;
    ++k;
    sort(a.begin(), a.end());
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, -INF));
    vector<vector<ll>> p(k + 1, vector<ll>(n + 1, -1));
    dp[0][0] = 0;
    for (ll i = 1; i <= k; ++i) {
        for (ll end = 0; end <= n; ++end) {
            for (ll begin = 0; begin < end; ++begin) {
                if (dp[i][end] < dp[i - 1][begin] + a[begin + 1] * (end - begin)) {
                    dp[i][end] = dp[i - 1][begin] + a[begin + 1] * (end - begin);
                    p[i][end] = begin;
                }
            }
        }
    }
    vector<ll> res;
    ll x = k;
    ll y = n;
    while (p[x][y] != -1) {
        res.emplace_back(a[p[x][y] + 1]);
        y = p[x][y];
        --x;
    }
    res.pop_back();
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    while (!res.empty() && res.back() == 0) {
        ++kek;
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    for (ll i : res) {
        cout << i << " ";
    }
    for (ll i = 0; i < kek; ++i) {
        cout << 10000 * 10000 + i << " ";
    }
    cout << endl;
    return 0;
}
