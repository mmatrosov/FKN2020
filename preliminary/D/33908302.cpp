#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const double pi = 3.1415926536;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a = x1 * y2 - x2 * y1;
    int b = x1 * x2 + y1 * y2;
    double ang = abs(atan2(a, b));
    cout.precision(16);
    cout << min((double) sqrt(x1 * x1 + y1 * y1) + sqrt(x2 * x2 + y2 * y2), abs(sqrt(x1 * x1 + y1 * y1) - sqrt(x2 * x2 + y2 * y2)) + min(sqrt(x1 * x1 + y1 * y1), sqrt(x2 * x2 + y2 * y2)) * ang);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
