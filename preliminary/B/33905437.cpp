#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

void PUNKS_NOT_DEAD() {
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2 && b1 == b2) cout << "coincide";
    else if (k1 == k2) cout << "parallel";
    else {
        double up = b2 - b1;
        double down = k1 - k2;
        double x = up / down;
        double y = x * k1 + b1;
        cout << fixed << setprecision(10) << "intersect " << x << ' ' << y;
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    PUNKS_NOT_DEAD();
}