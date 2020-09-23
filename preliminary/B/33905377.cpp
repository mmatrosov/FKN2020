#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2 && b1 == b2) {
        cout << "coincide";
        return;
    }
    if (k1 == k2) {
        cout << "parallel";
        return;
    }
    cout << "intersect\n";
    cout.precision(10);
    cout << (b2 - b1 + 0.0) / (k1 - k2) << ' ' << k1 * (b2 - b1 + 0.0) / (k1 - k2) + b1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
