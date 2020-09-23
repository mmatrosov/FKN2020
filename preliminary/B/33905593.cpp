#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;

    if (k1 == k2) {
        if (b1 == b2) {
            cout << "coincide\n";
        } else {
            cout << "parallel\n";
        }
    } else {
        cout << fixed << setprecision(7);

        ld x = (ld)(b2 - b1) / (k1 - k2);
        ld y = k1 * x + b1;

        cout << "intersect\n";
        cout << x << " " << y << '\n';
    }
}
