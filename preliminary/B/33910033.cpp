#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2 && b1 == b2) {
        cout << "coincide";
    } else if (k1 == k2) {
        cout << "parallel";
    } else {
        cout << "intersect" << '\n';
        cout.precision(20);
        double x = (b2 - b1) / (k1 - k2);
        double y = x * k1 + b1;
        cout << x << ' ' << y;
    }

}
