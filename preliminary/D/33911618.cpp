#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    cout << fixed << setprecision(15);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (make_pair(x1, y1) == make_pair(x2, y2)) {
        cout << 0;
        exit(0);
    }
    long double d1, d2, mid, mxd;
    d1 = sqrtl(x1 * x1 + y1 * y1);
    d2 = sqrtl(x2 * x2 + y2 * y2);
    mid = min(d1, d2);
    mxd = max(d1, d2);
    if (x1 * y2 == x2 * y1) {
        cout << sqrtl((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        return 0;
    }
    long double ang = acos((x1 * x2 + y1 * y2) / (d1 * d2));
    if (ang < 2) {
        cout << (mxd - mid) + mid * ang;
    }
    else {
        cout << d1 + d2;
    }
}
