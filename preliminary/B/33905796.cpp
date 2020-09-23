#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2 && b1 == b2) {
        cout << "coincide";
    } else if (k1 == k2) {
        cout << "parallel";
    } else {
        cout << "intersect\n";
        double x = double(b2 - b1) / (k1 - k2);
        double y = k1 * x + b1;
        cout << fixed << setprecision(7) << x << " " << y;
    }
}

int main() {
#ifdef OLYMP
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
