#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long

using namespace std;
const int INF = 2e9;
const int MB = 20;
const int MOD = 1e9 + 7;

void solve() {
    int k;
    cin >> k;
    // k = 2 * (n + m - 2)
    if (k % 2) {
        cout << (k == 1 ? "YES" : "NO");
        return;
    }
    cout << "YES";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(12);
    //srand(time(0));
    int t = 1;
    //int t;
    //cin >> t;
    while (t--) solve();
}