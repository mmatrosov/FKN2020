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
    double k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2 && b1 == b2) {
        cout << "coincide";
    }
    else if (k1 == k2) {
        cout << "parallel";
    }
    else {
        cout << "intersect\n";
        double x = (double)(b2 - b1) / (k1 - k2);
        double y = k1 * x + b1;
        cout << x << " " << y;
    }
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